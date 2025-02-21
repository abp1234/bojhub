import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] pr = new int[N][];
        String[] ps = new String[N];

        for(int i = 0; i < N; i++){
            int ml = Integer.parseInt(br.readLine());
            pr[i] = new int[ml];
            st = new StringTokenizer(br.readLine());
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < ml;j++){
                pr[i][j]=Integer.parseInt(st.nextToken());
                if(j>0)sb.append(" ");
                sb.append(pr[i][j]);
            }
            ps[i]=sb.toString();
        }
        boolean res = false;
        for(int i = 0;i<=pr[0].length-K;i++){
            StringBuilder sb = new StringBuilder();
            for(int j = i; j < i + K;j++){
                if(j>i)sb.append(" ");
                sb.append(pr[0][j]);
            }
            String pt = sb.toString();

            sb = new StringBuilder();
            for(int j = i + K - 1; j >= i; j--){
                if(j<i+K-1)sb.append(" ");
                sb.append(pr[0][j]);
            }
            String rp = sb.toString();

            boolean fl = true;
            for(int j = 1; j < N;j++){
                if(km(ps[j],pt).size()>0 || km(ps[j],rp).size()>0){
                    continue;
                }else{
                    fl=false;
                    break;
                }
            }
            if(fl){
                res = true;
                break;
            }
        }
        bw.write(res ? "YES":"NO");
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
    public static int[] cp(String p){
        int[] tb = new int[p.length()];
        int i = 0;
        for(int j = 1; j < p.length();j++){
            while (i>0&&p.charAt(i)!=p.charAt(j)){
                i=tb[i-1];
            }
            if(p.charAt(i)==p.charAt(j)){
                i++;
                tb[j]=i;
            }
        }
        return tb;
    }
    public static ArrayList<Integer> km(String s, String p){
        int[] tb = cp(p);
        int i = 0;
        ArrayList<Integer> al = new ArrayList<Integer>();
        for(int j = 0;j<s.length();j++){
            while (i>0&&p.charAt(i)!=s.charAt(j)){
                i = tb[i-1];
            }
            if(p.charAt(i)==s.charAt(j)){
                i++;
                if(i==p.length()){
                    al.add(j-i+2);
                    i=tb[i-1];
                }
            }
        }
        return al;
    }
}