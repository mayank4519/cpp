using namespace std;

class Animal{
  protected:
    string m_name;
    
     Animal(string name) :
        m_name(name)
     {
     }
     public:
     string getName(){return m_name;}
     
     virtual string speak() = 0; // Pure virtual function..making Animal a abstract class which means it cannot be instantiated. 
};

class Cow : public Animal
{
    public:
     Cow(string name) : 
     Animal(name)
     {
     }
     string speak(){return "cow voice";} // If speak is not defined here,Cow will become an abstract class.
};

int main()
{
    Cow cow("cow_cow");
    cout << cow.getName() << endl;;
    cout << cow.speak();
    return 0;
}