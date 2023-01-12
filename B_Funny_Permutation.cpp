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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1 || n == 3)
            cout << -1 << nl;
        else
        {
            if (n & 1)
            {
                for (int i = 0, j = n; i < n / 2; i++, j--)
                {
                    cout << j << " ";
                }
                for (int i = 1; i <= (n / 2) + 1; i++)
                    cout << i << " ";
                cout << nl;
            }
            else
            {
                for (int i = n; i >= 1; i--)
                {
                    cout << i << " ";
                }
                cout << nl;
            }
        }
    }
    return 0;
}