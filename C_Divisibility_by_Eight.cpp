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

string s;
ll ans;
bool flag = false;
void dp(int i, string sx)
{
    ll n;
    if (sz(sx))
        n = stoll(sx);
    if (sz(sx) > 1 && sx[0] == '0')
        return;
    if (sz(sx) && n % 8 == 0)
    {
        flag = true;
        ans = n;
    }
    if (sz(sx) == 3 || i == sz(s))
        return;
    string sy = sx + s[i];
    dp(i + 1, sy);
    dp(i + 1, sx);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    dp(0, "");
    if (flag)
    {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}