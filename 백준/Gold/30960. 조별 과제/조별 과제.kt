import java.util.*

fun main() {
    val N= readLine()!!.toInt()
    val A= readLine()!!.split(" ").map{it.toInt()}.toMutableList()
    A.sort()
    val half=(N-1)/2
    var arr_even=LongArray(half){0}
    var arr_odd=LongArray(half){0}
    for (i in 0 until N-1){
        if(i%2==0){
            if(i==0){
                arr_even[0]= (A[i+1]-A[i]).toLong()
            }else{
                arr_even[i/2]=(A[i+1]-A[i]+arr_even[i/2-1]).toLong()
            }
        }else{
            if(i==1){
                arr_odd[0]= (A[(N-i)]-A[N-i-1]).toLong()
            }else{
                arr_odd[i/2]=(A[(N-i)]-A[N-i-1]+arr_odd[i/2-1]).toLong()
            }
        }
    }
    var min_cnt=Long.MAX_VALUE
    if(N!=3){
        for(i in 0 until N-2 step 2){
            val awk= if (i==0){
                -A[i] + A[i + 2] +arr_odd[half-2]
            }
            else if(i==N-3){
                -A[i] + A[i + 2] +arr_even[half-2]
            }
            else{
                -A[i] + A[i + 2] + arr_even[i/2-1] + arr_odd[(N-i-1)/2-2]
            }
            min_cnt = minOf(awk, min_cnt)
        }
    } else{
        min_cnt= (-A[0] + A[ 2]).toLong()
    }

    println(min_cnt)
}