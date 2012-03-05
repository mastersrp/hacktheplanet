#ifndef HTP_UTIL_TIMER_HPP
#define HTP_UTIL_TIMER_HPP

#include <htp/config.hpp>
#ifdef HTP_CXX0X
#include <chrono>
#else
#include <ctime>
#endif

namespace HTP {
	namespace util {
		#ifdef HTP_CXX0X
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
				
				virtual void start();
				virtual void pause();
				virtual void unpause();
				virtual TIME get_duration();
		};

		Timer<TIME>::Timer()
		{
			paused = false;
			started = false;
			stopped = false;
		}
		
		void Timer<TIME>::start()
		{
			started = true;
			paused = false;
			stopped = false;
			timer_start = std::chrono::high_resolution_clock::now();
		}

		void Timer<TIME>::pause()
		{
			if ( started == true && paused == false )
			{
				paused = true;
				timer_paused = std::chrono::high_resolution_clock::now();
			}
		}

		void Timer<TIME>::unpause()
		{
			if( started == true && paused == true ) 
			{
				paused = false;
				timer_pausedTicks = std::chrono::high_resolution_clock::now()-timer_paused;
			}
		}

		TIME Timer<TIME>::get_duration()
		{
			return std::chrono::high_resolution_clock::now() - timer_start;
		}
		#else /* We're NOT using the C++0x standard! */
		class Timer
		{
			public:
				Timer();

				virtual void start();
				virtual void pause();
				virtual void unpause();
				virtual double get_duration();
			private:
				time_t timer_start;
				time_t timer_paused;
				double timer_pausedTicks;
				bool started,paused,stopped;
		};
		Timer::Timer()
		{
			started = false;
			paused = false;
			stopped = false;
		}

		void Timer::start()
		{
			started = true;
			paused = false;
			stopped = false;
		}

		void Timer::pause()
		{
			if( started == true && paused == false ) {
				paused = true;
				time( &timer_paused );
			}
		}

		void Timer::unpause()
		{
			if( started == true && paused == false ) {
				paused = false;
				time_t now;
				time( &now );
				timer_pausedTicks += difftime( timer_paused, now );
			}
		}

		double Timer::get_duration()
		{
			time_t now;
			time( &now );
			double diff = difftime( timer_start, now );
			diff = diff - timer_pausedTicks;
			return diff;
		}
		#endif
	}
}

#endif /* HTP_UTIL_TIMER_HPP */
