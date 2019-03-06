//**********************************************************
// File: cli.cpp                                         
// Author: wtzhuque@163.com                               
// Description: Cli Tool of Alita
//**********************************************************

#include <stdio.h>

namespace alita {

int run(int argc, char** argv) {
	fprintf(stderr, "hello alita\n");
	return 0;
}

} // namespace alita

int main(int argc, char** argv) {
	return ::alita::run(argc, argv);
}
