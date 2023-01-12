#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        for (int i = 0; i < k - 3; i++)
        {
            cout << 1 << " ";
            n--;
        }
        if(n & 1)
        {
            ll z = n / 2;
            cout << z << " " << z << " " << 1 << endl;
        }
        else if (n == 4)
        {
            cout << "2 1 1" << endl;
        }
        else
        {
            ll z = n / 2;
            if (z & 1)
            {
                cout << z - 1 << " " << z - 1 << " " << 2 << endl;
            }
            else 
            {
                cout << z  << " " << z / 2 << " " << z / 2 << endl;
            }
        }
    }
    return 0;
}
