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
        cin >> n;
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;
        string ans = "";
        map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            m[v[i][0]]++;
        }
        for (auto &i : m)
        {
            if (i.ss >= 3)
            {
                ans += i.ff;
            }
        }
        if (sz(ans))
            cout << ans << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}