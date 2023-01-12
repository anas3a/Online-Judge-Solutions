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

vi parent, sizex;
vpi ans1;
void make_set(int u)
{
    parent[u] = u;
    sizex[u] = 1;
}
int find_set(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
}
void union_sets(int ax, int bx)
{
    int a = find_set(ax);
    int b = find_set(bx);
    if (a != b)
    {
        if (sizex[a] < sizex[b])
            swap(a, b);
        parent[b] = a;
        sizex[a] += sizex[b];
    }
    else
        ans1.pb({ax, bx});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    parent.resize(n + 1);
    sizex.resize(n + 1);
    for (int i = 1; i <= n; i++)
        make_set(i);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(find_set(i));
    vi ans2(all(st));
    cout << sz(ans2) - 1 << endl;
    for (int i = 0; i < sz(ans2) - 1; i++)
    {
        cout << ans1[i].ff << " " << ans1[i].ss << " " << ans2[i] << " " << ans2[i + 1] << endl;
    }
    return 0;
}