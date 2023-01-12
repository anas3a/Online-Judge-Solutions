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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll mx = 5e6 + 100;
    vector <unsigned ll> phi(mx + 3);

    for (int i = 0; i <= mx; i++)
        phi[i] = i;

    for (int i = 2; i <= mx; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= mx; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    for (int i = 2; i <= mx; i++)
    {
        phi[i] *= phi[i];
        phi[i] += phi[i - 1];
    }

    ll t, cs = 0;
    cin >> t;
    while(t--)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case %lld: %llu\n", ++cs, phi[b] - phi[a - 1]);
    }
    return 0;
}