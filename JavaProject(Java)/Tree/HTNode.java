package Tree;

public class HTNode {

    private int weight;

    private int parent;

    private int lChild;

    private int rChild;

    public HTNode(int weight, int parent, int lChild, int rChild) {
        this.weight = weight;
        this.parent = parent;
        this.lChild = lChild;
        this.rChild = rChild;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getParent() {
        return parent;
    }

    public void setParent(int parent) {
        this.parent = parent;
    }

    public int getlChild() {
        return lChild;
    }

    public void setlChild(int lChild) {
        this.lChild = lChild;
    }

    public int getrChild() {
        return rChild;
    }

    public void setrChild(int rChild) {
        this.rChild = rChild;
    }
}
