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

    int n, m, k;
    cin >> n >> m >> k;
    int x = 1, y = 1, z = n * m;
    bool f = false;
    for (int i = 1; i <= k; i++)
    {
        if (i < k)
        {
            z -= 2;
            cout << 2 << " ";
            cout << x << " " << y << " ";
            if ((y == m || y == 1) && f)
                x++, f = false;
            else
            {
                if (x & 1)
                    y++;
                else
                    y--;
                f = true;
            }
            cout << x << " " << y << " ";
            if ((y == m || y == 1) && f)
                x++, f = false;
            else
            {
                if (x & 1)
                    y++;
                else
                    y--;
                f = true;
            }
            cout << endl;
        }
        else
        {
            cout << z << " ";
            while (z > 0)
            {
                z--;
                cout << x << " " << y << " ";
                if ((y == m || y == 1) && f)
                    x++, f = false;
                else
                {
                    if (x & 1)
                        y++;
                    else
                        y--;
                    f = true;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
