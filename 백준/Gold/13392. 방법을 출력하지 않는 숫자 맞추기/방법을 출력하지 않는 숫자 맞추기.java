import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

class Rot {
    int[][] dp;
    char[] f,t;
    int n;

    Rot(int n, char[] f, char[] t){
        this.n = n;
        this.f = f;
        this.t = t;
        this.dp = new int[n+1][11];
        for(int[] row: dp){
            Arrays.fill(row, -1);
        }
    }

    int dpf(int k, int turn){
        if(k==n)return 0;
        if(dp[k][turn] != -1) return dp[k][turn];

        int turnLeft = (t[k]-f[k]-turn +20)%10;
        int turnRight = 10 - turnLeft;

        int left = dpf(k+1,(turn+turnLeft)%10)+turnLeft;
        int right = dpf(k+1,turn)+turnRight;

        return dp[k][turn] = Math.min(left,right);
    }
}

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        char[] from = br.readLine().toCharArray();
        char[] to = br.readLine().toCharArray();

        for(int i = 0;i<n;i++){
            from[i]-='0';
            to[i]-='0';
        }

        Rot rot = new Rot(n, from, to);
        int result = rot.dpf(0,0);

        bw.write(result+"\n");
        bw.flush();

        br.close();
        bw.close();
    }
}