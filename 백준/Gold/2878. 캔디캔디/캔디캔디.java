import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static long m;
    static ArrayList<Long> v = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        m = Long.parseLong(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        long s = -m;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long in = Long.parseLong(st.nextToken());
            v.add(in);
            s += in;
        }

        Collections.sort(v);
        long ans = 0;

        for (int i = 0; i < n; i++) {
            long r = Math.min(v.get(i), s / (n - i));
            ans += r * r;
            s -= r;
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
