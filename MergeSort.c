#include <iostream>
using namespace std;

void merge_sort( int arr[5] , int l , int m , int n )
{
    int n1 = m-l+1 ;
    int n2 = n-m ;
    
    int *arr1 = new int[n1] ;
    int *arr2 = new int[n2] ;
    
    for( int i = 0 ; i < n1 ; i++ )
    {
        arr1[i] = arr[l+i];
    }
    for( int j = 0 ; j < n2 ; j++ )
    {
        arr2[j] = arr[m+1+j] ;
    }
    
    int i = 0 , j = 0 , k = l ; 
    
    while( i < n1 && j < n2 )
    {
        if( arr1[i] <= arr2[j] )
        {
            arr[k] = arr1[i] ;
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j] ;
            j++;
            k++;
        }
        
    }
     while( i < n1 )
        {
            arr[k] = arr1[i] ;
            i++;
            k++;
        }
        
        while( j < n2 )
        {
            arr[k] = arr2[j] ;
            j++;
            k++;
        }
}
void sort( int arr[5] , int l , int n )
{
    if(l<n)
    {
        int m = l + (n-l)/2 ;
        sort(arr,l,m);
        sort(arr,m+1,n);
        merge_sort(arr,l,m,n);
    }
}
int main()
{
    int arr[5] = {5,4,2,2,1} ;
    sort(arr,0,4);
    
    for( int i = 0 ; i < 5 ; i++ )
    {
        cout<<arr[i]<<" ";
    }
}
