#include <iostream>

class mystr{
private:
    std::string str;
public:
     mystr(int size) // explicit mystr(int size)-->explicit keyword will tell compiler not to do implicit constructor conversion.
    {
        std::cout << "implicit constructor conversion";
        str.resize(size);
    }
    mystr(std::string pstr)
    {
        str = pstr;
    }
    friend std::ostream& operator<<(std::ostream &out , mystr &ms)
    {
        out << ms.str;
        return out;
    }
};


int main()
{
    mystr ms = 'a';//this direct assignment will do the implicit conversion of 'a' to int and call the first constructor.
    std::cout <<  ms << std::endl;
    return 0;
}