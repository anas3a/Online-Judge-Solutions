#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    o_set<pii> st;
    int n, m;
    scanf("%d %d", &n, &m);
    vpi v(n + 1, {0, 0});
    st.insert({0, 0});
    while (m--)
    {
        int t, p;
        scanf("%d %d", &t, &p);
        if (v[t] != mp(0, 0))
        {
            auto it = st.upper_bound(v[t]);
            st.erase(it);
        }
        v[t].ff--;
        v[t].ss += p;
        st.insert(v[t]);
        printf("%d\n", st.order_of_key(v[1]) + 1);
    }
    return 0;
}