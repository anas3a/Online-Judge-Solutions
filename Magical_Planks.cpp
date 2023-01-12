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
        string s;
        cin >> n >> s;
        ll cntb = 0, cntw = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                if (s[i - 1] == 'B')
                    cntb++;
                else
                    cntw++;
            }
        }
        if (s[n - 1] == 'W')
            cntw++;
        else
            cntb++;
        cout << min(cntw, cntb) << endl;
    }
    return 0;
}