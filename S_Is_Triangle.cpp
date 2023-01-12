#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0] + v[1] <= v[2])
        cout << "Invalid" << endl;
    else
    {
        double s = (v[0] + v[1] + v[2]) / 2.0;
        cout << "Valid" << endl;
        cout << fixed << setprecision(6) << sqrt(s * (s - v[0]) * (s - v[1]) * (s - v[2])) << endl;
    }
    return 0;
}
