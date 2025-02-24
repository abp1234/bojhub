import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.Duration;
import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    static LocalDateTime cd(String d, String t){
        String[] a = d.split("-");
        int y = Integer.parseInt(a[0]);
        int m = Integer.parseInt(a[1]);
        int d0 = Integer.parseInt(a[2]);
        String[] b = t.split(":");
        int h = Integer.parseInt(b[0]);
        int mi = Integer.parseInt(b[1]);
        return LocalDateTime.of(y,m,d0,h,mi);
    }

    public static void main(String[] ag) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        var s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        String l = s[1];
        int f = Integer.parseInt(s[2]);

        var p = l.split("/");
        int dd = Integer.parseInt(p[0]);
        String tt = p[1];
        var q = tt.split(":");
        int hh = Integer.parseInt(q[0]);
        int mm = Integer.parseInt(q[1]);
        int ft = dd * 1440+hh*60+mm;

        Map<String, Map<String, LocalDateTime>> rt = new HashMap<String, Map<String, LocalDateTime>>();
        Map<String, Long> fe = new HashMap<String, Long>();

        for(int i = 0; i<n;i++){
            var t = br.readLine().split(" ");
            String d = t[0];
            String ti = t[1];
            String it = t[2];
            String m = t[3];
            LocalDateTime dt = cd(d,ti);

            if(!rt.containsKey(m)){
                rt.put(m, new HashMap<String, LocalDateTime>());
            }
            Map<String, LocalDateTime>mp = rt.get(m);
            if(mp.containsKey(it)){
                LocalDateTime st = mp.remove(it);

                long dm = Duration.between(st,dt).toMinutes();

                if(dm>ft){
                    fe.put(m,fe.getOrDefault(m,0L)+((dm-ft)*f));
                }
            }else{
                mp.put(it,dt);
            }
        }
        if(!fe.isEmpty()){
            TreeMap<String,Long>tm = new TreeMap<String, Long>(fe);
            for(Map.Entry<String,Long>e:tm.entrySet()){
                System.out.println(e.getKey()+" "+e.getValue());
            }
        }else{
            System.out.println(-1);
        }
    }
}