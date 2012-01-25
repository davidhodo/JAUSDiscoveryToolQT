#ifndef _H_DISCOVERYCLIENT_DISCOVERYCLIENTFSM_SM
#define _H_DISCOVERYCLIENT_DISCOVERYCLIENTFSM_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : DiscoveryClient_DiscoveryClientFSM_sm.sm
 */


#define SMC_USES_IOSTREAMS

#include <statemap.h>

namespace urn_is4s_discovery_client_1_0
{
    // Forward declarations.
    class DiscoveryClient_DiscoveryClientFSM_SM;
    class DiscoveryClient_DiscoveryClientFSM_SM_Ready;
    class DiscoveryClient_DiscoveryClientFSM_SM_Internally_Generated_State_DO_NOT_USE;
    class DiscoveryClient_DiscoveryClientFSM_SM_Default;
    class DiscoveryClient_DiscoveryClientFSMState;
    class DiscoveryClient_DiscoveryClientFSMContext;
    class DiscoveryClient_DiscoveryClientFSM;

    class DiscoveryClient_DiscoveryClientFSMState :
        public statemap::State
    {
    public:

        DiscoveryClient_DiscoveryClientFSMState(const char *name, int stateId)
        : statemap::State(name, stateId)
        {};

        virtual void Entry(DiscoveryClient_DiscoveryClientFSMContext&) {};
        virtual void Exit(DiscoveryClient_DiscoveryClientFSMContext&) {};

        virtual void GuiControlEnteredTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        virtual void GuiControlEnteredTransition(DiscoveryClient_DiscoveryClientFSMContext& context, GuiControlEntered msg);
        virtual void ReportConfigurationTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        virtual void ReportIdentificationTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        virtual void ReportIdentificationTransition(DiscoveryClient_DiscoveryClientFSMContext& context, ReportIdentification msg);
        virtual void ReportServiceListTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        virtual void ReportServicesTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        virtual void ReportServicesTransition(DiscoveryClient_DiscoveryClientFSMContext& context, ReportServices msg);
        virtual void ReportSubsystemListTransition(DiscoveryClient_DiscoveryClientFSMContext& context);

    protected:

        virtual void Default(DiscoveryClient_DiscoveryClientFSMContext& context);
    };

    class DiscoveryClient_DiscoveryClientFSM_SM
    {
    public:

        static DiscoveryClient_DiscoveryClientFSM_SM_Ready Ready;
        static DiscoveryClient_DiscoveryClientFSM_SM_Internally_Generated_State_DO_NOT_USE Internally_Generated_State_DO_NOT_USE;
    };

    class DiscoveryClient_DiscoveryClientFSM_SM_Default :
        public DiscoveryClient_DiscoveryClientFSMState
    {
    public:

        DiscoveryClient_DiscoveryClientFSM_SM_Default(const char *name, int stateId)
        : DiscoveryClient_DiscoveryClientFSMState(name, stateId)
        {};

    };

    class DiscoveryClient_DiscoveryClientFSM_SM_Ready :
        public DiscoveryClient_DiscoveryClientFSM_SM_Default
    {
    public:
        DiscoveryClient_DiscoveryClientFSM_SM_Ready(const char *name, int stateId)
        : DiscoveryClient_DiscoveryClientFSM_SM_Default(name, stateId)
        {};

        void GuiControlEnteredTransition(DiscoveryClient_DiscoveryClientFSMContext& context, GuiControlEntered msg);
        void ReportIdentificationTransition(DiscoveryClient_DiscoveryClientFSMContext& context, ReportIdentification msg);
        void ReportServicesTransition(DiscoveryClient_DiscoveryClientFSMContext& context, ReportServices msg);
    };

    class DiscoveryClient_DiscoveryClientFSM_SM_Internally_Generated_State_DO_NOT_USE :
        public DiscoveryClient_DiscoveryClientFSM_SM_Default
    {
    public:
        DiscoveryClient_DiscoveryClientFSM_SM_Internally_Generated_State_DO_NOT_USE(const char *name, int stateId)
        : DiscoveryClient_DiscoveryClientFSM_SM_Default(name, stateId)
        {};

        void GuiControlEnteredTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        void ReportConfigurationTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        void ReportIdentificationTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        void ReportServiceListTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        void ReportServicesTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
        void ReportSubsystemListTransition(DiscoveryClient_DiscoveryClientFSMContext& context);
    };

    class DiscoveryClient_DiscoveryClientFSMContext :
        public statemap::FSMContext
    {
    public:

        DiscoveryClient_DiscoveryClientFSMContext(DiscoveryClient_DiscoveryClientFSM& owner)
        : FSMContext(DiscoveryClient_DiscoveryClientFSM_SM::Ready),
          _owner(owner)
        {};

        DiscoveryClient_DiscoveryClientFSMContext(DiscoveryClient_DiscoveryClientFSM& owner, const statemap::State& state)
        : FSMContext(state),
          _owner(owner)
        {};

        virtual void enterStartState()
        {
            getState().Entry(*this);
            return;
        }

        DiscoveryClient_DiscoveryClientFSM& getOwner() const
        {
            return (_owner);
        };

        DiscoveryClient_DiscoveryClientFSMState& getState() const
        {
            if (_state == NULL)
            {
                throw statemap::StateUndefinedException();
            }

            return (dynamic_cast<DiscoveryClient_DiscoveryClientFSMState&>(*_state));
        };

        void GuiControlEnteredTransition()
        {
            setTransition("GuiControlEnteredTransition");
            (getState()).GuiControlEnteredTransition(*this);
            setTransition(NULL);
        };

        void GuiControlEnteredTransition(GuiControlEntered msg)
        {
            setTransition("GuiControlEnteredTransition");
            (getState()).GuiControlEnteredTransition(*this, msg);
            setTransition(NULL);
        };

        void ReportConfigurationTransition()
        {
            setTransition("ReportConfigurationTransition");
            (getState()).ReportConfigurationTransition(*this);
            setTransition(NULL);
        };

        void ReportIdentificationTransition()
        {
            setTransition("ReportIdentificationTransition");
            (getState()).ReportIdentificationTransition(*this);
            setTransition(NULL);
        };

        void ReportIdentificationTransition(ReportIdentification msg)
        {
            setTransition("ReportIdentificationTransition");
            (getState()).ReportIdentificationTransition(*this, msg);
            setTransition(NULL);
        };

        void ReportServiceListTransition()
        {
            setTransition("ReportServiceListTransition");
            (getState()).ReportServiceListTransition(*this);
            setTransition(NULL);
        };

        void ReportServicesTransition()
        {
            setTransition("ReportServicesTransition");
            (getState()).ReportServicesTransition(*this);
            setTransition(NULL);
        };

        void ReportServicesTransition(ReportServices msg)
        {
            setTransition("ReportServicesTransition");
            (getState()).ReportServicesTransition(*this, msg);
            setTransition(NULL);
        };

        void ReportSubsystemListTransition()
        {
            setTransition("ReportSubsystemListTransition");
            (getState()).ReportSubsystemListTransition(*this);
            setTransition(NULL);
        };

    private:

        DiscoveryClient_DiscoveryClientFSM& _owner;
    };
}


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_DISCOVERYCLIENT_DISCOVERYCLIENTFSM_SM