import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Nd {
    public final int y;
    public final int x;
    public Nd(int y, int x) {
        this.y = y;
        this.x = x;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Nd)) return false;
        Nd n = (Nd) o;
        return this.y == n.y && this.x == n.x;
    }
    @Override
    public int hashCode() {
        return 31 * y + x;
    }
}

public class Main{

    public static int bf(int a, int b, int c, int d){
        Deque<Nd> dq = new ArrayDeque<>();
        dq.add(new Nd(0,0));
        Map<Nd, Integer> vs = new HashMap<>();
        vs.put(new Nd(0,0),0);
        if(c==0&&d==0){
            return 0;
        }
        while (!dq.isEmpty()){
            Nd cur = dq.pollFirst();
            int cy = cur.y;
            int cx = cur.x;
            int st = vs.get(cur);

            if(vs.containsKey(new Nd(c,d))){
                return vs.get(new Nd(c,d));
            }

            Nd na = new Nd(a,cx);
            if(!vs.containsKey(na)){
                vs.put(na,st+1);
                dq.add(na);
            }
            Nd nb = new Nd(cy,b);
            if(!vs.containsKey(nb)){
                vs.put(nb,st+1);
                dq.add(nb);
            }

            Nd nc = new Nd(0,cx);
            if(!vs.containsKey(nc)){
                vs.put(nc, st+1);
                dq.add(nc);
            }

            Nd nd = new Nd(cy,0);
            if(!vs.containsKey(nd)){
                vs.put(nd,st+1);
                dq.add(nd);
            }

            if(cy<=b-cx){
                Nd ne = new Nd(0,cx+cy);
                if(!vs.containsKey(ne)){
                    vs.put(ne,st+1);
                    dq.add(ne);
                }
            }else{
                Nd nf = new Nd(cy - (b-cx),b);
                if(!vs.containsKey(nf)){
                    vs.put(nf,st+1);
                    dq.add(nf);
                }
            }
            if(cx<=a-cy){
                Nd ng = new Nd(cy+cx,0);
                if(!vs.containsKey(ng)){
                    vs.put(ng,st+1);
                    dq.add(ng);
                }
            }else{
                Nd nh = new Nd(a, cx-(a-cy));
                if(!vs.containsKey(nh)){
                    vs.put(nh,st+1);
                    dq.add(nh);
                }
            }
        }
        return -1;
    }
    public static void main(String[] at) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int ans = bf(a,b,c,d);

        sb.append(ans).append('\n');
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }
}