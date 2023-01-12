#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll n = 3;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    while (next_permutation(v.begin(), v.end()))
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}