#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int rim_to_arab(string n)
{
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    m['i'] = 1;
    m['v'] = 5;
    m['x'] = 10;
    m['l'] = 50;
    m['c'] = 100;
    m['d'] = 500;
    m['m'] = 1000;

    int tmp = 0;
    int res = 0;
    for (int i = 0; i < n.size(); ++i)
    {
        char c = n[i];
        int n = m[c];
        if (n < tmp)
        {
            res += tmp;
            tmp = n;
        }
        else if (n > tmp)
        {
            if (tmp == 0)
            {
                tmp = n;
            }
            else
            {
                res += n - tmp;
                tmp = 0;
            }
        }
        else if (n == tmp)
        {
            res += tmp + n;
            tmp = 0;
        }
    }
    return res + tmp;
}

string arab_to_rim(int arab_number)
{
    char One[4] = {'I', 'X', 'C', 'M'};
    char Five[3] = {'V', 'L', 'D'};
    string ret;
    int buf, m = 4;
    for (int i = 0; i < m; i++)
    {
        buf = (int)(arab_number / pow(10, m - i - 1)) % 10;
        if (buf == 0)
            continue;
        else if (buf < 4)
        {
            for (int j = 0; j < buf; j++)
                ret += One[m - 1 - i];
        }
        else if (buf == 4)
        {
            ret += One[m - 1 - i];
            ret += Five[m - 1 - i];
        }
        else if (buf == 5)
            ret += Five[m - 1 - i];
        else if (buf < 9)
        {
            ret += Five[m - 1 - i];
            for (int j = 0; j < buf - 5; j++)
                ret += One[m - 1 - i];
        }
        else
        {
            ret += One[m - 1 - i];
            ret += One[m - i];
        }
    }
    return ret;
}

int main()
{
    string in;

    string number_1 = "";
    int enum_type = 0;
    string number_2 = "";

    cin >> in;

    int i = 0;
    for (; i < in.size(); ++i)
    {
        if (in[i] == '+')
        {
            enum_type = 1;
            break;
        }
        if (in[i] == '-')
        {
            enum_type = 2;
            break;
        }
        if (in[i] == '*')
        {
            enum_type = 3;
            break;
        }
        if (in[i] == '/')
        {
            enum_type = 4;
            break;
        }
        number_1 += in[i];
    }

    i += 1;

    for (; i < in.size(); ++i)
    {
        number_2 += in[i];
    }

    // cout << number_1 << endl;
    // cout << enum_type << endl;
    // cout << number_2 << endl;

    if (enum_type == 1)
    {

        int arab_result = rim_to_arab(number_1) + rim_to_arab(number_2);
        cout << arab_to_rim(arab_result);
        return 0;
    }

    if (enum_type == 2)
    {
        int arab_result = rim_to_arab(number_1) - rim_to_arab(number_2);
        cout << arab_to_rim(arab_result);
        return 0;
    }

    if (enum_type == 3)
    {
        int arab_result = rim_to_arab(number_1) * rim_to_arab(number_2);
        cout << arab_to_rim(arab_result);
        return 0;
    }

    if (enum_type == 4)
    {
        int arab_result = rim_to_arab(number_1) / rim_to_arab(number_2);
        cout << arab_to_rim(arab_result);
        return 0;
    }

    return 0;
}
