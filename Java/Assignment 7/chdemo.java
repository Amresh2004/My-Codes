import java.awt.*;

public class chdemo extends Frame 
{
    public static void main(String[] args) 
    {
        chdemo c= new chdemo();
        c.setLayout(new FlowLayout());

        Panel p=new Panel();
        Choice ch=new Choice();

        ch.add("FY");
        ch.add("SY");
        ch.add("TY");
        ch.add("MSC-I");
        ch.add("MSC-II");
        
        p.add(ch);
        c.add(p);

        c.setTitle("CHOICE LIST DEMO");
        c.setSize(400,150);
        c.setVisible(true);
    }
}
