import java.awt.*;

public class fdemo1 extends Frame 
{
    public static void main(String[] args) 
    {
        fdemo1 f=new fdemo1();
        f.setLayout(new BorderLayout());
        Button E,W,S,N,C;

        E= new Button("EAST");
        W= new Button("WEST");
        S= new Button("SOUTH");
        N= new Button("NORTH");
        C= new Button("CENTER");
        
        f.add(E,BorderLayout.EAST);
        f.add(W,BorderLayout.WEST); 
        f.add(N,BorderLayout.NORTH);
        f.add(S,BorderLayout.SOUTH);
        f.add(C,BorderLayout.CENTER); 

        f.setTitle("Border Layout Demo");
        f.setSize(400,150);
        f.setVisible(true);
    }
}
