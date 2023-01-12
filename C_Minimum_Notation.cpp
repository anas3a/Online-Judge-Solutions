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
        int ind = -1;
        map<char, ll> m;
        int n = sz(s);
        vector<bool> vis(n + 1, false);
        set<int> st;
        for (int i = 0; i <= 9; i++)
        {
            for (int j = ind + 1; j < sz(s); j++)
            {
                if (s[j] == char('0' + i))
                {
                    m[s[j]]++;
                    vis[j] = true;
                    for (int k = j - 1; k > ind; k--)
                    {
                        if (!vis[k])
                        {
                            st.insert(k);
                            vis[k] = true;
                        }
                    }
                    ind = j;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                st.insert(i);
            }
        }
        for (auto &i : st)
        {
            char x = min('9', char (s[i] + 1));
            m[x]++;
        }
        for (auto &i : m)
        {
            for (int j = 0; j < i.ss; j++)
                cout << i.ff;
        }
        cout << nl;
    }
    return 0;
}