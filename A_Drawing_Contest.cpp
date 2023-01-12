#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    int n, c = 0;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        vi v1(k), v2(k);
        for (auto &i : v1)
            cin >> i;
        for (auto &i : v2)
            cin >> i;
        sort(all(v1));
        sort(all(v2));
        ll ans = 0;
        for (int i = 0; i < k; i++)
        ans += abs(v1[i] - v2[i]);
        cout << "Case " << ++c << ": " << ans << endl;
    }
    return 0;
}
