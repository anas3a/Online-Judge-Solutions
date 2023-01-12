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

string s, t;

bool ok(int a, int b)
{
    int i, j;
    for (i = 0, j = 0; i < sz(s); i++)
    {
        if (i == a)
            i = b + 1;
        if (i >= sz(s))
            break;
        if (j < sz(t) && s[i] == t[j])
            j++;
    }
    return j == sz(t);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    ll ans = 0;
    for (ll i = 0, j = 0; i < sz(s); i++)
    {
        while (j <= i && !ok(j, i))
            j++;
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;
}