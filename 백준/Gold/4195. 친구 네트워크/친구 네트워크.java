import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Main {
    static int[] par;
    static int[] cnt;
    static HashMap<String,Integer> mp;
    static int idx;

    static int fd(int x){
        if(par[x]==x)return x;
        return par[x]=fd(par[x]);
    }

    static int un(int a,int b){
        a=fd(a);
        b=fd(b);
        if(a==b) return cnt[a];
        par[b]=a;
        cnt[a]+=cnt[b];
        return cnt[a];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int F = Integer.parseInt(br.readLine());
            par = new int[F*2];
            cnt = new int[F*2];
            mp = new HashMap<>();
            idx = 0;
            for (int i = 0; i < F; i++) {
                st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();

                if(!mp.containsKey(a)){
                    mp.put(a,idx);
                    par[idx]=idx;
                    cnt[idx++]=1;
                }
                if(!mp.containsKey(b)){
                    mp.put(b,idx);
                    par[idx]=idx;
                    cnt[idx++]=1;
                }
                int r = un(mp.get(a),mp.get(b));
                sb.append(r).append("\n");
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}



//union -find진행

// 부모 관계를 기록할, 배열과 해당 인덱스가 어떤 친구를 가르키는지 기록할 딕셔너리 선언

// 친구관계가 주어지면, 해당 친구들의 부모관계 기록 배열상 어떤 인덱스인지 파악하기 위해, 딕셔너리 찾기

// 유니온 파인드 진행 후 해당 집합의 갯수 를 계산 후 리턴



