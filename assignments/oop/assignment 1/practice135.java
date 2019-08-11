import java.util.Random;

public class practice135{
	static int first=0,second=1,fib_sum=0;
	public static void fibonacci(){
		fib_sum=first+second;
		System.out.print("fibonacci series:"+first+" "+second);
		int x=swap1();
		fib_sum=fib_sum+x;
		second=x;
		System.out.print(" "+second);
		x=swap1();
		fib_sum=fib_sum+x;
		second=x;
		System.out.print(" "+second);
		x=swap1();
		fib_sum=fib_sum+x;
		second=x;
		System.out.print(" "+second);
		System.out.println("\nfibonacci sum="+fib_sum);
	}
	public static int swap1(){
		int tmp=first;
		first=second;
		second=tmp;
		return (first+second);
	}
	public static void digit_sum(){
		Random rand= new Random();
		int x=100+Math.abs(rand.nextInt()%(999-100));
		System.out.println("digit sum\nx="+x);
		int sum=0;
		while(x>0){
			sum=sum+x%10;
			x=x/10;
		}
		System.out.println("sum="+sum);
	}
	public static void swap(int x,int y){
		System.out.println("swapping\ninput values: x="+x+" y="+y);
		int tmp=x;
		x=y;
		y=tmp;
		System.out.println("output values: x="+x+" y="+y);
	}
	public static void which_is_larger_and_smaller(int x1,int y1,int z1){
        int x=2*(x1)+1;
        int y=2*(y1)+1;
        int z=2*(z1)+1;
		System.out.println("odd numbers x="+x+" y="+y+" z="+z);
		if(x<y && x<z){
			System.out.println("x is smaller\n");
		}
		else if(y<x && y<z){
			System.out.println("y is smaller\n");
		}
		else if(z<x && z<y){
			System.out.println("z is smaller\n");
		}
		if(x>y && x>z){
			System.out.println("x is larger\n");
		}
		else if(y>x && y>z){
			System.out.println("y is larger\n");
		}
		else if(z>x && z>y){
			System.out.println("z is larger\n");
		}		
	}
	public static void add(int x,int y){
	    System.out.println(" x+y="+(x+y));
	}
	public static void sub(int x,int y){
	    System.out.println(" x-y="+(x-y));
	}
	public static void multi(int x,int y){
	    System.out.println(" x*y="+(x*y));
	}
	public static void div(int x,int y){
	    System.out.println(" x/y="+((float)x/y));
	}
	public static void main(String[] args) {
        int x=0,y=0,z=0;
        Random rand= new Random();
        x=20+Math.abs(rand.nextInt()%(100-20));
        y=20+Math.abs(rand.nextInt()%(100-20));
        z=20+Math.abs(rand.nextInt()%(100-20));
		System.out.println("\nfirst question solution");
		System.out.println("x="+x+"\ny="+y+"\nz="+z);
		add(x,y);
		sub(x,y);
		multi(x,y);
		div(x,y);
		System.out.println("\nsecond question solution");
		which_is_larger_and_smaller(x,y,z);
		System.out.println("\nthird question solution");
		swap(x,y);
		System.out.println("\nfourth question solution");
		digit_sum();
		System.out.println("\nfifth question solution");
		fibonacci();
	}
}
