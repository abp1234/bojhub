import java.io.*;

public class Main{
    private static long A, HA, LA;
    private static int oneCnt;
    private static long one = 1, mask = 3;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        A = Long.parseLong(br.readLine());

        while(true){
            if(LA!=0&&HA!=0)break;
            if(one>A)break;

            if((A&mask)==(one<<1))getNearestLower();
            if((A&mask)==one)getNearestHigher();
            if((A&one)!=0)++oneCnt;

            one<<=1;
            mask<<=1;
        }
        bw.write(LA+" "+HA+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
    private static void getNearestLower(){
        LA = A^mask;
        LA=(LA/one)*one;
        long n = (one>>1);
        int cnt = oneCnt;
        while(n!=0&&cnt-->0){
            LA+=n;
            n>>=1;
        }
    }

    private static void getNearestHigher(){
        HA = A ^ mask;
        HA = (HA/one)*one;
        long n = 1;
        int cnt = oneCnt;
        while(n<one&&cnt-->0){
            HA+=n;
            n<<=1;
        }
    }

}