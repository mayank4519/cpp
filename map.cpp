#include <iostream>
#include <map>
int main()
{
    using namespace std;
    map<int,string> mymap;
    mymap.insert(make_pair(1,"a"));
    mymap.insert(make_pair(2,"b"));
    mymap.insert(make_pair(3,"c"));
    mymap.insert(make_pair(4,"d"));

    map<int,string>::iterator it;
    it  = mymap.begin();
    while(it != mymap.end())
    {
        cout << *it->first << " " << *it->second;
        it++;
    }
 
    cout << endl;
}