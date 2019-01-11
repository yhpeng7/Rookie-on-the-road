import java.io.File;
import java.io.IOException;

public class fileUtil {
	
    public static void copyFile(String srcPath, String destPath) throws IOException {
        copyFile(new File(srcPath), new File(destPath));
    }

    public static void copyFile(File src, File dest) throws IOException {
        if (!src.isFile()) {
            throw new IOException("只能拷贝文件！");
        }

        //如果执行文件写入文件夹等操作，若是发现有同名的文件夹就抛出一个异常
        if (dest.isDirectory()) {
            throw new IOException(dest.getAbsolutePath() + "不能建立同名文件夹！");
        }

        //选择流
        InputStream is = new FileInputStream(src);
        OutputStream os = new FileOutputStream(dest);

        byte[] flush = new byte[1024];
        int len = 0;
        while (-1 != (len = is.read(flush))) {
            //若是不存在则会新建一个文件
            os.write(flush, 0, len);
        }
        os.flush();

        //选择流，先打开的后关闭
        os.close();
        is.close();
    }
	
	
    public static void copyDir(String srcPath, String destPath) throws IOException {
        copyDir(new File(srcPath), new File(destPath));
    }

    public static void copyDir(File src, File dest) throws IOException {
        if (src.isDirectory()) {
            dest = new File(dest, src.getName());
        }
        copyDetail(src, dest);
    }

    public static void copyDetail(File src, File dest) throws IOException {
        if (src.isFile() && dest.isDirectory()) {   //文件写入文件夹，增强程序的健壮性
            CopyFile.copyFile(src, new File(dest, src.getName()));
        } else if (src.isFile()) {
            CopyFile.copyFile(src, dest);
        } else if (src.isDirectory()) {
            dest.mkdirs();
            for (File sub : src.listFiles()) {
                copyDetail(sub, new File(dest, sub.getName()));
            }
        }
    }
}