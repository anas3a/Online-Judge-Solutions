#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int sum, n;
int arr[101];
int dp[60000];
int f(int i, int sum_x)
{
    if (i == n)
        return abs(sum_x - (sum - sum_x));
    if (dp[sum_x] != -1)
        return dp[sum_x];
    int a = f(i + 1, sum_x + arr[i]);
    int b = f(i + 1, sum_x);
    return dp[sum_x] = min(a, b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> arr[i], sum += arr[i];
        cout << f(0, 0) << endl;
    }
}