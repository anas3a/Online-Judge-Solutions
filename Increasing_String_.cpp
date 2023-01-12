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
        vvi v(26);
        char x = 'X';
        for (int i = 0; i < sz(s); i++)
        {
            v[s[i] - 'a'].pb(i);
            if (i && x == 'X' && s[i] < s[i - 1])
                x = s[i - 1];
        }
        string ans;
        set<int> st;
        int mx = -1;
        for (int i = 0; i < 26; i++)
        {
            if (x - 'a' == i)
            {
                string tmp, tmpx(sz(v[i]), x);
                for (int i = 0; i < mx; i++)
                {
                    if (st.count(i))
                        continue;
                    tmp += s[i];
                }
                if (tmp < tmpx)
                    break;
            }
            for (auto &j : v[i])
            {
                if (j > mx)
                {
                    mx = j;
                    st.insert(j);
                    ans += char('a' + i);
                }
            }
            if (x - 'a' == i)
                break;
        }
        for (int i = 0; i < sz(s); i++)
        {
            if (st.count(i))
                continue;
            ans += s[i];
        }
        cout << ans << endl;
    }
    return 0;
}