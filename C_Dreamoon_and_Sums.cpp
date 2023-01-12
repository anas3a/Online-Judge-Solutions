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

    ll a, b;
    cin >> a >> b;
    ll c = ((b - 1) * a * b) + (b - 1);
    ll sum = 0;
    vll v;
    for (int i = 1; i <= c; i++)
    {
        if (i % b != 0 && i / b >= 1)
        {
            if ((i / b) / (i % b) <= a && ((i / b) % (i % b)) == 0)
            {
                sum += i;
                v.pb(i);
            }
        }
    }
    sort(all(v));
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}