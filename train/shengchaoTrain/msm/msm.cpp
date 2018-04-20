#include <iostream>
#include <boost/msm/back/state_machine.hpp>
 
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>
#include <boost/static_assert.hpp>
 
namespace {
    namespace msm = boost::msm;
    namespace msmf = boost::msm::front;
    namespace mpl = boost::mpl;
 
    // ----- Events
    struct Event1 {};
    struct Event2 {};
    struct Event3 {};

    struct Action1
    {
	template <class Event, class StateMachine, class SourceState, class TargetState>
	void operator()(Event const& event, StateMachine&, SourceState&, TargetState&)
        {
	    std::cout << "---------Action1---------\r\n" << std::endl;
	}
    };

    struct Action2
    {
	template <class Event, class StateMachine, class SourceState, class TargetState>
        void operator()(Event const& event, StateMachine&, SourceState&, TargetState&)
	{
	    std::cout << "---------Action2---------\r\n" << std::endl;
	}
    };
	
    struct Guard1
    {
        template <class Event, class StateMachine, class SourceState, class TargetState>
        bool operator()(Event const& event, StateMachine&, SourceState&, TargetState&)
        {
            std::cout << "+++++++++Guard1++++++++++\r\n" << std::endl;
	   // return true;
	    return false;
	}
    };

    struct Guard2
    {
	template <class Event, class StateMachine, class SourceState, class TargetState>
	bool operator()(Event const& event, StateMachine&, SourceState&, TargetState&)
	{
	    std::cout << "+++++++++Guard2++++++++++\r\n" << std::endl;
	    return true;
        }
    };
 
    // ----- State machine
    struct OuterSm_:msmf::state_machine_def<OuterSm_>
    {
		
        struct State1_:msmf::state_machine_def<State1_>
        {
            template <class Event,class Fsm>
            void on_entry(Event const&, Fsm&) const {
                std::cout << "State1::on_entry()\r\n" << std::endl;
            }
            template <class Event,class Fsm>
            void on_exit(Event const&, Fsm&) const {
                std::cout << "State1::on_exit()\r\n" << std::endl;
            }
 
            struct SubState1:msmf::state<> {
                template <class Event,class Fsm>
                void on_entry(Event const&, Fsm&) const {
                    std::cout << "SubState1::on_entry()\r\n" << std::endl;
                }
                template <class Event,class Fsm>
                void on_exit(Event const&, Fsm&) const {
                    std::cout << "SubState1::on_exit()\r\n" << std::endl;
                }
            };
			
            struct SubState2:msmf::state<> {
                template <class Event,class Fsm>
                void on_entry(Event const&, Fsm&) const {
                    std::cout << "SubState2::on_entry()\r\n" << std::endl;
                }
                template <class Event,class Fsm>
                void on_exit(Event const&, Fsm&) const {
                    std::cout << "SubState2::on_exit()\r\n" << std::endl;
                }
            };
 
            // Set initial state
            typedef mpl::vector<SubState1> initial_state;
            // Transition table
            struct transition_table:mpl::vector<
                //          Start      Event   Next       Action      Guard
                msmf::Row < SubState1, Event2, SubState2, Action1, Guard1 >,
                msmf::Row < SubState2, Event3, SubState1, Action2, Guard2 >
                > {};
                
            template <class StateMachine, class Event>
	    void no_transition(const Event& event, StateMachine& stateMachine, int state)
	    {
		 std::cout << "State1 no_transition\r\n" << std::endl;
	    }
        };
        
        struct State2:msmf::state<>
        {
            template <class Event,class Fsm>
            void on_entry(Event const&, Fsm&) const {
                std::cout << "State2::on_entry()\r\n" << std::endl;
            }
            template <class Event,class Fsm>
            void on_exit(Event const&, Fsm&) const {
                std::cout << "State2::on_exit()\r\n" << std::endl;
            }
			template <class StateMachine, class Event>
	        void no_transition(const Event& event, StateMachine& stateMachine, int state)
	        {
	            std::cout << "State2 no_transition\r\n" << std::endl;
	        }
        };
 
        typedef msm::back::state_machine<State1_> State1;
 
        // Set initial state
        typedef State1 initial_state;
        // Transition table
        struct transition_table:mpl::vector<
            //          Start   Event   Next    Action      Guard
            msmf::Row < State1, Event1, State2, msmf::none, msmf::none >
        > {};
		/*
        template <class StateMachine, class Event>
	void no_transition(const Event& event, StateMachine& stateMachine, int state)
	{
	    std::cout << "State no_transition\r\n" << std::endl;
	} */
    };

    // Pick a back-end
    typedef msm::back::state_machine<OuterSm_> Osm;
 
    void test()
    {        
        Osm osm;
        osm.start(); 
 
        std::cout << "> process_event Event2()\r\n" << std::endl;
        osm.process_event(Event2());
        std::cout << "> process_event Event3()\r\n" << std::endl;
        osm.process_event(Event3());
        std::cout << "> process_event Event1()\r\n" << std::endl;
        osm.process_event(Event1());
    }
}
 
int main()
{
    test();
    return 0;
}

