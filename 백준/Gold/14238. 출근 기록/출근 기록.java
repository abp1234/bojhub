import java.io.*;
import java.util.*;

class Main{
    static final int A = 0, B = 1, C = 2;
    static int[] cnt = new int[3];
    static char[] ans;
    static boolean[][][][][] dp;

    static boolean dfs(int a, int b, int c, int[] prev) throws IOException{
        if(a==cnt[A]&&b==cnt[B]&&c==cnt[C]){
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            bw.write(String.valueOf(ans));
            bw.flush();
            bw.close();
            System.exit(0);
        }
        if(dp[a][b][c][prev[0]][prev[1]]){
            return false;
        }
        dp[a][b][c][prev[0]][prev[1]]=true;
        if(a+1<=cnt[A]){
            ans[a+b+c]='A';
            if(dfs(a+1,b,c,new int[]{prev[1],A})){
                return true;
            }
        }
        if(b+1<=cnt[B]){
            ans[a+b+c]='B';
            if(prev[1]!=B){
                if(dfs(a,b+1,c,new int[]{prev[1],B})){
                    return true;
                }
            }
        }
        if(c+1<=cnt[C]){
            ans[a+b+c]='C';
            if(prev[0]!=C&&prev[1]!=C){
                if(dfs(a,b,c+1,new int[]{prev[1],C})){
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine().trim();

        int len = s.length();
        ans = new char[len];

        cnt[A]=(int)s.chars().filter(ch->ch=='A').count();
        cnt[B]=(int)s.chars().filter(ch->ch=='B').count();
        cnt[C]=(int)s.chars().filter(ch->ch=='C').count();

        dp = new boolean[len+1][len+1][len+1][3][3];
        if(!dfs(0,0,0,new int[]{0,0})){
            System.out.println(-1);
        }
    }

}