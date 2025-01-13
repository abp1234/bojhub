import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;

public class Main{

    static class R{
        int t;
        public R(int t){
            this.t = t;
        }
    }

    static boolean ck(long m, R[] ar,int q, long n){
        long c = q;
        for(R r : ar){
            c+=m/r.t;
        }
        return c>=n;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        long n  =Long.parseLong(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        R[] ar = new R[q];

        int i = 0;
        while(i<q){
            if(!st.hasMoreTokens()){
                st = new StringTokenizer(br.readLine());
            }
            int tmp = Integer.parseInt(st.nextToken());
            ar[i] = new R(tmp);
            i++;
        }
        if(n<=q){
            sb.append(n);
            bw.write(sb.toString());
            bw.flush();
            bw.close();
            br.close();
            return;
        }

        long l = 1, h = 60000000000L, m = 0, tm = 0;

        while (l<=h){
            m = (l+h)/2;
            if(ck(m,ar,q,n)){
                tm=m;
                h = m -1;
            }else{
                l = m+1;
            }
        }

        long cp = q;
        for(R r:ar){
            cp+=(tm-1)/r.t;
        }

        int an = 0;
        for(int j =0;j<q;j++){
            if(tm%ar[j].t==0){
                cp++;
                if(cp==n){
                    an=j+1;
                    break;
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