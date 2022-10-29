#include <iostream>
#include <string>

using namespace std;

class repeat{
  public:
  void find_non_rep(string str)
  {
      int idx1,idx2;
      idx1=0;
      idx2=0;
      pair<int,int> arr[256];
      for(int i=0;i<str.length();i++)
      {
          (arr[str[i]].first)++;
          arr[str[i]].second = i;
      }
      int start = 10000;
      for(int i=0;i<255;i++)
      {
          if(arr[i].first == 1)
          {
              if(arr[i].second < start)
              {
                  start = arr[i].second;
              }
          }
      }
      cout << str[start];
  }
  
};

int main()
{
    string str = "ddcccckia";
    repeat rep;
    int len = str.length();
    rep.find_non_rep(str);

    return 0;
}
