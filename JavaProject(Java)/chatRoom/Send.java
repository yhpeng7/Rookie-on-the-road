package Socket.chatRoom2;

import IO流.FileUtilClose;
import java.io.*;
import java.net.Socket;

public class Send implements Runnable{
    //控制台输入流
    private BufferedReader console;
    //管道输出就
    private DataOutputStream dos;
    //控制线程
    private boolean isRunning = true;

    private String name;

    public Send() {
        try {
            console = new BufferedReader(new InputStreamReader(System.in, "utf-8"));
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public Send(Socket client,String name) {
        this();
        try {
            dos = new DataOutputStream(client.getOutputStream());
            this.name = name;
            send(this.name);
        } catch (IOException e) {
            e.printStackTrace();
            isRunning = false;
            FileUtilClose.close(dos,console);
        }
    }

    private String getMsgFromConsole() {
        try {
            return console.readLine();
        } catch (IOException e) {
            return "";
        }
    }

    private void send(String msg) {
        if (msg != null && !msg.equals("")) {
            try {
                dos.writeUTF(msg);
                //强制刷新
                dos.flush();
            } catch (IOException e) {
                isRunning = false;
                FileUtilClose.close(dos, console);
            }
        }
    }

    @Override
    public void run() {
        //线程体
        while (isRunning) {
            send(getMsgFromConsole());
        }
    }
}