#include<bits/stdc++.h>
using namespace std;

// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 100000

struct Coordinate
{
    int X;
    int Y;
};
int orientation(Coordinate p, Coordinate q, Coordinate r);
bool doIntersect(Coordinate p1, Coordinate q1, Coordinate p2, Coordinate q2);
bool inInsideChecker(Coordinate polYgon[], int n, Coordinate p);
int main(){
   int red,black;
   scanf("%d%d",&red,&black);
    Coordinate Red[red],Black[black];
   for(int i=0;i<red;i++)
        scanf("%d%d",&Red[i].X,&Red[i].Y);
   for(int i=0;i<black;i++)
        scanf("%d%d",&Black[i].X,&Black[i].Y);
   int Q;
   scanf("%d",&Q);//referred from geeksforgeeks
   while(Q--){

        int n,idX;
        scanf("%d",&n);
        Coordinate polYgon1[n];
        for(int i=0;i<n;i++){
            scanf("%d",&idX);
            polYgon1[i].X=Red[idX-1].X;
            polYgon1[i].Y=Red[idX-1].Y;
        }
        int ans=0;
        for(int i=0;i<black;i++){
            Coordinate p;
             p.X=Black[i].X;
             p.Y=Black[i].Y;
            if(inInsideChecker(polYgon1, n, p))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Coordinate p, Coordinate q, Coordinate r)
{
    int val = (q.Y - p.Y) * (r.X - q.X) -
              (q.X - p.X) * (r.Y - q.Y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegmentHelper(Coordinate p, Coordinate q, Coordinate r)
{
    if (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) &&
            q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y))
        return true;
    return false;
}


// Returns true if the point p lies inside the polYgon[] with n vertices
bool inInsideChecker(Coordinate polYgon[], int n, Coordinate p)
{
    // There must be at least 3 vertices in polYgon[]
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite
    Coordinate eXtreme = {INF, p.Y};

    // Count intersections of the above line with sides of polYgon
    int count = 0, i = 0;
    do
    {
        int neXt = (i+1)%n;

        // Check if the line segment from 'p' to 'eXtreme' intersects
        // with the line segment from 'polYgon[i]' to 'polYgon[neXt]'
        if (doIntersect(polYgon[i], polYgon[neXt], p, eXtreme))
        {
            // If the point 'p' is colinear with line segment 'i-neXt',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polYgon[i], p, polYgon[neXt]) == 0)
               return onSegmentHelper(polYgon[i], p, polYgon[neXt]);

            count++;
        }
        i = neXt;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Coordinate p1, Coordinate q1, Coordinate p2, Coordinate q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegmentHelper(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegmentHelper(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegmentHelper(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegmentHelper(p2, q1, q2)) return true;

    return false; // Doesn't fall in anY of the above cases
}
