/*
 Find combination of a number
 Brute: Write factorial fn (for n! it runs loop n times) TC-O(N!) and use that fn to find n!,r!,(n-r)!
 Optimal:
 Trick: Instead of  nCr = n!/r!*(n-r)!
        10c3 = (10*9*8)/(3*2*1) i.e. (10*9*8)/(1*2*3) i.e (10/1)*(9/2)*(8/3)
Time complexity: O(r)
 */
#include<bits/stdc++.h>
using namespace std;

int findCombination(int n, int r) {
    int res=1;
   // (10/1)*(9/2)*(8/3) --> 3 times i.e r times so for loop is running r times
    for (int i = 0; i < r; i++) {
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

int main(){
    int n=10,r=3;
   cout<<n<<"c"<<r<<" is "<< findCombination(n,r);
}


