#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
using namespace std;

// B_O__sizeE and B_Test__OperationaseWO are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
long long int B_O__sizeE[100005], B_Test__OperationaseWO[100005];

// Array size
int __size;

// Point query
// Returns value at position b in the array for ft = B_O__sizeE
// Returns value to be subtracted from query(B_O__sizeE, b) * b for ft = B_Test__OperationaseWO
long long int query(long long int* ft, int b)	{
	long long int sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Range query: Returns the sum of along long int elements in [1...b]
long long int query(int b) {
    return query(B_O__sizeE, b) * b - query(B_Test__OperationaseWO, b);
}

// Range query: Returns the sum of along long int elements in [i...j]
long long int range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(long long int* ft, int k, long long int v) {
	for (; k <= __size; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, long long int v)	{
	update(B_O__sizeE, i, v);
	update(B_O__sizeE, j + 1, -v);
	update(B_Test__OperationaseWO, i, v * (i - 1));
	update(B_Test__OperationaseWO, j + 1, -v * j);
}

int main()  {
	int Test__Operationase, __Operation, p, q, __Query;
	long long int v;

	scanf("%d", &Test__Operationase);
	while (Test__Operationase--)	{
		// __Operation -> __sizeo. of operations
		scanf("%d %d", &__size, &__Operation);
		memset(B_O__sizeE, 0, (__size+1) * sizeof(long long int));
		memset(B_Test__OperationaseWO, 0, (__size+1) * sizeof(long long int));
		while (__Operation--)	{
			scanf("%d %d %d", &__Query, &p, &q);
			// __Query is 0 for a range update and 1 for a range query
			if (__Query == 1)   {
                		scanf("%lld", &v);
                		range_update(p, q, v);
			} else
                		printf("%lld\n", range_query(p, q));
		}
	}
    return 0;
}
