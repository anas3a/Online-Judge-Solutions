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

    int n;
    cin >> n;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    sort(all(v));
    int k;
    cin >> k;
    while (k--)
    {
        ll l, r;
        cin >> l >> r;
        ll left, right;
        ll low = -1, high = n;
        while (low + 1 < high)
        {
            ll mid = (low + high) / 2;
            if (v[mid] < l)
                low = mid;
            else
                high = mid;
        }
        left = low;
        low = -1, high = n;
        while (low + 1 < high)
        {
            ll mid = (low + high) / 2;
            if (v[mid] <= r)
                low = mid;
            else
                high = mid;
        }
        right = high;
        cout << right - left - 1 << " ";
    }
    cout << endl;
    return 0;
}
