package student1;
import java.util.*;
public class studentinformation
{
	public int rno;
	public String Class,name;
	public double per;
	public studentinformation(int rno,String name,String Class,double per)
	{
		this.rno=rno;
		this.name=name;
		this.Class=Class;
		this.per=per;
	}
	public void display()
	{
		System.out.println(rno+"\t"+name+"\t"+Class+"\t"+per);
	}
}

