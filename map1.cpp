#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    m.insert(make_pair("mayank1",10));
    m.insert(make_pair("mayank2",20));
    m.insert(make_pair("mayank3",30));
    m.insert(make_pair("mayank4",40));
    map<string,int>::iterator it1;
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        cout << it->first << ": " << it->second;
    }
    it1 = m.erase(m.find("mayank1"));
    cout << endl;
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        cout << it->first << ": " << it->second;
    }
}
