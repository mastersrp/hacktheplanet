#ifndef HTP_UTIL_TIMER_HPP
#define HTP_UTIL_TIMER_HPP

#include <config.hpp>
#include <chrono>

namespace HTP {
    namespace util {
	class Timer 
        {
	    private:
	        std::chrono::high_resolution_clock::time_point timer_start;
	        std::chrono::high_resolution_clock::time_point timer_paused;
	        std::chrono::nanoseconds timer_pausedTicks;
	        bool paused,started,stopped;
	    public:
	        Timer();
	    
		void start();
		void pause();
		void unpause();
		std::chrono::nanoseconds get_duration();
	};
    }
}

HTP::util::Timer::Timer()
{
    paused = false;
    started = false;
    stopped = false;
}

void HTP::util::Timer::start()
{
    started = true;
    paused = false;
    stopped = false;
    timer_start = std::chrono::high_resolution_clock::now();
}

void HTP::util::Timer::pause()
{
    if ( started == true && paused == false )
    {
    	paused = true;
	timer_paused = std::chrono::high_resolution_clock::now();
    }
}

void HTP::util::Timer::unpause()
{
    if( started == true && paused == true )
    {
	paused = false;
	timer_pausedTicks = std::chrono::high_resolution_clock::now()-timer_paused;
    }
}
std::chrono::nanoseconds HTP::util::Timer::get_duration()
{
    return std::chrono::high_resolution_clock::now()-timer_start;
}

#endif /* HTP_UTIL_TIMER_HPP */
