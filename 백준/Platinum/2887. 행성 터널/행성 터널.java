import java.util.*;


class Planet{
    int idx, x, y, z;

    Planet(int idx, int x, int y, int z){
        this.idx = idx;
        this.x = x;
        this.y = y;
        this.z = z;
    }

}

class Edge implements Comparable<Edge>{
    int cost, p1, p2;

    Edge(int cost, int p1, int p2){
        this.cost = cost;
        this.p1 = p1;
        this.p2 = p2;
    }

    @Override
    public int compareTo(Edge other){
        return this.cost - other.cost;
    }
}


public class Main{
    static int[] parent;

    static int findParent(int[] parent, int x){
        if(parent[x] != x){
            parent[x] = findParent(parent, parent[x]);
        }
        return parent[x];
    }

    static void unionParent(int[] parent, int a, int b){
        a = findParent(parent, a);
        b = findParent(parent, b);
        if(a<b){
            parent[b]=a;
        }else{
            parent[a]=b;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();


        List<Planet> planets = new ArrayList<>();

        for(int i=0;i<n;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            planets.add(new Planet(i, x, y, z));
        }
    
        List<Edge> edges = new ArrayList<>();

        addEdges(planets, edges, n, Comparator.comparingInt(p->p.x),'x');
        addEdges(planets, edges, n, Comparator.comparingInt(p->p.y), 'y');
        addEdges(planets, edges, n, Comparator.comparingInt(p-> p.z), 'z');

        Collections.sort(edges);

        parent = new int[n];
        for (int i=0;i<n;i++){
            parent[i]=i;
        } 

        int resultCost =0;
        for(Edge edge : edges){
            if(findParent(parent, edge.p1) != findParent(parent, edge.p2)){
                unionParent(parent, edge.p1, edge.p2);
                resultCost += edge.cost;
            }
        }
        System.out.println(resultCost);
    }

    static void addEdges(List<Planet> planets, List<Edge> edges, int n, Comparator<Planet> comparator, char axis){
        planets.sort(comparator);
        for(int i=1;i<n;i++){
            Planet p1 = planets.get(i-1);
            Planet p2 = planets.get(i);
        
            int cost = 0;
            if(axis =='x'){
                cost = Math.abs(p1.x - p2.x);
            } else if(axis =='y'){
                cost = Math.abs(p1.y - p2.y);
            }else if(axis =='z'){
                cost = Math.abs(p1.z - p2.z);
            }

            edges.add(new Edge(cost, p1.idx, p2.idx));
        }
    }

}