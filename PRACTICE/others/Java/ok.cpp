#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int T,l1,l2,w1,w2,__min,__max;
	scanf("%d",&T);

	for(;T>0;T--){
	
		scanf("%d%d%d%d",&l1,&w1,&l2,&w2);
		__max=(l1*w1)+(l2*w2);
		__min = __max-(min(l1,l2)*min(w1,w2));
		printf("%d %d\n",__min,__max);
	}
	return 0;
}
