import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Arrays;

class Graph{
    static final int RED = 1;
    static final int BLUE = 2;
    int v, e, redCnt;
    int[] vis;
    List<Integer>[] adj;

    @SuppressWarnings("unchecked")
    Graph(int v,int e){
        this.v = v;
        this.e = e;
        this.redCnt = 0;
        this.vis = new int[v+1];
        this.adj = new ArrayList[v+1];
        for(int i =1; i<=v;i++){
            adj[i]=new ArrayList<>();
        }
    }

    void addEdge(int u, int w){
        adj[u].add(w);
        adj[w].add(u);
    }

    void dfs(int x){
        if(vis[x]==0){
            vis[x]=RED;
            redCnt++;
        }
        for(int y : adj[x]){
            if(vis[y]==0){
                if(vis[x]==RED){
                    vis[y]=BLUE;
                }else{
                    vis[y]=RED;
                    redCnt++;
                }
                dfs(y);
            }
        }
    }
    boolean isBinary(){
        for(int i = 1; i<=v;i++){
            for(int num : adj[i]){
                if(vis[i]==vis[num]){
                    return false;
                }
            }
        }
        return true;
    }
    int calcResult(){
        if(isBinary()){
            return redCnt*(v-redCnt)*2;
        }else{
            return 0;
        }
    }
}

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        Graph g = new Graph(v, e);

        for(int i =0; i<e;i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            g.addEdge(u, w);
        }

        for(int i =1;i<=v;i++){
            if(g.vis[i]==0){
                g.dfs(i);
            }
        }
        bw.write(g.calcResult()+"\n");
        bw.flush();

        br.close();
        bw.close();
    }
}