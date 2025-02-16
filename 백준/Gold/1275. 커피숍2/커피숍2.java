import java.io.*;
import java.util.StringTokenizer;

public class Main{
    static class ST{
        int n;
        long[] tr;

        ST(int n, long[] ar){
            this.n = n;
            tr = new long[n<<1];
            for(int i = 0; i < n; i++){
                tr[n+i]=ar[i];
            }
            for(int i = n - 1; i > 0; i--){
                tr[i] = tr[i<<1]+tr[i<<1|1];
            }
        }
        void up(int i, long v){
            i +=n;
            tr[i] = v;
            while(i>1){
                i>>=1;
                tr[i]=tr[i<<1]+tr[i<<1|1];
            }
        }

        long qr(int l, int r){
            long s = 0;
            l += n;
            r += n;
            while(l<=r){
                if((l&1)==1){
                    s+=tr[l++];
                }
                if((r&1)==0){
                    s+=tr[r--];
                }
                l>>=1;
                r>>=1;
            }
            return s;
        }
    }

    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        long[] ar = new long[n];
        int ct = 0;
        while (ct < n){
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()&&ct<n){
                ar[ct++]=Long.parseLong(st.nextToken());
            }
        }

        ST sg = new ST(n, ar);

        for(int i = 0; i<q;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int ai = Integer.parseInt(st.nextToken());
            long b = Long.parseLong(st.nextToken());

            if(x>y){
                int tp=x;
                x=y;
                y=tp;
            }
            sb.append(sg.qr(x-1,y-1)).append("\n");
            sg.up(ai-1,b);
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}