//**********************************************************
// File: service.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Alita Service Implemention
//**********************************************************

#include "service.h"

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

void ServiceImpl::query(::google::protobuf::RpcController* controller,
                        const ::alita::Request* request,
                        ::alita::Response* response,
                        ::google::protobuf::Closure* done) {
}

} // namespace alita
