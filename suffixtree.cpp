#include <cstdio>
#include <iostream>
#include <cstring>
#define ALPHABET_SIZE 26
#define MAX_LENGTH 10000
using namespace std;
struct trie_node
{
    int value;
    struct trie_node* children[ALPHABET_SIZE];
};
typedef struct trie_node Node;
struct trie
{
    int count;
    Node* root;
};
typedef struct trie Trie;
int getIndex(char s)
{
    return s - 'a';
}
Node* createNode()
{
    Node *temp = new Node();
    temp->value = 0;
    for(int i=0; i<ALPHABET_SIZE; i++)
    {
        temp->children[i]= NULL;
    }
    return temp;
}
void initializeTrie(Trie* &t)
{
    t->count = 0;
    t->root = createNode();
}
void insert(Trie* &t, char s[])
{
    int length = strlen(s);
    Node* current = t->root;
    t->count++;
    int level;
    for(level = 0; level < length; level++)
    {
        int child_index = getIndex(s[level]);
        if(current->children[child_index])
        {
            current = current->children[child_index];
        }
        else
        {
            current->children[child_index] = createNode();
            current = current->children[child_index];
        }
    }
    current->value = t->count;
}
bool search(Trie* &t, char s[])
{
    int length = strlen(s);
    Node* current = t->root;
    int level;
    for(level = 0; level < length; level++)
    {
        int child_index = getIndex(s[level]);
        if(!current->children[child_index])
        {
            return false;
        }
        current = current->children[child_index];
    }
    if(current && current->value)
    {
        return true;
    }
    return false;
}
void buildSuffixTree(Trie* &root, char s[])
{
    int length = strlen(s),i,j;
    char input[length][MAX_LENGTH];
    for(i=0; i<length; i++)
    {
        for(j=0; s[i+j]; j++)
        {
            input[i][j] = s[i+j];
        }
        input[i][j] = '\0';
    }
    for(i=0; i<length-1; i++)
        insert(root, input[i]);
    for(i=0; i<length-1; i++)
        cout<<search(root, input[i])<<endl;
}
int main()
{
    Trie* root;
    initializeTrie(root);
    buildSuffixTree(root,"banana");
    return 0;
}
