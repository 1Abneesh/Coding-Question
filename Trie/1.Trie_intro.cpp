#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    
    void insert(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
    bool search(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                return false;
            }
            node = node->get(s[i]);
        }
        return node->isEnd();
    }
    bool startswith(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                return false;
            }
            node = node->get(s[i]);
        }
        return true;
    }
};

int main()
{
    cout<<"Hello\n";
    vector<string> dp = {"apple", "app", "axe", "box", "boxplot", "bofer"};
    Trie t;
    for (auto it : dp)
    {
        t.insert(it);
    }
    cout<<"Successfully inserted all the words\n";
    if (t.startswith("app"))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "NO\n";
    }
    if (t.search("ax"))
    {
        cout << "The word is present\n";
    }
    else
    {
        cout << "The word is NOt present";
    }

    return 0;
}