#pragma once
#include <chrono>
#include <functional>
#include <iostream>

template <typename U>
class Timer {
    public:
        Timer(std::string const& name = "Timer"):
            m_name(name),
            m_start_time(std::chrono::high_resolution_clock::now()) {}
        ~Timer() {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<U>(end_time - m_start_time);
            std::cout << m_name << " 用时: " << duration.count() << "\n";
        }
    private:
        std::string m_name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
};


template<typename U, typename T, typename... Args>
void timeit(std::string const& name, std::function<T> f, Args... args) {
    Timer<U> timer(name);
    f(args...);
}
