import java.io.*;
import java.util.*;

class P{
    int v;
    long w;

    P(long w, int v){
        this.v = v;
        this.w = w;
    }

}

public class Main{

    static final long INF = (long) 1e18;
    static int n, m, k;
    static ArrayList<P>[] adj;
    static long[] d;
    static PriorityQueue<P> pq;

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n+1];
        for(int i =0; i<=n;i++){
            adj[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            long dist = Long.parseLong(st.nextToken());
            adj[to].add(new P(dist, from));
        }

        d = new long[n+1];
        Arrays.fill(d, INF);

        pq = new PriorityQueue<>(Comparator.comparingLong(p->p.w));

        st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            int num = Integer.parseInt(st.nextToken());
            d[num]=0;
            pq.offer(new P(0,num));
        }

        dijkstra();

        int idx = -1;
        long maxD = -1;
        for(int i = 1; i <=n;i++){
            if(maxD<d[i]){
                maxD=d[i];
                idx = i;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(idx).append("\n").append(maxD);
        bw.write(sb.toString());
        bw.flush();

        br.close();
        bw.close();
    }

    static void dijkstra(){
        while (!pq.isEmpty()){
            P cur = pq.poll();

            if(d[cur.v] < cur.w) continue;

            for(P nxt: adj[cur.v]){
                if(d[nxt.v]>d[cur.v]+nxt.w){
                    d[nxt.v]=d[cur.v]+nxt.w;
                    pq.offer(new P(d[nxt.v], nxt.v));
                }
            }
        }
    }


}