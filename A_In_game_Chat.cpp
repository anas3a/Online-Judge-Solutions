#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                cnt++;
            else
                break;
        }
        ll x = s.size() - cnt;
        if (cnt > x)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
