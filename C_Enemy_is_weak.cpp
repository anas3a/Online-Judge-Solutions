#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

    o_set<int> st;
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        st.insert(a);
        ll x = st.order_of_key(a);
        dg(x);
        if (x >= 2)
            ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}