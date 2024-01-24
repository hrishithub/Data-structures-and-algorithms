


#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int>& a) {
    int i=-1;

    //find first zero el and place i pointer there
    for (int j = 0; j < n; j++)
    {
       if(a[j]==0){
        i=j;
        break;
       }
    } 

    if(i==-1) return a; //In this case array contain all non zero elements

    for (int j = i+1; j < n; j++)
    {
       if(a[j]!=0){
        swap(a[i],a[j]);
        i++;
       }
    } 
    return a;
    
    
    
}


int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
     moveZeros(n, arr);
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
