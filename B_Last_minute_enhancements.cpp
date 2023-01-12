#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for (auto &i : v)
        {
            cin >> i;
            s.insert(i);
        }
        int cnt = s.size();
        if (n >= 2)
        {
            if (v[n - 1] == v[n - 2])
                cnt++;
        }
        v[n - 1]++;
        for (int i = n - 1; i >= 1; i--)
        {
            if (v[i] == v[i - 1])
            {
                if (v[i + 1] - v[i] > 1)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
}