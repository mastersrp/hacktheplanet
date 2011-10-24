#include <boost/chrono.hpp>

namespace HTP {
	namespace util {
		class Timer 
		{
			private:
				boost::chrono::system_clock::time_point timer_start;
				boost::chrono::system_clock::time_point timer_paused;
				boost::chrono::duration<float> timer_pausedTicks;
				bool paused,started,stopped;
			public:
				Timer();

				void start();
				void pause();
				void unpause();
				boost::chrono::duration<float> get_duration();
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
	timer_start = boost::chrono::system_clock::now();

}

void HTP::util::Timer::pause()
{
	if ( started == true && paused == false )
	{
		paused = true;
		timer_paused = boost::chrono::system_clock::now();
	}
}

void HTP::util::Timer::unpause()
{
	if( started == true && paused == true )
	{
		paused = false;
		timer_pausedTicks = boost::chrono::system_clock::now() - timer_paused;
	}
}

boost::chrono::duration<float> HTP::util::Timer::get_duration()
{
	return boost::chrono::system_clock::now() - timer_start;
}
