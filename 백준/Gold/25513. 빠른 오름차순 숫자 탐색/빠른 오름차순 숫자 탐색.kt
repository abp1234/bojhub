import java.util.*

fun main() {
    val N=5
    val check=Array(N){IntArray(N)}
    var cnt=0
    for (i in 0 until N){
        val inputs=readLine()!!.split(" ").map{it.toInt()}
        for (j in 0 until N){
            check[i][j]=inputs[j]
        }
    }
    val (r,c)=readLine()!!.split(" ").map{it.toInt()}
    val diry=intArrayOf(0,0,-1,1)
    val dirx=intArrayOf(-1,1,0,0)
    val q: Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(0,r*100+c))
    for (i in 1..6){
        val visited=Array(5){IntArray(5){1000} }
        val(cntt,idx)=q.peek()
        visited[idx/100][idx%100]=0
        var flag=0
        while (q.isNotEmpty()){
            val(cntt,idx)=q.poll()
            for (j in 0 until 4){
                var dy=diry[j]+idx/100
                var dx=dirx[j]+idx%100
                if(dy<0 || dx<0 || dy>=5 || dx>=5) continue
                if(check[dy][dx]==-1)continue
                if(check[dy][dx]==i){
                    flag=cntt+1
                    q.clear()
                    q.add(Pair(0,dy*100+dx))
                    break
                }
                if(visited[dy][dx]>cntt+1){
                    visited[dy][dx]=cntt+1
                    q.add(Pair(cntt+1,dy*100+dx))
                }
            }
            if(flag!=0)break
        }
        if(flag==0){
            cnt=-1
            break
        }
        cnt+=flag
    }
    println(cnt)
}