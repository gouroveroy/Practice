#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    int totalCount = 0;
    int i = start, j = mid + 1;
    int k = start;
    for (; i <= mid && j <= end;)
    {
        if (v[i] > v[j])
        {
            temp[k++] = v[j++];
            totalCount += mid - i + 1;
            continue;
        }
        temp[k++] = v[i++];
    }
    while (i <= mid)
    {
        temp[k++] = v[i++];
    }
    while (j <= end)
    {
        temp[k++] = v[j++];
    }
    for (int i = start; i <= end; i++)
    {
        v[i] = temp[i];
    }
    return totalCount;
}

int mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if (end <= start)
    {
        return 0;
    }
    int mid = (start + end) / 2;
    int countLeft = mergeSort(v, temp, start, mid);
    int countRight = mergeSort(v, temp, mid + 1, end);
    int totalCount = countLeft + countRight;
    totalCount += merge(v, temp, start, mid, end);
    return totalCount;
}

int CountInversion(vector<int> &v, int n)
{
    vector<int> temp(n);
    return mergeSort(v, temp, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int count = CountInversion(v, n);
    cout << count << endl;
    // for(auto &i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    return 0;
}
