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
        string s;
        cin >> s;
        ll n = sz(s);
        if (n & 1)
            cout << "NO" << endl;
        else
        {
            string a, b;
            for (int i = 0; i < n; i++)
            {
                if (i < n / 2)
                    a += s[i];
                else
                    b += s[i];
            }
            if (a == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}