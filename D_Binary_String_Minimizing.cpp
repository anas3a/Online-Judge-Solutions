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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        string s;
        cin >> n >> k >> s;
        priority_queue<ll, vll, greater<ll>> pq;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == '1')
                pq.push(i);
            else
            {
                if (pq.empty() || pq.top() > i)
                    continue;
                else
                {
                    ll z = pq.top();
                    pq.pop();
                    if (i - z <= k)
                    {
                        swap(s[z], s[i]);
                        k -= i - z;
                    }
                    else 
                    {
                        swap(s[i], s[i - k]);
                        break;
                    }
                    pq.push(i);
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}