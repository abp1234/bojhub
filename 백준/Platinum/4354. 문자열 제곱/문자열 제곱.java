import java.io.*;

public class Main {

    static class ST{
        int[] tb;

        ST(int n){
            tb = new int[n];
        }
    }

    public static void main(String[] args) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        var sb = new StringBuilder();

        String tx = br.readLine();

        while(tx.charAt(0)!='.'){
            int sz = tx.length();

            ST st = new ST(sz);

            int[] tb = st.tb;

            int j = 0;
            for(int i = 1; i < sz; i++){
                while(j>0&&tx.charAt(i)!=tx.charAt(j)){
                    j = tb[j-1];
                }
                if(tx.charAt(i)==tx.charAt(j)){
                    tb[i] = ++j;
                }
            }

            int div = sz - tb[sz-1];
            if(sz%div!=0){
                sb.append(1).append("\n");
            }else{
                sb.append(sz/div).append("\n");
            }
            tx= br.readLine();
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }


}