#include<bits/stdc++.h>
using namespace std;

int moves=0;
void towerHanoiDemo(int num,char _from,char _to,char _aux){


	if(num<=1){

		cout<<num<<"th : "<<_from<<" -> "<<_to<<endl;
		moves++;
		return ;
	}
	towerHanoiDemo(num-1,_from,_aux,_to);
	cout<<num<<"th : "<<_from<<" -> "<<_to<<endl;
	moves++;
	towerHanoiDemo(num-1,_aux,_to,_from);
	return;
}
int main(){


	int n;
	cout<<"Number of Dices : "<<endl;
	cin>>n;

	//A --> C via B...
	//fun(n,from ,to, aux)
	cout<<"A -> C via B"<<endl;
	cout<<"*************Moves of Dices***************\n";
	towerHanoiDemo(n,'A','C','B');
	cout<<"Total No. of Moves : "<<moves<<endl;
	return 0;
}