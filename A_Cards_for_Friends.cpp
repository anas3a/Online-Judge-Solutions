#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll cnt = 1, w, h, n;
        cin >> w >> h >> n;
        while (true)
        {
            if ((w & 1) && (h & 1))
            break;
            if (w % 2 == 0)
            {
                w /= 2;
                cnt*= 2;
            }
            else if (h % 2 == 0)
            {
                h /= 2;
                cnt *= 2;
            }
            if (cnt == n)
            break;
        }
        if (cnt >= n)
        cout << "YES" << endl;
        else 
        cout << "NO" << endl;
    }  
}
