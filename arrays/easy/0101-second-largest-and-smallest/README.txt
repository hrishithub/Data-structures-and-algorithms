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


Optimal: 
𝐃𝐨 𝐢𝐭 𝐮𝐬𝐢𝐧𝐠 𝐬𝐢𝐧𝐠𝐥𝐞 𝐟𝐨𝐫 𝐥𝐨𝐨𝐩 (𝐅𝐢𝐫𝐬𝐭 𝐚𝐬𝐬𝐮𝐦𝐞 𝐞𝐥𝐞𝐦𝐞𝐧𝐭 𝐚𝐭 𝟎𝐭𝐡 𝐢𝐧𝐝𝐞𝐱 𝐚𝐬 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐚𝐧𝐝 𝐰𝐡𝐢𝐥𝐞 𝐥𝐨𝐨𝐩𝐢𝐧𝐠 𝐰𝐡𝐞𝐧 𝐲𝐨𝐮 𝐟𝐢𝐧𝐝 𝐞𝐥𝐞𝐦𝐞𝐧𝐭 𝐠𝐫𝐞𝐚𝐭𝐞𝐫 𝐭𝐡𝐚𝐧 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐭𝐡𝐞𝐧 𝐭𝐡𝐚𝐭 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐢𝐬 𝐧𝐨𝐰 𝐬𝐞𝐜𝐨𝐧𝐝𝐋𝐚𝐫𝐠𝐞𝐬𝐭 𝐚𝐧𝐝  𝐧𝐞𝐰𝐥𝐲 𝐟𝐨𝐮𝐧𝐝 𝐞𝐥𝐞𝐦𝐞𝐧𝐭 𝐢𝐬 𝐧𝐨𝐰 𝐥𝐚𝐫𝐠𝐞𝐬𝐭)
Time Complexity- O(N)
Space Complexity- o(1) 
 




