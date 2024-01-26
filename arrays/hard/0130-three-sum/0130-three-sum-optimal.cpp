/*
Optimal: Will use two pointer approach that we used in two sum problem. We need to do improvisation in terms of space as better approach was taking  O(2 * no. of the unique triplets) + O(N)
Time Complexity: O(NlogN)+O(N2), where N = size of the array.
Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 
Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;

    //array need to be in sorted manner to apply this approach as we've seen in two sum problem cause that's how we are moving pointers
    sort(arr.begin(),arr.end());

    for (int i = 0; i < n; i++) {

        if(i>0 && arr[i]==arr[i-1]) continue; //for i==0 we can't check arr[i]==arr[i-1]
        int j=i+1, k=n-1;

        while(j<k){

            long long sum= arr[i]+arr[j]+arr[k];

            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++,k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
        }


    }
    //now set contains all unique triplets now put them in vector<vector<int>> ans ans return ans
    //vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
