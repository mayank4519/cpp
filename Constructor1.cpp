/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Ball{
  string m_colour;
  double m_radius = 10;
  const int xx;
  
  public:
  Ball(string colour="black", double radius=10.0) : 
  m_colour(colour), m_radius(radius), xx(67)
  {}
  
  Ball(double radius):    m_radius(radius),m_colour("black"), xx(67) // using member initialisation list
  {}
  
  void print()
  {
      cout << m_colour << m_radius << endl;
  }
    
};

int main()
{
    Ball ball;
    ball.print();
    
    Ball ball1("blue");
    ball1.print();
    
    Ball ball2(20);
    ball2.print();
    
    Ball ball3("orange",30);
    ball3.print();
    
    return 0;
}
