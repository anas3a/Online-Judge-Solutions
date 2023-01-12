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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll cnt = 0, n, m, ans = 0, ansx = LLONG_MAX;
    ll mn = LLONG_MAX, mx = LLONG_MIN;

    for (int i = 2; i <= 26; i++)
    {
        cout << "? " << i << " " << 1 << endl;
        cin >> n;
        cout << "? " << 1 << " " << i << endl;
        cin >> m;
        if (n == -1)
        {
            ans = i - 1;
            break;
        }
        if (n != m)
        {
            ans = (n + m);
            break;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}