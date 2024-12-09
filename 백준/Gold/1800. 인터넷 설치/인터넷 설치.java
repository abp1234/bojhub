import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main{
    static class Edge{
        int to, cost;

        Edge(int to, int cost){
            this.to = to;
            this.cost = cost;
        }
    }

    static final int INF = Integer.MAX_VALUE;
    static int n, p, k;
    static ArrayList<Edge>[] g;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        g = new ArrayList[n+1];
        for(int i = 0;i<=n;i++){
            g[i]=new ArrayList<>();
        }

        for(int i =0;i<p;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            g[a].add(new Edge(b,c));
            g[b].add(new Edge(a,c));
        }
        int l =0;
        int r=1000000;
        int res=-1;

        while(l<=r){
            int mid=(l+r)/2;
            if(dij(mid)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        bw.write(res+"\n");
        bw.flush();
        bw.close();
    }

    static boolean dij(int base){
        PriorityQueue<int[]> pq=new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        pq.offer(new int[]{0,1});
        int[] d = new int[n+1];
        Arrays.fill(d,INF);
        d[1]=0;

        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int usedFree = cur[0];
            int now = cur[1];

            if(d[now]<usedFree){
                continue;
            }

            for(Edge e : g[now]){
                int cost = usedFree;
                if(e.cost>base){
                    cost++;
                }
                if(cost<d[e.to]){
                    d[e.to]=cost;
                    pq.offer(new int[]{cost, e.to});
                }
            }
        }
        return d[n]<=k;
    }

}