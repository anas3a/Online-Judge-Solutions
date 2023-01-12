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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v(n);
        for (auto &i : v)
        cin >> i;
        ll cnt = 0;
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            if(v[i])
            f = true;
            if (f && v[i] == 0)
            cnt++;
        }
        for (int i = n -1; i >= 0; i--)
        {
            if (v[i])
            break;
            cnt--;
        }
        cout << cnt << endl;
    }
    return 0;
}
