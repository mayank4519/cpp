#include <iostream>

template <typename T>
class vector{
private:
    T *array;
    T size;
    T capacity;
    
public:
    //construtor
    vector() :
    array(new T array[1]) , size(0) , capacity(1);
    {}
    
    void push_back(T &t)
    {
        if(size == capacity)
            resize(capacity*2);
        array[size] = t;
        size++;
    }
    
    void resize(T &t)
    {
        capacity = t;
        T new_array = new T new_array[t]; // create a new array
        for(int i=0; i < size ; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        
        //to do
    }
    
    T* begin()
    {
        return array;
    }
    T* end()
    {
        return array + size;
    }
    
    //destructor
    ~vector()
    {
        delete[] array;
    }
    
};

int main()
{
    vector<int> v;
    v.push_back(1);
    vector<int>::iterator it;
    std::cout << it.begin();
    return 0;
}
