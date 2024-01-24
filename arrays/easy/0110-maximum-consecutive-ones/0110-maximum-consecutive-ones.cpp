/*
https://leetcode.com/problems/max-consecutive-ones/
TC- O(N) SC- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector < int > & nums) {
    int maxCount=0,count=0;
    for(int num : nums) {
        if(num==1){
            count++;
            maxCount=max(maxCount,count);
        }
        else count=0;
    }

    return maxCount;

}


int main() {
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    int ans = findMaxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans;
    return 0;
}