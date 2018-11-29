package Tree;

public final class GraphStore {

    final class adjMatrixGraph {

        private vertexType[] vexs;

        private edgeType[][] arc;

        private int numVertexes;
        private int numEdges;

        public adjMatrixGraph() {
            vexs = new vertexType[Constant.MAXVEX];
            arc = new edgeType[Constant.MAXVEX][Constant.MAXVEX];
        }

        public vertexType[] getVexs() {
            return vexs;
        }

        public edgeType[][] getArc() {
            return arc;
        }

        public int getNumVertexes() {
            return numVertexes;
        }

        public void setNumVertexes(int numVertexes) {
            this.numVertexes = numVertexes;
        }

        public int getNumEdges() {
            return numEdges;
        }

        public void setNumEdges(int numEdges) {
            this.numEdges = numEdges;
        }
    }

    final class adjList {

        final class vertexNode {

            private vertexType data;

            private edgeNode firstedge;
        }

        final class edgeNode {

            int adjvex;

            edgeType weight;

            edgeNode next;
        }

        final class adjListGraph {

            vertexNode[] adjList;

            int numVertexes;
            int numEdges;

            public adjListGraph() {
                adjList = new vertexNode[Constant.MAXVEX];
            }

            public vertexNode[] getAdjList() {
                return adjList;
            }

            public void setAdjList(vertexNode[] adjList) {
                this.adjList = adjList;
            }

            public int getNumVertexes() {
                return numVertexes;
            }

            public void setNumVertexes(int numVertexes) {
                this.numVertexes = numVertexes;
            }

            public int getNumEdges() {
                return numEdges;
            }

            public void setNumEdges(int numEdges) {
                this.numEdges = numEdges;
            }
        }
    }

}

final class vertexType {

    private String point;

    public String getPoint() {
        return point;
    }

    public void setPoint(String point) {
        this.point = point;
    }
}

final class edgeType {

    private int value;

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
