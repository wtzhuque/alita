//**********************************************************
// File: flow.h                                         
// Author: wtzhuque@163.com                               
// Description: Process Flow
//**********************************************************
#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace alita {

class Node;
class Runtime;

class Flow {
public:
	Flow();

	~Flow();

	/**
	 * @brief init work flow
	 */
	int init(const std::string& flow_config);

	/**
	 * @brief destroy work flow
	 */
	int destroy();

	/**
	 * @brief start running
	 */
	bool run(Runtime* rt);

private:
	bool init_node();

private:
	std::unordered_map<std::string, Node*> _nodes;
	std::vector<Node*> _node_stream;
}; // class Flow

} // namespace alita
