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
    map<ll, ll> ind, dif;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        ind[a] = i;
    }
    for (int i = 0; i < n; i++)
    {
        ll a, x;
        cin >> a;
        if (ind[a] >= i)
            x = ind[a] - i;
        else
            x = n - i + ind[a];
        dif[x]++;
    }
    ll mx = 0;
    for (auto &i : dif)
        mx = max(mx, i.ss);
    cout << mx << endl;
    return 0;
}
