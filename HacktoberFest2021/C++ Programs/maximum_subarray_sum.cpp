// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;
 
int maxSubArraySum(int a[], int n)
{
    int  maxSum=INT_MIN;
    int currentSum=0;
        // Your code here
    for (int i = 0; i < n; i++){
        currentSum= currentSum + a[i];
        if (maxSum < currentSum)
           maxSum = currentSum ;
 
        if (currentSum < 0)
            currentSum = 0;
    }     
        return maxSum;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
