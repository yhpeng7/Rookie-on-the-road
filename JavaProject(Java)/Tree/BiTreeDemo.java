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

        HTNode[] huffmanTree = new HTNode[7];
        int weight[] = {1, 3, 6, 9};
        demo.createHuffmanTree(huffmanTree, weight, 4);
        for (int i = 0; i < 7; i++) {
            System.out.println(huffmanTree[i].getWeight());
        }
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

    private void createHuffmanTree(HTNode[] huffmanTree, int[] weight, int count) {
        int n = 2 * count - 1;
        for (int i = 0; i < count; i++) {
            huffmanTree[i] = new HTNode(weight[i], 0, 0, 0);
        }
        for (int i = count; i < n; i++) {
            huffmanTree[i] = new HTNode(0, 0, 0, 0);
        }
        for (int i = count; i < n; i++) {
            //在huffmanTree的前i - 1项选双亲为0且权值最小的两节点
            int firstMin = -1;
            int secondMin = -1;
            for (int j = 0; j < i; j++) {
                if (huffmanTree[j].getParent() == 0) {
                    if (firstMin == -1 || secondMin == -1) {
                        if (firstMin == -1) {
                            firstMin = j;
                        } else if (secondMin == -1) {
                            secondMin = huffmanTree[firstMin].getWeight() > huffmanTree[j].getWeight() ? firstMin : j;
                            firstMin = huffmanTree[firstMin].getWeight() < huffmanTree[j].getWeight() ? firstMin : j;
                        }
                    } else if (huffmanTree[j].getWeight() < huffmanTree[firstMin].getWeight()) {
                        secondMin = firstMin;
                        firstMin = j;
                    }
                }
            }
            //设置权值
            huffmanTree[i].setWeight(huffmanTree[firstMin].getWeight() + huffmanTree[secondMin].getWeight());
            //设置左右孩子
            huffmanTree[i].setlChild(firstMin);
            huffmanTree[i].setrChild(secondMin);
            //设置父亲
            huffmanTree[firstMin].setParent(i);
            huffmanTree[secondMin].setParent(i);
        }
    }
}
