//**********************************************************
// File: service.h                                         
// Author: wtzhuque@163.com                               
// Description: Alita Service
//**********************************************************

#include "alita_service.pb.h"

namespace alita {

class ServiceImpl : public AlitaService {
public:
	ServiceImpl();

	~ServiceImpl();

	int init();

	int destroy();
  
	virtual void query(::google::protobuf::RpcController* controller,
                       const ::alita::Request* request,
                       ::alita::Response* response,
                       ::google::protobuf::Closure* done);

private:
}; // class ServiceImpl

} // namespace alita
