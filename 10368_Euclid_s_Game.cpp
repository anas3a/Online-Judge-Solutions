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

    while (true)
    {
        ll n, m;
        cin >> n >> m;
        if (n + m == 0)
            break;
        ll w = 1;
        while (true)
        {
            w = 1 - w;
            if (n < m)
                swap(n, m);
            if (n % m == 0)
                break;
            if (n / m >= 2)
                break;
            n = n - m;
        }
        if (w == 0)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}
