#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

void
raw_pointers() {
    cout << "\nDealing with raw pointers\n";
    auto v = std::vector<int*>{new int(2), new int(3), new int(5), new int(4)};
    
    //Safe way to delete elements from a a vector of raw pointers is to use stable_partition.
    //This means to put the elements that satisfy the predicate at the beginning, and the elements that don’t satisfy
    //the predicate at the end. 
    auto itr = std::stable_partition(v.begin(), 
                                    v.end(),
                                    [](auto const &ptr){
                                        return *ptr % 2 != 0;
                                    });
                                    
    //Delete the memory of these unused pointers.                                
    for_each(itr, v.end(), [](int *ptr){
        delete ptr;
    });                                
          
    //Now safely erase the pointers from vector.
    v.erase(itr, v.end());
    
    //print the remaining elements
    for_each(v.begin(), v.end(), [](auto const &ptr){cout << *ptr << " ";});
}

int main()
{
    auto v = std::vector<unique_ptr<int>>{};
    v.push_back(std::make_unique<int>(2));
    v.push_back(std::make_unique<int>(3));
    v.push_back(std::make_unique<int>(5));
    v.push_back(std::make_unique<int>(4));

    //Remove pointers from vectors with predicate as not equal to 2!
    v.erase(std::remove_if(v.begin(), v.end(), [](auto const &ptr){return *ptr%2 == 0;}), v.end());
    for_each(v.begin(), v.end(), [](auto const &ptr){cout << *ptr << " ";});
    
    
    raw_pointers();
    return 0;
}
