package Tree;

import java.util.ArrayDeque;
import java.util.Scanner;

class BiTNode {

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

public class BiTreeDemo {

    private Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        BiTreeDemo demo = new BiTreeDemo();
        BiTNode BiTree = new BiTNode(new Data(27, "鹏"));

        TreeInsert(BiTree, new Data(20, "枣"));
        TreeInsert(BiTree, new Data(11, "天"));
        TreeInsert(BiTree, new Data(29, "王"));

        InOrderTraverse(BiTree);
//        levelOrder(BiTree);
    }

    private static BiTNode TreeInsert(BiTNode T, Data value) {
        if (T == null) {
            T = new BiTNode(value);
            T.lChild = null;
            T.rChild = null;
        } else if (value.id > T.data.id) {
            T.rChild = TreeInsert(T.rChild, value);
        } else if (value.id < T.data.id) {
            T.lChild = TreeInsert(T.lChild, value);
        }
        return T;
    }

    private static void InOrderTraverse(BiTNode root) {
        ArrayDeque stack = new ArrayDeque();
        BiTNode t = root;
        while (t != null || !stack.isEmpty()) {
            while (t != null) {
                stack.push(t);
                t = t.lChild;
            }
            if (!stack.isEmpty()) {
                t = (BiTNode) stack.pop();
                System.out.println(t.data.id + "    " + t.data.name);
                t = t.rChild;
            }
        }
    }

    private static void levelOrder(BiTNode root) {
        ArrayDeque queue = new ArrayDeque();
        BiTNode t = root;
        queue.add(t);
        while (!queue.isEmpty()) {
            t = (BiTNode) queue.remove();
            System.out.println(t.data.id + "    " + t.data.name);
            if (t.lChild != null) {
                queue.add(t.lChild);
            }
            if (t.rChild != null) {
                queue.add(t.rChild);
            }
        }
    }
}
