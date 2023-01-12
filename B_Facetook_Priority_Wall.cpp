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

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.ss == b.ss)
        return a.ff < b.ff;
    return a.ss > b.ss;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    cin.ignore();
    map<string, int> m;
    while (n--)
    {
        string sx, s1, s2;
        getline(cin, sx);
        {
            int j = 0;
            for (int i = 0; i < sz(sx); i++, j++)
            {
                if (sx[i] == ' ')
                    break;
                s1 += sx[i];
            }
            j++;
            for (int i = sz(sx) - 8; i >= 0; i--)
            {
                if (sx[i] == ' ')
                    break;
                s2 += sx[i];
            }
            reverse(all(s2));
            if (s1 != s && s2 != s)
            {
                m[s1] += 0;
                m[s2] += 0;
            }
            else
            {
                if (s1 != s)
                    swap(s1, s2);
                if (sx[j] == 'p')
                    m[s2] += 15;
                else if (sx[j] == 'c')
                    m[s2] += 10;
                else if (sx[j] == 'l')
                    m[s2] += 5;
            }
        }
    }
    vector<pair<string, int>> v;
    for (auto &i : m)
        v.pb({i.ff, i.ss});
    sort(all(v), comp);
    for (auto &i : v)
        cout << i.ff << endl;
    return 0;
}
