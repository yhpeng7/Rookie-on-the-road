//过多的同步方法容易造成死锁 --- 同一份资源
public class deadLock {
    public static void main(String[] args) {
        movie testMovie = new movie("左青龙");

        new Thread(new player(testMovie)).start();
        new Thread(new watcher(testMovie)).start();
    }
}

class movie {
    private String film;
    private boolean flag = true;

    public movie(String film) {
        this.film = film;
    }

    public synchronized void play(String film) {
        if (!flag) {    //生产者等待
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        //开始生产
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        this.film = film;
        //通知消费
        this.notify();
        //生产者等待
        flag = false;
    }

    public synchronized void watch() {
        if (flag) {     //消费者等待
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println(film);
        this.notify();
        flag = true;
    }
}

class watcher implements Runnable {
    private movie film;

    public watcher(movie film) {
        this.film = film;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            film.watch();
        }
    }
}

class player implements Runnable {
    private movie film;

    public player(movie film) {
        this.film = film;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            if (i % 2 == 0) {
                film.play("小王子");
            } else {
                film.play("玫瑰");
            }
        }
    }
}