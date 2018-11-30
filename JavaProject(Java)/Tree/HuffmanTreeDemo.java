package Tree;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public final class HuffmanTreeDemo {

    public static void main(String[] args) {

        HuffmanTreeDemo demo = new HuffmanTreeDemo();
        int weight[] = {1, 3, 6, 9};
        HTNode[] huffmanTree = new HTNode[2 * weight.length - 1];
        demo.createHuffmanTree(huffmanTree, weight);
        for (int i = 0; i < huffmanTree.length; i++) {
            System.out.println(huffmanTree[i].getWeight());
        }
        List<String> huffmanCode = new ArrayList<>();
        demo.createHuffmanCode(huffmanTree, huffmanCode,weight.length);
        for (String code : huffmanCode) {
            System.out.println(code);
        }
    }

    private void createHuffmanTree(HTNode[] huffmanTree, int[] weight) {
        int count = weight.length;
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

    private void createHuffmanCode(HTNode[] huffmanTree, List<String> huffmanCode, int count) {
        StringBuilder code;
        for (int i = 0; i < count; i++) {
            code = new StringBuilder();
            int currentNode = i;
            int parent = huffmanTree[currentNode].getParent();
            while (parent != 0) {
                if (huffmanTree[parent].getlChild() == currentNode) {
                    code.append('0');
                } else {
                    code.append('1');
                }
                currentNode = parent;
                parent = huffmanTree[parent].getParent();
            }
            code.reverse();
            huffmanCode.add(code.toString());
        }
    }

    private HashMap<String,String> translateHuffmanCode(HTNode[] huffmanTree, List<String> huffmanCode) {
        HashMap<String, String> huffmanMap = new HashMap<>();

        return huffmanMap;
    }
}
