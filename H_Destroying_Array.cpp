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

vector<int> parent, rankx;
ll n, sum = 0;
vll vt, vx;
vll sumx;
vector<bool> vis(n + 1, false);
void make_set(int v)
{
    parent[v] = v;
    rankx[v] = 0;
    sumx[v] = vt[v - 1];
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rankx[a] < rankx[b])
            swap(a, b);
        parent[b] = a;
        sumx[a] += sumx[b];
        if (rankx[a] == rankx[b])
        {
            rankx[a]++;
        }
    }
    if (sumx[a] > sum)
        sum = sumx[a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vt.clear();
    vx.clear();
    vt.resize(n);
    vx.resize(n);
    vis.resize(n + 1, false);
    sumx.resize(n + 1);
    rankx.resize(n + 1);
    parent.resize(n + 1);
    for (auto &i : vt)
        cin >> i;
    for (auto &i : vx)
        cin >> i;
    reverse(all(vx));
    vll ans;
    for (int i = 1; i <= n; i++)
        make_set(i);
    for (int i = 0; i < n; i++)
    {
        ans.pb(sum);
        vis[vx[i]] = true;
        sum = max(sum, vt[vx[i] - 1]);
        if (vx[i] - 1 != 0 && vis[vx[i] - 1])
            union_sets(vx[i], vx[i] - 1);
        if (vx[i] + 1 <= n && vis[vx[i] + 1])
            union_sets(vx[i], vx[i] + 1);
    }
    reverse(all(ans));
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}