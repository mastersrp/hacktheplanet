#include <chrono>

namespace HTP {
	namespace util {
		class Timer 
		{
			private:
				std::chrono::time_point<std::chrono::system_clock> timer_start;
				std::chrono::system_clock::time_point timer_paused;
				std::chrono::duration<float> timer_pausedTicks;
				bool paused,started,stopped;
			public:
				Timer();

				void start();
				void pause();
				void unpause();
				std::chrono::duration<float> get_duration();
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
	timer_start = std::chrono::system_clock::now();

}

void HTP::util::Timer::pause()
{
	if ( started == true && paused == false )
	{
		paused = true;
		timer_paused = std::chrono::system_clock::now();
	}
}

void HTP::util::Timer::unpause()
{
	if( started == true && paused == true )
	{
		paused = false;
		timer_pausedTicks = std::chrono::system_clock::now() - timer_paused;
	}
}

std::chrono::duration<float> HTP::util::Timer::get_duration()
{
	return std::chrono::system_clock::now() - timer_start;
}
