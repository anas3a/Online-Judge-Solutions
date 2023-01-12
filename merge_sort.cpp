#include <iostream>
using namespace std;

int a[100005];
void merge(int l, int m, int r)
{
    int left = m - l + 1;
    int right = r - m;
    int templeft[left], tempright[right];
    for (int i = 0; i < left; i++)
        templeft[i] = a[i + l];
    for (int i = 0; i < right; i++)
        tempright[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < left && j < right)
    {
        if (templeft[i] <= tempright[j])
            a[k++] = templeft[i++];
        else
            a[k++] = tempright[j++];
    }
    while (i < left)
        a[k++] = templeft[i++];
    while (j < right)
        a[k++] = tempright[j++];
}
void mergesort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}