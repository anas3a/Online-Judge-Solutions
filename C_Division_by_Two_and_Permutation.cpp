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
        vll v(n);
        for (auto &i : v)
            cin >> i;
        set<ll> st;
        vector<bool> vx(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            while (v[i] != 0)
            {
                if (v[i] <= n && !vx[v[i]])
                {
                    vx[v[i]] = true;
                    break;
                }
                v[i] /= 2;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (!vx[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}