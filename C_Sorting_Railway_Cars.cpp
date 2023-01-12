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
    vll v(n), pos(n + 3);
    for (int i = 0; i < n; i++)
        cin >> v[i], pos[v[i]] = i;
    int mx = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i] > pos[i - 1])
            mx++;
        else
            mx = 1;
        ans = max(mx, ans);
    }
    cout << n - ans << endl;
    return 0;
}