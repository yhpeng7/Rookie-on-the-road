public class SxtLinkedList {
    private Node first;
    private Node last;

    private int size;

    public void add(Object obj) {
        Node n = new Node();
        n.setObj(obj);
        n.setNext(null);
        if (first == null) {
            n.setPrevious(null);
            last = first = n;
        } else {
            n.setPrevious(last);
            last.setNext(n);
            last = n;
        }
        size++;
    }

    private void rangeCheck(int index) {
        if (index > size || index < 1) {
            try {
                throw new Exception();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public Object get(int index) {
        rangeCheck(index);
        if (index < size >> 1) {
            Node temp = first;
            for (int i = 1; i < index; i++) {
                temp = temp.next;
            }
            return temp.obj;
        } else {
            Node temp = last;
            for (int i = size - 1;i > index; i--) {
                temp = temp.previous;
            }
            return temp.obj;
        }
    }

    public Object get(Object obj) {
        Node temp = first;
        while (temp != null) {
            if (temp.obj.equals(obj)) {
                return temp.obj;
            }
            temp = temp.next;
        }
        return null;
    }

    public void remove(int index) {
        rangeCheck(index);
        Node temp = first;
        for (int i = 1; i < index; i++) {
            temp = temp.next;
        }
        if (first == temp) {
            first = first.next;
        } else if (temp.next == null) {
            temp.previous.next = null;
        } else {
            temp.previous.next = temp.next;
            temp.next.previous = temp.previous;
        }
        size--;
    }

    public int size() {
        return size;
    }
}

class Node {
    public Node previous;
    public Object obj;
    public Node next;

    public Node() {
    }

    public Node(Node previous, Node obj, Node next) {
        this.previous = previous;
        this.obj = obj;
        this.next = next;
    }

    public Node getPrevious() {
        return previous;
    }

    public Object getObj() {
        return obj;
    }

    public Node getNext() {
        return next;
    }

    public void setPrevious(Node previous) {
        this.previous = previous;
    }

    public void setObj(Object obj) {
        this.obj = obj;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}