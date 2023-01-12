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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        if (sz(s) == 1)
        {
            cout << "1 0" << endl;
            continue;
        }
        string t = s;
        sort(all(t));
        if (t.front() == t.back())
        {
            cout << sz(s) << " 0" << endl;
            continue;
        }
        cout << 1 << " ";
        int c1 = 0, c0 = 0;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == '1')
                c1++;
            else
                c0++;
        }
        int nx = abs(c1 - c0);
        vvi ans;
        int xx = 0;
        for (int i = 0; i < nx; i++)
        {
            string x;
            for (int j = 0; j < sz(s) - 1; j++)
            {
                if (s[j] == '0' && s[j + 1] == '1')
                {
                    xx = j;
                    break;
                }
                if (s[j] == '1' && s[j + 1] == '0')
                {
                    xx = j;
                    break;
                }
            }
            for (int j = 0; j < sz(s); j++)
            {
                if (j != xx && j != xx + 1)
                    x += s[j];
                else if (j == xx)
                {
                    if (c0 > c1)
                        x += "1";
                    else
                        x += "0";
                }
            }
            if (c0 > c1)
                ans.pb({xx + 1, xx + 2, 1});
            else
                ans.pb({xx + 1, xx + 2, 0});
            s = x;
        }
        ans.pb({1, sz(s), 0});
        cout << sz(ans) << endl;
        for (auto &i : ans)
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
    return 0;
}