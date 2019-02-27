//**********************************************************
// File: engine.h                                         
// Author: wtzhuque@163.com                               
// Description: Alita Engine
//**********************************************************
#pragma once

#include <string>

namespace alita {

class Engine {
public:
	static Engine* instance();

public:
	int init();

	int destroy();

	int handle(const std::string& msg, std::string* res);
	
public:
	~Engine() {}

private:
	Engine() {}
	Engine(const Engine&) {}
}; // class Engine

} // namespace alita
