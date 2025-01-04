import java.io.*;
import java.util.*;

public class Main{

    static int[] dp = new int[41];
    static int[] zeorCount = new int[41];
    static int[] oneCount = new int[41];

    static void fibo(int n){
        if(dp[n]!=-1){
            return;
        }

        for(int i = 2; i<=n;i++){
            dp[i] = dp[i-2]+dp[i-1];
            zeorCount[i]=zeorCount[i-2]+zeorCount[i-1];
            oneCount[i]=oneCount[i-2]+oneCount[i-1];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        Arrays.fill(dp,-1);
        Arrays.fill(zeorCount,0);
        Arrays.fill(oneCount,0);

        dp[0]=0;
        dp[1]=1;

        zeorCount[0]=1;
        oneCount[1]=1;

        int t = Integer.parseInt(br.readLine());

        StringBuilder result = new StringBuilder();

        for(int i=0;i<t;i++){
            int n=Integer.parseInt(br.readLine());

            fibo(n);

            result.append(zeorCount[n]).append(" ").append(oneCount[n]).append("\n");
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(result.toString());
        bw.flush();
        bw.close();

    }
}