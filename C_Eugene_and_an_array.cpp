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
    vll v(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i], v[i] += v[i - 1];
    ll ans = 0;
    set<ll> st;
    st.insert(0);
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && !st.count(v[j + 1]))
        {
            j++;
            st.insert(v[j]);
        }
        ans += j - i;
        st.erase(v[i]);
    }
    cout << ans << endl;
    return 0;
}