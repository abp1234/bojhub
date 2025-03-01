import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{
    static class Ptr{
        public int v;
        public Ptr(int v) {this.v = v;}
    }
    static class PR{
        public Ptr p;
        public Ptr r;
        public PR(int pVal, int rVal){
            p = new Ptr(pVal);
            r = new Ptr(rVal);
        }
    }


    public static int[] mn(String s){
        int n = s.length();
        int[] a = new int[n];
        PR pr = new PR(0,0);

        for(int i =0;i<n;i++){
            if(i<=pr.r.v){
                a[i]=Math.min(a[2*pr.p.v-i],pr.r.v-i);
            }
            while (i-a[i]-1>=0&&i+a[i]+1<n&&s.charAt(i-a[i]-1)==s.charAt(i+a[i]+1)){
                a[i]++;
            }
            if(i+a[i]>pr.r.v){
                pr.r.v = i +a[i];
                pr.p.v=i;
            }
        }
        return a;
    }
    public static void main(String[] args) throws IOException{
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            var in = br.readLine().trim();
            var sb = new StringBuilder();
            sb.append("@");
            for(char c : in.toCharArray()){
                sb.append(c).append("@");
            }
            var s = sb.toString();
            int n = s.length();
            int[] a = mn(s);
            int mx = Arrays.stream(a).max().getAsInt();
            System.out.println(mx);
        }
    }
}