import java.util.LinkedList;

public class SxtMap {
    //此处忽略数组扩容
    LinkedList[] array = new LinkedList[1000];  //Map的底层结构：数组 + 链表

    public void put(Object key, Object value) {
        SxtEntry e = new SxtEntry(key, value);

        int hash = hashCode() % array.length;
        hash = hash > 0 ? hash : -hash;
        int a = hash % array.length;

        if (array[a] == null) {
            LinkedList list = new LinkedList();
            array[a] = list;
            list.add(e);
        } else {
            LinkedList list = array[a];
            for (int i = 0; i < list.size(); i++) {
                SxtEntry e1 = (SxtEntry) list.get(i);
                if (e1.key.equals(key)) {
                    e1.value = value;
                    return;
                }
            }
            array[a].add(e);
        }
    }

    public Object get(Object key) {

        int hash = hashCode() % array.length;
        hash = hash > 0 ? hash : -hash;
        int a = hash % array.length;

        if (array[a] != null){
            LinkedList list = array[a];
            for (int i = 0; i < list.size(); i++) {
                SxtEntry e = (SxtEntry) list.get(i);
                if (e.key.equals(key)) {
                    return e.value;
                }
            }
        }
        return null;
    }

    class SxtEntry {
        Object key;
        Object value;

        public SxtEntry(Object key, Object value) {
            this.key = key;
            this.value = value;
        }
    }
}
