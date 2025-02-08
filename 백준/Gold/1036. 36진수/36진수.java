import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static final String NUM36 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static int N, K;

    static String toBase36(BigInteger num){
        if(num.equals(BigInteger.ZERO))return "0";
        StringBuilder sb = new StringBuilder();
        BigInteger base = BigInteger.valueOf(36);
        while (num.compareTo(BigInteger.ZERO)>0){
            BigInteger[] divRem = num.divideAndRemainder(base);
            sb.append(NUM36.charAt(divRem[1].intValue()));
            num=divRem[0];
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        List<String> nums = new ArrayList<>();

        for (int i = 0; i<N;i++){
            nums.add(br.readLine().trim());
        }

        K = Integer.parseInt(br.readLine().trim());

        BigInteger numSum = BigInteger.ZERO;
        List<List<Character>>numSep = new ArrayList<>();
        List<BigInteger> num36Diff = new ArrayList<>();

        for (String num : nums){
            List<Character> temp = new ArrayList<>();
            for(char ch : num.toCharArray()){
                temp.add(ch);
            }
            numSep.add(temp);
            numSum= numSum.add(new BigInteger(num,36));
        }

        for(char k : NUM36.toCharArray()){
            BigInteger numSumDiff = BigInteger.ZERO;
            for(List<Character> num : numSep){
                StringBuilder tempStr = new StringBuilder();
                for(char n : num){
                    if(n==k){
                        tempStr.append('Z');
                    }else{
                        tempStr.append(n);
                    }
                }
                numSumDiff=numSumDiff.add(new BigInteger(tempStr.toString(),36));
            }
            num36Diff.add(numSumDiff.subtract(numSum));
        }
        Collections.sort(num36Diff,Collections.reverseOrder());

        BigInteger gainSum= BigInteger.ZERO;
        for(int i = 0; i < K;i++){
            gainSum=gainSum.add(num36Diff.get(i));
        }
        BigInteger maxSum = numSum.add(gainSum);


        String result = toBase36(maxSum);
        System.out.println(result.isEmpty()?"0":result);
    }
}