/* 
Return majority element(Element that appears more than n/3 times)
Brute: Use nested for loop TC- O(N^2) SC- O(1)
Better: Use hashing (element with freq >n/3 is maj el) TC- If ordered map use O(NlogN) else O(N) SC-O(N)
Optimal: Moore's voting algorithm (If there exist a maj el then it won't get fully cancelled by others)

==> In an array at max two such elements >n/3 can exist (0,1,2)
*/ 
#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    vector<int> ans;
    //size of the given array:
    int n = v.size();
    int cnt1=0,el1=INT_MIN, cnt2=0, el2=INT_MIN;

    for (int i = 0; i < n; i++) {

        if(cnt1==0 && v[i]!=el2) {
            el1=v[i];              //whenever cnt1 gets zero element at ith index is el1
            cnt1++;
        }
        else if(cnt2==0 && v[i]!=el1) {
            el2=v[i];              //whenever cnt2 gets zero element at ith index is el2
            cnt2++;
        }
        else if(v[i]==el1) cnt1++;  //if element at ith index is equal el1 then increment cnt1
        else if(v[i]==el2) cnt2++;  //if element at ith index is equal el2 then increment cnt2
        else cnt1--,cnt2--;         //if element at ith index is not equal el1 and el2 then decrement cnt1 and cnt2

    }


    //Now if there exist a maj el then its element stored in el1 and el2
    //this step will not execute if question clearly states that there always will exist maj el


    int checkcnt1=0,checkcnt2=0;
    for (int i = 0; i < n; i++){
        if(v[i]==el1) checkcnt1++;
        else if(v[i]==el2) checkcnt2++;
    }
    int mm= (int) ((n/3) + 1);

    if(checkcnt1>=mm) ans.push_back(el1);
    if(checkcnt2>=mm) ans.push_back(el2);

    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    vector<int> arr = { 1,1,1,2,2,2};
    vector<int> ans = majorityElement(arr);
    cout << "The majority element is: " << ans[0] <<" "<<ans[1]<< endl;
    return 0;
}
