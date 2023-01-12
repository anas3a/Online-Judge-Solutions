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

    ll n, k, cnt1 = 0, cnt2 = 0;
    cin >> n >> k;
    vll vx, v1, v2;
    for (int i = 0; i < n; i++)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        cnt1 += a, cnt2 += b;
        if (a + b == 2)
            vx.pb(t);
        else if (a)
            v1.pb(t);
        else if (b)
            v2.pb(t);
    }
    if (cnt1 < k || cnt2 < k)
        cout << -1 << endl;
    else
    {
        sort(all(vx)), sort(all(v1)), sort(all(v2));
        ll sum = 0, k1 = 0, k2 = 0, i = 0, j = 0, l = 0;
        while (k1 < k || k2 < k)
        {
            if (k2 >= k)
            {
                if (j == sz(v1))
                    sum += vx[i++];
                else if (i == sz(vx))
                    sum += v1[j++];
                else
                {
                    if (vx[i] <= v1[j])
                        sum += vx[i++];
                    else
                        sum += v1[j++];
                }
                k1++;
            }
            else if (k1 >= k)
            {
                if (l == sz(v2))
                    sum += vx[i++];
                else if (i == sz(vx))
                    sum += v2[l++];
                else
                {
                    if (vx[i] <= v2[l])
                        sum += vx[i++];
                    else
                        sum += v2[l++];
                }
                k2++;
            }
            else
            {
                if (j == sz(v1) || l == sz(v2))
                    sum += vx[i++];
                else if (i == sz(vx))
                {
                    sum += v1[j++];
                    sum += v2[l++];
                }
                else
                {
                    if (vx[i] <= v1[j] + v2[l])
                        sum += vx[i++];
                    else
                        sum += v1[j++] + v2[l++];
                }
                k1++, k2++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
