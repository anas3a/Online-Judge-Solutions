#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        set <int> s;
        for (int i = 0; i < n + m; i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        cout << n + m - s.size() << endl;
    }
}
