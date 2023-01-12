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

ll n, k;
vi v[2600];
ll cnt[2600];
ll f(ll ind, ll col, bitset<2600> &bt)
{
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (i == col)
            continue;
        bt[i] = 1;
        cnt[i]++;
        if (v[ind].size() == 0)
        {
            if (bt.count() == k)
                sum++;
        }
        else
        {
            for (int j = 0; j < v[ind].size(); j++)
                sum += f(v[ind][j], i, bt);
        }
        cnt[i]--;
        if (!cnt[i])
            bt[i] = 0;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        v[x].pb(i);
    }
    bitset<2600> bt;
    cout << f(0, -1, bt) << endl;
    return 0;
}
