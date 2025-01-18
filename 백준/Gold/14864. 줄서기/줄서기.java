import java.io.*;
import java.util.*;


public class Main{

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] out = new int[n+1];
        int[] in = new int[n+1];
        int[] num = new int[n+1];
        int[] ans = new int[n+1];

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            out[a]++;
            in[b]++;
        }

        for(int i = 1; i <= n; i++){
            int less = out[i]+i-1-in[i];
            int greater = n - i - out[i]+in[i];

            if(less+greater>=n||num[less+1]==1){
                bw.write("-1\n");
                bw.flush();
                return;
            }

            num[less+1]=1;
            ans[i]=less+1;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 1; i<= n; i++){
            sb.append(ans[i]).append(' ');
        }

        bw.write(sb.toString().trim());
        bw.flush();
        br.close();
        bw.close();


    }
}