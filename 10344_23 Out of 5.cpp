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

vll v;
vector<bool> vx;
bool fl;
void f(ll sum, ll cnt, ll first)
{
    if (cnt == 5)
    {
        if (sum == 23)
            fl = true;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (vx[i])
        {
            vx[i] = false;
            if (!first)
                f(v[i], cnt + 1, 1);
            else
            {
                f(sum + v[i], cnt + 1, 1);
                f(sum - v[i], cnt + 1, 1);
                f(sum * v[i], cnt + 1, 1);
            }
            vx[i] = true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        v.assign(5, 0);
        vx.assign(5, true);
        for (auto &i : v)
            cin >> i;
        if (v[0] == 0)
            break;
        fl = false;
        f(0, 0, 0);
        if (fl)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
