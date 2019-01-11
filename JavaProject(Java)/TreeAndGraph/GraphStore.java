package Tree;

/******************************临接矩阵存储图*****************************************/

final class adjMatrixGraph {

    String[] vexs;

    int[][] arc;

    int numVertexes;

    int numEdges;

    public adjMatrixGraph() {
        vexs = new String[Constant.MAXVEX];
        arc = new int[Constant.MAXVEX][Constant.MAXVEX];
    }
}

/******************************临接表存储图*****************************************/

final class adjListGraph {

    vertexNode[] adjList;

    int numVertexes;

    int numEdges;

    public adjListGraph() {
        adjList = new vertexNode[Constant.MAXVEX];
    }
}

final class vertexNode {

    String data;

    edgeNode firstEdge;

}

final class edgeNode {

    //临接点
    int adjvex;

    //权值
    int weight;

    edgeNode next;

}
