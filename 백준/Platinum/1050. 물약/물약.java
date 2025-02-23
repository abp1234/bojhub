import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static final int LI = 1000000000;

    static class PR<A,B>{
        A a;
        B b;
        PR(A a, B b){
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        ArrayList<PR<String, ArrayList<PR<Integer, String>>>> vl = new ArrayList<>();

        HashMap<String, Integer> ct = new HashMap<>();

        for(int i = 0; i < n;i++){
            String s = sc.next();
            int c = sc.nextInt();
            ct.put(s,c);
        }

        for(int i = 0; i<m;i++){
            String tm = sc.next();

            int p = tm.indexOf('=');
            String k = tm.substring(0,p);
            int ps = p+1;
            ArrayList<PR<Integer,String>> al = new ArrayList<>();

            while (true){
                int q = tm.indexOf('+',ps);
                if(q==-1){
                    q=tm.length();
                }
                String pt = tm.substring(ps,q);
                int mu = pt.charAt(0)-'0';
                String ig = pt.substring(1);

                ps = q + 1;
                if(!ct.containsKey(ig)){
                    ct.put(ig,-1);
                }
                al.add(new PR<>(mu,ig));
                if(q==tm.length())break;
            }
            if(!ct.containsKey(k))ct.put(k,-1);
            vl.add(new PR<>(k,al));
        }
        boolean fl = true;
        while (fl){
            fl =false;
            for(PR<String, ArrayList<PR<Integer, String>>>pr : vl){
                long sum = 0;
                String nm = pr.a;
                for(PR<Integer, String>pr2:pr.b){
                    int mu = pr2.a;
                    String ig = pr2.b;
                    if(ct.get(ig)!=-1){
                        sum+=mu*(long)ct.get(ig);
                        if(sum>LI){
                            sum=LI+1;
                        }
                    }else{
                        sum=-1;
                        break;
                    }
                }
                if(sum>0){
                    if(ct.get(nm)==-1||ct.get(nm)>sum){
                        ct.put(nm,(int)sum);
                        fl=true;
                    }
                }
            }

        }
        if(!ct.containsKey("LOVE")){
            System.out.println("-1");
        }else{
            System.out.println(ct.get("LOVE"));
        }
    }
}