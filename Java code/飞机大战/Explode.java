package io.github.yhklsdf666.game;

import java.awt.*;

public class Explode {
    double x, y;

    public Explode(double x, double y) {
        this.x = x;
        this.y = y;
    }

    static Image[] imgs = new Image[9];
    static{
        for (int i = 0; i < 9; i++) {
            imgs[i] = GameUtil.getImage("images/explode/explode00" + (i + 1) + ".jpg");
            imgs[i].getWidth(null);
        }
    }

    int count;

    public void draw(Graphics g) {
        if (count < 9) {
            g.drawImage(imgs[count++], (int) x, (int) y, null);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
