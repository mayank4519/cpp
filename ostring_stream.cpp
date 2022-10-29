#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
inline std::string ToString(T x)
{
    std::ostringstream ostream;
    ostream << x;
    return ostream.str();
}
int main()
{
    string src(ToString(4));
    cout << src;
    return 0;
}
