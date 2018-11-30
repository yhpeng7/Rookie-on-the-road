package Tree;

import java.util.Scanner;

public class GraphDemo {

    private Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

        GraphStore graphStore = new GraphStore();

        //图的存储集合
        GraphDemo demo = new GraphDemo();

        GraphStore.adjMatrixGraph adjMatrixGraph = graphStore.new adjMatrixGraph();

        GraphStore.adjList adjList = graphStore.new adjList();

//        demo.createAdjMatrixGraph(adjMatrixGraph);

//        demo.printAdjMatrixGraph(adjMatrixGraph);

        demo.createAdjListGraph(adjList);

        demo.printAdjListGraph(adjList);
    }

    private void createAdjMatrixGraph(GraphStore.adjMatrixGraph G) {
        System.out.print("请输入图的顶点数和边数：");
        G.setNumVertexes(input.nextInt());
        G.setNumEdges(input.nextInt());
        //初始化 --- 边和顶点
        for (int i = 0; i < G.getNumVertexes(); i++) {

            for (int j = 0; j < G.getNumVertexes(); j++) {
                G.getArc()[i][j] = new edgeType();
                G.getArc()[i][j].setValue(Constant.INFINITY);
            }
        }
        System.out.println("请输入点信息：");
        for (int i = 0; i < G.getNumVertexes(); i++) {
            System.out.print("请输入第" + (i + 1) + "个顶点：");
            G.getVexs()[i] = new vertexType(input.next());
        }
        System.out.println("请输入边信息：");
        for (int i = 0; i < G.getNumEdges(); i++) {
            System.out.print("请输入第" + (i + 1) + "条边：");
            String edge = input.next();
            //基本数据类型.toString()是最快的方式、String.valueOf(数据)次之、数据+”"最慢
            int j = 0;
            int k = 0;
            for (; !String.valueOf(edge.charAt(0)).equals(G.getVexs()[j].getPoint()) && j < G.getNumEdges() - 1; j++);
            for (; !String.valueOf(edge.charAt(1)).equals(G.getVexs()[k].getPoint()) && k < G.getNumEdges() - 1; k++);

            G.getArc()[j][k].setValue(1);
        }
    }

    private void printAdjMatrixGraph(GraphStore.adjMatrixGraph G) {
        System.out.println("您输入的邻接矩阵如下：");
        for (int i = 0; i < G.getNumVertexes(); i++) {
            for (int j = 0; j < G.getNumVertexes(); j++) {
                if (G.getArc()[i][j].getValue() == Constant.INFINITY) {
                    System.out.print("0 ");
                } else {
                    System.out.print(G.getArc()[i][j].getValue() + " ");
                }
            }
            System.out.println();
        }
        for (int i = 0; i < G.getNumVertexes(); i++) {
            int in = 0;
            int out = 0;
            for (int j = 0; j < G.getNumVertexes(); j++) {
                if (G.getArc()[i][j].getValue() == 1) {
                    out++;
                }
                if (G.getArc()[j][i].getValue() == 1) {
                    in++;
                }
            }
            System.out.println("顶点：" + G.getVexs()[i].getPoint() + " 出度：" + out + " 入度：" + in);
        }
    }

    private void createAdjListGraph(GraphStore.adjList G) {
        GraphStore.adjList.adjListGraph adjListGraph = G.new adjListGraph();
        G.setAdjListGraph(adjListGraph);
        System.out.print("请输入图的顶点数和边数：");
        adjListGraph.setNumVertexes(input.nextInt());
        adjListGraph.setNumEdges(input.nextInt());

        System.out.println("请输入点信息：");
        for (int i = 0; i < adjListGraph.getNumVertexes(); i++) {
            adjListGraph.getAdjList()[i] = G.new vertexNode();
            System.out.print("请输入第" + (i + 1) + "个顶点：");
            //设置顶点信息
            adjListGraph.getAdjList()[i].setData(new vertexType(input.next()));
            adjListGraph.getAdjList()[i].setFirstedge(null);
        }

        System.out.println("请输入边信息：");
        for (int i = 0; i < adjListGraph.getNumEdges(); i++) {
            System.out.print("请输入第" + (i + 1) + "条边：");
            String edge = input.next();
            //基本数据类型.toString()是最快的方式、String.valueOf(数据)次之、数据+”"最慢
            int j = 0;
            int k = 0;
            for (; !String.valueOf(edge.charAt(0)).equals(adjListGraph.getAdjList()[j].getData().getPoint()) && j < adjListGraph.getNumEdges() - 1; j++);
            for (; !String.valueOf(edge.charAt(1)).equals(adjListGraph.getAdjList()[k].getData().getPoint()) && k < adjListGraph.getNumEdges() - 1; k++) ;

            //头插法添加新的边
            GraphStore.adjList.edgeNode edgeNode = G.new edgeNode();
            edgeNode.setAdjvex(k);
            edgeNode.setNext(adjListGraph.getAdjList()[j].getFirstedge());
            adjListGraph.getAdjList()[j].setFirstedge(edgeNode);
        }
    }

    private void printAdjListGraph(GraphStore.adjList G) {
        GraphStore.adjList.edgeNode edge;
        System.out.println("您输入的临接表如下：");
        for (int i = 0; i < G.getAdjListGraph().getNumVertexes(); i++) {
            edge = G.getAdjListGraph().getAdjList()[i].getFirstedge();
            System.out.print("顶点:" + G.getAdjListGraph().getAdjList()[i].getData().getPoint() + "--> ");
            while (edge != null) {
                System.out.print(G.getAdjListGraph().getAdjList()[edge.getAdjvex()].getData().getPoint() + " ");
                edge = edge.getNext();
            }
            System.out.println();
        }

        int in, out;
        for (int i = 0; i < G.getAdjListGraph().getNumVertexes(); i++) {
            in = out = 0;
            System.out.print("顶点" + G.getAdjListGraph().getAdjList()[i].getData().getPoint() + "：");
            edge = G.getAdjListGraph().getAdjList()[i].getFirstedge();
            while (edge != null) {
                out++;
                edge = edge.getNext();
            }

            System.out.print(" 出度：" + out);

            for (int j = 0; j < G.getAdjListGraph().getNumVertexes(); j++) {
                edge = G.getAdjListGraph().getAdjList()[j].getFirstedge();
                while (edge != null) {
                    if (edge.getAdjvex() == i) {
                        in++;
                    }
                    edge = edge.getNext();
                }
            }

            System.out.println(" 入度：" + in);
        }
    }
}
