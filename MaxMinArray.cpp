#include <iostream>
#include <vector>
using namespace std;

pair<int, int> MinMaxArray(vector<int> &v, int start, int end)
{
    int max, min;
    if (end == start)
    {
        return {v[start], v[end]};
    }
    else if (end - start == 1)
    {
        return (v[start] > v[end]) ? make_pair(v[start], v[end]) : make_pair(v[end], v[start]);
    }
    int mid = (start + end) / 2;
    pair<int, int> p1 = MinMaxArray(v, start, mid);
    pair<int, int> p2 = MinMaxArray(v, mid + 1, end);
    max = p1.first > p2.first ? p1.first : p2.first;
    min = p1.second < p2.second ? p1.second : p2.second;
    return {max, min};
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
    pair<int, int> p = MinMaxArray(v, 0, n - 1);
    cout << "maximum : " << p.first << endl;
    cout << "minimum : " << p.second << endl;
    return 0;
}
