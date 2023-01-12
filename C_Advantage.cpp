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
        vll v(n);
        map<ll, ll> m;
        for (auto &i : v)
        {
            cin >> i;
            m[i]++;
        }
        auto it = m.end();
        it--;
        for (auto &i : v)
        {
            if (i == it->first)
            {
                if (it->second > 1)
                    cout << i - it->first << " ";
                else
                {
                    auto itx = it;
                    itx--;
                    cout << i - itx->first << " ";
                }
            }
            else
                cout << i - it->first << " ";
        }
        cout << endl;
    }
    return 0;
}