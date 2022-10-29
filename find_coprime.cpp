#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a , int b)
{
    if(b == 0)
        return a;
    else
        gcd(b,a%b);
}

void findcoPrime(int a , int b)
{
    vector<int> v;
    int sum,k,i;
    for(i=a; i<=b; i++)
    {
        sum=0;
        k = i;
        while(k>0)
        {
           sum +=  k%10;
            k =k/10;
        }
        v.push_back(sum);
    }
    
    for(auto it = v.begin(); it != v.end(); it++)
    {
        for(auto it1 = it+1; it1 != v.end(); it1++)
        {
            if(gcd(*it, *it1) == 1) 
            {
                cout<< *it << *it1;
            }
            cout << " ";
        }
    }
}

int main()
{
    using namespace std;
    int a =11;
    int b = 15;
    findcoPrime(a,b);
}