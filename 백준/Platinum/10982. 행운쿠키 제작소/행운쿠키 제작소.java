import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{
    static final int NM = 100010;

    static class P {
        int a;
        int b;
        P(int a, int b){
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args)throws IOException{
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        var sb = new StringBuilder();

        var T = Integer.parseInt(br.readLine());

        for(var t = 0; t < T; t++){
            var st = new StringTokenizer(br.readLine());
            var N = Integer.parseInt(st.nextToken());
            var ip = new ArrayList<P>();

            for(var i = 0; i<N;i++){
                st = new StringTokenizer(br.readLine());
                var a = Integer.parseInt(st.nextToken());
                var b = Integer.parseInt(st.nextToken());
                ip.add(new P(a,b));
            }
            var s = 0;
            for(var p : ip){
                s+=p.a;
            }
            var dp = new int[s+1];
            Arrays.fill(dp,NM);
            dp[0]=0;

            var r = NM;
            s = 0;

            for (var i = 0; i < N; i++){
                var a = ip.get(i).a;
                var b = ip.get(i).b;
                s+=a;

                for (var j = s; j>=0;j--){
                    if(j>=a){
                        dp[j]=Math.min(dp[j-a],dp[j]+b);
                    }else{
                        dp[j]=dp[j]+b;
                    }
                    if(i==N-1){
                        r=Math.min(r,Math.max(j,dp[j]));
                    }
                }
            }
            sb.append(r).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}