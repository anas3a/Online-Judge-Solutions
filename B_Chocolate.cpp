#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    ll n, ans = 0, cnt = 0;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            if (f)
            {
                ans = 1;
                f = false;
                cnt = 0;
            }
            else
            {
                ans *= cnt + 1;
                cnt = 0;
            }
        }
        else
            cnt++;
    }
    cout << ans << endl;
    return 0;
}
