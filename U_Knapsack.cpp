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

int n, w;
vpi v;
ll f(int i, int w)
{
    if (i == n)
    return 0;
    ll a = 0, b = 0;
    if (w >= v[i].first)
    a = v[i].second + f(i + 1, w - v[i].first);
    b = f(i + 1, w);
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    v.resize(n);
    for (auto &i : v)
    cin >> i.first >> i.second;
    cout << f(0, w);
    return 0;
}
