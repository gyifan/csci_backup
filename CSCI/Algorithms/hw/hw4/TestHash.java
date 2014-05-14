/**
 *  * A class to test hash function variations
 *   * Requires two integers to be provided on the command line
 *    */
import java.util.Scanner;
import java.io.*;

public class TestHash {

		public static void printStats(int[] count){
				int len = count.length;
				double mean = 0;
				double var = 0;
				double stdev = 0;
				int maxIndex = 0;
				int max = count[maxIndex];
				int minIndex = 0;
				int min = count[minIndex];
				int zerocnt = 0;

				int totalcnt = 0; // sum of counts
				double varSum = 0; // sum of (count - mean)^2

				// Gets total count
				for(int i=0; i<len; i++){
						totalcnt+=count[i];
						if(count[i] == 0)
								zerocnt += 1;
						if(count[i] > max){
								max = count[i];
								maxIndex = i;
						}
						else if(count[i] < min){
								min = count[i];
								minIndex = i;
						}
				}

				mean = (double)totalcnt/(double)len;

				for(int i=0;i<len;i++){
						varSum += Math.pow((count[i]-mean),2.0);
				}

				var = varSum/len;
				stdev = Math.sqrt(var);

				System.out.printf("Statistics of the " +
								"hash table:\n MEAN = %f\n # of ZEROS = %d\n" +
								" MAX COUNT = %d @ %d\n MIN COUNT: " +
								"%d @ %d\n VARIANCE = %f\n " +
								"STANDARD DEV = %f\n", mean, zerocnt, max, 
								maxIndex, min, minIndex, var, stdev);

		}

		public static void main(String[] args) {

				try {

						int radix = Integer.parseInt(args[0]);
						int modulus = Integer.parseInt(args[1]);
						int[] count = new int[modulus];
						int htmp;
						File inFile = new File(args[2]);
						Scanner in = new Scanner(inFile);
						String inStr;

						System.out.println();
						System.out.println("Using radix " + radix + " and modulus "
										+ modulus
										+ ".");
						System.out.println();
					//	System.out.println("  Input   \t|  hash value");
					//	System.out.println("--------------------------------");

						while (in.hasNext()){
								inStr = in.next();
								htmp = Hash.hash(inStr, radix, modulus);
								count[htmp]++;
					//			System.out.printf("%7s   \t|%8d\n", inStr,
					//							htmp);
						}

				//		System.out.println("\n");

						// Print to stdout with readable format
					//				for(int i=0; i<modulus; i++){
					//					if(count[i] != 0)
					//						System.out.printf("hashvalue %d, " +
					//								"\t count = %d\n", i, count[i]);
					//				}

						// Print the statistics of count array
						printStats(count);

				}
				catch (FileNotFoundException e) {
						System.out.println("ERROR: File not found." + e);
				}
		}
}
