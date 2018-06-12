import java.util.*;

/*
 * 思路：先把54张牌放到poker(ArrayList<String>)中(按照3333,4444 ... 2222的顺序放进去),用0 - 53 将order(ArrayList<Integer>)填满，用pokerHm(HashMap<Integer, String>)按(0-3,1-3,2-3 ... 53-大王的顺序)以键值对的形式把牌放进去,再用Collections.shuffle(order)将order的顺序打乱，然后用TreeSet将3个玩家和底牌的牌号(order)按顺序放进去，最后再通过pokerHm.get()将玩家的牌和底牌打印出来
 */

public class PokerDemo2 {
    public static void main(String[] args) {
        ArrayList<String> poker = new ArrayList<>();
        HashMap<Integer, String> pokerHm = new HashMap<>();
        ArrayList<Integer> order = new ArrayList<>();

        String[] colors = {"♥", "♠", "♦", "♣"};
        String[] numbers = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};

        for (String number : numbers) {
            for (String color : colors) {
                poker.add(color.concat(number));
            }
        }

        poker.add("大王");
        poker.add("小王");

        for (int i = 0; i < 54; i++) {
            pokerHm.put(i, poker.get(i));
        }

        for (int i = 0; i < 54; i++) {
            order.add(i);
        }

        Collections.shuffle(order);

        TreeSet<Integer> player1 = new TreeSet<>();
        TreeSet<Integer> player2 = new TreeSet<>();
        TreeSet<Integer> player3 = new TreeSet<>();
        TreeSet<Integer> holecards = new TreeSet<>();

        for (int i = 0; i < order.size(); i++) {
            if (i + 3 >= order.size()) {
                holecards.add(order.get(i));
            } else if (i % 3 == 0) {
                player1.add(order.get(i));
            } else if (i % 2 == 0) {
                player2.add(order.get(i));
            } else if (i % 1 == 0) {
                player3.add(order.get(i));
            }
        }

        LinkedList<TreeSet<Integer>> player = new LinkedList<>();
        player.add(player1);
        player.add(player2);
        player.add(player3);
        player.add(holecards);

        for(TreeSet<Integer> players : player){
            for (Integer pokers : players) {
                System.out.print(pokerHm.get(pokers) + " ");
            }
            System.out.println();
        }
    }
}
