#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    using namespace std;
 
    vector<int> vect;
    for (int nCount=6; nCount > 0; nCount--)
        vect.push_back(nCount);
 
    vector<int>::const_iterator it; // declare a read-only iterator
    sort(vect.begin(),vect.end());
        it = vect.begin(); // assign it to the start of the vector
    while (it != vect.end()) // while it hasn't reach the end
        {
        cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
        }
    std::cout << std::endl;
    reverse(vect.begin(),vect.end());
          it = vect.begin(); // assign it to the start of the vector
    while (it != vect.end()) // while it hasn't reach the end
        {
        cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
        }
            std::cout << std::endl;

    it = find(vect.begin(), vect.end(), 3);
    vect.insert(it,10);
           it = vect.begin(); // assign it to the start of the vector
    while (it != vect.end()) // while it hasn't reach the end
        {
        cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
        }
    cout << endl;
    
    it = min_element(vect.begin(), vect.end());
    std::cout << *it << " ";
    it = max_element(vect.begin(), vect.end());
    std::cout << *it;
}