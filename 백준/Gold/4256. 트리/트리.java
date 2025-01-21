import java.io.*;
import java.util.*;

public class Main{
    static int T;
    static int N;
    static int[] pre, in;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static void po(int s, int e, int p) throws IOException{
        for(int i = s; i < e; i++){
            if(in[i]==pre[p]){
                po(s,i,p+1);
                po(i+1,e,p+1+(i-s));
                bw.write(pre[p]+" ");
            }
        }
    }
    static void solve() throws  IOException{
        po(0, N, 0);
        bw.newLine();
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());

        for(int i = 0; i< T; i++){
            N = Integer.parseInt(br.readLine());
            pre = new int[N];
            in = new int[N];

            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                pre[j] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                in[j] = Integer.parseInt(st.nextToken());
            }
            solve();
        }
        bw.flush();
        br.close();
    }
}