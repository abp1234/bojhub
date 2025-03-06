import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {


    static int N;
    static int M;
    static int[][] en;


    private static class ST {
        int[][] d;
        ST(int[][] d) {
            this.d = d;
        }
    }


    static ST sv(int x) {
        int L = N + 1;

        int[][] dp = new int[4][L];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < L; j++) {
                dp[i][j] = 2 * N;
            }
        }
        dp[x][L - 1] = 0;



        for (int n = 0; n < N; n++) {

            int p = (n - 1 + L) % L;


            for (int i = 0; i < 4; i++) {

                int add = ((i & 1) == 0 ? 1 : 0) + ((i & 2) == 0 ? 1 : 0);
                dp[0][n] = Math.min(dp[0][n], dp[i][p] + add);
            }

            if (en[0][n] + en[1][n] <= M) {
                dp[0][n] = Math.min(dp[0][n], dp[0][p] + 1);
            }

            if (en[0][n] + en[0][n + 1] <= M) {
                dp[1][n] = Math.min(dp[0][p] + 2, dp[2][p] + 1);
            }

            if (en[1][n] + en[1][n + 1] <= M) {
                dp[2][n] = Math.min(dp[0][p] + 2, dp[1][p] + 1);
            }

            if (en[0][n] + en[0][n + 1] <= M && en[1][n] + en[1][n + 1] <= M) {
                dp[3][n] = dp[0][p] + 2;
            }
        }
        return new ST(dp);
    }


    public static void main(String[] ag) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();


        int t = Integer.parseInt(br.readLine());


        for (int ti = 0; ti < t; ti++) {

            StringTokenizer stz = new StringTokenizer(br.readLine());
            N = Integer.parseInt(stz.nextToken());
            M = Integer.parseInt(stz.nextToken());


            en = new int[2][N + 1];

            stz = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                en[0][i] = Integer.parseInt(stz.nextToken());
            }
            en[0][N] = 0;


            stz = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                en[1][i] = Integer.parseInt(stz.nextToken());
            }
            en[1][N] = 0;
            if (N == 1) {
                int res = (en[0][0] + en[1][0] <= M) ? 1 : 2;
                sb.append(res).append("\n");
                continue;
            }

            ST stObj = sv(0);
            int res = stObj.d[0][N - 1];


            if (en[0][0] + en[0][N - 1] <= M) {

                ST stObj1 = sv(1);
                res = Math.min(res, Math.min(stObj1.d[2][N - 2] + 1, stObj1.d[0][N - 2] + 2));
            }

            if (en[1][0] + en[1][N - 1] <= M) {

                ST stObj2 = sv(2);
                res = Math.min(res, Math.min(stObj2.d[1][N - 2] + 1, stObj2.d[0][N - 2] + 2));
            }

            if (en[0][0] + en[0][N - 1] <= M && en[1][0] + en[1][N - 1] <= M) {

                res = Math.min(res, sv(3).d[0][N - 2] + 2);
            }

            sb.append(res).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
