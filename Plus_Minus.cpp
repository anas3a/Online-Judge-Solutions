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

    ll n;
    cin >> n;
    vll arr(n);
    for (auto &i : arr)
        cin >> i;
    ll neg = 0, zero = 0, pos = 0;
    for (auto &i : arr)
    {
        if (i > 0)
            pos++;
        else if (i < 0)
            neg++;
        else
            zero++;
    }
    cout << fixed << setprecision(6) << pos / (double)n << endl;
    cout << fixed << setprecision(6) << neg / (double)n << endl;
    cout << fixed << setprecision(6) << zero / (double)n << endl;
    return 0;
}