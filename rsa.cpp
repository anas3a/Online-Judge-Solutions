#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int p = 3, q = 7;
    long long int n = p * q;
    long long int e = 2;
    long long int phi = (p - 1) * (q - 1);
    while (e < phi)
    {
        if (__gcd(e, phi) == 1)
            break;
        e++;
    }
    long long int k = 2;
    long long int d = (1 + (k * phi)) / e;
    long long int data;
    cin >> data;
    cout << "Original Data: " << data << endl;
    long long int c = (long long int)pow(data, e) % n;
    cout << "Encrypted Data: " << c << endl;
    double m = (long long int)pow(c, d) % n;
    cout << "Decrypted Data: " << m << endl;
    return 0;
}