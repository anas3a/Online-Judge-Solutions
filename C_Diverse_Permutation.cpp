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

    int n, k, x = 1;
    ;
    cin >> n >> k;
    int a = 1, b = n, f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (k == 1)
        {
            if (f)
            {
                cout << a << " ";
                a++;
            }
            else
            {
                cout << b << " ";
                b--;
            }
        }
        else
        {
            if (f)
            {
                cout << a << " ";
                a++;
            }
            else
            {
                cout << b << " ";
                b--;
            }
            f = 1 - f;
            k--;
        }
    }
    cout << endl;
    return 0;
}
