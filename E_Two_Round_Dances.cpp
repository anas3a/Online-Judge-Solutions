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

ll fact(ll n)
{
    if (n == 1)
    return 1;
    return fact(n - 1) * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, z;
    cin >> n;
    ll r = n / 2;
    z = fact(n);
    cout << z / (n * r) << endl;
    return 0;
}
