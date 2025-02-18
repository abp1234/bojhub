import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException{
        final int im = 0x3f3f3f3f;

        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        var sb = new StringBuilder();

        var st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[][][] d = new int[n+1][n+1][n+1];

        for (int i = 1; i<=n;i++){
            st=new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++){
                d[0][i][j]=Integer.parseInt(st.nextToken());
                if(i!=j&&d[0][i][j]==0){
                    d[0][i][j]=im;
                }
            }
        }
        for(int k = 1; k <=n;k++){
            for(int i = 1; i<=n;i++){
                for(int j =1;j<=n;j++){
                    d[k][i][j]=Math.min(d[k-1][i][j],d[k-1][i][k]+d[k-1][k][j]);
                }
            }
        }
        for(int i =0; i < q; i++){
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int ans = (d[c-1][s][e]==im?-1:d[c-1][s][e]);
            sb.append(ans).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}