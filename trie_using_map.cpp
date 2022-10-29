
#include <iostream>
#include<map>
using namespace std;

#define MAX_ALPHABETS 26

struct trieNode{
   
   map<char,trieNode*> mp;
   bool isendOfWord; 
};

trieNode* getNode()
{
    trieNode *node;
    if(!(node = new trieNode))
    {
        cout << "Error: Out of memory\n" << endl;//if there is not enough memory to allocate, then return NULL;
        return NULL;
    }
    node->isendOfWord  = false;
    return node;
}

void insert(struct trieNode *&root, string str)
{
    if(root == nullptr)
        root = getNode();
    char ch;
    trieNode *temp;
    temp = root;
    for(int i=0; i<str.length(); i++)
    {
        ch = str.at(i);
        if(temp->mp.find(ch) == temp->mp.end())
            temp->mp[ch] = getNode();
        
        temp = temp->mp[ch];
    }
    temp->isendOfWord = true;
}

bool search(struct trieNode *root, string str)
{
    if(root == nullptr)
        return false;
    trieNode *temp = root;
    for(int i=0;i<str.length();i++)
    {
       //temp = temp->mp[str[i]];
       if(temp == nullptr)
          return false;
        temp = temp->mp[str[i]];
    }
    return temp->isendOfWord;
}

int main()
{
    trieNode *root = nullptr;
    insert(root,"ab");
    if(root == nullptr)
        cout << "root is null";
    insert(root,"abcd");
    insert(root,"abcdef");
    insert(root,"lmn");
    insert(root,"lmnop");
    cout << search(root,"abc");
    return 0;
}
