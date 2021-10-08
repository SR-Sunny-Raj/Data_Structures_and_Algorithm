#include<iostream>
using namespace std;


int majorityElement(int a[], int n){

    int count=1,res=0;
    for(int i=1;i<n;i++){
        if(a[res]==a[i]){
            count++;
        }
        else count--;
        if(count==0){
            count=1;
            res=i;
        }
    }    

count=0;
for(int i=0;i<n;i++){
    if(a[i]==a[res]){
count++;
    }
}

if(count>n/2){
    return a[res];
}
else return -1;

}



int main(){

int a[]={1,4,4,4,4,4,4,4,4,4,41,5};
int size=sizeof(a)/sizeof(a[0]);
cout<<"the majority element is :"<<endl;
 cout<<majorityElement(a,size)<<endl;;
    return 0;

}
