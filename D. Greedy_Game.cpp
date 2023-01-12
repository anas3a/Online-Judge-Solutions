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

vpl v1, v2;
bool comp1(int &a, int &b)
{
    return v2[a].ff >= v2[b].ff;
}
bool comp2(int &a, int &b)
{
    return v1[a].ff >= v1[b].ff;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi vis(n, 0);
    v1.resize(n), v2.resize(n);
    vpl v3(n), v4(n);
    map<ll, vi> m1, m2;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i].ff;
        v1[i].ss = i;
        m1[v1[i].ff].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i].ff;
        v2[i].ss = i;
        m2[v2[i].ff].push_back(i);
    }
    v3 = v1;
    v4 = v2;
    sort(rall(v3));
    sort(rall(v4));
    for (auto &i : m1)
        sort(all(i.ss), comp1);
    for (auto &i : m2)
        sort(all(i.ss), comp2);
    ll ans = 0;
    int j = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            while (vis[v4[j].ss])
                j++;
            int l = 0;
            ll z = v4[j].ff;
            while (vis[m2[z][l]])
                l++;
            ans += z;
            vis[m2[z][l]] = 1;
        }
        else
        {
            while (vis[v3[k].ss])
                k++;
            int l = 0;
            ll z = v3[k].ff;
            while (vis[m1[z][l]])
                l++;
            vis[m1[z][l]] = 1;
        }
    }
    // for (auto &i : m)
    // {
    //     cout << i.ff << " ";
    //     for (auto &j : i.ss)
    //         cout << j << " ";
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}
