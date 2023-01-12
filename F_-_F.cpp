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
        string s;
        int k;
        cin >> s >> k;
        multiset<string> st;
        for (int i = 0; i < sz(s); i++)
        {
            string t;
            for (int j = i; j < sz(s); j++)
            {
                t += s[j];
                string u = t;
                reverse(all(u));
                if (u == t)
                    st.insert(t);
            }
        }
        if (sz(st) < k)
            cout << -1 << endl;
        else
        {
            int cnt = 0;
            for (auto &i : st)
            {
                cnt++;
                if (cnt == k)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}