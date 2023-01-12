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

    ll n, cnt;
    cin >> n;
    if (n <= 5)
        cout << -1 << endl;
    else
    {
        ll k = (n + 2) / 2;
        cnt = 2;
        while (cnt <= k)
        {
            cout << 1 << " " << cnt << endl;
            cnt++;
        }
        while (cnt <= n)
        {
            cout << 2 << " " << cnt << endl;
            cnt++;
        }
    }
    cnt = 2;
    while (cnt <= n)
    {
        cout << 1 << " " << cnt << endl;
        cnt++;
    }
    return 0;
}
