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

    ll n, sum = 0;
    cin >> n;
    vll v(n);
    for (auto &i : v)
        cin >> i, sum += i;
    ll m = n;
    sort(all(v));
    while (m != 0)
    {
        m /= 4;
        for (int i = n - m; i < n; i++)
            sum += v[i];
    }
    cout << sum << endl;
    return 0;
}
