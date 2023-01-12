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

    ll n, a;
    cin >> n;
    cout << 2 << endl;
    a = n;
    for (int i = n - 1; i >= 1; i--)
    {
        cout << a << " " << i << endl;
        if ((a + i) % 2)
            a = ((a + i) / 2) + 1;
        else
            a = (a + i) / 2;
    }
    return 0;
}
