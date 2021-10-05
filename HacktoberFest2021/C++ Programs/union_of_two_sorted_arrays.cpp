// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
     
    // Defining set container s
    set<int> s;
   
    // Inserting array elements in s
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
   
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements after union operation: " << s.size() << endl;
      cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " "; 
    // s will contain only distinct elements from array a and b
}
 
// Driver Code
int main()
{   int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
      cin>>b[i];
    getUnion(a, n, b, m);
}
 
