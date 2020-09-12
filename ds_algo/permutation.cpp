#include <bits/stdc++.h>
using namespace std;
void printarr(int a[],int n)
{
  for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
  cout<<"\n";
}
void heap_permutation(int a[],int siz,int n)
{
  if(siz==1)
  {
    printarr(a,n);
    return ;
  }
  else
  {
    for(int i=0;i<siz;i++)
    {
      heap_permutation(a,siz-1,n);
      if(siz%2==0)
      swap(a[0],a[siz-1]);
      else
      swap(a[i],a[siz-1]);
    }
  }
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  //heap_permutation(a,n,n);

  
  do
  {
    printarr(a,n);
  }while(next_permutation(a,a+n));
}
