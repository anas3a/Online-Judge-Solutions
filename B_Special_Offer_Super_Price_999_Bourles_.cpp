#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

    string p;
    ll d;
    cin >> p >> d;
    ll j = 1;
    for (int i = sz(p) - 1; i > 0; i--, j *= 10)
    {
        if (p[i] == '9')
            continue;
        if (d < (p[i] - '0' + 1) * j)
            break;
        d -= (p[i] - '0' + 1) * j;
        p[i] = '9';
        if (p[i - 1] != '0')
            p[i - 1] -= 1;
        else
        {
            int x = i - 1;
            while (p[x] == '0')
            {
                p[x] = '9';
                x--;
            }
            p[x] -= 1;
        }
    }
    bool f = true;
    for (int i = 0; i < sz(p); i++)
    {
        if (f && p[i] == '0')
            continue;
        cout << p[i];
        f = false;
    }
    cout << endl;
    return 0;
}
