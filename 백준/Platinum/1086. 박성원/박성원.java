import java.io.*;
import java.util.*;

public class Main{
    private static int n, k;
    private static List<String> a = new ArrayList<>();

    private static long[][] dp;

    private static long[] remd;

    private static long[] lenRem;

    private static int rem(String x){
        int tmp=0;
        for(int i=0;i<x.length();i++){
            tmp=(tmp*10+(x.charAt(i)-'0'))%k;
        }
        return tmp;
    }

    private static long gcd(long a, long b){
        return b == 0?a:gcd(b,a%b);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i =0;i<n;i++){
            a.add(br.readLine());
        }
        k=Integer.parseInt(br.readLine());

        dp=new long[1<<n][k];
        remd = new long[n];
        lenRem = new long[51];

        for(int i=0;i<n;i++){
            remd[i]=rem(a.get(i));
        }

        lenRem[0]=1%k;
        for(int i = 1; i<=50;i++){
            lenRem[i]=(lenRem[i-1]*10)%k;
        }
        dp[0][0]=1;

        for(int num =0;num<(1<<n);num++){
            for(int i=0;i<n;i++){
                if((num&(1<<i))==0){
                    int next =(num|(1<<i));
                    for(int j=0;j<k;j++){
                        int nextRem=(int)(((j*lenRem[a.get(i).length()])%k+remd[i])%k);
                        dp[next][nextRem]+=dp[num][j];
                    }
                }
            }
        }

        long nume = 1, deno = 1;
        for(int i= 1; i<=n;i++){
            deno*=i;
        }
        nume = dp[(1<<n)-1][0];
        long gcdNum=gcd(nume,deno);

        bw.write((nume/gcdNum)+"/"+(deno/gcdNum)+"\n");
        bw.flush();
        bw.close();
    }
}