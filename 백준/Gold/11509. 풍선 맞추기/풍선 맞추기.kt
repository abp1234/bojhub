fun main() {
    val N=readLine()!!.toInt()
    val check=IntArray(1000002)
    var cnt=0
    val inputs=readLine()!!.split(" ").map{it.toInt()}
    for (i in 0 until N) {
        val temp =inputs[i]
        if(check[temp+1]>0) {
            check[temp+1]--
            check[temp]++
        }else{
            check[temp]++
            cnt++
        }
    }
    println(cnt)
}