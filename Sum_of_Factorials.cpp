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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll nx = 20;
    vll fact(nx, 0);
    fact[0] = 1;
    for (int i = 1; i < nx; i++)
        fact[i] = fact[i - 1] * i;

    ll t, cs = 0;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        cout << "Case " << ++cs << ": ";
        vi ans;
        for (int i = nx - 1; i >= 0; i--)
        {
            if (fact[i] <= n)
            {
                n -= fact[i];
                ans.pb(i);
            }
        }
        reverse(all(ans));
        if (n)
            printf("impossible\n");
        else
        {
            for (int i = 0; i < sz(ans); i++)
            {
                if (i)
                    printf("+");
                printf("%lld!", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}