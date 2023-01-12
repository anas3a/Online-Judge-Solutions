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
ll cnt;
bool conv(ll n, ll i)
{
    string s;
    while (n != 0)
    {
        s += (n % i) + '0';
        n /= i;
    }
    string r = s;
    reverse(all(r));
    return (s == r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, cnt = 0;
        cin >> n;
        for (int i = 2; i <= 16; i++)
        {
            if (conv(n, i))
                cout << i << " ", cnt++;
        }
        if (cnt == 0)
            cout << -1;
        cout << endl;
    }
    return 0;
}
