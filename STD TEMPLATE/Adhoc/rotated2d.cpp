#include<bits/stdc++.h>
using namespace std;

class Solution{

	public : void rotate(vector<vector<int> > &A);
};
void Solution::rotate(vector<vector<int> > &P) {

    int n=P.size();
	int A,B,C,D;
	int startRow=0;
	int endRow=n-1;
	int startCol=0;
	int endCol=n-1;
	int loop=n/2;
    int k=0;
	while(loop--){



	    for(int i=k;i<n-1-k;i++){


			A=P[startRow][i];
			B=P[i][endCol];
			C=P[endCol][endRow-i];
			D=P[endRow-i][startRow];
			//cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
			//cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
			P[startRow][i]=D;
			P[i][endCol]=A;
			P[endCol][endRow-i]=B;
			P[endRow-i][startRow]=C;

	    }
	    k++;
	}

}
//driver function
int main(){

	cout<<"Input "<<endl;
	int n;
	cin>>n;

	vector<vector<int> >Vec;
	vector<int > temp;
	int value;

	for(int i=0;i<n;i++){

		temp.clear();
		for(int j=0;j<n;j++){

			cin>>value;
			temp.push_back(value);
		}
		Vec.push_back(temp);
	}

	Solution Obj;

	Obj.rotate(Vec);
	cout<<"Output "<<endl;

	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){

			cout<<Vec[i][j]<<" ";
		}
		cout<<endl;
	}

    return 0;
}