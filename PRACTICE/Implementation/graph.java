class SumInLeavesVisitor extends TreeVis {
    public int getResult() {
      	//implement this
        return 0;
    }

    public void visitNode(TreeNode node) {
      	//implement this
    }

    public void visitLeaf(TreeLeaf leaf) {
      	//implement this
    }
}

class ProductOfRedNodesVisitor extends TreeVis {
    public int getResult() {
      	//implement this
        return 1;
    }

    public void visitNode(TreeNode node) {
      	//implement this
    }

    public void visitLeaf(TreeLeaf leaf) {
      	//implement this
    }
}

class FancyVisitor extends TreeVis {
    public int getResult() {
      	//implement this
        return 0;
    }

    public void visitNode(TreeNode node) {
    	//implement this
    }

    public void visitLeaf(TreeLeaf leaf) {
    	//implement this
    }
}

public class Solution {
  
    public static Tree solve() {
        //read the tree from STDIN and return its root as a return value of this function
        Scanner inp = new Scanner(System.in);
        
        int N; N=inp.nextInt ();
        
    int  []w=new int [N+1]; 
        for(int i=1;i<=N;i++) w[i]=inp.nextInt  ();
    int  []c=new int [N+1]; 
        for(int i=1;i<=N;i++) c[i]=inp.nextInt  ();
   	List<List<Integer>> graph = new ArrayList<List<Integer>>();
	for (int i = 0; i<=N;i++)
		graph.add(new ArrayList<Integer>());
    
    for(int i=1;i<=N-1;i++){
        int x,y;
        x=inp.nextInt ();
        y=inp.nextInt ();
        graph.get(x).add(y);
        graph.get(y).add(x);
    }
    int  [] depth = new int [N+1];
        for(int i=0;i<=N;i++) depth[i]=0;
    boolean [] visit = new boolean[N+1];
        for(int i=0;i<=N;i++) visit[i]=false;
   
    Queue<Integer> que = new LinkedList<Integer>();
    que.add(1);que.add(-1);
    int d =0;
    while(!que.isEmpty()){
        int curr = que.remove();
        if(curr==-1){
            if(que.isEmpty()){
                break;
            }else{
                d++;
                que.add(-1);
            }
        }else{
            for(int i=0;i<graph.get(curr).size();i++){
                int node = graph.get(curr).get(i);
                if(visit[node]==false){
                    visit[node]=true;
                    que.add(node);
                    depth[node]=d;
                }
            }
        }
    }
    Color color;
        Tree root = new TreeNode(w[1],(c[1]==0?color.RED:color.GREEN),depth[1]);
     return root;
    }   
