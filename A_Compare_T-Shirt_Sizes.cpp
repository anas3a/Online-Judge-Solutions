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
        ll ans = 1;
        string a, b;
        cin >> a >> b;
        if (b.back() < a.back())
            ans = 2;
        else if (a == b)
            ans = 3;
        else if (b.back() == a.back())
        {
            if (a.back() == 'S')
            {
                if (sz(b) < sz(a))
                    ans = 2;
                else if (sz(a) == sz(b))
                    ans = 3;
            }
            else if (a.back() == 'L')
            {
                if (sz(b) > sz(a))
                    ans = 2;
                else if (sz(a) == sz(b))
                    ans = 3;
            }
        }
        if (ans == 1)
            cout << ">" << nl;
        else if (ans == 2)
            cout << "<" << nl;
        else
            cout << "=" << nl;
    }
    return 0;
}