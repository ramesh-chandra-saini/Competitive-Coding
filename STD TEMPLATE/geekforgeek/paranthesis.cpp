# include<stdio.h>
# define MAX_SIZE 100

#include<bits/stdc++.h>
using namespace std;

vector<string> v;
void _printParenthesis(int pos, int n, int open, int close);
/* Wrapper over _printParenthesis()*/
void printParenthesis(int n)
{
  if(n > 0)
     _printParenthesis(0, n, 0, 0);
  return;
}

void _printParenthesis(int pos, int n, int open, int close)
{
  static char str[MAX_SIZE];

  if(close == n)
  {
    printf("%s \n", str);
    v.push_back(str);
    return;
  }
  else
  {
    if(open > close) {
        str[pos] = '}';
        _printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '{';
       _printParenthesis(pos+1, n, open+1, close);
    }
  }
}

/* driver program to test above functions */
int main()
{
  int n = 4;
  v.clear();
  printParenthesis(n);

 cout<<endl;
 cout<<"Hi"<<endl;
   for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
  cout<<endl;
    getchar();
  return 0;
}
