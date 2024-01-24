/*
Brute: Using set as set contain unique el TC- O(N1logN1+N2logN2+K) where K is no. of unique el in wc K can be equal to N1+N2 when both array contain unique el 

Optimal: Using two pointer TC-O(N1+N2) 

Space Complexity: We are using an vector to return ans of size K
*/
#include <bits/stdc++.h>
using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    vector <int> unionArr;
    int i=0,j=0;

    while (i<n && j<m)
    {
        if(arr1[i]<=arr2[j]){
            //if pushing for first time then unionArr.back() will give an error as unionArr is empty
            if(unionArr.empty() || unionArr.back()!=arr1[i])
                unionArr.push_back(arr1[i]);
                i++; //wheather arr1[i] gets push or not(will not get push when unionArr.back()==arr1[i]) i will increment
            
        }
        else{
            if(unionArr.empty() || unionArr.back()!=arr2[j])
                unionArr.push_back(arr2[j]);
                j++; //wheather arr2[j] gets push or not(will not get push when unionArr.back()==arr2[j]) j will increment
            
        }
    
    }

    while(i<n){ //If there are elemnts left is arr1 to traverse
        if(unionArr.empty() || unionArr.back()!=arr1[i])
            unionArr.push_back(arr1[i]);
            i++; //wheather arr1[i] gets push or not(will not get push when unionArr.back()==arr1[i]) i will increment
        
    }

    while (j<m){ //If there are elemnts left is arr2 to traverse
        if(unionArr.empty() || unionArr.back()!=arr2[j])
            unionArr.push_back(arr2[j]);
            j++; //wheather arr2[j] gets push or not(will not get push when unionArr.back()==arr2[j]) j will increment
            
        
    }

    return unionArr;
}

int main()

{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " <<endl;
    for(auto & it: Union) cout<<it<<" ";
    
    return 0;
}
