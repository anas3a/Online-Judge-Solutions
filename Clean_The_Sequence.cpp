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
        ll n, k;
        cin >> n >> k;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        ll cnt = 0;
        vll vc(k + 1, 0);
        ll c = v[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
            {
                cnt++;
                if (v[i] == c)
                    vc[v[i - 1]] += 2;
                else
                    vc[v[i - 1]]++;
                c = v[i - 1];
            }
        }
        // if (n > 1 && v[0] != v[1])
        //     vc[v[0]]++;
        if (k != 1)
            vc[v[n - 1]]++;
        for (int i = 1; i <= k; i++)
            cout << cnt - vc[i] << " ";
        cout << endl;
    }
    return 0;
}