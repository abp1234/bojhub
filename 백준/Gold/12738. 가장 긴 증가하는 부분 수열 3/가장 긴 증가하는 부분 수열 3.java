import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    static int[] arr, dp;
    static ArrayList<Integer> v = new ArrayList<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        arr = new int[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1;i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        v.add(arr[1]);
        for(int i = 2; i<= n;i++){
            if(v.get(v.size() - 1)< arr[i]){
                v.add(arr[i]);
            }else{
                int pos = Collections.binarySearch(v, arr[i]);
                if (pos < 0) pos = -(pos+1);
                v.set(pos, arr[i]);
            }
        }

        sb.append(v.size());
        bw.write(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }

}