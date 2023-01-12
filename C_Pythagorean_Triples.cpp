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
    if (n <= 2)
        cout << -1 << endl;
    else if (n & 1)
    {
        n *= n;
        n /= 2;
        cout << n << " " << n + 1 << endl;
    }
    else
    {
        n *= n;
        n /= 4;
        cout << n - 1 << " " << n + 1 << endl;
    }
    return 0;
}
