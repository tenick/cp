import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.math.*;
import java.util.List;
import java.util.ArrayList;

public class h
{
	public static void main(String[] args) {
	    // Fast input
	    FastReader fr = new FastReader();
	    
	    // inputs
        int s = fr.nextInt();
        int t = fr.nextInt();
        long[] b = new long[s];
        int[][] stars = new int[s][3];
        int[] telescopes = new int[t];
        
        // Get stars
        for(int i = 0; i < s; i++){
            for(int j = 0; j < 3; j++)
                stars[i][j] = fr.nextInt();
            b[i] = fr.nextLong();
        }
        
        // Get telescopes
        for(int i = 0; i < t; i++)
            telescopes[i] = fr.nextInt();
        
        // output all stars telescope can see
        for(int telescope : telescopes){
            int stars_saw = 0;
            HashSet<List<Integer>> star_vectors = new HashSet<List<Integer>>();
            for(int i = 0; i < s; i++){
                long d = (long)(Math.pow(stars[i][0], 2) + Math.pow(stars[i][1], 2) + Math.pow(stars[i][2], 2));
                //BigInteger a = b[i].divide(d);
                
				// check if star can be seen
                // 1. if star's gabisibility >= telescope sensitivity, visible
                if(d * telescope <= b[i]){
                    // 2. check if there is some star between it
                    // get lowest possible vector direction
                    int vector_divisor = multiGCD(new int[]{Math.abs(stars[i][0]), Math.abs(stars[i][1]), Math.abs(stars[i][2])});
                    int[] vd = {stars[i][0] / vector_divisor, stars[i][1] / vector_divisor, stars[i][2] / vector_divisor};
                    List<Integer> vector_direction = new ArrayList<Integer>(3);
                    for (int coords : vd){
	                    vector_direction.add(coords);
	                }
                    if(star_vectors.contains(vector_direction)){
                        continue;
                    }
                    else{
                        star_vectors.add(vector_direction);
                        stars_saw += 1;
                    }
                }
            }
			System.out.println(stars_saw);
	    }
	}
	
	static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
    
    static int multiGCD(int arr[]) 
    { 
        int result = arr[0]; 
        for (int i = 1; i < arr.length; i++) 
            result = gcd(arr[i], result); 
  
        return result; 
    }
	
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
		
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
