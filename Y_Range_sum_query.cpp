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

int mx = 1e5 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    int arr[mx];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    arr[0] = 0;
    for (int i = 1; i <= n; i++)
        arr[i] = arr[i] + arr[i - 1];

    while(m--)
    {
        int l, r;
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << endl;
    }
    return 0;
}

