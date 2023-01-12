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
        ll n;
        cin >> n;
        vector<string> v(n - 2);
        for (auto &i : v)
            cin >> i;
        string ans;
        ans += v[0][0];
        bool flag = true;
        for (int i = 0; i < n - 3; i++)
        {
            if (v[i][1] != v[i + 1][0])
            {
                ans += v[i][1], ans += v[i + 1][0];
                flag = false;
            }
            else
                ans += v[i][1];
        }
        ans += v[n - 3][1];
        if (flag)
            ans += "a";
        cout << ans << endl;
    }
    return 0;
}