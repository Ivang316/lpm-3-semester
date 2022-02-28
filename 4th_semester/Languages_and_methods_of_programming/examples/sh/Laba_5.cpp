#include <iostream>
using namespace std;

int countWord = 0;
//char mass[] = { 'a', 'b', 'c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r', 's','t','u','v','w','x','y','z' };

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool is_end;
};

TrieNode* getNode()
{
    TrieNode* p = new TrieNode;
    p->is_end = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        p->children[i] = NULL;
    return p;
 }

void add_Word(string key, TrieNode * root)
{
    TrieNode* p = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!p->children[index])
            p->children[index] = getNode();
        p = p->children[index];
    }
    p->is_end = true;
}

void interval(TrieNode* root)
{
    TrieNode* p = root;
    if (p->is_end)
    {
        countWord++;
    }
    for (int i = 0; i < ALPHABET_SIZE && p != NULL; i++)
    {
        if (p->children[i])
        {

            /*cout << "--------------------------------";
            cout << mass[i] << endl;*/
            interval(p->children[i]);
        }
    }
}

void substring(string key, TrieNode* root, int j)
{
    TrieNode* p = root;
    int index = key[j] - 'a';
    if (p != NULL)
    {
        for (int i = 0; i < ALPHABET_SIZE && j!=key.length(); i++)
        {
            if (i == index && p->children[index])
            {
                /*cout << mass[i] << endl;*/
                substring(key, p->children[i], j+1);
            }
            else if (p->children[i])
            {
                /*cout << mass[i] << endl;*/
                substring(key, p->children[i], 0);
            }
        }
        if (j == key.length())
            {
            j = 0;
            interval(p);
            }

    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    TrieNode* root = getNode();
    string word = { 0 };
    string sub = { 0 };
    cout << "Введите количество слов -> ";
    int N;
    cin >> N;
    cout << "Введите слова -> \n";
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        add_Word(word, root);
    }
    cout << "Введите подстроку -> ";
    cin >> sub;
    substring(sub, root, 0);
    cout << "Количество слов с заданной подстрокой: " << countWord<<endl;
    return 0;
}
 /*
  10
  align
  aligns
  alignin
  anon
  cloud
  folt
  fogn
  fogns
  fognp
  fognt
  */
