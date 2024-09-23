import kotlin.math.min

const val INF = 987654321

var n = 0
lateinit var map: Array<IntArray>
lateinit var dp: Array<IntArray>

fun dfs(cur: Int, visit: Int): Int{
    if(visit==(1 shl n) - 1){
        return if(map[cur][0]==0)INF else map[cur][0]
    }

    if (dp[cur][visit] !=-1){
        return dp[cur][visit]
    }

    dp[cur][visit] = INF
    for(i in 0 until n){
        if(map[cur][i]==0)continue
        if(visit and (1 shl i) != 0) continue

        dp[cur][visit] = min(dp[cur][visit], map[cur][i]+ dfs(i, visit or (1 shl i)))
    }

    return dp[cur][visit]
}

fun main(){
    n = readLine()!!.toInt()
    map = Array(n){IntArray(n)}
    dp = Array(n){IntArray(1 shl n){-1}}
    for (i in 0 until n){
        map[i] = readLine()!!.split(" ").map { it.toInt()}.toIntArray()
    }

    println(dfs(0,1))
}