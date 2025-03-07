import java.io.*;

public class Main {

    static final short INF = 1000;

    static class DP{
        short[][][] dp;
        int na, nb;

        DP(int na, int nb){
            this.na = na;
            this.nb = nb;
            dp = new short[na+1][nb+1][2];
        }

        void in(){
            dp[0][0][0]=0;
            dp[0][0][1]=INF;
            for(int i = 1; i <= nb; i++){
                dp[0][i][0]=INF;
                dp[0][i][1]=1;
            }
        }

        short cal(String a, String b){
            for(int i = 0; i < na;i++){
                for(int j = 0; j <=i;j++){
                    dp[i+1][j][0]=INF;
                    dp[i+1][j][1]=INF;
                }
                for(int j = i;j<nb;j++){
                    if(a.charAt(i)==b.charAt(j))
                        dp[i+1][j+1][0]=mn(dp[i][j][0],dp[i][j][1]);
                    else
                        dp[i+1][j+1][0]=INF;
                    dp[i+1][j+1][1]=mn((short)(dp[i+1][j][0]+1),dp[i+1][j][1]);
                }
            }
            return mn(dp[na][nb][0],dp[na][nb][1]);
        }
    }
    static short mn(short a, short b){
        return (a<b)?a:b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String a = br.readLine();
        String b = br.readLine();

        int na = a.length();
        int nb = b.length();

        if(na>nb){
            sb.append("-1");
            bw.write(sb.toString());
            bw.flush();
            bw.close();
            br.close();
            return;
        }
        var dpObj = new DP(na,nb);
        dpObj.in();

        short r = dpObj.cal(a,b);

        sb.append((r>=INF)?"-1":r);

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}
