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

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vvl v(30);
        for (int i = 0; i < sz(s); i++)
        {
            v[s[i] - 'a'].pb(i);
        }
        ll cost = abs(s.front() - s.back());
        vll ans;
        if (s.front() <= s.back())
        {
            for (int i = s.front() - 'a'; i <= s.back() - 'a'; i++)
            {
                for (int j = 0; j < sz(v[i]); j++)
                {
                    ans.pb(v[i][j]);
                }
            }
        }
        else
        {
            for (int i = s.front() - 'a'; i >= s.back() - 'a'; i--)
            {
                for (int j = 0; j < sz(v[i]); j++)
                {
                    ans.pb(v[i][j]);
                }
            }
        }
        cout << cost << " " << sz(ans) << endl;
        for (auto &i : ans)
            cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}