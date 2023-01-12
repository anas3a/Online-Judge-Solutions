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
        ll n, m, k;
        cin >> n >> m >> k;
        ll z = n / m, x = n % m;
        priority_queue<pll, vpl, greater<pll>> pq;
        for (int i = 1; i <= n; i++)
            pq.push({0, i});
        while (k--)
        {
            ll cx = n;
            for (int i = 0, j = 0; i < cx; j++)
            {
                ll a = z;
                if (j < x)
                    a++;
                cout << a << " ";
                for (int l = 0; l < a; l++)
                {
                    pll px = pq.top();
                    pq.pop();
                    cout << px.ss << " ";
                    i++;
                    if (a > z)
                        px.ff += 2;
                    else
                        px.ff += 1;
                    pq.push(px);
                }
                cout << endl;
            }
        }
        if (t)
            cout << endl;
    }
    return 0;
}