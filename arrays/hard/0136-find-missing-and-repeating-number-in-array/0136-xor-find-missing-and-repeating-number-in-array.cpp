/*
Brute, Better, Optimal approach with complexity analysis explain in pdf

Time Complexity: O(N), where N = the size of the given array.
Reason: We are using only one loop running for N times. So, the time complexity will be O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/


//XOR method takes less time than math method 
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {

    int n=a.size();
    int xr=0;
    // Step 1: (xor of all array el)^(xor of numbers from 1 to N) =xr
    //X^Y= xr  where is X repeating and Y is missing number
    for (int i = 0; i <n ; i++) {
      xr=xr^a[i];
      xr=xr^(i+1);
    }

    //XOR of two numbers is bound to be different at a position
    //Step 2: Now find position of rightmost set bit in xr and generate a number in which rightmost set bit from given number is set rest all is zero like 1100 --> 0100 , 100-->100

    int bitNo=0;
    while(1){
        if((xr & (1<<bitNo)) !=0) break;
        bitNo++;
    }

    //bitNo now store position of rightmost set bit in xr
    int number= 1<<bitNo; //or xr & ~(xr-1)

    /*
   Trick to generate a number from given number(xr in this case) in which rightmost set bit from given number is set rest all is zero
   1100 --> 0100 , 100-->100
   number= xr & ~(xr-1)  or find bitNo as above and do 1<<bitNo
   */



    //Step 3: Now based on that segregate into zero club and one club
    //element which result in non-zero output on doing AND with that generated number are in one club rest all in zero club

    int zero=0, one=0;
    for (int i = 0; i < n; i++) {
       if((a[i] & (1<<bitNo)) !=0) one= one^a[i]; //one club
       else zero= zero^a[i];  //zero club
    }

    for (int i = 0; i < n; i++) {
        if(((i+1) & (1<<bitNo)) !=0) one= one^(i+1); //one club
        else zero= zero^(i+1); //zero club
    }

    //Now either of one or zero contain repeating number and other contain missing number
    int cnt=0;
    for (int i = 0; i < n; i++) {
        if(a[i]==one) cnt++;
    }

    if(cnt==2) return {one,zero};
    else return {zero,one};

}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

/*
   Trick to generate a number from given number in which rightmost set bit from given number is set rest all is zero
   1100 --> 0100 , 100-->100
   number= xr & ~(xr-1)
*/

