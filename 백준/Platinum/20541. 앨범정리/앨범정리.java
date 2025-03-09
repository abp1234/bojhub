import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {

    static class Nd{
        String nm;
        int ac;
        int pc;
        TreeMap<String, Nd>ch;
        TreeSet<String> pi;
        Nd pa;

        Nd(String nm, Nd pa){
            this.nm = nm;
            this.pa = pa;
            this.ac = 0;
            this.pc = 0;
            this.ch = new TreeMap<String,Nd>();
            this.pi = new TreeSet<String>();
        }
    }

    static void ma(Nd cur, String s, StringBuilder sb){
        if(!cur.ch.containsKey(s)){
            cur.ch.put(s,new Nd(s,cur));
            Nd tm = cur;
            while(tm!=null){
                tm.ac++;
                tm = tm.pa;
            }
        }else{
            sb.append("duplicated album name\n");
        }
    }

    static void ra(Nd cur, String s, StringBuilder sb){

        if(cur.ch.isEmpty()){
            sb.append("0 0\n");
            return;
        }
        int ta, tp;
        if(s.equals("-1")){
            Map.Entry<String,Nd> en = cur.ch.firstEntry();
            ta=en.getValue().ac+1;
            tp=en.getValue().pc;
            cur.ch.remove(en.getKey());
        }else if(s.equals("0")){
            ta=cur.ac;
            tp=cur.pc - cur.pi.size();
            cur.ch.clear();
        }else if(s.equals("1")){
            Map.Entry<String,Nd> en = cur.ch.lastEntry();
            ta=en.getValue().ac+1;
            tp=en.getValue().pc;
            cur.ch.remove(en.getKey());
        }else{
            if(!cur.ch.containsKey(s)){
                sb.append("0 0\n");
                return;
            }
            Nd nd =cur.ch.get(s);
            ta = nd.ac+1;
            tp = nd.pc;
            cur.ch.remove(s);
        }

        sb.append(ta).append(" ").append(tp).append("\n");

        Nd tm =cur ;
        while(tm!=null){
            tm.ac -=ta;
            tm.pc-=tp;
            tm=tm.pa;
        }
    }

    static void in(Nd cur, String s, StringBuilder sb){
        if(!cur.pi.contains(s)){
            cur.pi.add(s);
            Nd tm =cur;
            while(tm!=null){
                tm.pc++;
                tm =tm.pa;
            }
        }else{
            sb.append("duplicated photo name\n");
        }
    }

    static void dl(Nd cur, String s, StringBuilder sb){
        if(cur.pi.isEmpty()){
            sb.append("0\n");
            return;
        }
        int tp = 0;
        if(s.equals("-1")){
            String f = cur.pi.first();
            cur.pi.remove(f);
            tp = 1;
        }else if(s.equals("0")){
            tp = cur.pi.size();
            cur.pi.clear();
        }else if(s.equals("1")){
            String l = cur.pi.last();
            cur.pi.remove(l);
            tp =1;
        }else{
            if(!cur.pi.contains(s)){
                sb.append("0\n");
                return;
            }
            cur.pi.remove(s);
            tp = 1;
        }
        sb.append(tp).append("\n");
        Nd tm = cur;
        while (tm!=null){
            tm.pc -=tp;
            tm = tm.pa;
        }
    }

    static Nd ca(Nd cur, String s, Nd rt, StringBuilder sb){
        if(s.equals("..")&&cur !=rt){
            cur = cur.pa;
        }else if(s.equals("/")&&cur!=rt){
            cur = rt;
        }else {
            if(cur.ch.containsKey(s)){
                cur = cur.ch.get(s);
            }
        }
        sb.append(cur.nm).append("\n");
        return cur;
    }

    public static void main(String[] args)throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        Nd rt = new Nd("album",null);
        Nd cr = rt;
        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            String ag = st.nextToken();

            if(op.equals("mkalb")){
                ma(cr,ag,sb);
            }else if(op.equals("rmalb")){
                ra(cr,ag,sb);
            }else if(op.equals("insert")){
                in(cr,ag,sb);
            }else if(op.equals("delete")){
                dl(cr,ag,sb);
            }else if(op.equals("ca")){
                cr = ca(cr,ag,rt,sb);
            }
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}