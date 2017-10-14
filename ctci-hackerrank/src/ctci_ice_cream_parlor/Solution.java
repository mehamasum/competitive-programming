package ctci_ice_cream_parlor;

import java.util.*;


public class Solution {

    static class Flavor implements Comparable<Flavor> {
        int id, cost;

        public Flavor(int id, int cost) {
            this.id = id;
            this.cost = cost;
        }

        @Override
        public int compareTo(Flavor o) {
            return Integer.compare(this.cost, o.cost);
        }

        @Override
        public String toString() {
            return "{" + "id=" + id + ", cost=" + cost + '}';
        }
    }

    private static int search(ArrayList<Flavor> arr, int start, int end, int x) {
        if(start>end) return -1;
        int mid = (start+end)/2;
        Flavor ele = arr.get(mid);
        if(ele.cost==x) {
            return mid;
        }
        else if(ele.cost>x) {
            return search(arr, start, mid-1, x);
        }
        else {
            return search(arr, mid+1, end, x);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int m = in.nextInt();
            int n = in.nextInt();
            ArrayList<Flavor> flavors = new ArrayList<>(n);
            for(int i=0; i < n; i++){
                flavors.add(new Flavor(i+1, in.nextInt()));
            }

            // soln
            Collections.sort(flavors);
            //System.out.println(flavors);

            for(int i=0; i < n; i++) {
                int cost = flavors.get(i).cost;
                if(cost<m) {
                    int idx = search(flavors, i+1, n-1, m-cost);
                    if(idx!=-1) {
                        int one = flavors.get(i).id;
                        int two = flavors.get(idx).id;
                        System.out.printf("%d %d\n", Math.min(one, two), Math.max(one, two));
                        break;
                    }
                }
            }
        }
    }
}
