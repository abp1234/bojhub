import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Collections;
import java.util.List;

public class Main{
    static int K,N,F;
    static boolean[][] am;
    static ArrayList<Integer>[] al;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        K=Integer.parseInt(st.nextToken());
        N=Integer.parseInt(st.nextToken());
        F=Integer.parseInt(st.nextToken());

        am=new boolean[N+1][N+1];
        al=new ArrayList[N+1];
        for(int i=0;i<=N;i++){
            al[i]=new ArrayList<Integer>();
        }

        for(int i=0;i<F;i++){
            st=new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            al[a].add(b);
            al[b].add(a);
            am[a][b]=true;
            am[b][a]=true;
        }
        br.close();

        for(int i=1;i<=N;i++){
            Collections.sort(al[i]);
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        if(K==1){
            sb.append("1\n");
        }else{
            List<Integer> rs =sv();
            if(rs==null){
                sb.append("-1\n");
            }else{
                Collections.sort(rs);
                for(int x :rs){
                    sb.append(x).append("\n");
                }
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }

    static List<Integer> bs(int st){
        boolean[] vs = new boolean[N+1];
        List<Integer> ph = new ArrayList<Integer>();
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>();

        vs[st]=true;
        ph.add(st);
        pq.offer(st);

        while(!pq.isEmpty()){
            int nw = pq.poll();

            for(int nx:al[nw]){
                if(!vs[nx]){
                    vs[nx]=true;
                    boolean fg =false;
                    for(int tg:ph){
                        if(!am[nx][tg]){
                            fg=true;
                            break;
                        }
                    }

                    if(!fg){
                        ph.add(nx);
                        if(ph.size()==K){
                            return ph;
                        }
                        pq.offer(nx);
                    }
                }
            }
        }
        return null;
    }
    static List<Integer> sv(){
        for(int st=1;st<=N;st++){
            List<Integer> rs = bs(st);
            if(rs != null){
                return rs;
            }
        }
        return null;
    }
}