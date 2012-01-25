

#ifndef DISCOVERYCLIENT_H
#define DISCOVERYCLIENT_H

#include <vector>
#include "EventReceiver.h"
#include "Transport/JausTransport.h"
#include "InternalEvents/InternalEvent.h"
#include "urn_is4s_discovery_client_1_0/DiscoveryClientService.h"
#include "urn_is4s_discovery_client_1_0/DiscoveryClient_DiscoveryClientFSM_sm.h"
using namespace urn_is4s_discovery_client_1_0;

class DiscoveryClient : public JTS::EventReceiver
{
public:
	DiscoveryClient(unsigned int subsystem, unsigned short node, unsigned short component);
	virtual ~DiscoveryClient();
	
	void startComponent();
	void shutdownComponent();
	
        JTS::InternalEventHandler* getIEHandler(){return ieHandler;}

        void queryIdentification(JausAddress dest);
        void queryIdentification();

        void queryServices(JausAddress dest);
        void queryConfiguration(JausAddress dest);
        void querySubsystemList(JausAddress dest);
        void queryServicesList(JausAddress dest);

        void setIdentCallback(identCallback cb){pDiscoveryClientService->setIdentCallback(cb);}

protected:
        virtual void processInternalEvent(JTS::InternalEvent* ie);
        std::vector<JTS::Service*> serviceList;
	JTS::JausRouter* jausRouter;
	
        DiscoveryClientService* pDiscoveryClientService;
};

#endif // DISCOVERYCLIENT_H
