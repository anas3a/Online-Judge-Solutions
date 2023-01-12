#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != 't')
                cout << s[i];
            else
                cnt++;
        }
        for (int i = 0; i < cnt; i++)
            cout << "t";
        cout << endl;
    }
    return 0;
}
