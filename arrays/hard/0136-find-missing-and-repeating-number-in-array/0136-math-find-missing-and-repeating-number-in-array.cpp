/*
Brute, Better, Optimal approach with complexity analysis explain in pdf

Time Complexity: O(N), where N = the size of the given array.
Reason: We are using only one loop running for N times. So, the time complexity will be O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n: Where Sn -> sum of first N natural numbers and S2n is sum of square of first N natural numbers
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S=0; //sum of all array elements
    long long S2=0; //sum of square of all array elements
    for(int i=0; i<n; i++){
        S=S+a[i];
        S2=S2+(a[i]*a[i]);
    }

    // val1= X-Y  where is X repeating and Y is missing number
    int val1 = S-SN;  //Equation 1

    //val2 = X^2-Y^2
    int val2 = S2-S2N;

    //X^2-Y^2 = val2
    // (X-Y) (X+Y) = val2
    //val2/X-Y = X+Y
    //val2/val1= X+Y
    //let store val2/val1 in val2 only

    // so now Val2 = X+Y and Val1=X-Y
    val2=val2/val1;  //Equation 2

    //Adding equation 1 and 2
    // Val1+Val2 = 2X
    int X= (val1+val2)/2;

    //from eqn 1
    //Y= X-Val1
    int Y= X-val1;

    return {X,Y};
    
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
