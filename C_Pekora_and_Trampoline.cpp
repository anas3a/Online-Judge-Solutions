#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " = ";
        for (int j = 1; j <= 10; j++)
            cout << (i & j) << " ";
        cout << endl;
    }
    return 0;
}
