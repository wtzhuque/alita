//**********************************************************
// File: operator.h                                         
// Author: wtzhuque@163.com                               
// Description: Operator
//**********************************************************
#pragma once

namespace alita {

class Operator : public Object {
public:
	Operator() {}

	virtual ~Operator() {}

	bool Run();
}; // class Operator

} // namespace alita
