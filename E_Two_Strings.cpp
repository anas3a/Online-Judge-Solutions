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

    int n;
    string a, b;
    cin >> n >> a >> b;
    if (a == b)
        cout << "NO" << endl;
    else if (a > b)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] > b[i])
            {
                cout << "YES" << endl;
                cout << 1 << " " << (i + 1) << endl;
                return 0;
            }
        }
        if (a[0] > b[0] && a[1] == b[1])
        {
            cout << "YES" << endl;
            cout << 1 << " " << 2 << endl;
            return 0;
        }
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                cout << "YES" << endl;
                cout << 1 << " " << (i + 1) << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}
