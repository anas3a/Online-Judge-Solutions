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

    vll scores;
    vector<int> ans(2, 0);
    int mn = scores[0], mx = scores[0];
    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i] < mn)
            mn = scores[i], ans[0]++;
        if (scores[i] > mx)
            mx = scores[i], ans[1]++;
    }
    return ans;
    return 0;
}