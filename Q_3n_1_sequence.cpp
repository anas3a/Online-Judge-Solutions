#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using pii = pair <int, int>;
using pll = pair <long, long>;
using vpi = vector <pii >;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

ll f (ll n)
{
    if (n == 1)
    return 1;
    if (n & 1)
    return 1 + f(3 * n + 1);
    else
    return 1 + f(n / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
