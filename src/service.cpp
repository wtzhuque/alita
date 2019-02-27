//**********************************************************
// File: service.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Alita Service Implemention
//**********************************************************

#include "service.h"

#include <brpc/server.h>

#include "engine.h"

namespace alita {

ServiceImpl::ServiceImpl() {
}

ServiceImpl::~ServiceImpl() {
}

int ServiceImpl::init() {
	return 0;
}

int ServiceImpl::destroy() {
	return 0;
}

void ServiceImpl::query(::google::protobuf::RpcController* cntl_base,
                        const ::alita::Request* request,
                        ::alita::Response* response,
                        ::google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);
    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

	Engine* engine = Engine::instance();
}

} // namespace alita
