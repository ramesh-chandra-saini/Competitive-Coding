#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int count( int S[], int m)
{
    int max_so_far=S[0];
    int curr_max=S[0];

    for(int i=1;i<m;i++){

		curr_max=max(S[i],curr_max+S[i]);
		max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far;
}

// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {-2, 1};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n", count(arr, m));

    return 0;

}