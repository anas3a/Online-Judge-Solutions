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
        vector<int> v(101, 0);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v[a]++;
        }
        int x = 101;
        while (x--)
        {
            for (int i = 0; i <= 100; i++)
            {
                if (v[i])
                {
                    cout << i << " ";
                    v[i]--;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
