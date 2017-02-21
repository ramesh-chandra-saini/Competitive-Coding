 ll N; cin >> N;
    ll w[N+1]; for(ll i=1;i<=N;i++) cin >> w[i];
    ll c[N+1]; for(ll i=1;i<=N;i++) cin >> c[i];
    vector<vector<ll> > graph(N+1,vector<ll>());
    for(ll i=1,x,y;i<=N-1;i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<ll> depth(N+1,0);
    vector<bool> visit(N+1,false);
    queue<ll> que;
    que.push(1); que.push(-1);
    ll d =0;
    while(!que.empty()){
        ll curr = que.front();que.pop();
        if(curr==-1){
            if(que.empty()){
                break;
            }else{
                d++,que.push(-1);
            }
        }else{
            for(ll i=0;i<graph[curr].size();i++){
                ll node = graph[curr][i];
                if(visit[node]==false){
                    visit[node]=true;
                    que.push(node);
                    depth[node]=d;
                }
            }
        }
    }
    Tree root = Tree(w[1],(c[1]==0?RED:GREEN),depth[1]);
