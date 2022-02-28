#include <iostream>
#include <string>
#include <fstream>

using namespace std;

unsigned int HASH_SIZE = 100, HASH_MULT = 8;
 
struct Info
{
    string name;
    string number;
    string adress;
    Info* next;
};

void hTabInit(Info** hT)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hT[i] = NULL;
    }
}

int hashs(string s)
{
    int h = 0;
    for (int i = 0; i < s.length(); i++)
    {
        h = h * HASH_MULT + s[i];
    }
    return h % HASH_SIZE;
}

void tab_add(Info** hTab, string name, string number, string adress)
{
    Info* node = new Info;
    int index = hashs(number);
    node->name = name;
    node->number = number;
    node->adress = adress;
    node->next = hTab[index];
    hTab[index] = node;
}

Info* tab_search(Info** hTab, string key)
{
    int index = hashs(key);
    Info* node;
    for (node = hTab[index]; node != NULL; node = node->next)
    {
        if (node->number == key)
            return node;
    }
    return NULL;
}

int main()
{
    Info* hastTab[HASH_SIZE];
    Info* node;
    hTabInit(hastTab);
    ifstream info("/Users/dosherak/Documents/Учеба/ЯМП/Лаба 6/lab6/lab6/information.txt");
    if (info.is_open())
    {
        string number, name, adress;
        cout << " Viewable numbers:\n";
    while (info)
    {
        info >> number >> name >> adress;
        if (info)
        {
        cout << " > " << number << " < " << endl;
        tab_add(hastTab, name, number, adress);
        }
    }
        string key;
        cout << "Enter the phone number from the phone book -> ";
        cin >> key;
        node = tab_search(hastTab, key);
        if (node)
        {
            cout << "Information about the person: \n";
            cout << "The name is " << node->name << ", she(he) lives in " << node->adress << " " << endl;
        }
        else
        {
            cout<<"This number is not find in this list!\n";
        }
    }
    else
    {
        cout<<"FILE IS NOT CREATED!\n";
    }
    info.close();
    return 0;
}
