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

    int cs = 0;
    while (true)
    {
        ll n;
        cin >> n;
        if (!n)
            break;
        cout << "Case " << ++cs << ": ";
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;
        map<string, int> m;
        for (auto &i : v)
            m[i]++;
        vi vx;
        for (auto &i : m)
            vx.pb(i.ss);
        sort(all(vx));
        vi vy(1e5, 0);
        for (auto &i : vx)
            vy[i]++;
        vector<string> ans;
        int sum = 0;
        for (int i = vx.back(); i > 0; i--)
        {
            sum += vy[i];
            ans.pb(to_string(sum));
        }
        for (auto &i : ans)
            cout << i;
        cout << endl;
    }
    return 0;
}