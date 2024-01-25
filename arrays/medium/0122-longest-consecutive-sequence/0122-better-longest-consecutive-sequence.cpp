/*
https://leetcode.com/problems/longest-consecutive-sequence/
Given an unsorted array of integers , return the length of the longest consecutive elements sequence.
Brute: Using nested loop, inside a for loop for every el use while(linearserach(arr[i]+1)==true) cnt++ TC- O(N^2) SC-O(1)
Better: TC- O(NlogN + N) SC-O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveElements(vector<int>&arr) {
    sort(arr.begin(),arr.end()); //sort array- NloN
    int last_smaller=INT_MIN, cnt=0, largest=1;

    //find longest consecutive sequence
    for(int i=0;i<arr.size();i++){  //N
        if(arr[i]-1==last_smaller){ //New element in that sequence is found
            cnt++;
            last_smaller=arr[i];
        }
        else if(arr[i]==last_smaller) continue; //same element as previous so no need to consider it again
        else if(arr[i]-1!=last_smaller){ //means it's a start of new sequence
            cnt=1;
            last_smaller=arr[i];
        }

        largest=max(largest,cnt);

    }
    return largest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestConsecutiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}