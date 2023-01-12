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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll cnt = 0, n;
    ll mn = LLONG_MAX, mx = LLONG_MIN;

    bool flag = true;
    for (int i = 0, l = 2; i < 25; i++)
    {
        cout << "? 1 " << l << endl;
        cin >> n;
        if (n == -1 && flag)
        {
            l--;
            flag = false;
        }
        mn = min(mn, n);
        mx = max(mx, n);
        cout << "? " << l << " " << 1 << endl;
        cin >> n;
        if (n == -1 && flag)
        {
            l--;
            flag = false;
        }
        if (flag)
            mn = min(mn, n);
        mx = max(mx, n);
        if (flag)
            l++;
    }
    cout << "! " << mn + mx << endl;
    return 0;
}