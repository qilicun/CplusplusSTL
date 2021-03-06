#include <boost/date_time/posix_time/posix_time.hpp>
#include <opm/lattice/utility/StopWatch.hpp>
#include <iostream>
#include <cassert>

StopWatch::StopWatch()
    : state_(UnStarted)
{
}


void StopWatch::start()
{
    start_time_ = boost::posix_time::microsec_clock::local_time();
    last_time_ = start_time_;
    state_ = Running;
}

void StopWatch::stop()
{
    if (state_ != Running) {
        std::cout << "Called stop() on a StopWatch that was not running." << std::endl;
        exit(1);
    }
    stop_time_ = boost::posix_time::microsec_clock::local_time();
    state_ = Stopped;
}

double StopWatch::secsSinceLast()
{
    boost::posix_time::ptime run_time;
    if (state_ == Running) {
    	run_time = boost::posix_time::microsec_clock::local_time();
    } else if (state_ == Stopped) {
	    run_time = stop_time_;
    } else {
	    assert(state_ == UnStarted);
	    std::cout << "Called secsSinceLast() on a StopWatch that had not been started.\n";
        exit(1);
    }

    boost::posix_time::time_duration dur = run_time - last_time_;
    last_time_ = run_time;

    return double(dur.total_microseconds())/1000000.0;
}

double StopWatch::secsSinceStart()
{
    boost::posix_time::ptime run_time;
    if (state_ == Running) {
    	run_time = boost::posix_time::microsec_clock::local_time();
    } else if (state_ == Stopped) {
    	run_time = stop_time_;
    } else {
	    assert(state_ == UnStarted);
	    std::cout <<"Called secsSinceStart() on a StopWatch that had not been started.\n";
        exit(1);
    }

    boost::posix_time::time_duration dur = run_time - start_time_;

    return double(dur.total_microseconds())/1000000.0;
}
