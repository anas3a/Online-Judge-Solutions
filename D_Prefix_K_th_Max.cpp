#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using vvl = vector <vll >;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vpi = vector <pii >;
using vpl = vector <pll >;

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

    ordered_set st;
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        st.insert(-a);
        if (i >= k - 1)
        {
            cout << (*(st.find_by_order(k - 1))) * -1 << endl;
        }
    }
    return 0;
}