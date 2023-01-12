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
        map<int, int> mp;
        for (int i = 0; i < 4; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        if (sz(mp) == 2)
        {
            ll z = 0;
            for (auto &i : mp)
                if (i.ss == 3)
                    z++;
            if (z == 0)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
        else
            cout << min(sz(mp) - 1, 2) << endl;
    }
    return 0;
}
