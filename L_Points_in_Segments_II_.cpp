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

    int t, cs = 0;
    scanf("%d", &t);
    while (t--)
    {
        printf("Case %d:\n", ++cs);
        int n, q;
        scanf("%d %d", &n, &q);
        vi vx, vy;
        while(n--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            vx.pb(a);
            vy.pb(b);
        }
        sort(all(vx));
        sort(all(vy));
        while(q--)
        {
            int x;
            scanf("%d", &x);
            int ind1 = upper_bound(all(vx), x) - vx.begin();
            int ind2 = lower_bound(all(vy), x) - vy.begin();
            printf("%d\n", ind1 - ind2);
        }
    }
    return 0;
}