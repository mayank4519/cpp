#include <iostream>
#include<map>

using namespace std;

int main()
{
    using m1 = std::map<int,string>;
    m1 m1_1;
    std::map<int,m1> m2;
    
    m2.insert(make_pair(1,m1()));
    m2.insert(make_pair(2,m1()));
    
    m2[1].insert(make_pair(17,"eif1"));
    m2[1].insert(make_pair(18,"eif2"));
    m2[1].insert(make_pair(19,"eif3"));
    
    m2[2].insert(make_pair(1,"eif4"));
    m2[2].insert(make_pair(16,"eif5"));
    m2[2].insert(make_pair(17,"eif6"));

    for(const auto &it : m2)
    {
        cout << it.first << " ";
        for(const auto &it1 : it.second)
        {
            cout << it1.first << " " << it1.second;
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}