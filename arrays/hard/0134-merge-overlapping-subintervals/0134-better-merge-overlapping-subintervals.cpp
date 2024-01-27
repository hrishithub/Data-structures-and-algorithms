/*
https://leetcode.com/problems/merge-intervals/
Brute: TC- O(2N+NlogN) SC- O(N) To return ans in case where given array doesn't contain any overlapping intervals then ans will contain all N elements
Optimal: Just kept on checking with previous intervals if lies in that interval then include or else form new interval  TC- O(NlogN) SC- O(N)
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array
    vector<vector<int>> ans;
    //sort the given intervals:
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

        int start=arr[i][0], end=arr[i][1];
        //(15,18) (16,17) already lies in interval so continue
        if(!ans.empty() && ans.back()[1]>=end) continue;
        for (int j = i+1; j < n; j++) {
            //(1,2) (2,4) --> (1,4)
            if(arr[j][0]<=end) end=max(end,arr[j][1]); //In case of overlapping only end updates
            else break; //(1,2) (4,5) not overlapping and now (4,5) will form new interval
        }
        ans.push_back({start,end});
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
