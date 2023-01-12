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

    int t;
    cin >> t;
    while (t--)
    {
        ll s, n, x;
        vll v;
        cin >> s >> n >> x;
        n++;
        v.assign(n, 0);
        ll s1 = s;
        v[0] = s1;
        for (int i = 1; i < n; i++)
        {
            ll a;
            cin >> a;
            if (s1 > x)
                continue;
            v[i] = a + s1;
            s1 += v[i];
        }
        ll sum = x;
        sort(rall(v));
        for (int i = 0; i < sz(v); i++)
        {
            if (v[i] <= sum)
                sum -= v[i];
            if (sum == 0)
                break;
        }
        if (sum == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
