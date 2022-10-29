/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstring>

class mystring{
private:
    char *m_arr;
    int m_len;
public:
    mystring(const char *src="")
    {
        int m_len = std::strlen(src) + 1;
        m_arr  = new char[m_len];
        for(int i=0 ; i<m_len ; i++)
        {
            m_arr[i] = src[i];
        }
        m_arr[m_len] = '\0';
    }
    
    mystring(mystring &mystr) :
    m_arr(mystr.m_arr) , m_len(mystr.m_len) // shallow copy of mystr to m_arr
    {}
    
    ~mystring()
    {
        delete[] m_arr;
    }
    
    char* getstring(){ return m_arr;}
    int getlength(){ return m_len;}
    
};


int main()
{
    mystring str{"hello,world"};
    //{
        mystring copy = str; // copy constructor is called
    //}
    //copy will go out of scope
    std::cout << str.getstring();
    return 0;
}
