package Tree;

import java.util.ArrayDeque;
import java.util.Scanner;

public class GraphDemo {

    private static Scanner input = new Scanner(System.in);
    private static int visited[] = new int[Constant.MAXVEX];

    public static void main(String[] args) {

        adjMatrixGraph adjMatrixGraph = new adjMatrixGraph();

        adjListGraph adjListGraph = new adjListGraph();

//        createAdjMatrixGraph(adjMatrixGraph);
//
//        printAdjMatrixGraph(adjMatrixGraph);

        createAdjListGraph(adjListGraph);

        printAdjListGraph(adjListGraph);

//        DFS(adjListGraph);

        BFS(adjListGraph);
    }

    /**
     * (1)访问顶点v,visited[v] = 1;
     * (2)w = v 的下一个临接点;
     * (3)while(w)存在{
     *     if(w未被访问){
     *         从顶点w出发递归执行该算法;
     *     }
     *     w = 顶点v的下一个临接点;
     * }
     * @param G 邻接表
     */
    public static void DFS(adjListGraph G,int v) {
        edgeNode p;
        visited[v] = 1;
        System.out.println(G.adjList[v].data);
        p = G.adjList[v].firstEdge;
        while (p != null) {
            if (visited[p.adjvex] != 1) {
                DFS(G,p.adjvex);
            }
            p = p.next;
        }
    }

    public static void DFS(adjListGraph G) {
        for (int i = 0; i < G.numVertexes; i++) {
            if (visited[i] != 1) {
                DFS(G, i);
            }
        }
    }

    /**
     * (1)访问顶点v,visited[v] = 1;
     * (2)顶点v入队列;
     * (3)while(队列非空){
     *     v = 队列的首元素出队
     *     w = 顶点v的第一个临接点
     *     while(w存在){
     *         if(w未访问){
     *             访问顶点w,visited[w] = 1;
     *             顶点w入队列
     *         }
     *         w = 顶点v的下一个临接点
     *     }
     * }
     * @param G 邻接表
     */
    public static void BFS(adjListGraph G) {
        edgeNode p;
        ArrayDeque<Integer> Q = new ArrayDeque();

        for (int i = 0,v; i < G.numVertexes; i++) {
            if (visited[i] != 1) {
                //访问顶点v并入队列
                System.out.println(G.adjList[i].data);
                visited[i] = 1;
                Q.add(i);
                while (!Q.isEmpty()) {
                    v = Q.remove();
                    p = G.adjList[v].firstEdge;
                    while (p != null) {
                        if (visited[p.adjvex] != 1) {
                            System.out.println(G.adjList[p.adjvex].data);
                            visited[p.adjvex] = 1;
                            Q.add(p.adjvex);
                        }
                        p = p.next;
                    }
                }
            }
        }
    }

    private static void createAdjMatrixGraph(adjMatrixGraph G) {
        System.out.print("请输入图的顶点数和边数：");
        G.numVertexes = input.nextInt();
        G.numEdges = input.nextInt();
        //初始化 --- 边和顶点
        for (int i = 0; i < G.numVertexes; i++) {
            for (int j = 0; j < G.numVertexes; j++) {
                G.arc[i][j] = Constant.INFINITY;
            }
        }
        System.out.println("请输入点信息：");
        for (int i = 0; i < G.numVertexes; i++) {
            System.out.print("请输入第" + (i + 1) + "个顶点：");
            G.vexs[i] = input.next();
        }
        System.out.println("请输入边信息：");
        for (int i = 0; i < G.numEdges; i++) {
            System.out.print("请输入第" + (i + 1) + "条边：");
            String edge = input.next();
            //基本数据类型.toString()是最快的方式、String.valueOf(数据)次之、数据+”"最慢
            int j = 0;
            int k = 0;
            for (; !String.valueOf(edge.charAt(0)).equals(G.vexs[j]) && j < G.numEdges - 1; j++) ;
            for (; !String.valueOf(edge.charAt(1)).equals(G.vexs[k]) && k < G.numEdges - 1; k++) ;

            G.arc[j][k] = 1;
        }
    }

    private static void printAdjMatrixGraph(adjMatrixGraph G) {
        System.out.println("您输入的邻接矩阵如下：");
        for (int i = 0; i < G.numVertexes; i++) {
            for (int j = 0; j < G.numVertexes; j++) {
                if (G.arc[i][j] == Constant.INFINITY) {
                    System.out.print("0 ");
                } else {
                    System.out.print(G.arc[i][j] + " ");
                }
            }
            System.out.println();
        }
        for (int i = 0; i < G.numVertexes; i++) {
            int in = 0;
            int out = 0;
            for (int j = 0; j < G.numVertexes; j++) {
                if (G.arc[i][j] == 1) {
                    out++;
                }
                if (G.arc[j][i] == 1) {
                    in++;
                }
            }
            System.out.println("顶点：" + G.vexs[i] + " 出度：" + out + " 入度：" + in);
        }
    }

    private static void createAdjListGraph(adjListGraph G) {

        System.out.print("请输入图的顶点数和边数：");
        G.numVertexes = input.nextInt();
        G.numEdges = input.nextInt();

        System.out.println("请输入点信息：");
        for (int i = 0; i < G.numVertexes; i++) {
            G.adjList[i] = new vertexNode();
            System.out.print("请输入第" + (i + 1) + "个顶点：");
            //设置顶点信息
            G.adjList[i].data = input.next();
            G.adjList[i].firstEdge = null;
        }

        System.out.println("请输入边信息：");
        for (int i = 0; i < G.numEdges; i++) {
            System.out.print("请输入第" + (i + 1) + "条边：");
            String edge = input.next();
            //基本数据类型.toString()是最快的方式、String.valueOf(数据)次之、数据+”"最慢
            int j = 0;
            int k = 0;
            for (; !String.valueOf(edge.charAt(0)).equals(G.adjList[j].data) && j < G.numEdges - 1; j++)
                ;
            for (; !String.valueOf(edge.charAt(1)).equals(G.adjList[k].data) && k < G.numEdges - 1; k++)
                ;

            //头插法添加新的边
            edgeNode edgeNode = new edgeNode();
            edgeNode.adjvex = k;
            edgeNode.next = G.adjList[j].firstEdge;
            G.adjList[j].firstEdge = edgeNode;
        }
    }

    private static void printAdjListGraph(adjListGraph G) {
        edgeNode edge;
        System.out.println("您输入的临接表如下：");
        for (int i = 0; i < G.numVertexes; i++) {
            edge = G.adjList[i].firstEdge;
            System.out.print("顶点:" + G.adjList[i].data + "--> ");
            while (edge != null) {
                System.out.print(G.adjList[edge.adjvex].data + " ");
                edge = edge.next;
            }
            System.out.println();
        }

        int in, out;
        for (int i = 0; i < G.numVertexes; i++) {
            in = out = 0;
            System.out.print("顶点" + G.adjList[i].data + "：");
            edge = G.adjList[i].firstEdge;
            while (edge != null) {
                out++;
                edge = edge.next;
            }

            System.out.print(" 出度：" + out);

            for (int j = 0; j < G.numVertexes; j++) {
                edge = G.adjList[j].firstEdge;
                while (edge != null) {
                    if (edge.adjvex == i) {
                        in++;
                    }
                    edge = edge.next;
                }
            }

            System.out.println(" 入度：" + in);
        }
    }
}
