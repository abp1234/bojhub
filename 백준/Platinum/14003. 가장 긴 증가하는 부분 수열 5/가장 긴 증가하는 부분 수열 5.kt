import java.util.Scanner

data class Elem(val num: Int, val idx: Int)

fun binarySearch(arr: List<Int>, num: Int): Int{
    var low = -1
    var high = arr.size

    while (low+1<high){
        val mid = (low +high)/2

        if(num>arr[mid]){
            low = mid
        }else{
            high = mid
        }
    }
    return high
}


fun main(){
    val sc = Scanner(System.`in`)
    sc.nextLine()
    val nums = sc.nextLine().split(" ").map{it.toInt()}.reversed().toMutableList()

    val lisArr = mutableListOf(-1000000001)
    val lisTotal = mutableListOf(Elem(-1000000001,0))

    while(nums.isNotEmpty()){
        val num = nums.removeAt(nums.size - 1)

        if(num > lisArr.last()){
            lisTotal.add(Elem(num, lisArr.size))
            lisArr.add(num)
        } else{
            val idx = binarySearch(lisArr, num)
            lisArr[idx] = num
            lisTotal.add(Elem(num, idx))
        }
    }

    var lisLength = lisArr.size - 1
    var lis = mutableListOf<Int>()

    while(lisTotal.isNotEmpty() && lisLength>0){
        val(num, idx)=lisTotal.removeAt(lisTotal.size - 1)
        if(idx==lisLength){
            lis.add(num)
            lisLength -=1
        }
    }

    println(lis.size)
    println(lis.reversed().joinToString(" "))

}