#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, sum = 0, a1 = 0, a2;
        cin >> n >> x;
        vector <int> v(n);
        for (auto &i : v)
        {
            cin >> i;
            sum += i;
            a1 += (i + (x - 1)) / x;
        }
        a2 = (sum + (x - 1)) / x;
        if (a1 > a2)
        swap(a1, a2);
        cout << a1 << " " << a2 << endl;
    }

}
