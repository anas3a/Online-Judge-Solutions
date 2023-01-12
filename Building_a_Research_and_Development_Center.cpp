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

ll n;
vll v;
vll parent, rankx;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v)
{
    parent[v] = v;
    rankx[v] = 0;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rankx[a] < rankx[b])
            swap(a, b);
        if (rankx[a] == rankx[b] && b > a)
            swap(a, b);
        parent[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> n >> q;
    v.resize(n);
    parent.resize(n);
    rankx.resize(n);
    for (int i = 0; i < n; i++)
    {
        make_set(i);
    }
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        rankx[a] = n - i; 
    }

    while (q--)
    {
        ll x, a, b;
        cin >> x;
        if (x == 1)
        {
            cin >> a >> b;
            union_sets(a, b);
        }
        else if (x == 2)
        {
            cin >> a;
            rankx[a]++;
            ll z = find_set(a);
            parent[a] = a;
            union_sets(a, z);
        }
        else
        {
            cin >> a;
            cout << find_set(a) << endl;
        }
    }
    return 0;
}