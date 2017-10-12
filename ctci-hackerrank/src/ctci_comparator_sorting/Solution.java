package ctci_comparator_sorting;

import java.util.*;

/**
 * Created by mehamasum on 10/11/2017.
 */

class Checker implements Comparator<Player> {
    @Override
    public int compare(Player o1, Player o2) {
        int ret =  Integer.compare(o2.score, o1.score);
        if(ret!=0) return ret;
        return  o1.name.compareTo(o2.name);
    }
}

class Player{
    String name;
    int score;

    Player(String name, int score){
        this.name = name;
        this.score = score;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();

        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.next(), scan.nextInt());
        }
        scan.close();

        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].name, player[i].score);
        }
    }
}
