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

    int rectangles, maxA = 0, maxB = 0, total = 0;

    cin >> rectangles;
    int row[rectangles], col[rectangles];

    for (int i = 0; i < rectangles; i++)
    {
        int j, k, overlap = 0;
        cin >> j >> k;
        row[i] = j;
        col[i] = k;

        if (i == 0)
        {
            maxA = row[i];
            maxB = col[i];
        }
        if (i > 0)
        {

            if (row[i] <= maxA && col[i] <= maxB)
            {
                overlap = row[i] * col[i];
            }
            else if (row[i] > maxA && col[i] <= maxB)
            {
                overlap = (row[i] - maxA) * col[i];
            }
            else if (row[i] <= maxA && col[i] > maxB)
            {
                overlap = row[i] * (col[i] - maxB);
            }
            else if (row[i] > maxA && col[i] > maxB)
            {
                overlap = (row[i] - maxA) * (col[i] - maxB);
            }
            else if (row[i] > maxA && col[i] <= maxB)
            {
                overlap = (row[i] - maxA) * col[i];
            }
            else if (row[i] <= maxA && col[i] > maxB)
            {
                overlap = row[i] * (col[i] - maxB);
            }
        }

        total += (row[i] * col[i]) - overlap;

        if (k >= maxB)
        {
            maxA = k;
        }
        if (j >= maxA)
        {
            maxA = j;
        }
    }
    cout << total << endl;
    return 0;
}