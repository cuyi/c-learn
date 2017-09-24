#include <iostream>
#include <cstdint>
#include "utils.hpp"

enum class State: uint8_t
{
	Unused = 0,
	Normal = 1,
	SuspendedBeamChange = 2,
	SuspendedReestablish = 3,
	Reestablished = 4
};

inline const char* toString(const State& state)
{
	switch(state)
	{
		case State::Unused: return "Unused";
		case State::Normal: return "Normal";
		case State::SuspendedReestablish: return "SuspendedReestablish";
		case State::Reestablished:		  return "Reestablished";
		default: break;
	}
    
	return ::utils::printRawUnknowValue((int)state);  
}

inline ::std::ostream& operator<<( ::std::ostream& o, const State& state)
{
    o << toString(state);
	return o;
}

int main(void)
{
	State s_test = State::Reestablished;
    std::cout << s_test << std::endl;
    State s = static_cast<State>(5);
	std::cout << s << std::endl;
}

