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

ll n, k;
string s;
bool f(ll m)
{
    int cnt = 0;
    bool f = true;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (i != 0 && s[i] == s[i - 1])
            f = false;
        if (i != 0 && s[i - 1] != s[i] && f)
        {
            cnt++;
            f = true;
            j = -1;
        }
        else if (j == k - 1 && i != n - 1)
        {
            cnt++;
            f = true;
            j = 0;
            i++;
        }
    }
    return cnt <= m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        ll l = -1, r = n;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (f(m))
                r = m;
            else
                l = m;
        }
        cout << r << endl;
    }
    return 0;
}
