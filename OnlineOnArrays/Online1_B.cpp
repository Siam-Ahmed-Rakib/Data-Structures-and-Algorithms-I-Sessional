#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int c[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        c[s[i] - 'a']++;
    }
    string ans = "";
    bool f = true;
    for (int i = 0; i < 26; i++)
    {
        if (c[i] % 2)
        {
            f = false;
            break;
        }
        if (c[i] > 0)
        {
            char ch = i + 'a';

            ans += ch;
        }
    }
    if (f)
    {
        string temp = "";
        for (int i = ans.length() - 1; i >= 0; i--)
        {
            temp += ans[i];
        }
        cout << "YES" << endl;
        cout << ans << " "<<temp << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}