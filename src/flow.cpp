//**********************************************************
// File: flow.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Process Flow
//**********************************************************

#include "flow.h"

namespace alita {

Flow::Flow() {
}

Flow::~Flow() {
}

int Flow::init(const std::string& flow_config) {
	return 0;
}

int Flow::destroy() {
	return 0;
}

bool Flow::run(Runtime* rt) {
	return false;
}

} // namespace alita
