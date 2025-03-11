import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());

        String s = br.readLine();

        st = new StringTokenizer(br.readLine());
        long m = Long.parseLong(st.nextToken());

        long[][] ed = new long[26][26];

        for(int i = 0; i < m;i++){
            String t = br.readLine();
            int a = t.charAt(0) - 'a';
            int b = t.charAt(1) - 'a';
            ed[a][b]=i+1;
        }

        long an =0;

        for(int i= 0;i<n-1;i++){
            List<Long> sq = new ArrayList<>();

            while (i<n-1&&ed[s.charAt(i)-'a'][s.charAt(i+1)-'a']!=0){
                sq.add(ed[s.charAt(i)-'a'][s.charAt(i+1)-'a']);
                i++;
            }

            if(sq.size()<m){
                continue;
            }

            long[] ct = new long[(int)(m+1)];
            int l =0;
            int ck =0;

            for(int r = 0;r<sq.size();r++){
                int idx = sq.get(r).intValue();
                ct[idx]++;
                if (ct[idx] == 1) {
                    ck++;
                }
                if(ck==m){
                    while (ct[sq.get(l).intValue()]>1){
                        ct[sq.get(l).intValue()]--;
                        l++;
                    }
                    an+=(l+1);
                }
            }
        }
        sb.append(an);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();


    }

}