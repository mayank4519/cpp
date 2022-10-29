#include <iostream>
using namespace std;

#define MAX_ALPHABETS 26

struct trieNode{
   
   struct trieNode *children[MAX_ALPHABETS];
   bool isendOfWord; 
};

struct trieNode* getNode()
{
    struct trieNode *temp = new trieNode;
    temp->isendOfWord = false;
    for(int i=0;i<MAX_ALPHABETS;i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}

void insert(struct trieNode *root, string str)
{
    struct trieNode *node = root;
    for(int i=0; i < str.length(); i++)
    {
        int key = str[i] - 'a';
        if(!node->children[key])
        {
            node->children[key] = getNode();
            node = node->children[key];
        }
    }
    node->isendOfWord = true;
    
}

bool search(struct trieNode *root, string str)
{
    struct trieNode *node = root;
    for(int i=0;i<str.length(); i++)
    {
        int key = str[i] - 'a';
        if(node->children[key] == NULL)
            return false;
        node = node->children[key];
    }
    return (node->isendOfWord == true && node!=NULL);
}

int main()
{
    string str[] = {"ab","abcd","abcdef",
    "lmn","lmnopq","l"
    };
    struct trieNode *root = getNode();
    for(int i=0; i<(sizeof(str)/sizeof(str[0])); i++)
    {
        insert(root, str[i]);
    }
    if(search(root, "ab"))
    {
        cout << "yes,ab is present\n";
    }
    return 0;
}
