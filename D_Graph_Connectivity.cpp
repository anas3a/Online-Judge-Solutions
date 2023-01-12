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
void union_sets(int a, int b)
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
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cin.ignore();
        int n = s[0] - 'A' + 1;
        parent.clear();
        sizex.clear();
        parent.resize(n), sizex.resize(n, 0);
        for (int i = 0; i < n; i++)
            make_set(i);
        while (getline(cin, s))
        {
            if (s == "\0")
                break;
            int a = s[0] - 'A', b = s[1] - 'A';
            union_sets(a, b);
        }
        set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(find_set(i));
        cout << sz(st) << "\n";
        if (t)
            cout << "\n";
    }
    return 0;
}