package Socket.chatRoom2;

import IO流.FileUtilClose;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
    private List<myChannel> all = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        new Server().start();
    }

    public void start() throws IOException {
        ServerSocket server = new ServerSocket(7777);
        while (true) {
            Socket client = server.accept();
            myChannel channel = new myChannel(client);
            all.add(channel);   //统一管理
            new Thread(channel).start();
        }
    }

    //内部类
    class myChannel implements Runnable {
        private DataInputStream dis;
        private DataOutputStream dos;
        private boolean isRunning = true;
        private String name;

        public myChannel(Socket client) {
            try {
                dis = new DataInputStream(client.getInputStream());
                dos = new DataOutputStream(client.getOutputStream());

                this.name = dis.readUTF();
                this.send("<系统消息>：欢迎您进入聊天室！");
                this.sendOthers(this.name + "进入了聊天室。",true);
            } catch (IOException e) {
                FileUtilClose.close(dos, dis);
                isRunning = false;
            }
        }

        private String reveive() {
            String msg = "";
            try {
                msg = dis.readUTF();
            } catch (IOException e) {
                FileUtilClose.close(dos, dis);
                isRunning = false;
                all.remove(this);   //移除自身
            }
            return msg;
        }

        public void send(String msg) {
            try {
                dos.writeUTF(msg);
                dos.flush();
            } catch (IOException e) {
                FileUtilClose.close(dos, dis);
                isRunning = false;
                all.remove(this);
            }
        }

        private void sendOthers(String msg,boolean sys) {
            if (msg.startsWith("@")) {
                if (msg.indexOf(":") > -1) {
                    String targetName = msg.substring(1, msg.indexOf(':'));
                    String targetMsg = msg.substring(msg.indexOf(':') + 1);
                    for (myChannel target : all) {
                        if (target.name.equals(targetName)) {   //不能用==！！！
                            target.send("From -> " + this.name + ":" + targetMsg);
                        }
                    }
                } else {
                    send("1.该用户不存在！" + '\n' + "2.请按照  @name:msg  的格式发送消息(注：':'是英文字符！");
                }
            } else {
                for (myChannel other : all) {
                    if (other != this) {
                        if (sys == true) {   //系统信息
                            other.send("<系统消息>：" + msg);
                        } else {
                            other.send("[" + this.name + "]:" + msg);
                        }
                    }
                }
            }
        }

        @Override
        public void run() {
            while (isRunning) {
                sendOthers(reveive(),false);
            }
        }
    }
}

/*
public class FileUtilClose {
    public static <T extends Closeable>void close(T ... io){
        for (Closeable temp : io) {
            if (temp != null) {
                try {
                    temp.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
*/