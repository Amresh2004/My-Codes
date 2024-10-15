import java.io.*;
import java.util.*;
class InvalidUsernameException extends Exception
{
	InvalidUsernameException(String u)
	{
		System.out.print("\n Invalid Username Exception caught::" +u);
	}
}
class InvalidPasswordException extends Exception
{
	InvalidPasswordException(String p)
	{
		System.out.print("\n Invalid Password Exception caught::" +p);
	}
}
class logindemo
{
	String username,password;
	logindemo()
	{
		username="Computer";
		password="123";
	}
	logindemo(String u, String p)
	{
		this.username=u; 
		this.password=p; 
	}
	public static void main(String args[])
	{
		logindemo d= new logindemo();
		String u,p;
		try
		{
			u = args[0];
			p = args[1];
			logindemo d1= new logindemo(u,p);
			if(d.username.equals(d1.username))
				System.out.println("Username is Valid");
			else
				throw new InvalidUsernameException(u);
			if(d.password.equals(d1.password))
				System.out.println("Password is Valid");
			else
				throw new InvalidPasswordException(p);
		}
		catch(InvalidUsernameException uu)
		{
			System.out.print("\t" + uu);
		}
		catch(InvalidPasswordException pp)
		{
			System.out.print("\t" +pp);

		}
	}
}
