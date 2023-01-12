#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, l, r, d;
    cin >> n >> m >> k;
    vll v(n + 3);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector <pair <int, pii > > vl(m + 3), vr(m + 3);
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r >> d;
        vl[i] = {l, {d, 1}};
        vr[i] = {r + 1, {d, 1}};
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        vl[x].second.second += 1;
        vr[y + 1].second.second += 1;
    }
    ll cnt = 0, sum = 0;
    vll ans1(n + 3, 0), ans2(n + 3, 0);
    for (int i = 1; i <= m; i++)
    {
        cnt += vl[i].second.second;
        cnt -= vr[i].second.second;
        ans1[vl[i].first] += vl[i].second.first * cnt;
        ans2[vr[i].first] += vr[i].second.first * cnt;
    }
    for (int i = 1; i <= n; i++)
    {
        sum += ans1[i];
        sum -= ans2[i];
        cout << v[i] + sum << " ";
    }
    cout << endl;
    return 0;
}
