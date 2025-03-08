import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {  
   
    static HashMap<String, List<String>> mp = new HashMap<String, List<String>>();
  
    static int nm = 0;
   
    static HashSet<String> fl = new HashSet<String>();

    
    static void ff(String sp) {
        var st = new Stack<String>();  
        st.push(sp);  
        while (!st.isEmpty()) {  
            String cp = st.pop();  
            var ls = mp.get(cp);   
            if (ls != null) {  
                for (String s : ls) {  
                    if (mp.containsKey(s)) {  
                        st.push(s);  
                    } else {  
                        fl.add(s);  
                        nm++;      
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));

        var st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        
        for (int i = 0; i < N + M; i++) {
            st = new StringTokenizer(br.readLine());
            String p = st.nextToken(); 
            String f = st.nextToken();  
            String c = st.nextToken();  
            if (!mp.containsKey(p)) {
          
                mp.put(p, new ArrayList<String>());
            }
            if (c.equals("1") && !mp.containsKey(f)) {
    
                mp.put(f, new ArrayList<String>());
            }
            mp.get(p).add(f);  
        }

        int Q = Integer.parseInt(br.readLine());  
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
 
        var sb = new StringBuilder(); 


        for (int i = 0; i < Q; i++) {
            fl = new HashSet<String>(); 
            nm = 0;                   
      
            String[] pa = br.readLine().trim().split("/");
            String sp = pa[pa.length - 1];  
            ff(sp);  
            sb.append(fl.size()).append(" ").append(nm).append("\n");
        }
        bw.write(sb.toString());  
        bw.flush();
        bw.close();
    }
}
