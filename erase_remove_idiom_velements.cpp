#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void
remove(vector<int> &v, const int &div) {

    v.erase(std::remove_if(v.begin(), v.end(), [div](int i){return i % div == 0;}), v.end());
}

int main()
{
    std::vector<int> v = {1,2,3,4,5};
    std::vector<int> v2 = v;
    std::vector<int>::iterator it = std::remove_if(v.begin(), v.end(), [](int i){return i % 2 == 0;});
    for_each(v.begin(), it, [](int i){cout << i << " ";});
    cout << "size of vector: " << v.size();
    
    cout << "\nElements are actually removed from the original vector\n";
    remove(v2,2);
    for_each(v2.begin(), v2.end(), [](int i){cout << i << " ";});
    cout << "size of vector: " << v2.size();
    return 0;
}
