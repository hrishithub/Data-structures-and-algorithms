/*
https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
Explanation with dry run and complexity analysis in pdf 
Previous approach was also optimal in terms of space and that was more intutuive this one you need to know beforhand
*/ 

/*
GAP Method (derived from shell sort) 
------------------------------------
First caluclate gap as ceil(len/2) then put left pointer on 0 right on left+gap 
then do comaprison and swapIfGreater and when right exceed len update gap = ceil(gap/2) keep doind it until gap=1
*/

#include <bits/stdc++.h>
using namespace std;


void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]) swap(arr1[ind1],arr2[ind2]);
} 

void merge(vector<int>& arr1, vector<int>& arr2, int n, int m) {

   int len=n+m; 

   int gap= (len/2) + (len%2); //calculate ceil as len/2 is by default floor so for even/2 complete division, odd/2 floor so 3/2 1.5 floor is 1 add 3%2=1 to it result in floor
   
   while(gap > 0){

   int left=0, right=left+gap; //declare left and right pointer
    
    while (right < len )
    {
        if(left<n && right<n){ //both left and right pointer are on arr1
        swapIfGreater(arr1,arr1,left,right);           
        } 
        else if(left<n && right>=n){ //left pointer is on arr1 and right pointer is on arr2
        swapIfGreater(arr1,arr2,left,right-n);    
        } 
        else{ //both left and right pointer are on arr2
        swapIfGreater(arr2,arr2,left-n,right-n);    
        } 
        left++,right++;
    } 
    
    if(gap==1) break;
    gap=(gap/2) + (gap%2);
   }
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
