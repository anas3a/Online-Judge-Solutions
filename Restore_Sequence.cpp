#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n), a(n);
        for (auto &i : v)
            cin >> i;
        ll x = n * 4;
        for (int i = n - 1; i >= 0; i--, x--)
            a[i] = x;
        for (int i = 0; i < n; i++)
        {
            a[i] = a[v[i] - 1];
        }
        for (auto &i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
