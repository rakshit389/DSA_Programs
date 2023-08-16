#include <iostream>
using namespace std;

int partition(int arr[5] , int l , int n )
{
    int pivot = arr[n] ;
    
    int count = l-1 ;
    
    for( int j = l ; j <= n-1 ; j++ )
    {
        if( arr[j] < pivot )
        {
            count++;
            swap( arr[count] , arr[j] );
        }
    }
    
    swap(arr[count+1] , arr[n] );
    return count+1;
}
void sort( int arr[5] , int l , int n )
{
    if(l<n)
    {
         int pi = partition(arr,l,n);
         sort(arr,l,pi-1);
         sort(arr,pi+1,n);
    }
}
int main()
{
    int arr[5] = {5,4,3,2,1} ;
    sort(arr,0,4);
    
    for( int i = 0 ; i < 5 ; i++ )
    {
        cout<<arr[i]<<" ";
    }
}
