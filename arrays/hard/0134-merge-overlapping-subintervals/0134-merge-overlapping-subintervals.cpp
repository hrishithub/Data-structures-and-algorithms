/*
https://leetcode.com/problems/merge-intervals/
Brute: TC- O(2N) SC- O(N) To return ans in case where given array doesn't contain any overlapping intervals then ans will contain all N elements
Optimal: Just kept on checking with previous intervals if lies in that interval then include or else form new interval  TC- O(N) SC- O(N)
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array
    vector<vector<int>> ans;
    //sort the given intervals:
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

        //formation of new interval will happen when its either first array element or non overlapping element)
        if(ans.empty() || arr[i][0] > ans.back()[1]) ans.push_back(arr[i]);
        //if it comes to else block means it for sure overlapping interval (overlapping with arr.back()) no need to check
        else{ //In case of overlapping only end updates
             // (1,3) (2,6) --> (1,6) 
            // (15,18) (16,17) --> (15,18)
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
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
