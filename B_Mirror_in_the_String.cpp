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
        string s;
        cin >> s;
        string sx = s;
        sort(all(sx));
        vector<string> vs;
        string sz;
        bool flag = false;
        sz = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1] && s[i] == s[0])
                break;
            if (s[i] > s[i - 1])
                break;
            sz += s[i];
        }
        string ans = sz;
        reverse(all(sz));
        cout << ans + sz << "\n";
    }
    return 0;
}