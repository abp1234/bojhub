import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Pt{
    int v,t;
    Pt(int v,int t){
        this.v=v;
        this.t=t;
    }
}

public class Main{
    static int d, ep, mt;
    static List<List<Pt>> g;
    static int[] vis;

    public static void dfs(int cur, int cnt){
        if(d<cnt){
            d=cnt;
            ep=cur;
            mt=vis[cur];
        }
        else if(d==cnt&&vis[cur]<mt){
            ep=cur;
            mt=vis[cur];
        }

        for(Pt nxt:g.get(cur)){
            if(vis[nxt.v]==-1){
                vis[nxt.v]=vis[cur]+nxt.t;
                dfs(nxt.v,cnt+1);
            }
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());

        g = new ArrayList<>();
        for(int i=0;i<n;i++){
            g.add(new ArrayList<>());
        }

        for(int i=0;i<n-1;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken())-1;
            int b = Integer.parseInt(st.nextToken())-1;
            int c = Integer.parseInt(st.nextToken());
            g.get(a).add(new Pt(b,c));
            g.get(b).add(new Pt(a,c));
        }

        d=0;
        ep=0;
        mt=Integer.MAX_VALUE;
        vis =new int[n];
        for(int i=0;i<n;i++)vis[i]=-1;
        vis[0]=0;

        dfs(0,1);

        vis=new int[n];
        for(int i=0;i<n;i++)vis[i]=-1;
        d=0;
        mt=Integer.MAX_VALUE;
        vis[ep]=0;

        dfs(ep,1);

        bw.write((int) Math.ceil((double) mt/t)+"\n");
        bw.flush();
        bw.close();
        br.close();
        
    }
}