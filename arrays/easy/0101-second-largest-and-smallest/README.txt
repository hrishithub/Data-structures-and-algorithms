Maximum size of an array that we can declare is - 
Globally : 10e7
Locally/Inside main function : 10e6

Problem Statement: 
Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.
https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse 

Brute Force: Sort the array and return element at n-2th index(works if array contains unique elements) or else
             arr.sort(arr.begin(),arr.end());
             largest = arr[n-1]
             for(i=n-2;i>=0;i--){
              if(arr[i]!= largest){ 
                secondLargest= arr[i];
                break; }
             } 
             return secondLargest;  
 
Time Complexity- O(NlogN + N)
Space Complexity- o(1) 


Better: First run for loop to find largest and then another for loop to find secondLargest 
Time Complexity- O(2N)
Space Complexity- o(1) 


Optimal: Do it using single for loop (First assume element at 0th index as largest and while looping when you find element greater than largest then that largest is now secondLargest and  newly found element is now largest) 
Time Complexity- O(N)
Space Complexity- o(1) 
 




