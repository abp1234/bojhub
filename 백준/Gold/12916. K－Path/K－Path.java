import java.io.*;
import java.util.*;


class M{
    static final int mod = 1000000007;
    long[][] a;

    M(int n){
        a = new long[n][n];
    }

    static M mul(M x, M y, int n){
        M r = new M(n);
        for(int i = 0; i < n;i++){
            for(int k = 0; k<n;k++){
                for(int j =0;j<n;j++){
                    r.a[i][j]=(r.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
                }
            }
        }
        return r;
    }

    static M pow(M b, int n, int p){
        M r = new M(n);
        for(int i =0;i<n;i++)r.a[i][i]=1;
        while(p>0){
            if((p&1)==1)r=mul(r,b,n);
            b=mul(b,b,n);
            p>>=1;
        }
        return r;
    }

}

public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        M b = new M(n);
        for(int i = 0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            for(int j =0;j<n;j++){
                b.a[i][j]=Long.parseLong(st.nextToken());
            }
        }

        M r = M.pow(b,n,p);

        long c = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0;j<n;j++){
                c = (c+r.a[i][j])%M.mod;
            }
        }

        bw.write(c+"\n");
        bw.flush();
        bw.close();
        br.close();
    }
}