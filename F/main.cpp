#include <iostream>
#include <stack>

using namespace std;

void isCorrectBreakets(string str)
{
    stack<char> myStack;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            if (myStack.empty())
            {
                cout << "0";
                return;
            }
            myStack.pop();
        }
        if (str[i] == '(')
        {
            myStack.push('(');
            // continue;
        }
    }
    cout << "1";
}

int main()
{
    string str;
    // cin >> str;
    getline(cin, str);

    string breaketsStr = "";
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            breaketsStr += str[i];
        }
        // cout << i << "-"  << str[i] << endl;
    }
    //  cout << breaketsStr << endl;

    isCorrectBreakets(breaketsStr);
    /*
        stack<char> myStack;
        for (int i = 0; i < str.size(); ++i) {
                if (str[i] == ')') {
                if (myStack.empty()) {
                        cout << "0";
                    return 0;
                }
                myStack.pop();
            }
            if (str[i] == '(') {
                myStack.push('(');
                //continue;
            }

        }
        cout << "1";*/

    return 0;
}
