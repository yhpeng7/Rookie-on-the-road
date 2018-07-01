package Socket.chatRoom2;

import IO流.FileUtilClose;
import java.io.*;
import java.net.Socket;

public class Receive implements Runnable {
    private DataInputStream dis;
    private boolean isRunning = true;

    public Receive(Socket slient){
        try {
            dis = new DataInputStream(slient.getInputStream());
        } catch (IOException e) {
            isRunning = false;
            FileUtilClose.close(dis);
        }
    }

    public String receive() {
        String msg = "";
        try {
            msg = dis.readUTF();
        } catch (IOException e) {
            isRunning = false;
            FileUtilClose.close(dis);
        }
        return msg;
    }

    @Override
    public void run() {
        while (isRunning) {
            System.out.println(receive());
        }
    }
}