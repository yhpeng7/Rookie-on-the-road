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

        private adjListGraph adjListGraph;

        public adjList.adjListGraph getAdjListGraph() {
            return adjListGraph;
        }

        public void setAdjListGraph(adjList.adjListGraph adjListGraph) {
            this.adjListGraph = adjListGraph;
        }

        final class vertexNode {

            private vertexType data;

            private edgeNode firstedge;

            public vertexType getData() {
                return data;
            }

            public void setData(vertexType data) {
                this.data = data;
            }

            public edgeNode getFirstedge() {
                return firstedge;
            }

            public void setFirstedge(edgeNode firstedge) {
                this.firstedge = firstedge;
            }
        }

        final class edgeNode {

            int adjvex;

            edgeType weight;

            edgeNode next;

            public int getAdjvex() {
                return adjvex;
            }

            public void setAdjvex(int adjvex) {
                this.adjvex = adjvex;
            }

            public edgeType getWeight() {
                return weight;
            }

            public void setWeight(edgeType weight) {
                this.weight = weight;
            }

            public edgeNode getNext() {
                return next;
            }

            public void setNext(edgeNode next) {
                this.next = next;
            }
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

    public vertexType(String point) {
        this.point = point;
    }

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
