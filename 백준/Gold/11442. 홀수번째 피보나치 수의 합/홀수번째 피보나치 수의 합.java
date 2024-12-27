import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main{
    static final int MD =(int)1e9+7;

    static class MT {
        long[][] m = new long[2][2];

        MT(){
            m[0][0]=0;m[0][1]=1;
            m[1][0]=1;m[1][1]=1;
        }

        MT(long[][] mat){
            for(int i=0;i<2;i++){
                System.arraycopy(mat[i],0,m[i],0,2);
            }
        }

        MT mul(MT o){
            long[][] t = new long[2][2];
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        t[i][j]=(t[i][j]+m[i][k]*o.m[k][j]%MD)%MD;
                    }
                }
            }
            return new MT(t);
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        n+=(n%2!=0?1:0);

        MT r = new MT(new long[][]{{1,0},{0,1}});
        MT b = new MT();

        while(n>0){
            if((n&1)==1){
                r=r.mul(b);
            }
            b=b.mul(b);
            n>>=1;
        }
        bw.write(r.m[1][0]+"\n");
        bw.flush();
        bw.close();
        br.close();
    }
}