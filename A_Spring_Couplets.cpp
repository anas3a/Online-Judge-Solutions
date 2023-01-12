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
        vector<string> vx(n), vy(n);
        for (auto &i : vx)
            cin >> i;
        for (auto &i : vy)
            cin >> i;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int x = vx[i].back() - '0';
            int y = vy[i].back() - '0';
            if (x <= 2 && y <= 2)
                flag = false;
            if (x >= 3 && y >= 3)
                flag = false;
            if (i == n - 1 && x <= 2)
                flag = false;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}