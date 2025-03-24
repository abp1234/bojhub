import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static class Ar{
        long[] a;
        long[] p;
        long[] d;
        Ar(int n){
            a = new long[n+1];
            p = new long[n+1];
            d = new long[n+1];
        }
    }

    public static void main(String[] args) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        var sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        long T = Long.parseLong(st.nextToken());
        T /=2;

        Ar ar = new Ar((int) N);

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            ar.a[i] = Long.parseLong(st.nextToken());
        }

        for (int i = 1; i < N; i++) {
            ar.d[i] = ar.a[i] + ar.a[i+1];
            ar.p[i] = ar.p[i-1] + ar.d[i];
        }

        long an = 0;

        for (int i = 1; i < N; i++) {
            if(i<=T){
                long ca = ar.p[i-1]+ar.d[i]*(T+1-i);
                if(ca>an){
                    an = ca;
                }
            }
        }

        sb.append(an);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}