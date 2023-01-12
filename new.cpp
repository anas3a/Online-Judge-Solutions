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

    vvi v(8, vi(3));
    for (auto &i : v)
    {
        for (auto &j : i)
            cin >> j;
    }
    for (int i = 0; i < 8; i++)
    {
        int a = v[i][0];
        int b = v[i][1];
        int c = v[i][2];
        cout << (c || (a && b)) << " " << (c || (b && a)) << endl;
    }
    return 0;
}
