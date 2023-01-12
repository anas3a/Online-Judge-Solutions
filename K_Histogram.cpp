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

    int tx, cs = 0;
    cin >> tx;
    while (tx--)
    {
        int n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        vll left_min(n);
        stack<ll> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && v[st.top()] >= v[i])
                st.pop();
            if (st.empty())
                left_min[i] = 0;
            else
                left_min[i] = st.top() + 1;
            st.push(i);
        }
        ll ans = 0;
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            int left = left_min[i], right;
            while (!st.empty() && v[st.top()] >= v[i])
                st.pop();
            if (st.empty())
                right = n - 1;
            else
                right = st.top() - 1;
            st.push(i);
            ans = max(ans, v[i] * (right - left + 1));
        }
        cout << "Case " << ++cs << ": " << ans << '\n';
    }
    return 0;
}