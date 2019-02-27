//**********************************************************
// File: main.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Main Entry of Alita
//**********************************************************

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/server.h>

#include "service.h"

DEFINE_int32(port, 8000, "TCP Port of this server");
DEFINE_int32(idle_timeout_s, -1, "Connection will be closed if there is no "
             "read/write operations during the last `idle_timeout_s'");

namespace alita {

int run(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);

	ServiceImpl impl;
	int ret = impl.init();
	if (ret != 0) {
		LOG(ERROR) << "Failed to init service"; 
		return ret;
	}
    
	brpc::Server server;
    
	if (server.AddService(&impl, brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add service";
        return -1;
    }
    
	brpc::ServerOptions options;
    options.idle_timeout_sec = FLAGS_idle_timeout_s;
    if (server.Start(FLAGS_port, &options) != 0) {
        LOG(ERROR) << "Fail to start EchoServer";
        return -1;
    }

    // Wait until Ctrl-C is pressed, then Stop() and Join() the server.
    server.RunUntilAskedToQuit();
	return 0;
}

} // namespace alita

int main(int argc, char** argv) {
	return alita::run(argc, argv);
}
