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
    vll v(n);
    for (auto &i : v)
        cin >> i;
    stack<pll> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().ff >= v[i])
            st.pop();
        if (st.empty())
            cout << 0 << " ";
        else
            cout << st.top().ss + 1 << " ";
        st.push({v[i], i});
    }
    cout << endl;
    return 0;
}
