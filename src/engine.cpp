//**********************************************************
// File: engine.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Alita Engine Implemention
//**********************************************************

#include "engine.h"

#include "butil/logging.h"
#include "butil/object_pool.h"

#include "runtime.h"

namespace {
	static alita::Engine* g_instance = nullptr;
}

namespace alita {

Engine* Engine::instance() {
	if (__builtin_expect(g_instance == nullptr, 0)) {
		g_instance = new Engine();
	}

	return g_instance;
}

int Engine::init(const std::string& config_file) {
	int ret = init_table(config_file);
	if (ret != 0) {
		LOG(WARNING) << "failed to init table";
		return ret;
	}
	return 0;
}

int Engine::destroy() {
	return 0;
}

int Engine::handle(const std::string& string, std::string* res) {
	res->assign(string);

	Runtime* runtime = butil::get_object<Runtime>();
	runtime->clear();

	if (!_flow->run(runtime)) {
		LOG(WARNING) << "run flow failed";
		return -1;
	}

	if (butil::return_object<Runtime>(runtime) != 0) {
		LOG(FATAL) << "object<Runtime> release failed [mem leak]";
		return -1;
	}

	return 0;
}

int Engine::init_table(const std::string& table_config) {
	return 0;
}

int Engine::init_flow(const std::string& flow_config) {
	return 0;
}

} // namespace alita
