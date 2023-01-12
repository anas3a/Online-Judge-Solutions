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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll c = max(a, b), d = min(a, b);
        cout << (c ^ d) << endl;
    }
    return 0;
}
