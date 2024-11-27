import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main{
    static final long M = 100000007L;


    static class  Mx{
        long[][] d;
        Mx(long[][] d){
            this.d =d;
        }
        public int r(){
            return d.length;
        }
        public int c(){
            return d[0].length;
        }

        public static Mx mul(Mx a, Mx b){
            int s1 = a.r();
            int s2 = a.c();
            int s3 = b.c();
            long[][] c = new long[s1][s3];
            for(int i =0;i<s1;i++){
                for(int j=0;j<s3;j++){
                    for(int k=0;k<s2;k++){
                        c[i][j]=(c[i][j]+a.d[i][k]*b.d[k][j])%M;
                    }
                }
            }
            return new Mx(c);
        }

        public static Mx expM(int x, Mx a){
            int sz = a.r();
            long[][] id = new long[sz][sz];
            for(int i=0;i<sz;i++){
                id[i][i]=1;
            }
            Mx r = new Mx(id);
            while(x>0){
                if(x%2==1){
                    r=mul(r,a);
                }
                a=mul(a,a);
                x/=2;
            }
            return r;
        }
    }

    static long expT(int x){
        long r = 1, a = 2;
        while(x>0){
            if(x%2==1){
                r=(r*a)%M;
            }
            a=(a*a)%M;
            x/=2;
        }
        return r;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while(t-->0){
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            if(k==0){
                sb.append(expT(n)%M).append('\n');
                continue;
            }
            long[] f =new long[k+1];
            f[0]=1;
            for(int i =1; i<=k;i++){
                f[i]=f[i-1];
                if(i-k-1>=0){
                    f[i]=(f[i]+f[i-k-1])%M;
                }
            }
            if(n<=k){
                sb.append(f[n]%M).append('\n');
                continue;
            }
            long[][] aData = new long[k+1][k+1];
            aData[0][0]=1;
            aData[0][k]=1;
            for(int i=1;i<=k;i++){
                aData[i][i-1]=1;
            }
            Mx a = new Mx(aData);
            Mx res = Mx.expM(n-k,a);
            long[][] xData = new long[k+1][1];
            for(int i=0;i<=k;i++){
                xData[i][0]=f[k-i];
            }
            Mx x = new Mx(xData);
            Mx ans = Mx.mul(res,x);
            sb.append(ans.d[0][0]%M).append('\n');
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}