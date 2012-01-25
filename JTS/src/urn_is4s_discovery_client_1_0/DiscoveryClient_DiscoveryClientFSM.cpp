

#include "urn_is4s_discovery_client_1_0/DiscoveryClient_DiscoveryClientFSM.h"
#include <iostream>
using namespace std;


using namespace JTS;

namespace urn_is4s_discovery_client_1_0
{



DiscoveryClient_DiscoveryClientFSM::DiscoveryClient_DiscoveryClientFSM()
{

	/*
	 * If there are other variables, context must be constructed last so that all 
	 * class variables are available if an EntryAction of the InitialState of the 
	 * statemachine needs them. 
	 */
	context = new DiscoveryClient_DiscoveryClientFSMContext(*this);

}



DiscoveryClient_DiscoveryClientFSM::~DiscoveryClient_DiscoveryClientFSM() 
{
	delete context;
}

void DiscoveryClient_DiscoveryClientFSM::setupNotifications()
{

}

void DiscoveryClient_DiscoveryClientFSM::addDiscoveryServerAction(ReportIdentification msg)
{
    /// Insert User Code HERE
    cout << "Received discovery server address: " << endl;
}

void DiscoveryClient_DiscoveryClientFSM::saveServicesAction(ReportServices msg)
{
    /// Insert User Code HERE
    cout << "Received list of services from discovery server." << endl;
}

void DiscoveryClient_DiscoveryClientFSM::sendQueryMessageAction(GuiControlEntered msg)
{
	/// Insert User Code HERE
    cout << "Sending query:" << msg.getGuiControlEnteredBody()->getGuiControlEnteredRecord()->getCommand() << endl;
    // see which query message I should send and send it
    // Cmd 1 - Query Identification
    // Cmd 2 - Query Services
    // Cmd 3 - Query Configuration
    // Cmd 4 - Query Subsystem List
    // Cmd 5 - Query Services List
    switch (msg.getGuiControlEnteredBody()->getGuiControlEnteredRecord()->getCommand()) {
        case QUERYIDENTIFICATION: {
            QueryIdentification qry;
            JausAddress recipient(msg.getGuiControlEnteredBody()->getGuiControlEnteredRecord()->getValue());
            cout << "Send QueryIdentification to: " << hex << (unsigned int)recipient.getSubsystemID() << ":"
                 << (unsigned int)recipient.getNodeID() << ":" << (unsigned int)recipient.getComponentID() << endl;
            sendJausMessage( qry, recipient);
        }
        break;
        case QUERYSERVICES: {
            cout << "Send QueryServices." << endl;
            QueryServices qry;
            // broadcast query to specified discovery service
            JausAddress recipient(msg.getGuiControlEnteredBody()->getGuiControlEnteredRecord()->getValue());
            sendJausMessage( qry, recipient);               
        }
        break;
        case QUERYCONFIGURATION:
            cout << "Send QueryConfiguration." << endl;
        break;
        case QUERYSUBSYSTEMLIST:
            cout << "Send QuerySubsystemList." << endl;
        break;
        case QUERYSERVICESLIST:
            cout << "Send QueryServicesList." << endl;
        break;
        default:
            cout << "Unknown GUI command." << endl;
        break;
        
    }
    
}





};
