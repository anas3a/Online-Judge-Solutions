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
        int n;
        string s;
        cin >> n >> s;
        map<char, char> m;
        for (int i = 0; i < 26; i++)
        {
            m['a' + i] = 'A';
        }
        vector<bool> vis(26, false);
        string ans;
        int j = -1;
        bool flag = true;
        for (int i = 0; i < sz(s); i++)
        {
            if (m[s[i]] != 'A')
                ans += m[s[i]];
            else
            {
                while (true)
                {
                    if (flag)
                        j++;
                    else
                        j--;
                    if (j == 26)
                    {
                        j--;
                        flag = false;
                    }
                    if (j == -1)
                    {
                        j++;
                        flag = true;
                    }
                    if (!vis[j] && char('a' + j) != s[i] && m[char('a' + j)] != s[i])
                    {
                        vis[j] = true;
                        m[s[i]] = char('a' + j);
                        ans += m[s[i]];
                        break;
                    }
                }
            }
        }
        cout << ans << nl;
    }
    return 0;
}