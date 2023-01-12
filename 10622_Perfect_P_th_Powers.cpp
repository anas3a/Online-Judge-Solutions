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

    while (true)
    {
        ll x;
        cin >> x;
        if (!x)
            break;
        bool f = true;
        ll z = x;
        x = abs(x);
        for (ll i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                ll sum = 1, cnt = 0;
                while (sum < x)
                {
                    sum *= i;
                    cnt++;
                }
                if (sum == x)
                {
                    if (z < 0 && cnt % 2 == 0)
                        continue;
                    f = false;
                    cout << cnt << endl;
                    break;
                }
            }
        }
        if (f)
            cout << 1 << endl;
    }
    return 0;
}
