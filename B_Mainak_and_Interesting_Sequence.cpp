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
        ll n, m;
        cin >> n >> m;
        bool flag = true;
        if (m < n)
            flag = false;
        if (!(n & 1) && (m & 1))
            flag = false;
        if (!flag)
            cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            if (n & 1)
            {
                cout << m - (n - 1) << " ";
                for (int i = 0; i < n - 1; i++)
                    cout << "1 ";
                cout << endl;
            }
            else
            {
                cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << " ";
                for (int i = 0; i < n - 2; i++)
                    cout << "1 ";
                cout << endl;
            }
        }
    }
    return 0;
}