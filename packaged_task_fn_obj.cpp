#include <iostream>
#include <thread>
#include <future>
#include <string>

class func{
public:
    std::string operator()(std::string s) {
        return "Hi child thread, return " + s;
    }
};


int main() {

    std::packaged_task<std::string (std::string)> task(std::move(func()));

    std::future f = task.get_future();

    std::thread t(std::move(task), "MJ");

    t.join();

    std::cout << f.get();

    return 0;
}