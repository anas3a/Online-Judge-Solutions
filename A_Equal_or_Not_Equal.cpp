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
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = sz(s);
        ll x = 1;
        vll v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = x;
            if (s[i] == 'N')
                x = 1 - x;
        }
        for (auto &i : v)
            cout << i << endl;
        if (s[n - 1] == 'E' && v[n - 1] == v[0])
            cout << "YES" << endl;
        else if (s[n - 1] == 'N' && v[n - 1] != v[0])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}