import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    static class ST{
        long v;
        ST(long v){this.v = v;}
    }

    public static void main(String[] args) throws Exception{

        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        var sb = new StringBuilder();

        var tk = new StringTokenizer(br.readLine());

        long n = Long.parseLong(tk.nextToken());

        ST st = new ST(n);

        long an = st.v;

        for(long i = 2; i*i <=st.v;i++){
            if(st.v%i !=0) continue;
            an -= an/i;
            while(st.v%i==0){
                st.v /= i;
            }
        }
        if(st.v>1){
            an-=an/st.v;
        }
        sb.append(an);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}