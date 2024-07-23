import java.util.Scanner;

public class VowelAndConsonant {
    public static void main(String a[])
	{
		char ch;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enetr the Character");
		ch=sc.next().charAt(0);
		switch(ch)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':	
			System.out.println(ch + " is Vowel");
			break;
	    default:
	    	System.out.println(ch + " is Consonant");
		}
	}
}
