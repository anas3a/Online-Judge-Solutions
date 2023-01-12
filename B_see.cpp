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

    ll n;
    string s;
    cin >> n >> s;
    ll ans = 1e5;
    for (int i = 0; i < n; i++)
    {
        ll c1 = 0, c2 = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (s[j] != 'R')
                c1++;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] != 'L')
                c2++;
        }
        ans = min(ans, c1 + c2);
    }
    cout << ans << endl;
    return 0;
}
