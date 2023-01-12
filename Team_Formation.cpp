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

    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        ll cnt = 0;
        ll sx = 0, tx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && t[i] == '1')
            {
                cnt++;
                s[i] = '0';
                t[i] = '0';
            }
            if (s[i] == '1')
                sx++;
            if (t[i] == '1')
                tx++;
        }
        cnt += min(sx, tx);
        cnt = min(n / 2, cnt);
        cout << cnt << endl;
    }
    return 0;
}
