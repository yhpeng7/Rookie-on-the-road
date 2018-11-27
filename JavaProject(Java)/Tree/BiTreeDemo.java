package Tree;

import java.util.ArrayDeque;

public class BiTreeDemo {

    public static void main(String[] args) {
        BiTreeDemo demo = new BiTreeDemo();
        BiTNode BiTree = new BiTNode(new Data(41, "鹏"));

        demo.TreeInsert(BiTree, new Data(20, "枣"));
        demo.TreeInsert(BiTree, new Data(11, "天"));
        demo.TreeInsert(BiTree, new Data(29, "王"));
        demo.TreeInsert(BiTree, new Data(32, "楼"));

//        demo.InOrderTraverse(BiTree);
//        demo.levelOrder(BiTree);
    }

    private BiTNode TreeInsert(BiTNode T, Data value) {
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

    private void InOrderTraverse(BiTNode root) {
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

    private void levelOrder(BiTNode root) {
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
