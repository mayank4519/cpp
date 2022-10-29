#include <iostream>
#include <thread>
#include <future>
#include <string>

std::string func(std::string s) {
    return "Hi child thread, return " + s;
}

int main() {

    std::packaged_task<std::string (std::string)> task(func);

    std::future f = task.get_future();

    std::thread t(std::move(task), "MJ");

    t.join();

    std::cout << f.get();

    return 0;
}