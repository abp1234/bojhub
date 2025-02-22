import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class DP{
        public long[][] d;
        public DP(int r, int c){
            d = new long[r+1][c+1];
        }
    }

    static class PT<T>{
        public T v;
        public PT(T v){
            this.v = v;
        }
    }

    static long mn(long a, long b, long c){
        long[] ar = new long[]{a,b,c};
        return Arrays.stream(ar).min().getAsLong();
    }

    public static void main(String[] args){
        var sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        String s1 = sc.next();
        String s2 = sc.next();

        DP dp = new DP(n, m);

        for (int i = 1; i <= n; i++) {
            dp.d[i][1] = dp.d[i - 1][1] + Math.abs(s1.charAt(i - 1) - s2.charAt(0));
        }

        for (int j = 1; j <= m; j++) {
            dp.d[1][j] = dp.d[1][j - 1] + Math.abs(s1.charAt(0) - s2.charAt(j - 1));
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp.d[i][j] = mn(dp.d[i - 1][j - 1], dp.d[i - 1][j], dp.d[i][j - 1]);
                } else {
                    dp.d[i][j] = mn(dp.d[i - 1][j - 1], dp.d[i - 1][j], dp.d[i][j - 1])
                            + Math.abs(s1.charAt(i - 1) - s2.charAt(j - 1));
                }
            }
        }
        PT<Long> pt = new PT<>(dp.d[n][m]);
        System.out.println(pt.v);

        sc.close();
    }

}