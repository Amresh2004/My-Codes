import java.awt.*;

public class chkdemo extends Frame 
{
    public static void main(String[] args) 
    {
        chkdemo c= new chkdemo();
        c.setLayout(new FlowLayout());
        Checkbox c1,c2,c3,c4;
        Label l;

        l=new Label("Select Games",Label.CENTER);
        c1= new Checkbox("FOODBALL",true);
        c2= new Checkbox("CRICKET");
        c3= new Checkbox("HOCKY");
        c4= new Checkbox("KHO-KHO");

        c.add(l);
        c.add(c1);
        c.add(c2);
        c.add(c3);
        c.add(c4);

        c.setTitle("CHECK BOX DEMO");
        c.setSize(500,100);
        c.setVisible(true);
    }    
}
