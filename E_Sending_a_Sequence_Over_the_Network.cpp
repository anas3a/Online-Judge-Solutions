#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int n;
vll v;
map<pii, int> m;
bool f(int i, int cnt)
{
    if (i == n)
    {
        if (cnt == 0)
            return true;
        return false;
    }
    if (m[{i, cnt}])
    {
        ll ans = m[{i, cnt}];
        if (ans == 1)
            return true;
        return false;
    }
    bool a = f(i + 1, cnt + 1), b = false, c = false;
    if (!cnt && v[i] + i + 1 <= n)
        b = f(i + 1 + v[i], 0);
    if (cnt == v[i])
        c = f(i + 1, 0);
    bool flag = (a || b || c);
    if (flag)
    {
        m[{i, cnt}] = 1;
        return true;
    }
    else
    {
        m[{i, cnt}] = 0;
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        v.clear();
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        m.clear();
        bool flag = f(0, 0);
        if (flag)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }
    return 0;
}