import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main{
    static int[][] dp = new int[501][501];

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i = 1; i<=m;i++){
            dp[i][1]=1;
            dp[i][0]=0;
        }

        for (int i = 1; i<=n;i++){
            dp[1][i]=i;
        }

        for(int i =2;i<=m;i++){
            for(int j = 2; j <=n; j++){
                dp[i][j] = Integer.MAX_VALUE;
                for(int k = 1; k<= j;k++){
                    dp[i][j] = Math.min(dp[i][j], 1+ Math.max(dp[i-1][k-1],dp[i][j-k]));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dp[m][n]).append("\n");
        bw.write(sb.toString());
        bw.flush();

        br.close();
        bw.close();
    }

}