

#include "urn_is4s_discovery_client_1_0/DiscoveryClientService.h"
#include <iostream>
using namespace JTS;
using namespace std;

namespace urn_is4s_discovery_client_1_0
{
	
DiscoveryClientService::DiscoveryClientService(JTS::JausRouter* jausRouter ) : Service()
{
	jausRouter->setTransportType(JausRouter::Version_1_0);
	
	pDiscoveryClient_DiscoveryClientFSM = new DiscoveryClient_DiscoveryClientFSM();
	pDiscoveryClient_DiscoveryClientFSM->setHandlers(ieHandler, jausRouter);
	pDiscoveryClient_DiscoveryClientFSM->setupNotifications();

}


DiscoveryClientService::~DiscoveryClientService()
{
	delete pDiscoveryClient_DiscoveryClientFSM;

}

/**
 *	This is the function that will actually be run by the thread at start-up.
 *  We override it from EventReceiver in order to handle any entry
 *  actions defined by the initial state. 
 */
void DiscoveryClientService::run()
{
	
	/// Perform any entry actions specified by the start state.

	
	/// Kick-off the receive loop...
	EventReceiver::run();
}

/**
 *	This is the function that will process an event either generated
 *  by the service, sent to it by another service on the same component,
 *  or as a message sent by a different component. 
 */
bool DiscoveryClientService::processTransitions(InternalEvent* ie)
{
        bool done = false;

   // Since this function can be called from multiple threads,
   // we use a mutex to ensure only one state transition is
   // active at a time.
   mutex.lock();

			// Invoke the FSM transition for this event.
			try
			{
				if ((done == false) && ie->getName().compare("GuiControlEntered") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					GuiControlEntered* casted_ie = (GuiControlEntered*) ie;
						GuiControlEntered msg = *casted_ie;
						pDiscoveryClient_DiscoveryClientFSM->context->GuiControlEnteredTransition(msg);
						done = true;
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportIdentification::ID)
					{
						ReportIdentification msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						// Unique identifier used to replace previous edits upon regeneration, do not delete this comment:3b3436f9-c46b-3259-8777-d16308ed9b6c
                                                unsigned int sender =
                                                        (casted_ie->getBody()->getReceiveRec()->getSrcSubsystemID() << 16) +
                                                        (casted_ie->getBody()->getReceiveRec()->getSrcNodeID() << 8) +
                                                        (casted_ie->getBody()->getReceiveRec()->getSrcComponentID());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportIdentificationTransition(msg, sender);
						done = true;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportServices::ID)
					{
						ReportServices msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						// Unique identifier used to replace previous edits upon regeneration, do not delete this comment:8ef023c2-315b-309a-a247-c9efd0755dfa
                                                unsigned int sender =
                                                        (casted_ie->getBody()->getReceiveRec()->getSrcSubsystemID() << 16) +
                                                        (casted_ie->getBody()->getReceiveRec()->getSrcNodeID() << 8) +
                                                        (casted_ie->getBody()->getReceiveRec()->getSrcComponentID());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportServicesTransition(msg, sender);
						done = true;
					}
				}
			} catch (...) {}

			 

   mutex.unlock();
   return done;
}


/**
 *	This is the function that will check for default transitions if
 *  no other transitions were satisfied. 
 */
bool DiscoveryClientService::defaultTransitions(InternalEvent* ie)
{
   bool done = false;

   // Since this function can be called from multiple threads,
   // we use a mutex to ensure only one state transition is
   // active at a time.
   mutex.lock();

			// Invoke the FSM transition for this event.
			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportServiceList::ID)
					{
						ReportServiceList msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportServiceListTransition();
						done = true;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportServices::ID)
					{
						ReportServices msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportServicesTransition();
						done = true;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportSubsystemList::ID)
					{
						ReportSubsystemList msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportSubsystemListTransition();
						done = true;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportIdentification::ID)
					{
						ReportIdentification msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportIdentificationTransition();
						done = true;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					if ( id == ReportConfiguration::ID)
					{
						ReportConfiguration msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						pDiscoveryClient_DiscoveryClientFSM->context->ReportConfigurationTransition();
						done = true;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("GuiControlEntered") == 0 && (ie->getSource().compare("DiscoveryClient_DiscoveryClientFSM") != 0))
				{
					GuiControlEntered* casted_ie = (GuiControlEntered*) ie;
						pDiscoveryClient_DiscoveryClientFSM->context->GuiControlEnteredTransition();
						done = true;
				}
			} catch (...) {}

	

   mutex.unlock();
   return done;
}


};
