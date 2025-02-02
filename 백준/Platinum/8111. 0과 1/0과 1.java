import java.io.*;
import java.util.ArrayDeque;


public class Main{
    static class ND{
        String st;
        int id;
        ND(String st, int id){
            this.st = st;
            this.id = id;
        }
    }

    static ND[] vs;
    static int vd =0;
    static final int SZ = 20001;

    public static void main(String[] ar)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();

        int tc = Integer.parseInt(br.readLine());

        vs = new ND[SZ];
        for(int i = 0; i <SZ;i++){
            vs[i]=new ND("",0);
        }

        for(int i = 0; i< tc; i++){
            vd++;

            String ln = br.readLine();
            boolean ok = true;
            for(int j =0,L=ln.length();j<L;j++){
                char ch = ln.charAt(j);
                if(ch!='0'&&ch!='1'){
                    ok = false;
                    break;
                }
            }
            if(ok){
                sb.append(ln).append("\n");
            }else{
                int nm = Integer.parseInt(ln);
                sb.append(bfs(nm)).append("\n");
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
    static String bfs(int nm){
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.offer(1);
        vs[1].st="1";
        vs[1].id=vd;

        while (!dq.isEmpty()){
            int cu = dq.poll();
            if(vs[cu].st.length()==100){
                return "BRAK";
            }
            for(int d = 0; d <2;d++){
                int nx = (cu*10+d)%nm;
                if(nx!=0){
                    if(vs[nx].id!=vd){
                        vs[nx].st=vs[cu].st+d;
                        vs[nx].id =vd;
                        dq.offer(nx);
                    }
                }else{
                    return vs[cu].st+d;
                }
            }
        }
        return "BRAK";
    }
}
