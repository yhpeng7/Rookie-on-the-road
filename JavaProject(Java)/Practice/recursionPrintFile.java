import java.io.File;

public class FileTest {
    public static void main(String[] args) {
        File f = new File("C:\\Asm");
        printFile(f, 0);
    }

    static void printFile(File file, int level) {
        if (null == file || !file.exists()) {
            return;
        }
        for (int i = 0; i < level; i++) {
            System.out.print("-");
        }
        System.out.println(file.getName());
        if (file.isDirectory()) {
            for (File temp : file.listFiles()) {
                printFile(temp, level + 1);
            }
        }
    }
}