#include <iostream>
using namespace std;

template <class T> class vector{
public:
    vector()
    {
        m_vec = new T[1];
        current = 0;
        capacity = 1;
    }
    
    ~vector()
    {
        delete [] m_vec;
    }

    //COPY ASSIGNMENT
    vector<T>& operator=(vector<T> & vv) 
    {
        m_vec = new T[1];
        capacity = vv.capacity;
        current = vv.current;
        for (int16_t i = 0; i < current; i++) 
        {
            m_vec[i] = vv.m_vec[i];
        }
        return *this;   
    }

    //COPY CONSTRUCTOR
    vector(vector<T> &vv) {
        m_vec = new T[1];
        capacity = vv.capacity;
        current = vv.current;
        for (int16_t i = 0; i < current; i++) 
        {
            m_vec[i] = vv.m_vec[i];
        }
    }

    T* begin()
    {
        return m_vec;    
    }
    T* end()
    {
        return m_vec + current;
    }
    uint16_t size()
    {
        return current;
    }

    void resize(uint16_t const& c)
    {
        T *temp_vec = new T[c];
        for (int16_t i = 0; i < current; i++) 
        {
            temp_vec[i] = m_vec[i];
        }
        delete [] m_vec;
        m_vec = temp_vec;
        capacity = c;
    }

    uint16_t getCapacity() {
        return capacity;
    }

    void push_back(T const& val)
    {
        if (current == capacity) {
            resize(capacity*2);
            m_vec[current] = val;
            current++;
        }
        else {
            m_vec[current] = val;
            current++;
        }
    }
private:
    T *m_vec;
    uint16_t capacity;
    uint16_t current;
};