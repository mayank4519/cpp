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
  const int xx[5];
 
  public:
  Ball(string colour="black", double radius=10.0) : 
  m_colour(colour), m_radius(radius), xx{1,2,3,4,5}
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
    
    Ball ball3("orange",30);
    ball3.print();
    
    return 0;
}
