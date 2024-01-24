#include <iostream>
using namespace std;
// Function to Reverse the array
void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to Rotate k elements to left
void Rotatetoleft(int arr[], int n, int k)
{
    // Reverse first k elements
    Reverse(arr, 0, k - 1);
    // Reverse last n-k elements
    Reverse(arr, k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
} 

// Function to Rotate k elements to right 
void Rotatetoright(int arr[], int n, int k)
{
    // Reverse last k elements
    Reverse(arr, n-k, n - 1);
    // Reverse first n-k elements
    Reverse(arr, 0, n-k-1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
} 

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 9;
    k%=n;
    Rotatetoleft(arr1, n, k);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    Rotatetoright(arr2, n, k);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}