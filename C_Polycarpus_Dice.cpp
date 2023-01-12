#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    ll n, a, sum = 0, ans = 0, x;
    cin >> n >> a;
    vll v(n), vx(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 0; i < n; i++)
    {
        x = sum - v[i];
        if (x < a)
            vx[i] += a - x - 1;
        if (v[i] > a - n + 1)
            vx[i] += v[i] - a + n - 1;
    }
    for (auto &i : vx)
        cout << i << " ";
    cout << endl;
    return 0;
}
