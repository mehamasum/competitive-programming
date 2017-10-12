package ctci_merge_sort;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by mehamasum on 10/11/2017.
 */
public class Solution {

    static long countInversions(int[] arr) {
        int[] helper = new int[arr.length];
        return mergeSort(arr, 0, arr.length-1, helper);
    }

    static long mergeSort(int[] arr, int low, int high, int[] helper) {
        long cnt=0;
        if(low<high) {
            int mid = (low+high)/2;

            long cnt3 = mergeSort(arr, low, mid, helper);
            cnt+= cnt3;

            //for(int i=low; i<=mid; i++) System.out.print(arr[i]+" ");
            //System.out.println("^ 1");
            long cnt2 =mergeSort(arr, mid+1, high, helper);
            cnt+=cnt2;
            //for(int i=mid+1; i<=high; i++) System.out.print(arr[i]+" ");
            //System.out.println("^ 2");

            long cnt1 =merge(arr, low, mid, high, helper);
            cnt+=cnt1;

            //System.out.println("lo="+low+"   hi="+high+"   > "+ cnt+" , "+cnt3+" , "+ cnt2+" , "+cnt1);

        }
        //System.out.println("lo="+low+"   hi="+high+"   > ");
        return cnt;
    }

    static long merge(int[] arr, int low, int mid, int high, int[] helper) {
        for(int i=low; i<=high; i++) {
            helper[i]=arr[i];
        }

        int left = low;
        int right = mid+1;
        int cur = low;
        long cnt = 0;
        while (left<=mid && right<=high) {
            if(helper[left]>helper[right]) {
                cnt+=mid-left+1;
                arr[cur++] = helper[right++];
            }
            else {
                arr[cur++] = helper[left++];
            }
        }

        while (left<=mid) {
            arr[cur++] =  helper[left++];
        }
        return cnt;
    }



    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            long result = countInversions(arr);
            System.out.println(result);
        }
        in.close();
    }
}

