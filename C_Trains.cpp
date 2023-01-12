#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, n;
    cin >> a >> b;
    n = (a * b) / (__gcd(a, b));
    ll x = n / a, y = n / b;
    if (x >= y)
    {
        if (x - y > 1)
            cout << "Dasha" << endl;
        else
            cout << "Equal" << endl;
    }
    else
    {
        if (y - x > 1)
        cout << "Masha" << endl;
        else
        cout << "Equal" << endl;
    }
    
    return 0;
}
