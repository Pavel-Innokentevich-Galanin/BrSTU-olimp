#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void arab_to_rim(int arab_number)
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
    cout << ret;
}

int main()
{
    int arab_number;
    cin >> arab_number;
    arab_to_rim(arab_number);
    return 0;
}
