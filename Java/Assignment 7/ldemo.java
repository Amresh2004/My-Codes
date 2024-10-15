import java.awt.*;

public class ldemo extends Frame 
{
    public static void main(String[] args) 
    {
        ldemo l= new ldemo();
        l.setLayout(new FlowLayout());
        Label l1,l2;
        TextField t1,t2;

        l1= new Label("Login_ID",Label.RIGHT);
        l2= new Label("Password",Label.LEFT);
        t1=new TextField(12);
        t2=new TextField(8);
        t2.setEchoChar('*');

        l.add(l1);
        l.add(t1);
        l.add(l2);
        l.add(t2);

        l.setTitle("LABLE and TEXTBOX DEMO");
        l.setSize(300,150);
        l.setVisible(true);
    }
}
