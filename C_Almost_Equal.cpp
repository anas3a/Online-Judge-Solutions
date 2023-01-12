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

    ll n;
    cin >> n;
    if (n & 1)
    {
        cout << "YES" << endl;
        cout << "1 ";
        for (int i = 4; i <= 2 * n; i += 4)
        {
            cout << i << " " << i + 1 << " ";
        }
        for (int i = 2; i <= 2 * n; i += 4)
        {
            cout << i << " ";
            if (i + 1 <= 2 * n)
                cout << i + 1 << " ";
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
