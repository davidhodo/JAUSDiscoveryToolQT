

#ifndef DISCOVERYCLIENT_DISCOVERYCLIENTFSM_H
#define DISCOVERYCLIENT_DISCOVERYCLIENTFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_is4s_discovery_client_1_0/Messages/MessageSet.h"
#include "urn_is4s_discovery_client_1_0/InternalEvents/InternalEventsSet.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef JTS::Receive_1_0 Receive;
typedef JTS::Send_1_0 Send;

#define QUERYIDENTIFICATION 1
#define QUERYSERVICES 2
#define QUERYCONFIGURATION 3
#define QUERYSUBSYSTEMLIST 4
#define QUERYSERVICESLIST 5


#include "DiscoveryClient_DiscoveryClientFSM_sm.h"

namespace urn_is4s_discovery_client_1_0
{

//typedef boost::function<void(long, long, configitem::ConfigItem)> identCallback;


class DllExport DiscoveryClient_DiscoveryClientFSM : public JTS::StateMachine
{
public:
    DiscoveryClient_DiscoveryClientFSM();
    virtual ~DiscoveryClient_DiscoveryClientFSM();

    /// Handle notifications on parent state changes
    virtual void setupNotifications();

    /// Action Methods
    virtual void addDiscoveryServerAction(ReportIdentification msg);
    virtual void saveServicesAction(ReportServices msg);
    virtual void sendQueryMessageAction(GuiControlEntered msg);


    /// Guard Methods



    DiscoveryClient_DiscoveryClientFSMContext *context;

protected:

    /// References to parent FSMs

    
    /// callbacks for receive methods


};

};

#endif // DISCOVERYCLIENT_DISCOVERYCLIENTFSM_H
