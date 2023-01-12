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

    ll x = 150001;
    ll n;
    cin >> n;
    vll v(x + 5, 0);
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v[a]++;
    }
    ll cnt = 0;
    for (int i = 1; i <= x; i++)
    {
        if (v[i - 1])
            v[i - 1]--, cnt++;
        else if (v[i])
            v[i]--, cnt++;
        else if (v[i + 1])
            v[i + 1]--, cnt++;
    }
    cout << cnt << endl;
    return 0;
}
