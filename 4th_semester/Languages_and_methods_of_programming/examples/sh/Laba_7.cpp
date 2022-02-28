#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
 
const int MAXLENGTH = 1000; // максимальное количество имён и размерность
vector<pair<string, int>> forCout; // запись имени и количества раз
int countOfName = 0;
 
class Name
{
private:
    int countInText; // подсчёт количества слов в тексте
    string name; // само слово
    
public:
    Name() // конструктор
    {
        countInText = 0;
        name = {0};
    }
    
    void choose_the_name(const string NAME) // назначение имени
    {
        if (NAME != "")
        {
            name = NAME;
        }
    }
    
    string get_name() // получение данного имени
    {
        return name;
    }
    
    void incremention_count() // функция инкременции
    {
        countInText++;
    }
    
    int get_count() // получение количества данного имени
    {
        return countInText;
    }
};
 
class HashTable
{
private:
    vector<vector<Name>> names; // хранение данных
    int hash_func(string word) // хеш-функция
    {
        int number = 26;
        __uint64_t hashnum = 0;
        int mult = 1;
        for (int i = 0; i < word.length(); i++)
        {
            hashnum += (word[i] - 'A' + 1) * mult;
            mult *= number;
        }
        return (hashnum % MAXLENGTH);
    }
public:
    HashTable() // конструктор
    {
        names.clear();
        names.resize(MAXLENGTH);
    }
     
    ~HashTable()
    {
        names.clear();
    }
    
    void push_name(Name& name)
    {
        __uint64_t h = hash_func(name.get_name());
        for (__uint64_t i = 0; i < names[h].size(); i++)
        {
            if (names[h][i].get_name() == name.get_name())
                return;
        }
        names[h].push_back(name);
    }
    
    void find_name(string word)
    {
        if (word[word.length()-1] == '.' || word[word.length()-1] == ',' || word[word.length()-1] == ';' || word[word.length()-1] == ':')
        {
            word.erase(word.length()-1);
        }
        __uint64_t id = hash_func(word);
        for (unsigned long i = 0; i < names[id].size(); i++)
        {
            if (names[id][i].get_name() == word)
            {
                names[id][i].incremention_count();
            }
        }
    }
    
    void find_count_of_name(string name)
    {
        ifstream file(name);
        string sameName;
        int j = 0;
        if (file.is_open())
        {
            while (!file.eof())
            {
                file >> sameName;
                __uint64_t id = hash_func(sameName);
                for (__uint64_t i = 0; i < names[id].size(); i++)
                {
                    if (names[id][i].get_name() == sameName)
                    {
                        countOfName++;
                        forCout[j].first = names[id][i].get_name();
                        forCout[j++].second = names[id][i].get_count();
                    }
                }
            }
        }
        else
        {
            cout << "File with names not found! Please check the directory.\n";
        }
    }
};

bool add_name(HashTable* hash, string fileWithNames)
{
    ifstream file(fileWithNames);
    if (file.is_open())
    {
        while (!file.eof())
        {
            string name;
            file >> name;
            Name sameName;
            sameName.choose_the_name(name);
            hash->push_name(sameName);
        }
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}
 
void find_name(HashTable* hash)
{
    ifstream text("/Users/dosherak/Documents/Учеба/ЯМП/Лаба 7/text.txt");
    if (text.is_open())
    {
        while (!text.eof())
        {
            string word;
            text >> word;
            hash->find_name(word);
        }
    }
    else
    {
        cout << "The text file was not found in this directory! Check it out.\n";
    }
    text.close();
}

void printOnScreen()
{
    for (int i = 0; i < countOfName; i++)
    {
        cout<< "Name: "<< forCout[i].first << ", count: "<< forCout[i].second <<endl;
    }
}
 
int main()
{
    forCout.clear();
    forCout.resize(MAXLENGTH);
    HashTable tableOfNames;
    HashTable* pointer = &tableOfNames;
    if (add_name(pointer, "/Users/dosherak/Documents/Учеба/ЯМП/Лаба 7/names.txt"))
    {
        find_name(pointer);
        pointer->find_count_of_name("/Users/dosherak/Documents/Учеба/ЯМП/Лаба 7/names.txt");
        printOnScreen();
    }
    else
    {
        cout << "File with names not found! Please check the directory.\n";
    }
//    delete[]pointer;
    return 0;
}

