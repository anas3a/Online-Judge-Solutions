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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vll v(n + 3);
    v[1] = 4;
    v[2] = 4;
    int x = 8, y = 5;
    for (int i = 3; i <= n + 1; i++)
    {
        if (i & 1)
        {
            v[i] = v[i - 2] + x;
            x += 4;
        }
        else 
        {
            v[i] = v[i - 2] + y;
            y += 2;
        }
    }
    cout << v[n] << endl;
    return 0;
}
