package com.anshul;

import java.util.ArrayList;
import java.util.Scanner;

public class ChefAndNumbergame {
    public static void main(String args[])
    {
        Scanner scan= new Scanner(System.in);
        //System.out.println("Hello, World!");
        int t=0;
        if(scan.hasNextInt())
        t=scan.nextInt();
        //System.out.println(t);
        while(t >0) {
            ArrayList<Integer> g = new ArrayList<Integer>();
            boolean negative = false;
            int negative_count = 0;
            boolean zero = false;
            int zero_count = 0;
            int j=0,n=0;
            if(scan.hasNextInt())
            n = scan.nextInt();
            for (int i = 0; i < n; i++) {
                if(scan.hasNextInt())
                j = scan.nextInt();
                if (j < 0) {
                    negative = true;
                    negative_count++;
                }
                if (j == 0) {
                    zero = true;
                    zero_count++;
                }
                g.add(j);
            }
            int max = 0;
            int min = 0;
            int positive_count = n - (negative_count + zero_count);
            if (positive_count > 0) {
                if (zero) {
                    min = 1;
                    if (!negative) {
                        max = n - 1;
                    } else {
                        if (negative_count > positive_count) {
                            max = negative_count + (zero_count - 1);
                        } else {
                            max = positive_count + (zero_count - 1);
                        }
                    }
                } else {
                    if (negative) {
                        if (negative_count < positive_count) {
                            min = negative_count;
                            max = positive_count;
                        } else {
                            min = positive_count;
                            max = negative_count;
                        }
                    } else {
                        min = positive_count;
                        max = positive_count;
                    }
                }
        }
        else{
                if(!negative){
                    min=1;
                    max=n-1;
                }
                else{
                    if(zero){
                        min=1;
                        max=negative_count+(zero_count-1);

                    }
                    else {
                        min=negative_count;
                        max=negative_count;
                    }
                }
            }
            System.out.println(max+" "+min);
            t--;

        }
        scan.close();
    }
}
