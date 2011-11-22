#ifndef HTP_UTIL_TIMER_HPP
#define HTP_UTIL_TIMER_HPP

#include <config.hpp>
#ifdef USE_BOOST
#include <boost/chrono.hpp>
#else
#include <chrono>
#endif

namespace HTP {
	namespace util {
		class Timer 
		{
			private:
				#ifdef USE_BOOST
				boost::chrono::system_clock::time_point timer_start;
				boost::chrono::system_clock::time_point timer_paused;
				boost::chrono::duration<float> timer_pausedTicks;
				#else
				std::chrono::high_resolution_clock::time_point timer_start;
				std::chrono::high_resolution_clock::time_point timer_paused;
				std::chrono::high_resolution_clock::duration<float> timer_pausedTicks;
				#endif
				bool paused,started,stopped;
			public:
				Timer();

				void start();
				void pause();
				void unpause();
				#ifdef USE_BOOST
				boost::chrono::duration<float> get_duration();
				#else
				std::chrono::milliseconds get_duration();
				#endif
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
	#ifdef USE_BOOST
	timer_start = boost::chrono::system_clock::now();
	#else
	timer_start = std::chrono::high_resolution_clock::now();
	#endif

}

void HTP::util::Timer::pause()
{
	if ( started == true && paused == false )
	{
		paused = true;
		#ifdef USE_BOOST
		timer_paused = boost::chrono::system_clock::now();
		#else
		timer_paused = std::chrono::high_resolution_clock::now();
		#endif
	}
}

void HTP::util::Timer::unpause()
{
	if( started == true && paused == true )
	{
		paused = false;
		#ifdef USE_BOOST
		timer_pausedTicks = boost::chrono::system_clock::now() - timer_paused;
		#else
		timer_pausedTicks = std::chrono::high_resolution_clock::now() - timer_paused;
		#endif
	}
}
#ifdef USE_BOOST
boost::chrono::duration<float> HTP::util::Timer::get_duration()
{
	return boost::chrono::high_resolution_clock::now() - timer_start;
}
#else
std::chrono::milliseconds HTP::util::Timer::get_duration()
{
	return std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::high_resolution_clock::now() - timer_start).count();
}
#endif

#endif /* HTP_UTIL_TIMER_HPP */
