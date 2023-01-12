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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<string> st;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            st.insert(s);
        }
        int cnt = 0;
        for (auto &s : st)
        {
            for (int i = 1; i < s.size(); i++)
            {
                string prefix = s.substr(0, i);
                string suffix = s.substr(i, s.size() - i);
                if (st.count(prefix) && st.count(suffix))
                {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
