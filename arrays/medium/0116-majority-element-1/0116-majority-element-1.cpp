/*
Brute: Use nested for loop TC- O(N) SC- O(1)
Better: Use hashing (element with freq >n/2 is maj el) TC- If ordered map use O(NlogN) SC-O(N)
Optimal: Moore's voting algorithm (If there exist a maj el then it won't get fully cancelled by others)
*/
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt=0,el;

    for (int i = 0; i < n; i++) {

        if(cnt==0) {
            el=v[i];              //whenever cnt gets zero element at ith index is el
            cnt++;
        }
        else if(v[i]!=el) cnt--;  //if element at ith index is not equal el then decrement cnt
        else cnt++;              //if element at ith index is equal el then increment cnt

    }


    //Now if there exist a maj el then its element stored in el
    //this step will not execute if question clearly states that there always will exist maj el


    int checkCnt=0;
    for (int i = 0; i < n; i++) if(v[i]==el) checkCnt++;
    if(checkCnt > n/2) return el;
    else return -1;




}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
