#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000];
void Merge(int low, int high, int mid)
{
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
void MergeSort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, high, mid);
    }
}
void insertion_sort()
{
    int i, tmp, j;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = tmp;
    }
}
int part(int l, int h)
{
    int pi = a[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pi)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return (i + 1);
}
void quick(int l, int h)
{
    if (l < h)
    {
        int p = part(l, h);
        quick(l, p - 1);
        quick(p + 1, h);
    }
}
int main()
{
    clock_t t;
    n = 200000;

    double time_taken;
    for (int i = 0; i < n; i++)
        a[i] = rand();
    t = clock();
    insertion_sort();
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout << "Insertion sort: " << time_taken << endl;


    for (int i = 0; i < n; i++)
        a[i] = rand();
    t = clock();
    MergeSort(0, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout << "Merge sort: " << time_taken << endl;


    for (int i = 0; i < n; i++)
        a[i] = rand();
    t = clock();
    quick(0, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout << "Quick sort: " << time_taken << endl;
}

