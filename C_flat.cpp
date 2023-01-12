#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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
    if (n % 3 == 0)
    {
        cout << n / 3 << " " << 0 << " " << 0 << endl;
    }
    else if (n % 3 == 1)
    {
        if (n <= 6)
            cout << -1 << endl;
        else
        {
            ll x = (n / 3) - 2;
            cout << x << " " << 0 << " " << 1 << endl;
        }
    }
    else if (n % 3 == 2)
    {
        if (n <= 4)
            cout << -1 << endl;
        else
        {
            ll x = (n / 3) - 1;
            cout << x << " " << 1 << " " << 0 << endl;
        }
    }
    return 0;
}
