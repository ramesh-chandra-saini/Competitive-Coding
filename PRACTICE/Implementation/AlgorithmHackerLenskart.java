import java.util.*;


public class AlgorithmHackerLenskart  {
	
	
	public static boolean checkPrime(int a)
	{
		if(a==1)
			return false;
		else
		for(int k=2;k<=a/2;k++)
	        
    	{
			
    		if(a%k==0)
    		{
    			return false;
    			
    		}
    		
    	}
		return true;
		
		
    
	}
	
    public static void main(String args[] ) throws Exception {
        /*
         * Read input from stdin and provide input before running
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);

        //Scanner*/
        
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
		int []a=new int[N];
		int diff=0;
		int temp=0;
		int p=0;
        for (int i = 0; i < N; i++) {
            a[i]=s.nextInt();
        }
        for(int i=0;i<N;i++)
        {
        		
    		if((AlgorithmHackerLenskart.checkPrime(a[i])))
    		{
    			
    			System.out.print(a[i]+" ");
    		}
    		else
    		{
    			diff=0;
            	temp=N;
            	
            	for (int j=0;j<N;j++)
            	{
            		if(i==j)
            			continue;
            		else
            			if(AlgorithmHackerLenskart.checkPrime(a[j]))
            			{
            				diff=i-j;
            				//System.out.println("diff"+diff+"a[i]"+a[i]+"a[j]"+a[j]);
            				if(diff<0)
            					diff=diff*-1;
            				
            				if(diff<temp)
                    		{
                    			temp=diff;
                    			p=j;
                    		//	System.out.println("temp minimum diff"+temp+"p value"+p);
                    		}
            			}
            			
            		    			
            	}
            	if(temp<N)
            	{
            		//System.out.println(">>>>>>>>>>>>nearst prime"+p);
            		System.out.print(a[p]+" ");
            	}
        	
        	  }
        		
    		 
        	}
        }
       

      //  System.out.println("Hello World!");
    }



