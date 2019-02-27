//**********************************************************
// File: engine.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Alita Engine Implemention
//**********************************************************

#include "engine.h"

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

int Engine::init() {
	return 0;
}

int Engine::destroy() {
	return 0;
}

int Engine::handle(const std::string& string, std::string* res) {
	res->assign(string);
	return 0;
}

} // namespace alita
