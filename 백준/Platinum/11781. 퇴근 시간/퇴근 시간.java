import java.io.*;
import java.util.*;

class Info{
    long dest, dist;
    boolean isJam;

    Info(long dest, long dist, boolean isJam){
        this.dest = dest;
        this.dist = dist;
        this.isJam = isJam;
    }
}

public class Main{
    static final long INF = (long) 1e18;
    static List<List<Info>> edges;
    static long[] cost;
    static int n, m;
    static long s, e, answer = 0;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        s = Long.parseLong(st.nextToken())*2;
        e = Long.parseLong(st.nextToken())*2;

        edges = new ArrayList<>();
        for(int i = 0;i<=n;i++)edges.add(new ArrayList<>());

        cost = new long[n+1];
        Arrays.fill(cost,INF);

        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long l = Long.parseLong(st.nextToken()) * 2;
            boolean t1 = Integer.parseInt(st.nextToken())==1;
            boolean t2 = Integer.parseInt(st.nextToken())==1;

            edges.get(a).add(new Info(b, l, t1));
            edges.get(b).add(new Info(a, l, t2));
        }

        dijkstra();
        findAnswer();

        if(answer % 2 == 0){
            bw.write((answer/2)+"\n");
        }else{
            bw.write((answer/2)+".5\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }

    static long calc(long a, long l){
        if(a<s){
            if(s-a>=l)return l;
            long l1 = s-a;
            long l2 = l-l1;
            long t1 = e-s;
            return (l2*2<=t1)?(l1+l2*2):(l+t1/2);
        }else if(a>=s&&a<e){
            long t1 = e - a;
            return (t1>=l*2)?(l*2):(l+t1/2);
        }else{
            return l;
        }
    }
    static void dijkstra(){
        PriorityQueue<long[]>pq=new PriorityQueue<>(Comparator.comparingLong(o->o[0]));
        cost[1]=0;
        pq.offer(new long[]{0,1});

        while(!pq.isEmpty()){
            long[] cur = pq.poll();
            long curC = cur[0];
            int curX =(int) cur[1];

            if(cost[curX]<curC)continue;

            for(Info next: edges.get(curX)){
                long nextC = next.dist;
                if(next.isJam) nextC = calc(curC,next.dist);

                if(cost[(int) next.dest]>curC+nextC){
                    cost[(int) next.dest]=curC+nextC;
                    pq.offer(new long[]{cost[(int) next.dest], next.dest});
                }
            }
        }
    }

    static void findAnswer(){
        for(int i=2;i<=n;i++){
            answer = Math.max(answer, cost[i]);
        }
    }
}