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

    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        vll v;
        string s;
        getline(cin, s);
        stringstream sx(s);
        ll x;
        while (sx >> x)
            v.pb(x);
        ll mx = 0;
        for (int i = 0; i < sz(v); i++)
        {
            for (int j = i + 1; j < sz(v); j++)
                mx = max(mx, __gcd(v[i], v[j]));
        }
        cout << mx << endl;
    }
    return 0;
}
