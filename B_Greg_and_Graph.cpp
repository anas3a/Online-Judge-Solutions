// Floyd Warshall APSP - O(N^3)

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

vector<vector<ll>> d;
vll ans;
void FloydWarshal(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] < LLONG_MAX && d[k][j] < LLONG_MAX)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        ll sum = 0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sum += d[i][j];
            }
        }
        cout << sum << nl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    d.resize(n, vector<ll>(n));
    for (auto &i : d)
        for (auto &j : i)
            cin >> j;
    FloydWarshal(n);
    return 0;
}