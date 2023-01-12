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

struct stck
{
    vector<ll> v, vg = {0};
    void push(ll x)
    {
        v.push_back(x);
        vg.push_back(__gcd(x, vg.back()));
    }
    ll pop()
    {
        ll res = v.back();
        v.pop_back();
        vg.pop_back();
        return res;
    }
    bool empty()
    {
        return v.empty();
    }
    ll gcd()
    {
        return vg.back();
    }
};
struct stck s1, s2;
void remove()
{
    if (s1.empty())
    {
        while (!s2.empty())
            s1.push(s2.pop());
    }
    s1.pop();
}

bool good()
{
    if (__gcd(s1.gcd(), s2.gcd()) == 1)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    ll l = 0, ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        s2.push(v[i]);
        while (good())
        {
            remove();
            ans = min(ans, i - l + 1);
            l++;
        }
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}
