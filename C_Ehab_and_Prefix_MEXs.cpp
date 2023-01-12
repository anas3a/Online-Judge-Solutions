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
    vll v(n), vx(n);
    vector<bool> vb(n + 5, false);
    for (auto &i : v)
        cin >> i, vb[i] = true;
    vx = v;
    sort(all(vx));
    if (vx != v)
        cout << -1 << endl;
    else
    {
        ll cnt = 0;
        while (vb[cnt])
            cnt++;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && v[i] != v[i - 1])
                cout << v[i - 1] << " ";
            else
            {
                cout << cnt << " ";
                cnt++;
                while (vb[cnt])
                    cnt++;
            }
        }
        cout << endl;
    }
    return 0;
}