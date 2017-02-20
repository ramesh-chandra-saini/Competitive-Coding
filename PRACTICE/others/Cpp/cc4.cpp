#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

/* A utility function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */
   float A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */
   float A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */
   float A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

/* Driver program to test above function */
int main()
{

  int red,black;
   scanf("%d%d",&red,&black);
 int Red[red][2],Black[black][2];
   for(int i=0;i<red;i++)
        scanf("%d%d",&Red[i][0],&Red[i][1]);
   for(int i=0;i<black;i++)
        scanf("%d%d",&Black[i][0],&Black[i][1]);
   int Q;
   scanf("%d",&Q);//referred from geeksforgeeks
     int ans=0;
    for(int i=0;i<black;i++)
        ans+=isInside(Red[0][0],Red[0][1],Red[1][0],Red[1][1],Red[2][0],Red[2][1],Black[i][0], Black[i][1]);
   while(Q--){

        int n,idx;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&idx);
     printf("%d\n",ans);
   }

   return 0;
}
