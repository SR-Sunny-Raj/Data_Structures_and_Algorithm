#include<iostream>
#include<algorithm>

/*  Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1] 
*/

//time complexity O(logn)
using namespace std;
int firstOccur(int arr[],int n,int target){
 int lo=0;
 int hi=n-1;
 int mid=0;
 int result=-1;
 while(lo<=hi){
     mid=lo+(hi-lo)/n;
     if(arr[mid]==target){
        result=mid;
        hi=mid-1; 
     }
     else if(arr[mid]<target)
       lo=mid+1;
    else
    hi=mid-1;
 }
 return result;
}
int lastOccur(int arr[],int n,int target){
 int lo=0;
 int hi=n-1;
 int mid=0;
 int result=-1;
 while(lo<=hi){
     mid=lo+(hi-lo)/n;
     if(arr[mid]==target){
        result=mid;
        lo=mid+1; 
     }
     else if(arr[mid]<target)
       lo=mid+1;
    else
    hi=mid-1;
 }
 return result;

}
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int target;
    cout<<"Enter the target value"<<endl;
    cin>>target;
    int first =firstOccur(arr,n,target);
    int last=lastOccur(arr,n,target);
    cout<<first<<" "<<last<<endl;
}