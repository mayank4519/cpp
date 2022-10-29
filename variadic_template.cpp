#include <iostream>

void log() {

}

template <class T, class ... Args>
void log(T first, Args ... args) {
    std::cout << first <<std::endl;
    log(args ...);
}

int main() {
    log(0);
    log("fdd");
    return 0;
}