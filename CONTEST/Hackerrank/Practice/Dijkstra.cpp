#include<bits/stdc++.h>
using namespace std;

 int   main(){

    long long int   T;

    cin >> T;

    while(T--){

        long long int   N,M;

        cin >> N >> M;

        long long int   graph[N+1][N+1];

        memset(graph,INT_MAX,sizeof(graph));

        while(M--){

            long long int   x,y,r;

            cin >> x >> y >> r;

            graph[x][y]=graph[y][x]=min(r,min( graph[x][y],graph[y][x]));
        }

        vector<bool> visit(N+1,false);
        vector<long long int> Dist(N+1,INT_MAX);

        long long int   S;
        cin >> S;

        Dist[S]=0;
         //insert source

         for(long long int   __i=1;__i<=N;__i++){

            //find min dist....

            long long int   minDist=INT_MAX;
            long long int   idx=0;

            for(long long int   i=1;i<=N;i++){

                if( !visit[i] && minDist> Dist[i]){

                    idx=i;
                    minDist=Dist[i];
                }
            }
            if(idx){

                //cout<<idx<<endl;
                visit[idx]=true;

                for(long long int   i=1;i<=N;i++)
                    Dist[i]=min(Dist[i],graph[idx][i]+Dist[idx]);
            }
         }


        for(long long int   i=1;i<S;i++){

            if(Dist[i]==INT_MAX) cout<<"-1"<<" ";
            else cout<<Dist[i]<<" ";
        }

        for(long long int   i=S+1;i<=N;i++){

            if(Dist[i]==INT_MAX) cout<<"-1"<<" ";
            else cout<<Dist[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
