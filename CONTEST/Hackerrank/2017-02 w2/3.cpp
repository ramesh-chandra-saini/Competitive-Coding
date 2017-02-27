#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<char> > &mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}
double dist(double x1,double y1,double x2,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void draw_circle(int w,int h,vector<vector<char> >&mat){

    double xc,yc,r; cin >>xc >> yc >> r;
    //draw circle
    for(double i =0;i<h;i+=1)
        for(double j=0;j<w;j+=1)
            if( dist(2*i,2*j,2*yc,2*xc)<=(2*r)*(2*r) )
                mat[int(i)][int(j)]='#';
}
double area(double x1,double y1,double x2,double y2,double x3,double y3){
    return abs((x1*y2+x2*y3+x3*y1) - (y1*x2+y2*x3+y3*x1));
}
bool check( double i, double j,  double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
    return (area(x1,y1,x2,y2,x3,y3) ==  area(i,j,x1,y1,x2,y2) + area(i,j,x2,y2,x3,y3) + area(i,j,x3,y3,x1,y1) ) ||
           (area(x1,y1,x4,y4,x3,y3) ==  area(i,j,x1,y1,x4,y4) + area(i,j,x4,y4,x3,y3) + area(i,j,x3,y3,x1,y1) );
}
void draw_square(int w,int h,vector<vector<char> >&mat){

    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x3 >> y3;

    //find remaining vertices
    x2 = (x1+x3+y3-y1)/2.0,y2 = (y1+y3+x1-x3)/2.0;
    x4 = (x1+x3+y1-y3)/2.0,y4 = (y1+y3+x3-x1)/2.0;

    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    //get mid of each pixels
    //x1 += .5,y1 += .5;    x3 += .5,y3 += .5;
    //x2 += (x2==int(x2))?.5:0 , y2 += (y2==int(y2))?.5:0;
    //x4 += (x4==int(x4))?.5:0  , y4 += (y4==int(y4))?.5:0;
    //cout<<x2<<" "<<y2<<" "<<x4<<" "<<y4<<endl;
    //draw square
    for(double i = 0;i<h;i+=1)
        for(double j = 0;j<w;j+=1)
            if(check(2*i,2*j,2*y1,2*x1,2*y2,2*x2,2*y3,2*x3,2*y4,2*x4) )
                mat[int(i)][int(j)]='#';
}
int main(){
    //freopen("in.txt","r",stdin);
    int w,h; cin >> w >> h;
    vector<vector<char> > mat(h,vector<char>(w,'.'));
    draw_circle(w,h,mat);
    //print(mat);
    draw_square(w,h,mat);
    print(mat);

    return 0;
}
