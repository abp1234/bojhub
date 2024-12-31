import java.io.*;
import java.util.*;

public class Main{
    static final long INF = (long) 1e18;
    static long[][][][] dp;
    static long[] arr, brr, crr;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        arr = new long[1010101];
        brr = new long[1010101];
        crr = new long[1010101];

        st = new StringTokenizer(br.readLine());
        int a1 = Integer.parseInt(st.nextToken());
        for(int i=1;i<=a1;i++){
            arr[i]=Integer.parseInt(st.nextToken())-1;
        }

        st=new StringTokenizer(br.readLine());
        int a2 = Integer.parseInt(st.nextToken());
        for(int i=1;i<=a2;i++){
            brr[i]=(Integer.parseInt(st.nextToken())-1-n/3+n)%n;
        }

        st = new StringTokenizer(br.readLine());
        int a3 = Integer.parseInt(st.nextToken());
        for(int i=1;i<=a3;i++){
            crr[i]=(Integer.parseInt(st.nextToken())-1+n/3)%n;
        }

        dp=new long[a1+1][a2+1][a3+1][4];
        for(int i=0;i<=a1;i++){
            for(int j=0;j<=a2;j++){
                for(int k=0;k<=a3;k++){
                    Arrays.fill(dp[i][j][k],INF);
                }
            }
        }

        dp[0][0][0][1]=0;
        dp[0][0][0][2]=0;
        dp[0][0][0][3]=0;

        for(int i=0;i<=a1;i++){
            for(int j=0;j<=a2;j++){
                for(int k=0;k<=a3;k++){
                    if(i>0){
                        dp[i][j][k][1]=Math.min(dp[i][j][k][1],dp[i-1][j][k][1]+dist(arr[i-1],arr[i],n));
                        dp[i][j][k][1]=Math.min(dp[i][j][k][1],dp[i-1][j][k][2]+dist(brr[j],arr[i],n));
                        dp[i][j][k][1]=Math.min(dp[i][j][k][1],dp[i-1][j][k][3]+dist(crr[k],arr[i],n));
                    }
                    if(j>0){
                        dp[i][j][k][2]=Math.min(dp[i][j][k][2],dp[i][j-1][k][1]+dist(arr[i],brr[j],n));
                        dp[i][j][k][2]=Math.min(dp[i][j][k][2],dp[i][j-1][k][2]+dist(brr[j-1],brr[j],n));
                        dp[i][j][k][2]=Math.min(dp[i][j][k][2],dp[i][j-1][k][3]+dist(crr[k],brr[j],n));
                    }
                    if(k>0){
                        dp[i][j][k][3] = Math.min(dp[i][j][k][3], dp[i][j][k - 1][1] + dist(arr[i], crr[k], n));
                        dp[i][j][k][3] = Math.min(dp[i][j][k][3], dp[i][j][k - 1][2] + dist(brr[j], crr[k], n));
                        dp[i][j][k][3] = Math.min(dp[i][j][k][3], dp[i][j][k - 1][3] + dist(crr[k - 1], crr[k], n));
                    }
                }
            }
        }

        long result = Math.min(Math.min(dp[a1][a2][a3][1],dp[a1][a2][a3][2]),dp[a1][a2][a3][3]);
        bw.write(result+"\n");
        bw.flush();
        br.close();
        bw.close();
    }

    static long dist(long x, long y, long n){
        return Math.min((n+x-y)%n,(n+y-x)%n);
    }

}