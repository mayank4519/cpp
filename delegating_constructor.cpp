/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Ball{
  string m_colour="red"; // non-static member intialisation
  double m_radius = 10;
 
  public:
  Ball(string colour="red", double radius=10.0) : 
  m_colour(colour), m_radius(radius)
  {}
  
  Ball(string &colour) : Ball(colour,10) // using delegating construtor
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
    
    Ball ball3("orange");
    ball3.print();
    
    return 0;
}
