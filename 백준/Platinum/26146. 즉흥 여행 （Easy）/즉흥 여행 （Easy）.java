import java.io.*;
import java.util.*;

public class Main {
    static int[] V,P;
    static boolean[] os;
    static int[] cnt = new int[1];
    static ArrayList<Integer>[] G;
    static Deque<Integer> st;
    static ArrayList<ArrayList<Integer>> SCC;

    static void df(int x){
        V[x] = cnt[0];
        P[x] = cnt[0];
        cnt[0]++;
        st.push(x);
        os[x]= true;

        for (int nx : G[x]){
            if(V[nx]==-1){
                df(nx);
                P[x]=Math.min(P[x],P[nx]);
            }else if (os[nx]){
                P[x]=Math.min(P[x],V[nx]);
            }
        }

        if(V[x]==P[x]){
            ArrayList<Integer> scc = new ArrayList<>();
            while(true){
                int w =st.pop();
                os[w]=false;
                scc.add(w);
                if(w==x)break;
            }
            SCC.add(scc);
        }
    }

    public static void main(String[] args) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        var sb = new StringBuilder();

        StringTokenizer stt = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(stt.nextToken());
        int M = Integer.parseInt(stt.nextToken());

        G = new ArrayList[N+1];
        for (int i = 1; i <= N; i++) {
            G[i] = new ArrayList<>();
        }
        for (int i = 1; i <= M; i++) {
            stt = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(stt.nextToken());
            int b = Integer.parseInt(stt.nextToken());
            G[a].add(b);
        }

        V = new int[N+1];
        P = new int[N+1];
        os = new boolean[N+1];
        for (int i = 1; i <= N; i++) {
            V[i] = -1;
            P[i] = -1;
        }

        st = new ArrayDeque<>();
        SCC = new ArrayList<>();

        for (int i = 1; i <= N; i++) {
            if (V[i] == -1) {
                df(i);
            }
        }

        sb.append(SCC.size()==1?"Yes":"No");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }


}