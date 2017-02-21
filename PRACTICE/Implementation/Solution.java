import java.io.*;
import java.util.*;

public  class Solution{

    public enum Player{
        USER,COMPUTER
    }
    public enum Cell{
        EMPTY,FULL,Queen
    }
    public static void main(String [] args){

        Scanner inp = new Scanner(System.in);
    
        int N = inp.nextInt();
        //1 based indexing
        Cell arr[][] = new Cell[(N+1)][(N+1)];
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                arr[i][j]=Cell.FULL;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                System.out.print(arr[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
        Random r = new Random();
        int turnId = r.nextInt(2);
         System.out.print(turnId);
        
    }

}
