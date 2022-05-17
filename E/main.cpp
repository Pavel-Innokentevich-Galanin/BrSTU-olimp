#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isIzogram(string str)
{
    vector<char> symbol_map;        // вектор символов
    vector<int> symbol_map_counter; // вектор количества символов

    symbol_map.push_back(str[0]);    // добавляю первый символ
    symbol_map_counter.push_back(1); // первый символ в количестве один

    for (int i = 1; i < str.size(); ++i) // прохожусь по даннной мне строке
    {
        bool isChanged = false;
        for (int j = 0; j < symbol_map.size(); j++) // прохожусь по вектору символов
        {
            if (symbol_map[j] == str[i]) // если символ в строке равен символу в векторе
            {
                symbol_map_counter[j] += 1; // увеличиваю счётчик
                isChanged = true;           // ставлю флаг, что изменил
                break;
            }
        }
        if (isChanged == false) // если не увеличивали счётчик
        {
            symbol_map.push_back(str[i]);    // добавляем символ в вектор
            symbol_map_counter.push_back(1); // символ в количестве один
        }
    }

    for (int i = 0; i < symbol_map.size(); ++i)
    {
        // cout << symbol_map[i] << " = " << symbol_map_counter[i] << endl;
        if (symbol_map_counter[i] > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cin >> str;

    // Уменьшаем каждую букву
    for (int i = 0; i < str.size(); ++i)
    {
        str[i] = (char)tolower(str[i]);
    }

    vector<char> symbols; // символ
    vector<int> numbers;  // количество символов

    symbols.push_back(str[0]); // добавляем первый символ в вектор
    numbers.push_back(1);      // первый символ в количестве один
    for (int i = 1; i < str.size(); ++i)
    {
        if (symbols.back() == str[i]) // если это тот же символ
        {
            numbers[numbers.size() - 1] += 1; // то увеличиваем счётчик
        }
        else // иначе
        {
            symbols.push_back(str[i]); // добавляем новый символ в вектор
            numbers.push_back(1);      // новый символ в количестве 1
        }
    }

    string ret = "";                         // возвращаемая строка
    for (int i = 0; i < symbols.size(); ++i) // проходимся по вектору символов (и вектору счётчика)
    {
        if (numbers[i] == 1) // если количество символов один
        {
            // cout << symbols[i];
            ret += symbols[i]; // то выводим только букву
        }
        else // иначе количество символов больше один
        {
            // cout << symbols[i] << numbers[i];
            ret += symbols[i]; // выводим символ
            stringstream ss;   // ! делаю через поток, т.к. выведится кракозябра, если строка плюс число [str += int]
            ss << numbers[i];  // ! добавляю число в поток
            ret += ss.str();   // выводим число ! взял число из потока
        }
    }

    if (isIzogram(ret) == true) // если это изограм
    {
        cout << ret; // вывожу строку a2b4cfg2
    }
    else // иначе вывожу перевернутую строку
    {
        for (int i = str.size() - 1; i >= 0; --i)
        {
            cout << str[i];
        }
    }

    return 0;
}
