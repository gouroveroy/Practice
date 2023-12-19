//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
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
    
    int findSum(int A[], int N)
    {
        // code here.
        vector<int> v(N);
        for (int i = 0; i < N; i++)
        {
            v[i] = A[i];
        }
        pair<int, int> p = MinMaxArray(v, 0, N);
        return p.first + p.second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        int ans = ob.findSum(arr, n);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends