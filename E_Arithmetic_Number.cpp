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

    ll n;
    cin >> n;
    string s = to_string(n);
    if (sz(s) <= 2)
        cout << s << endl;
    else
    {
        bool flag = true;
        ll z = s[1] - s[0];
        for (int i = 2; i < sz(s); i++)
        {
            ll y = s[i] - s[i - 1];
            if (y != z)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << s << endl;
        else
        {

            ll dif = 0;
            vector<string> ans;
            while (dif < 10)
            {
                for (int i = 1; i <= 9; i++)
                {
                    ll z = (dif * (sz(s) - 1)) + i;
                    if (z > 9)
                        break;
                    string ss;
                    char cx = char(i + '0');
                    ss += cx;
                    while (sz(ss) < sz(s))
                    {
                        cx += dif;
                        ss += cx;
                    }
                    ans.pb(ss);
                }
                dif++;
            }
            dif = 9;
            while (dif >= 0)
            {
                for (int i = 9; i >= 1; i--)
                {
                    ll z = i - (dif * (sz(s) - 1));
                    if (z < 0)
                        break;
                    string ss;
                    char cx = char(i + '0');
                    ss += cx;
                    while (sz(ss) < sz(s))
                    {
                        cx -= dif;
                        ss += cx;
                    }
                    ans.pb(ss);
                }
                dif--;
            }
            sort(all(ans));
            for (auto &i : ans)
            {
                if (i >= s)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}