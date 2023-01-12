#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using pii = pair <int, int>;
using pll = pair <long, long>;
using vpi = vector <pii >;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

ll n, mx = -1e12;
vll v;
void f(int i)
{
    if (i == n)
    return;
    mx = max(mx, v[i]);
    cout << mx << " ";
    return f(i + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
    cin >> i;
    f(0);
    cout << endl;
    return 0;
}
