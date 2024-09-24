import java.util.*;


class Nde{
    int[] ary;
    boolean vst;
    int cst;

    Nde(int[] ary, int cst){
        this.ary = ary.clone();
        this.vst = false;
        this.cst = cst;
    }
}

public class Main{

    public static Map<Integer, Nde> slv(int[] ary, List<int[]> ops){
        Map<Integer, Nde> grf = new HashMap<>();
        int key = Arrays.hashCode(ary);
        grf.put(key, new Nde(ary,0));
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
    
        pq.add(new int[]{0, key});

        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int cst = curr[0];
            int currKey = curr[1];
            Nde nde = grf.get(currKey);

            if (nde.vst) {
                continue;
            }

            for(int[] op:ops){
                int l =op[0],r=op[1],nCost =op[2];
                int[] tmp = nde.ary.clone();
                int nxtCost = cst + nCost;

                int t = tmp[l];
                tmp[l] =tmp[r];
                tmp[r]=t;

                int nKey = Arrays.hashCode(tmp);

                if(!grf.containsKey(nKey)){
                    grf.put(nKey, new Nde(tmp, nxtCost));
                    pq.add(new int[]{nxtCost, nKey});
                } else if (nxtCost<grf.get(nKey).cst){
                    grf.get(nKey).cst = nxtCost;
                    pq.add(new int[]{nxtCost, nKey});
                }
            }
            nde.vst = true;
        }
        return grf;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] ary = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            ary[i] = sc.nextInt();
        }

        int M = sc.nextInt();
        List<int[]> ops = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int c = sc.nextInt();
            ops.add(new int[]{l, r, c});
        }

        int[] tgt = ary.clone();
        Arrays.sort(tgt);

        Map<Integer, Nde> grf = slv(ary, ops);

        int tgtKey = Arrays.hashCode(tgt);
        if (grf.containsKey(tgtKey)) {
            System.out.println(grf.get(tgtKey).cst);
        } else {
            System.out.println(-1);
        }
    }
}