package Socket.chatRoom2;

import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    private String name;

    public static void main(String[] args) throws IOException {
        Socket client = new Socket("localhost", 7777);
        System.out.println("请输入昵称：");
        String name = new Scanner(System.in).nextLine();
        if (name.equals("")) {
            return;
        }
        new Thread(new Send(client,name)).start();
        new Thread(new Receive(client)).start();
    }
}
