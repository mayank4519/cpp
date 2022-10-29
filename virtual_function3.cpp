#include<iostream> 
  using namespace std;


class Animal{
public:
    string m_name;
public:
    Animal(string name) :
    m_name(name)
    {}
    string getname()
    {
        return m_name;
    }
    virtual string speak()
    {
        return "??";
    }
    
};

class Cat : public Animal{
public:
    Cat(string name) :
    Animal(name)
    {}
    string speak()
    {
        return "meow";
    }

};

class Dog : public Animal{
public:
    Dog(string name) :
    Animal(name)
    {}
    string speak()
    {
        return "bhaun bhaun"; 
    }
};

void print(Animal &animal)
//if you give the reference then only you can achieve run time polymorphism, else animal object will always call the Animal class functions.
//So point is run time polymorphism is achieved through refrence n pointers.
{
    cout << animal.getname() << " " << animal.speak() << endl;
}

int main () 
{
    Cat cat("fred");
    Dog dog("bomb");
    print(dog);
    print(cat);
  
return 0;
}
