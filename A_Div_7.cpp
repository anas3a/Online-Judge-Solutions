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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n % 7 == 0)
            cout << n << endl;
        else
        {
            n /= 10;
            n *= 10;
            while (n % 7 != 0)
                n++;
            cout << n << endl;
        }
    }
    return 0;
}