import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main{
    static final int MOD =1000000007;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        arr = new int[n+1];
        dp = new int[n+1][5001];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());

            if(arr[i]>=5000){
                bw.write("0\n");
                bw.flush();
                return;
            }
        }
        if(arr[1]>0||arr[n]>0){
            bw.write("0\n");
            bw.flush();
            return;
        }
        dp[1][0]=1;
        arr[n]=0;

        for(int i =2;i<=n;i++){
            if(arr[i]==-1){
                dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
                for(int k = 1; k<5000;k++){
                    dp[i][k]=((dp[i-1][k-1]+dp[i-1][k])%MOD +dp[i-1][k+1])%MOD;
                }
            }else{
                if(arr[i]==0)dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
                else dp[i][arr[i]]=((dp[i-1][arr[i]-1]+dp[i-1][arr[i]])%MOD+dp[i-1][arr[i]+1])%MOD;
            }
        }
        sb.append(dp[n][0]);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}