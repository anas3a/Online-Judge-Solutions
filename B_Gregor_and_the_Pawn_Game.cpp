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
        string s, x;
        cin >> s >> x;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '1')
            {
                if (i != 0 && s[i - 1] == '1')
                {
                    s[i - 1] = '2';
                    cnt++;
                }
                else if (s[i] == '0')
                {
                    s[i] = '2';
                    cnt++;
                }
                else if (i < n - 1 && s[i + 1] == '1')
                {
                    s[i + 1] = '2';
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
