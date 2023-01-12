#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int l = 0;
    for (int i = 0; i < m; i++)
    {
        while (l < n && a[l] < b[i])
            l++;
        cout << l << " ";
    }
    cout << endl;
    return 0;
}
