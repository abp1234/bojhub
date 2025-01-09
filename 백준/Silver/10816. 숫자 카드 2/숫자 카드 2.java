import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main{

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine().trim());
        int[] ns = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        for(int i =0;i<n;i++){
            ns[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine().trim());
        int[] ms = new int[m];
        st = new StringTokenizer(br.readLine().trim());
        for(int i = 0; i < m;i++){
            ms[i] = Integer.parseInt(st.nextToken());
        }

        Map<Integer, Integer> cntMap = new HashMap<>();
        for(int num : ns){
            cntMap.put(num, cntMap.getOrDefault(num, 0)+1);
        }

        StringBuilder sb = new StringBuilder();
        for(int num : ms){
            sb.append(cntMap.getOrDefault(num, 0)).append(" ");
        }

        bw.write(sb.toString().trim());
        bw.flush();
        br.close();
        bw.close();
    }
}