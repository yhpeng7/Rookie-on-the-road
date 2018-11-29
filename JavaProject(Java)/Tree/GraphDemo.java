package Tree;

import java.util.Scanner;

public class GraphDemo {

    private Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

        //图的存储集合
        GraphStore graphStore = new GraphStore();
        GraphDemo demo = new GraphDemo();

        GraphStore.adjMatrixGraph adjMatrixGraph = graphStore.new adjMatrixGraph();

        GraphStore.adjList adjList = graphStore.new GraphStore.adjList();

        demo.createAdjMatrixGraph(adjMatrixGraph);

        demo.printAdjMatrixGraph(adjMatrixGraph);

        demo.createAdjListGraph(adjList);

        demo.printAdjListGraph(adjList);
    }

    private void createAdjMatrixGraph(GraphStore.adjMatrixGraph G) {
        System.out.print("请输入图的顶点数和边数：");
        G.setNumVertexes(input.nextInt());
        G.setNumEdges(input.nextInt());
        //初始化 --- 边和顶点
        for (int i = 0; i < G.getNumVertexes(); i++) {
            G.getVexs()[i] = new vertexType();
            for (int j = 0; j < G.getNumVertexes(); j++) {
                G.getArc()[i][j] = new edgeType();
                G.getArc()[i][j].setValue(Constant.INFINITY);
            }
        }
        System.out.println("请输入点信息：");
        for (int i = 0; i < G.getNumVertexes(); i++) {
            System.out.print("请输入第" + (i + 1) + "个顶点：");
            G.getVexs()[i].setPoint(input.next());
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
        System.out.print("请输入图的顶点数和边数：");
        adjListGraph.setNumVertexes(input.nextInt());
        adjListGraph.setNumEdges(input.nextInt());

    }

    private void printAdjListGraph(GraphStore.adjList G) {
    }

}
