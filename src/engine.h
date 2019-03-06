//**********************************************************
// File: engine.h                                         
// Author: wtzhuque@163.com                               
// Description: Alita Engine
//**********************************************************
#pragma once

#include <string>
#include <memory>

#include "tablebase.h"
#include "flow.h"

namespace alita {

class Engine {
public:
	static Engine* instance();

public:
	int init(const std::string& config_file);

	int destroy();

	int handle(const std::string& msg, std::string* res);

private:
	int init_table(const std::string& table_config);
	
	int init_flow(const std::string& flow_config);
	
public:
	~Engine() {}

private:
	Engine() {}
	Engine(const Engine&) {}

private:
	std::shared_ptr<TableBase> _table;
	std::shared_ptr<Flow> _flow;
}; // class Engine

} // namespace alita
