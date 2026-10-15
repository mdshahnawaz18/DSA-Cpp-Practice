

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        return insertUtil(child, word.substr(1));
    }

    void insertWord(string arr)
    {
        return insertUtil(root, arr);
    }

    void lcp(string str, string &ans)
    {
        TrieNode *curr = root;

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (curr->childCount == 1 && !curr->isTerminal)
            {
                ans.push_back(str[i]);
                int index = ch - 'a';
                curr = curr->children[index];
            }
            else
            {
                break;
            }
            if (curr->isTerminal)
            {
                break;
            }
        }
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        // your code here
        int n = arr.size();
        if (n == 0)
        {
            return "";
        }

        Trie *t = new Trie('\0');

        for (int i = 0; i < n; i++)
        {
            t->insertWord(arr[i]);
        }

        string str = arr[0];
        string ans = "";

        t->lcp(str, ans);
        return ans;
    }
};