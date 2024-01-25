/*
Brute: Generate all possible permutation and then do linear search to find given permutation and then return next permutation to it TC- O(N!+N) SC-O(N) req space to store generated permutations
Optimal: In C++ internal STL fn next_permutation(a.begin(),a.end()); But we cant just give that as soln in an interview
Implementation of C++ internal STL fn next_permutation(a.begin(),a.end())

*/
#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &A,int start,int end){
     if(start > end) return ;

     while(start <= end){
         int temp= A[start];
         A[start]=A[end];
         A[end]=temp;
         start++,end--;
     }

}

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.
    int breakPt=-1;

    //Step 1: Find break point
    for (int i=n-2;i>=0;i--) {
        if(A[i]<A[i+1]){
            breakPt=i;
            break;
        }
    }
    //if no break point then it's a last permutation so simply reverse array to get and return first permutation
    if(breakPt==-1){
        reverse(A,0,n-1);
        return A;
    }

    //Step 2: Find element which is just greater than a[breakPt] and swap it with a[breakPt]
    for(int i=n-1;i>breakPt;i--){
        if(A[i]>A[breakPt]){
            int temp= A[i];
            A[i]=A[breakPt];
            A[breakPt]=temp;
            break;
        }
    }

    //Step 3: Keep breakPt+1 to n-1 this part as small as possible
    reverse(A,breakPt+1,n-1);

    return A;

}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}
