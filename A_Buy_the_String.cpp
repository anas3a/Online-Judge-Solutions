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
        ll n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (c1 + h < c0)
                    sum += c1 + h;
                else
                    sum += c0;
            }
            if (s[i] == '1')
            {
                if (c0 + h < c1)
                    sum += c0 + h;
                else
                    sum += c1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
