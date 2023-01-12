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
    bool f = true;
    while (t--)
    {
        ll n, x = 9;
        cin >> n;
        string s = "9876543210123456789";
        if (n > s.size())
        {
            int c = 0;
            for (int i = s.size(); i < n; i++)
            {
                s += to_string(c);
                if (c == 9)
                    c = -1;
                c++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
