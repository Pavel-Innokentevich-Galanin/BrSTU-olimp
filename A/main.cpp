#include <iostream>

using namespace std;

int main()
{
    int w, h, p;
    cin >> w >> h >> p;
    if (p % 2 == 1)
    {
        cout << "NO";
        return 0;
    }
    p /= 2;
    p -= w + h;
    int buf = p - h;
    for (int i = w - 1; i > 0; i--)
    {
        if (buf == i)
        {
            cout << "YES";
            return 0;
        }
    }
    buf = p - w;
    for (int i = h - 1; i > 0; i--)
    {
        if (buf == i)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
