import java.io.*;
import java.util.*;

class Main{

    private static final long DIV = 1000000007L;
    private static final Map<Long,Long> f = new HashMap<>();

    private static long fb(long n){
        if(n==0) return 0;
        if(n==1||n==2)return 1;
        if(f.containsKey(n))return f.get(n);

        if(n%2==0){
            long m = n/2;
            long t1 = fb(m-1);
            long t2 = fb(m);
            long res = ((2*t1+t2)*t2)%DIV;
            f.put(n,res);
            return res;
        }else{
            long m =(n+1)/2;
            long t1 = fb(m);
            long t2 = fb(m-1);
            long res = (t1*t1+t2*t2)%DIV;
            f.put(n, res);
            return res;
        }
    }

    public static void main(String[] args) throws  IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        StringBuilder sb = new StringBuilder();
        sb.append(fb(n));

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}