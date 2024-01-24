/*
Brute: Using visited array TC- O(N1+N2) SC- O(min(N1,N2)) space taken by visited array
Optimal: Two pointer approach 

Space Complexity: We are using an vector to return ans of size K as mentioned in question so we may not consider that as extra space
*/
#include <bits/stdc++.h>
using namespace std;

vector < int > Findintersection(int arr1[], int arr2[], int n, int m) {
    vector <int> intersectionArr;
    int i=0,j=0;
    
    while (i<n && j<m)
    {
        if(arr1[i]<arr2[j]) i++;
        else if(arr2[j]<arr1[i]) j++;
        else {//when both equal
        intersectionArr.push_back(arr1[i]);
        i++,j++;
        }
    } 
    return intersectionArr;
}

int main()

{
    int n = 11, m = 8;
    int arr1[] = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 3, 4, 4, 5, 11, 12};
    vector < int > intersection = Findintersection(arr1, arr2, n, m);
    cout << "intersection of arr1 and arr2 is  " <<endl;
    for(auto & it: intersection) cout<<it<<" ";
    
    return 0;
}
