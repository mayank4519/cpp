#include <iostream>
#include <thread>
#include <future>

void set_promise_obj(std::promise<int> *obj) {
    std::cout << "inside child thread\n";
    obj->set_value(100);
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread th(set_promise_obj, &p);

    //po some operations in main thread

    std::cout << f.get();

    th.join();

    return 0;
}