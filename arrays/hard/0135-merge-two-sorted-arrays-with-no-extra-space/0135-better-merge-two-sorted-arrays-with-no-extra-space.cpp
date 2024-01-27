/*
https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
Explanation and complexity analysis in pdf
*/
#include <bits/stdc++.h>
using namespace std;
//1 3 5 7        0 2 6 8 9
void merge(vector<int>& arr1, vector<int>& arr2, int n, int m) {

    int left=n-1,right=0;

    //put elements in correct part
    while(left>=0 && right<m){      //O(min(n,m)
        if(arr1[left] > arr2[right]){
            swap(arr1[left],arr2[right]);
        }
        left--,right++;
    }

    //now sort them as elements are now in correct part
     sort(arr1.begin(),arr1.end()); //NlogN
     sort(arr2.begin(),arr2.end()); //MlogM


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
