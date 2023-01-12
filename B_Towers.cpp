#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using pii = pair <int, int>;
using pll = pair <long, long>;
using vpi = vector <pii >;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    set<pll > s;
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        s.insert({a, i});
    }
    ll cnt = 0;
    vpi v;
    while(k--)
    {
        pll x = *(s.begin()), y = *(--s.end());
        if (x.first == y.first)
        break;
        s.erase(*s.begin());
        s.erase(*(--s.end()));
        x.first += 1;
        y.first -= 1;
        s.insert(x);
        s.insert(y);
        v.pb(mp(y.second, x.second));
    }
   pll x = *(s.begin()), y = *(--s.end());
   cout << y.first - x.first << " " << (int) v.size() << endl;
   for (auto &i : v)
   cout << i.first << " "  << i.second << endl;
   return 0;
}
