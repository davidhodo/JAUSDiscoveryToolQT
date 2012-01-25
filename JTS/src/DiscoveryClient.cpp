

#include "DiscoveryClient.h"
#include "JausUtils.h"
#include <iostream>
using namespace std;

using namespace JTS;
using namespace urn_is4s_discovery_client_1_0;


DiscoveryClient::DiscoveryClient(unsigned int subsystem, unsigned short node, unsigned short component)
{
	jausRouter = new JausRouter(JausAddress(subsystem, node, component), ieHandler);
	
	/// Instantiate services
        pDiscoveryClientService = new DiscoveryClientService(jausRouter);
	
	
	/// Add all the Services for the Component
	serviceList.push_back(pDiscoveryClientService);
}

DiscoveryClient::~DiscoveryClient()
{
	Service* service;
	
	while (!serviceList.empty())
	{
		service = serviceList.back();
		serviceList.pop_back();
		
		delete service;
	}
	
	delete jausRouter;
}


void DiscoveryClient::startComponent()
{
	Service* service;
	
	jausRouter->start();
	this->start();
	
	for (unsigned int i = 0; i < serviceList.size(); i++)
	{
		 service = serviceList.at(i);
		 service->start();
	}
}


void DiscoveryClient::shutdownComponent()
{
	Service* service;
	
	for (unsigned int i = 0; i < serviceList.size(); i++)
	{
		 service = serviceList.at(i);
		 service->stop();
	}
	
	this->stop();
	jausRouter->stop();
}

void DiscoveryClient::processInternalEvent(InternalEvent *ie)
{
    bool done = false;
	
	//
	// When a component receives an internal event, it passes it
	// to the services to handling, children services first.  If the
	// event is not processed by normal transitions, it's passed
	// again to the services (children first) for default transitions.
	// A given event may only be processed by at most one service.
	//
	for (unsigned int i = serviceList.size(); i>0; i--)
	{
		if (!done) done = serviceList.at(i-1)->processTransitions(ie);
	}
	for (unsigned int i = serviceList.size(); i>0; i--)
	{
		if (!done) done = serviceList.at(i-1)->defaultTransitions(ie);
	}
}

void DiscoveryClient::queryIdentification()
{
    JausAddress broadcastAdr(0xFFFF,0xFF,0xFF);
    queryIdentification(broadcastAdr);
}

void DiscoveryClient::queryIdentification(JausAddress dest)
{
    GuiControlEntered *guiEvent = new GuiControlEntered;
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setCommand( QUERYIDENTIFICATION );
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setValue( dest.get() );
    ieHandler->invoke(guiEvent);
}

void DiscoveryClient::queryServices(JausAddress dest) {
    GuiControlEntered *guiEvent = new GuiControlEntered;
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setCommand( QUERYSERVICES );
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setValue( dest.get() );
    ieHandler->invoke(guiEvent);

}

void DiscoveryClient::queryConfiguration(JausAddress dest) {
    GuiControlEntered *guiEvent = new GuiControlEntered;
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setCommand( QUERYCONFIGURATION );
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setValue( dest.get() );
    ieHandler->invoke(guiEvent);
}

void DiscoveryClient::querySubsystemList(JausAddress dest) {
    GuiControlEntered *guiEvent = new GuiControlEntered;
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setCommand( QUERYSUBSYSTEMLIST );
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setValue( dest.get() );
    ieHandler->invoke(guiEvent);

}

void DiscoveryClient::queryServicesList(JausAddress dest) {
    GuiControlEntered *guiEvent = new GuiControlEntered;
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setCommand( QUERYSERVICESLIST );
    guiEvent->getGuiControlEnteredBody()->getGuiControlEnteredRecord()->setValue( dest.get() );
    ieHandler->invoke(guiEvent);
}
