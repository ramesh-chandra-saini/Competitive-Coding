// C program for range minimum query using segment tree
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define ll long long int
// A utility function to get minimum of two numbers
ll minVal(ll x, ll y) { return (x < y)? x: y; }

// A utility function to get the middle index from corner indexes.
ll getMid(ll s, ll e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range
     of array indexes. The following are parameters for this function.

    st    --> Poller to segment tree
    index --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                  by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;

    // If a part of this segment overlaps with the given range
    ll mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
ll RMQ(ll *st, ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    ll mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
ll *constructST(ll arr[], ll n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    ll x = (ll)(ceil(log2(n)));

    // Maximum size of segment tree
    ll max_size = 2*(ll)pow(2, x) - 1;

    ll *st = new ll[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}
#include<bits/stdc++.h>
using namespace std;
// Driver program to test above functions
int main()
{
    ll n; cin>>n;
    ll arr[n]; for(ll i=0;i<n;i++) cin >> arr[i];

    // Build segment tree from given array
    ll *st = constructST(arr, n);

    int q; cin >> q;
    while(q--){

    ll qs = 1;  // Starting index of query range
    ll qe = 5;  // Ending index of query range
    cin >> qs>>qe;
    // Prll minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQ(st, n, qs, qe));
}
    return 0;
}
