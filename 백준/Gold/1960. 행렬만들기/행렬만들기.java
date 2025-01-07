import java.io.*;
import java.util.*;

public class Main{
    static int n;
    static int[] rw;
    static int[] cl;
    static int[][] mat;

    static boolean isValid(){
        for(int j =0;j<n;j++){
            int cs =0;
            for(int i =0;i<n;i++){
                cs+=mat[i][j];
            }
            if(cs != cl[j]) return false;
        }
    return true;
    }

    static void solve() throws IOException{
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->b[0]-a[0]);
        for(int i =0;i<n;i++){
            pq.add(new int[]{cl[i],i});
        }

        for(int i =0;i<n;i++){
            Queue<int[]> tmp = new LinkedList<>();
            for(int j =0; j<rw[i];j++){
                int[] top = pq.poll();
                mat[i][top[1]]=1;
                top[0]--;
                tmp.add(top);
            }
            while (!tmp.isEmpty()){
                pq.add(tmp.poll());
            }
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        if(!isValid()){
            bw.write("-1\n");
        }else{
            bw.write("1\n");
            StringBuilder sb = new StringBuilder();
            for(int[] row:mat){
                for(int val : row){
                    sb.append(val);
                }
                sb.append("\n");
            }
            bw.write(sb.toString());
        }
        bw.flush();
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        rw = new int[n];
        cl = new int[n];
        mat = new int[n][n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n;i++) rw[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i <n;i++) cl[i] = Integer.parseInt(st.nextToken());

        solve();
    }
}