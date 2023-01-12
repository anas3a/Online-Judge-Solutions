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

    string s;
    while (getline(cin, s))
    {
        s.erase(remove(s.begin(), s.end(), '\r'), s.end());
        s.erase(remove(s.begin(), s.end(), '\t'), s.end());
        s.erase(remove(s.begin(), s.end(), '\n'), s.end());
        if (s[0] == 'S')
        {
            int n = s.size();
            if (s.back() == ')')
                n -= 2;
            bool flag = false;
            for (int i = 4; i < n; i++)
            {
                if (flag && s[i] >= 'A' && s[i] <= 'Z')
                {
                    cout << ' ';
                }
                s[i] = tolower(s[i]);
                flag = true;
                cout << s[i];
            }
        }
        else
        {
            if (s[2] == 'C')
                s[4] = toupper(s[4]);
            bool flag = false;
            for (int i = 4; i < s.size(); i++)
            {
                if (flag)
                    s[i] = toupper(s[i]), flag = false;
                if (s[i] == ' ')
                    flag = true;
                else
                    cout << s[i];
            }
            if (s[2] == 'M')
                cout << "()";
        }
        cout << endl;
    }
    return 0;
}