#include <iostream>
#include <string>
using namespace std;

bool reverse(string &s) {
    if (s.length()  == 0) {
        return true;
    }
    char temp;
    for(uint8_t i=0; i < s.length() / 2; i++) 
    {
        temp = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = temp;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << "input " << s << endl;

    reverse(s);
    cout << s;

}