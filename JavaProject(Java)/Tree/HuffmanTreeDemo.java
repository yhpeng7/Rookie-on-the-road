package Tree;

import java.io.*;
import java.util.*;

class charNode {

    int c;

    int weight;

    public charNode(int c, int weight) {
        this.c = c;
        this.weight = weight;
    }
}

class HTNode {

    private charNode charNode;

    private int parent;

    private int lChild;

    private int rChild;

    public HTNode(charNode charNode, int parent, int lChild, int rChild) {
        this.charNode = charNode;
        this.parent = parent;
        this.lChild = lChild;
        this.rChild = rChild;
    }

    public charNode getCharNode() {
        return charNode;
    }

    public void setCharNode(charNode charNode) {
        this.charNode = charNode;
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

public final class HuffmanTreeDemo {

    public static void main(String[] args) throws IOException {
        HuffmanTreeDemo demo = new HuffmanTreeDemo();

        //存储字符与权值的键值对
        List<charNode> charList = new ArrayList<>();

        //统计编码
        String sourcePath = "D:\\课设\\huffman.source";
        demo.readCharFromFile(charList, sourcePath);

        //建立哈夫曼树
        HTNode[] huffmanTree = new HTNode[2 * charList.size() - 1];
        demo.createHuffmanTree(huffmanTree, charList);

        //编码
        String codePath = "D:\\课设\\huffman.code";
        demo.createHuffmanCode(huffmanTree, charList.size(), sourcePath, codePath);

        //译码
        String decodePath = "D:\\课设\\huffman.decode";
        demo.translateHuffmanCode(huffmanTree, codePath, decodePath);
    }

    private void readCharFromFile(List<charNode> charList, String path) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(path)));
        int c;
        int i;
        while ((c = br.read()) != -1) {
            for (i = 0; i < charList.size(); i++) {
                if (charList.get(i).c == c) {
                    charList.get(i).weight++;
                    break;
                }
            }
            if (i == charList.size()) {
                charList.add(new charNode(c, 1));
            }
        }
        br.close();
    }

    private void createHuffmanTree(HTNode[] huffmanTree, List<charNode> charList) {
        int count = charList.size();
        int n = 2 * count - 1;
        for (int i = 0; i < count; i++) {
            huffmanTree[i] = new HTNode(charList.get(i), 0, 0, 0);
        }
        for (int i = count; i < n; i++) {
            huffmanTree[i] = new HTNode(new charNode((char) 0, 0), 0, 0, 0);
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
                            secondMin = huffmanTree[firstMin].getCharNode().weight > huffmanTree[j].getCharNode().weight ? firstMin : j;
                            //此处一定要是'<='!!!
                            firstMin = huffmanTree[firstMin].getCharNode().weight <= huffmanTree[j].getCharNode().weight ? firstMin : j;
                        }
                    } else if (huffmanTree[j].getCharNode().weight < huffmanTree[firstMin].getCharNode().weight) {
                        secondMin = firstMin;
                        firstMin = j;
                    } else if (huffmanTree[j].getCharNode().weight < huffmanTree[secondMin].getCharNode().weight) {
                        secondMin = j;
                    }
                }
            }
            //设置权值
            huffmanTree[i].setCharNode(new charNode((char) 0, huffmanTree[firstMin].getCharNode().weight + huffmanTree[secondMin].getCharNode().weight));
            //设置左右孩子
            huffmanTree[i].setlChild(firstMin);
            huffmanTree[i].setrChild(secondMin);
            //设置父亲
            huffmanTree[firstMin].setParent(i);
            huffmanTree[secondMin].setParent(i);
        }
    }

    private void createHuffmanCode(HTNode[] huffmanTree, int count, String sourcePath, String codePath) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(sourcePath)));
        BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(codePath));
        StringBuilder code;
        int currentNode;
        HashMap<Integer, String> codeMap = new HashMap();
        for (int i = 0; i < count; i++) {
            code = new StringBuilder();
            currentNode = i;
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
            codeMap.put(huffmanTree[i].getCharNode().c, code.reverse().toString());
        }
        int c;
        while ((c = br.read()) != -1) {
            bos.write(codeMap.get(c).getBytes());
        }
        bos.flush();
        bos.close();
        br.close();
    }

    private void translateHuffmanCode(HTNode[] huffmanTree, String codePath, String decodePath) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(codePath)));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(decodePath)));
        int num;
        int currentNode = huffmanTree.length - 1;
        while ((num = br.read()) != -1) {
            if (num == '0') {
                currentNode = huffmanTree[currentNode].getlChild();
            } else if (num == '1') {
                currentNode = huffmanTree[currentNode].getrChild();
            }
            if (huffmanTree[currentNode].getlChild() == 0 && huffmanTree[currentNode].getrChild() == 0) {
                bw.write(huffmanTree[currentNode].getCharNode().c);
                currentNode = huffmanTree.length - 1;
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}