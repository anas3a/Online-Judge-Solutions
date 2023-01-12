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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<pll, vpl, greater<pll>> pq;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            pq.push({x, y});
        }
        int d, m;
        cin >> d >> m;
        int sec = 0;
        bool alive = true;
        while (!pq.empty())
        {
            pll tmp = pq.top();
            pq.pop();
            if (tmp.first <= sec * d)
            {
                alive = false;
                break;
            }
            tmp.second -= m;
            sec++;
            if (tmp.second <= 0)
                continue;
            tmp.first += m;
            pq.push(tmp);
        }
        if (alive)
            cout << "Wakanda Forever" << endl;
        else
            cout << "DIED" << endl;
    }
    return 0;
}