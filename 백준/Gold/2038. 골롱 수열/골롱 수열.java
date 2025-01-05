import java.io.*;
import java.util.StringTokenizer;

public class Main{

    static class Dp{
        int[] d;

        Dp(int size){
            this.d = new int[size];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Dp dp = new Dp(1000001);

        solve(dp, n, bw);

        bw.flush();
        bw.close();
    }

    static void solve(Dp dp, int n, BufferedWriter bw) throws IOException {
        dp.d[1] = 1;
        int s = dp.d[1];
        int i = 1;

        while(s<n){
            i +=1;
            dp.d[i] = 1 +dp.d[i-dp.d[dp.d[i-1]]];
            s+=dp.d[i];
        }
        bw.write(i+"\n");
    }
}