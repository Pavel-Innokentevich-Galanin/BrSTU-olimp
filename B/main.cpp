#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (vec[j] <= 0)
            {
                count += 1;
            }
            vec[j] -= 1;
        }
        if (count == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << n;

    return 0;
}