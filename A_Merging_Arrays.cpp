#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vi a(n), b(m), c(n + m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);
    int i = 0, j = 0, k = 0;
    while (i < n || j < m)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    for (auto &i : c)
        cout << i << " ";
    cout << endl;
    return 0;
}
