

#ifndef DISCOVERYCLIENTSERVICE_H
#define DISCOVERYCLIENTSERVICE_H

#include "Service.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JConstants.h"
#include "urn_is4s_discovery_client_1_0/Messages/MessageSet.h"
#include "urn_is4s_discovery_client_1_0/InternalEvents/InternalEventsSet.h"
#include "Transport/OS.h"

#include "DiscoveryClient_DiscoveryClientFSM.h"


namespace urn_is4s_discovery_client_1_0
{
	
class DllExport DiscoveryClientService : public JTS::Service
{
public:
	DiscoveryClientService( JTS::JausRouter* jausRouter );
	virtual ~DiscoveryClientService();
	
	virtual bool processTransitions(JTS::InternalEvent* ie);
	virtual bool defaultTransitions(JTS::InternalEvent* ie);
	
	// FSMs are public so that children services can access them
	DiscoveryClient_DiscoveryClientFSM* pDiscoveryClient_DiscoveryClientFSM;
	
        void setIdentCallback(identCallback cb){pDiscoveryClient_DiscoveryClientFSM->setIdentCallback(cb);}

	
protected:
	virtual void run();

};

};

#endif // DISCOVERYCLIENTSERVICE_H
