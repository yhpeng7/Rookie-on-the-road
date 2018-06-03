package io.github.yhklsdf666.game;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * 飞机游戏窗口的创建
 *
 * @author 鹏举翅摩天
 */
public class MyGameFrame extends Frame {

    Image pictureImg = GameUtil.getImage("images/planeImg.png");
    Image bgImg = GameUtil.getImage("images/bg.jpg");

    Plane plane1 = new Plane(pictureImg, 800, 800, 30);
    Shell[] shells = new Shell[50];
    Explode explode;
    long startTime = System.currentTimeMillis();
    long endTime = System.currentTimeMillis();
    boolean live = true;

    @Override
    public void paint(Graphics g) {
        Color c = g.getColor();
        g.drawImage(bgImg, 0, 0, null);
        plane1.drawSelf(g);
        for (int i = 0; i < shells.length; i++) {
            shells[i].drawSelf(g);

            //碰撞检测
            boolean crash = shells[i].getRect().intersects(plane1.getRect());
            if (crash ) {
                plane1.live = false;
                live = true;
                for (i = 0; i < shells.length; i++) {
                    shells[i].speed = 3;
                }
                if (explode == null) {
                    explode = new Explode(plane1.x, plane1.y);
                    endTime = System.currentTimeMillis();
                }
                explode.draw(g);
        }
            int period = (int) ((endTime - startTime) / 1000);
            Font f = new Font("宋体", Font.BOLD, 20);
            g.setColor(Color.red);
            g.setFont(f);
            g.drawString("SurvivalTime：" + period + "seconds", Constant.GAME_WIDH - 300, 90);
        }
        if ((System.currentTimeMillis() - endTime) >= 7000) {
            plane1.live = true;
        }
        g.setColor(c);
    }

    class PaintThread extends Thread {
        @Override
        public void run() {
            while (true) {
                repaint();
                try {
                    Thread.sleep(30);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    //定义键盘监听的内部类
    class keyMonitor extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            plane1.addDirection(e);
        }

        @Override
        public void keyReleased(KeyEvent e) {
            plane1.minDirection(e);
        }
    }

    /**
     * 初始化窗口
     */
    public void launchFrame() {
        this.setTitle("小王子与玫瑰");
        this.setVisible(true);
        this.setSize(Constant.GAME_WIDH, Constant.GAME_HEIGHT);
        this.setLocation(30, 40);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        new PaintThread().start();
        addKeyListener(new keyMonitor());
        for (int i = 0; i < shells.length; i++) {
            shells[i] = new Shell();
        }
    }

    //用双缓冲解决屏幕闪烁问题
    private Image offScreenImage = null;

    public void update(Graphics g) {
        if (offScreenImage == null) {
            offScreenImage = this.createImage(Constant.GAME_WIDH, Constant.GAME_HEIGHT);
        }
        Graphics gOff = offScreenImage.getGraphics();
        paint(gOff);
        g.drawImage(offScreenImage, 0, 0, null);
    }

    public static void main(String[] args) {
        MyGameFrame f = new MyGameFrame();
        f.launchFrame();
    }
}
