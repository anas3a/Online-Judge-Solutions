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
        if ((s[n - 1] - '0') % 2 == 0)
            cout << 0 << endl;
        else
        {
            if ((s[0] - '0') % 2 == 0)
                cout << 1 << endl;
            else
            {
                ll cnt = 0;
                for (int i = 0; i < sz(s); i++)
                {
                    if ((s[i] - '0') % 2 == 0)
                        cnt++;
                }
                if (!cnt)
                    cout << -1 << endl;
                else
                    cout << 2 << endl;
            }
        }
    }
    return 0;
}