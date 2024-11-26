import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;


public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while((line =br.readLine() )!=null){
            String[] firstInput = line.split(" ");
            int n = Integer.parseInt(firstInput[0]);
            int a = Integer.parseInt(firstInput[1]);
            int b = Integer.parseInt(firstInput[2]);

            if(n==0)break;

            int[] bl = new int[n];
            List<Diff> df = new ArrayList<>();
            long sm = 0;

            for(int i=0;i<n;i++){
                String[] balloonInput = br.readLine().split(" ");
                int k = Integer.parseInt(balloonInput[0]);
                int ca = Integer.parseInt(balloonInput[1]);
                int cb = Integer.parseInt(balloonInput[2]);

                sm+=(long)k*ca;
                bl[i]=k;
                df.add(new Diff(cb-ca,i));
                a-=k;
            }

            df.sort(Comparator.comparingInt(o->o.d));

            int i=0;
            while(i<n){
                Diff cur = df.get(i);
                int d = cur.d;
                int idx = cur.idx;
                int k = bl[idx];

                if(a+k>0)break;
                a+=k;
                b-=k;
                sm+=(long)d*k;
                i++;
            }
            if(i<n){
                Diff cur = df.get(i);
                int d=cur.d;
                int idx=cur.idx;
                int k=bl[idx];

                bl[idx]+=a;
                sm-=(long)d*a;
                b+=a;

                while(i<n){
                    cur=df.get(i);
                    d=cur.d;
                    idx=cur.idx;
                    k=bl[idx];

                    if(d>=0||b-k<0)break;
                    b-=k;
                    sm+=(long)d*k;
                    i++;
                }

                if(d<0){
                    sm+=(long)d*b;
                }
            }
            System.out.println(sm);
        }

    }
    static class Diff{
        int d;
        int idx;

        Diff(int d, int idx){
            this.d=d;
            this.idx=idx;
        }
    }
}