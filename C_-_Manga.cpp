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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vll v(n);
    map<ll, ll> m;
    set<ll> st;
    for (auto &i : v)
        cin >> i, m[i]++, st.insert(i);

    int cnt = 0;
    for (auto &i : m)
    {
        if (i.ss > 1)
            cnt += i.ss - 1;
    }
    ll ans = 0;
    for (int i = 1;; i++)
    {
        if (st.count(i))
            ans++;
        else
        {
            if (cnt >= 2)
                ans++, cnt -= 2;
            else
            {
                if (st.empty())
                    break;
                ll z = *st.rbegin();
                if (z > i)
                {
                    if (cnt)
                    {
                        ans++;
                        st.erase(z);
                        cnt = 0;
                    }
                    else
                    {
                        st.erase(z);
                        if (st.empty())
                            break;
                        ll zz = *st.rbegin();
                        if (zz > i)
                        {
                            ans++;
                            st.erase(zz);
                        }
                        else
                            break;
                    }
                }
                else
                    break;
            }
        }
    }
    cout << ans << nl;
    return 0;
}