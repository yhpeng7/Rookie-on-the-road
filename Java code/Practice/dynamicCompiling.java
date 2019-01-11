import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;
import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class dongTaiBianYi {
    public static void main(String[] args) {
        //String 表示浏览器发送的代码
        String code = "public class helloWorld {public static void main(String[] args) {System.out.println(\"Hello world!\");}}";

        //通过正则表达式提取出文件名
        Pattern p = Pattern.compile("public class (\\w+)");
        Matcher m = p.matcher(code);
        String fileName = null;
        if (m.find()) {
            fileName = m.group(1);
        } else {
            System.out.println("请检查类名是否正确");
            return;
        }

        try {
            //生成一个临时文件，将浏览器上传的代码写入到该文件里，注意这里不能用File.createTempFile()，因为这种方法生成的文件文件名后会有一串随机数字，导致编译不通过。
            File f = new File(fileName.concat(".java"));
            f.createNewFile();
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f), "utf-8"));
            bw.write(code, 0, code.length());
            //写完的时候记得flush一下
            bw.flush();

            //动态编译
            JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
			//参数：1.为Java编译器提供参数 2. 得到Java编译器的输出信息 3.接收编译器的错误信息 4.可变参数(一个String数组)，能传入一个或多个Java源文件
            int result = compiler.run(null, null, null, f.getAbsolutePath());
            System.out.println(result);     //0表示编译成功
            bw.close();
            f.delete();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}