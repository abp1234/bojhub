import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class P{
    public int v;
    public P(int v){
        this.v = v;
    }
}

public class Main {
    static ArrayList<Integer> f(String p){
        int n = p.length();
        ArrayList<Integer> t = new ArrayList<Integer>(n);
        for (int i = 0;i<n;i++){
            t.add(0);
        }

        P j =new P(0);
        for(int i = 1; i<n;i++){
            while (j.v>0&&p.charAt(i)!=p.charAt(j.v)){
                j.v=t.get(j.v-1);
            }
            if(p.charAt(i)==p.charAt(j.v)){
                j.v++;
                t.set(i,j.v);
            }
        }
        return t;
    }

    public static void main(String[] args){
        var r = new Scanner(System.in);
        var s = r.nextLine().trim();
        var a =0;

        for(var i = 0; i < s.length();i++){
            var x = s.substring(i);
            var l = f(x);
            var m = Collections.max(l);
            a = Math.max(a,m);
        }
        System.out.println(a);
    }
}