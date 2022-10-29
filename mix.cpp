#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

template <class T> class A;
template <class T> ostream& operator<<(ostream &out, A<T>& a);

template <class T>
class base{
T _m;
public:
    base(T x) : _m(x) {}
    virtual T getM() {return _m;}; 
};

template <class T>
class A : public base<T>{
T _m1;
T *ptr = new T;
public:
    A(const T &x) : _m1(x-10) , base<T>(x+10) {}
    void print() {cout << _m1 << " " << *ptr << endl;}
    T operator+(const T &x) {return _m1 + x;}
    friend ostream& operator<< <>(ostream &out, A<T>& a);
    A(const A& a) {
        _m1 = a._m1;
        ptr = new T;
        *ptr = *(a.ptr);
    }
    void operator=(const T& a) {
        _m1 = a._m1;
    }
    void set(T x) {*ptr = x;}
    
    ~A() {delete ptr;}
    
    T operator()(T x) {return x + _m1;} // functors
    
    T getM() override final {cout << "derived\n"; return _m1;}
};

template<class T>
ostream& operator<<(ostream &out, A<T>& a) {
        out << a._m1 << endl;
        return out;
}

class B {
int _m2;
public:
    B(const int &x) : _m2(x) {}
    void print() {cout << _m2 << endl;}
    friend ostream& operator<<(ostream &out, B& b);
};

ostream& operator<<(ostream &out, B& b) {
        out << b._m2 << endl;
        return out;
}

void fun() {
    cout << "hey\n";
}

void fun_caller(void (*fptr)()) {fptr();}

float change(float x) {return x + 100;}

int main()
{
    A<double> a(10.6);
    B b(20);
    a.print();
    b.print();
    
    void(*fptr)() = &fun;
    //fptr();
    fun_caller(fptr);
    
    //functors
    vector<double> v{1,2,3,4,5};
    
    // transform(v.begin(), v.end(), v.begin(), a);
    
    float(*p)(float) = &change;
    transform(v.begin(), v.end(), v.begin(), p);
    
    for_each(v.begin(), v.end(), [](double x){cout << x << " ";});
    cout << "-------\n";
    base<int> *org = new base<int>(100);
    cout << org->getM();
    delete org;
    cout << "----\n";
    unique_ptr<base<int>> uptr = make_unique<A<int>>(20);
    cout << uptr->getM();
    
    shared_ptr<base<int>> sptr = make_shared<A<int>>(20);
    cout << sptr->getM();
    

    return 0;
}