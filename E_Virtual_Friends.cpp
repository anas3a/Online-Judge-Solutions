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

int n = 3e5;
vi parent, sizex;
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
int union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sizex[a] < sizex[b])
            swap(a, b);
        parent[b] = a;
        sizex[a] += sizex[b];
    }
    return sizex[a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        parent.clear();
        sizex.clear();
        parent.resize(n + 1);
        sizex.resize(n + 1);
        for (int i = 0; i < n; i++)
            make_set(i);
        map<string, int> mp;
        int m;
        cin >> m;
        int cnt = 1;
        while (m--)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (!mp[s1])
                mp[s1] = cnt++;
            if (!mp[s2])
                mp[s2] = cnt++;
            int a = mp[s1];
            int b = mp[s2];
            int x = union_sets(a, b);
            cout << x << '\n';
        }
    }
    return 0;
}