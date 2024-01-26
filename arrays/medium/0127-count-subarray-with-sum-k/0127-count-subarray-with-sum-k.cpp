/*
https://leetcode.com/problems/subarray-sum-equals-k/
Brute: Run nested for loops and check all possible subarrays for sum k TC-O(N^2) SC-O(1)
Optimal: This approach is optimal when array contains positives,negatives and zeroes
Time complexity - O(NlogN) where logN is time to search in map (we are doing it(searching in map) N times so overall NlogN),which will be 1 if we use unordered_map but it can also be N^2 (which is very rare) in WC
This is because ordered map are implemented using red black trees while unordered_map are implemented using hashing so wc occur when collision freq become high so requires time to resolve it
Space complexity- In wc O(N)
*/
#include <bits/stdc++.h>
using namespace std;
//See dry run below!
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    unordered_map<int,int> mpp;   //preSum --> count(how many times that preSum occurs) Explantaion below
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map. Initially preSum is 0 so count of 0 is 1
    for (int i = 0; i < n; i++) {
        preSum+=arr[i];

        int rem=preSum-k;
        //if there is someone from start whose prefix sum is X-K then will add count of that i.e. mpp[rem] in cnt
        //Because -> See dry run below!
        // if(mpp.find(rem)!=mpp.end()) i.e. if (exist in map) --> No need to put this check as if not exist in map then mpp[rem]=0 this will get add in cnt
       cnt+=mpp[rem];

        mpp[preSum]++;

    }
    return cnt;
}

int main()
{
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;

}
/*
    arr= [1,2,3,-3,1,1,1,4,2,-3] k=3

  9  | 9->1 | cnt=6+2=8  9-3=6 in map
  8  | 12->1|            12-3=9 not in map
  7  | 10->1|            10-3=7 not in map
  6  | 6->2 | cnt=4+2=6  6-3=3 in map     
  5  | 5->1 |            5-3=2 not in map
  4  | 4->1 | cnt=3+1=4  4-3=1 in map
  3  | 3->2 | cnt=2+1=3  3-3=0 in map
  2  | 6->1 | cnt=1+1=2  6-3=3 in map
  1  | 3->1 | cnt=0+1=1  3-3=0 in map  //this is why initially we are storing 0 -> 1 in map
  0  | 1->1 |            1-3=-2 not in map
     | 0->1 |
     |______|

 Why are we storing (pSum --> count) count of pSum occurance in map?
  At index 6 preSum is 6 so 6-3=3 means for 1 to be last el of subarray with sum k there needs someone from start with pSum 3 and there are two such pSum previously
  means there are two such subarrays with sum k whose last el is 1(at index 6) and they are [3,-3,1,1,1],[1,1,1]
 
 
 */


/*
    arr= [3, 1, 2, 4]   k=6
    | 10->1| cnt=1+1=2  10-6=4 in map add its cnt
    | 6->1 | cnt=0+1=1  6-6=0 in map add its cnt
    | 4->1 |            4-6=-2 not in map
    | 3->1 |            3-6=-3 not in map
    | 0->1 |
    |______|
*/


