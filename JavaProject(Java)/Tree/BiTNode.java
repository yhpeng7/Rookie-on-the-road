package Tree;

public class BiTNode {

    Data data;

    BiTNode lChild;

    BiTNode rChild;

    public BiTNode(Data data) {
        this.data = data;
    }
}

class Data {

    int id;

    String name;

    public Data(int id, String name) {
        this.id = id;
        this.name = name;
    }
}
