import java.util.*;
/**
    Author : Ramesh Chandra
    National Institute of Technology 
        Karnataka Surathkal
    http://ramesh-chandra.strikingly.com/
*/
/*
    Time Complexity : O(NlogN) approx.
*/
public class ShoutoutInLondon{

    public static boolean [] isPrime = new boolean [1000006];
    /**
        check below algorithm here : 
        http://www.geeksforgeeks.org/sieve-of-eratosthenes/
        https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    */
    public static void sieve(){
        isPrime[0] = isPrime[1] =false; // base cases 
        //intialize isPrime array
        for(int i=2;i<1000006;i++)
            isPrime[i]=true;
        //mark which all number are not prime as false
        for(int i=2;i*i<1000006;i++)
            if(isPrime[i]==true)
                for(int j=i*i;j<1000006;j+=i)
                    isPrime[j]=false;
    } 
    public static void main(String args[] ) throws Exception {
        
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
		int []arr = new int[N];       
        for (int i = 0; i < N; i++) 
            arr[i]=scanner.nextInt();
        
        //preprocessing
        sieve();
        
        //calculate left nearest prime index which is safe
        int []leftNearestPrime =  new int[N];
        int leftNearestPrimeIndex = -1;//-1 indicate not present prime index in left 
        for(int i=0;i<N;i++){
            if(isPrime[arr[i]]==true)
                leftNearestPrimeIndex = i;
            leftNearestPrime[i]=leftNearestPrimeIndex;
        }        
        //calculate right nearest prime index which is safe
        int []rightNearestPrime =  new int[N];
        int rightNearestPrimeIndex = -1;//-1 indicate not present prime index in right 
        for(int i=N-1;i>=0;i--){
            if(isPrime[arr[i]]==true)
                rightNearestPrimeIndex = i;
            rightNearestPrime[i]=rightNearestPrimeIndex;
        }
        
        int []ans = new int[N]; //final answer to online judge
        
        for(int i=0;i<N;i++){
            int L = -1;// L :-> leftNearestIndex of safe city
            int R = -1;// R ;-> rightNearestIndex of safe city
            //check for left side prime safe city, if present 
            if(leftNearestPrime[i]!=-1)
                L = leftNearestPrime[i];
            //check for right side prime safe city, if present 
            if(rightNearestPrime[i]!=-1)
                R = rightNearestPrime[i];
            //choose nearest one if exist..:P
            ans[i]=(L==-1 && R==-1)?-1:(L!=-1 || R!=-1)?Math.max(L,R):(Math.abs(L-i)>Math.abs(R-i))?L:R; 
        }
        //final answer to judge
        for(int i=0;i<N;i++)
            System.out.printf("%d ",(ans[i]==-1)?ans[i]:arr[ans[i]]);
        System.out.println();   
    }
}
