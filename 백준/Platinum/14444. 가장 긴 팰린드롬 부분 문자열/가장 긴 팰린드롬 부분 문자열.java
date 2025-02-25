import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    static class St{
        int r;
        int p;
        public St(){
            r = 0;
            p = 0;
        }
    }

    static int[] ma(char[] c){
        int n = c.length;
        int[] a = new int[n];
        var st = new St();
        for(int i = 0; i<n;i++){
            if(i<=st.r){
                a[i]=Math.min(a[2*st.p-i],st.r-i);
            }
            while (i-a[i]-1>=0&&i+a[i]+1<n&&c[i-a[i]-1]==c[i+a[i]+1]){
                a[i]++;
            }
            if(i+a[i]>st.r){
                st.r=i+a[i];
                st.p=i;
            }
        }
        return a;
    }

    public static void main(String[] args)throws IOException{
        var br = new BufferedReader(new InputStreamReader(System.in));
        String s= br.readLine();
        int  n = s.length();

        var al = new ArrayList<Character>();
        for(int i = 0; i < n;i++){
            al.add('@');
            al.add(s.charAt(i));
        }
        al.add('@');

        char[] c = new char[al.size()];
        for(int i = 0;i<al.size();i++){
            c[i]= al.get(i);
        }
        int[] a = ma(c);
        int m = Arrays.stream(a).max().getAsInt();
        System.out.println(m);
    }
}