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

    int n, a, b, c = 1;
    cin >> n >> a >> b;
    if (!b && a && a == n - 1)
        cout << -1 << endl;
    else
    {
        cout << c << " ";
        for (int i = 2; i <= n; i++)
        {
            if (b)
            {
                c *= 2;
                cout << c << " ";
                b--;
            }
            else if (a)
            {
                if (i == 2 && b == 0)
                    c--, a++;
                c++;
                cout << c << " ";
                a--;
            }
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}