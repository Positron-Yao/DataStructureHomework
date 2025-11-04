#pragma once
#include <chrono>
#include <functional>
#include <iostream>

class Timer {
    public:
        Timer(std::string const& name = "Timer"):
            m_name(name),
            m_start_time(std::chrono::high_resolution_clock::now()) {}
        ~Timer() {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - m_start_time);
            std::cout << m_name << " 用时: " << duration.count() << " μs\n";
        }
    private:
        std::string m_name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
};


template<typename T, typename... Args>
void timeit(std::string const& name, std::function<T> f, Args... args) {
    Timer timer(name);
    f(args...);
}
