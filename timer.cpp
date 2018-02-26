#include "Poco/Timer.h"
#include "Poco/Thread.h"
#include "Poco/Stopwatch.h"
#include <iostream>

class TimerExample {
public:
    TimerExample() { _sw.start(); }

    void onTimer(Poco::Timer&) {
        std::cout << "Callback called after "
            << _sw.elapsed()/1000
            << " ms" << std::endl;
    }

private:
    Poco::Stopwatch _sw;
};

int main(int, char* []) {
    TimerExample example;

    Poco::Timer timer(250, 500);
    timer.start(Poco::TimerCallback<TimerExample>(example, &TimerExample::onTimer));

    Poco::Thread::sleep(5000);
    timer.stop();
    return 0;
}
