#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        for (auto &i : s)
            cin >> i;
        char a = s[0][1], b = s[1][0];
        char x = s[n - 2][n - 1], y = s[n - 1][n - 2];
        vi v;
        if (a == b)
        {
            if (a == x)
            {
                v.pb(n - 1);
                v.pb(n);
            }
            if (a == y)
            {
                v.pb(n);
                v.pb(n - 1);
            }
        }
        else if (a != b)
        {
            if (x != y)
            {
                if (x == a)
                {
                    v.pb(1);
                    v.pb(2);
                    v.pb(n);
                    v.pb(n - 1);
                }
                else
                {
                    v.pb(1);
                    v.pb(2);
                    v.pb(n - 1);
                    v.pb(n);
                }
            }
            else
            {
                if (x == a)
                {
                    v.pb(1);
                    v.pb(2);
                }
                else
                {
                    v.pb(2);
                    v.pb(1);
                }
            }
        }
        cout << v.size() / 2 << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
            if (i & 1)
                cout << endl;
        }
    }
    return 0;
}
