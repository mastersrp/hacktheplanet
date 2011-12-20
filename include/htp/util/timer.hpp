#ifndef HTP_UTIL_TIMER_HPP
#define HTP_UTIL_TIMER_HPP

#include <config.hpp>
#include <chrono>

namespace HTP {
	namespace util {
		template <class TIME>
		class Timer 
        {
			private:
				std::chrono::high_resolution_clock::time_point timer_start;
				std::chrono::high_resolution_clock::time_point timer_paused;
				TIME timer_pausedTicks;
				bool paused,started,stopped;
			public:
				Timer();
				
				void start();
				void pause();
				void unpause();
				TIME get_duration();
		};
	}
}
template <class TIME>
HTP::util::Timer<TIME>::Timer()
{
	paused = false;
	started = false;
	stopped = false;
}
template <class TIME>
void HTP::util::Timer<TIME>::start()
{
	started = true;
	paused = false;
	stopped = false;
	timer_start = std::chrono::high_resolution_clock::now();
}

template <class TIME>
void HTP::util::Timer<TIME>::pause()
{
	if ( started == true && paused == false )
	{
		paused = true;
		timer_paused = std::chrono::high_resolution_clock::now();
	}
}
template<class TIME>
void HTP::util::Timer<TIME>::unpause()
{
	if( started == true && paused == true ) 
	{
		paused = false;
		timer_pausedTicks = std::chrono::high_resolution_clock::now()-timer_paused;
	}
}
template <class TIME>
TIME HTP::util::Timer<TIME>::get_duration()
{
    return std::chrono::high_resolution_clock::now()-timer_start;
}

#endif /* HTP_UTIL_TIMER_HPP */
