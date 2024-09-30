import java.util.*;

class St{
    int[] val = new int[7];
    boolean[] zero = new boolean[7];
    int[] cnt = new int[7];
}

public class Main{
    static final long MOD = 1000000007L;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];

        for(int i=0;i<n;i++)a[i]=sc.nextInt();
        for(int i=0;i<m;i++)b[i]=sc.nextInt();

        St st = new St();
        for (int i=0;i<7;i++)st.val[i]=i;
        Arrays.fill(st.zero, false);
        Arrays.fill(st.cnt, 0);

        for(int i=0;i<n;i++)st.cnt[a[i]%7]++;

        long pl =0;
        for(int i=0;i<m;i++){
            St newSt = copySt(st);

            for(int j=0;j<7;j++){
                if(st.zero[j])continue;
                newSt.val[j]=(st.val[j]+b[i])%7;
                if(newSt.val[j]==0){
                    newSt.cnt[j]=0;
                    newSt.zero[j]=true;
                }
            }

            if(Arrays.stream(newSt.cnt).sum() !=0){
                pl =(pl+b[i])%MOD;
                st = newSt;
            }
        }

        List<Long> res = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(!st.zero[a[i]%7]){
                res.add((a[i]+pl)%MOD);
            }
        }
        System.out.println(res.size());
        for(long x : res){
            System.out.print(x+" ");
        }
    }

    static St copySt(St st) {
        // TODO Auto-generated method stub
        //throw new UnsupportedOperationException("Unimplemented method 'copySt'");
        St newSt = new St();
        System.arraycopy(st.val, 0, newSt.val, 0, 7);
        System.arraycopy(st.zero, 0, newSt.zero, 0, 7);
        System.arraycopy(st.cnt, 0, newSt.cnt, 0, 7);
        return newSt;
    }
}