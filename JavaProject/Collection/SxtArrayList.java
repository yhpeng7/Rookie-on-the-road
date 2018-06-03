import java.util.Arrays;

public class SxtArrayList {
    private Object[] elementData;
    private int size;

    public SxtArrayList() {
        this(2);
    }

    public SxtArrayList(int initialCapacity) {
        if (initialCapacity < 0) {
            try {
                throw new Exception();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        elementData = new Object[initialCapacity];
    }

    public boolean isempty() {
        return size == 0;
    }

    //检测数组是否越界
    private void rangeCheck(int index) {
        if (index < 0 || index >= size) {
            try {
                throw new Exception();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    //数组扩容
    private void ensureCapacity() {
        if (size > elementData.length - 1) {
            elementData = Arrays.copyOf(elementData, 2 * size + 1);
        }
    }

    public void add(Object obj) {
        ensureCapacity();
        elementData[size++] = obj;
    }

    public void add(int index, Object obj) {
        rangeCheck(index);
        ensureCapacity();
        System.arraycopy(elementData,index,elementData,index + 1,size - index);
        elementData[index] = obj;
        size++;
    }

    public void remove(int index) {
        rangeCheck(index);
        int numMoved = size - 1 - index;
        if (numMoved > 0) {
            System.arraycopy(elementData, index + 1, elementData, index, numMoved);
        }
        elementData[--size] = null;
    }

    public boolean remove(Object obj) {
        if (obj == null) {
            for (int i = 0; i < size; i++)
                if (elementData[i] == null) {
                    remove(i);
                    return true;
                }
        } else {
            for (int i = 0; i < size; i++)
                if (obj.equals(elementData[i])) {
                    remove(i);
                    return true;
                }
        }
        return false;
    }

    public Object get(int index) {
        rangeCheck(index);
        return elementData[index];
    }

    public int size() {
        return size;
    }
}