// http://docs.oracle.com/javase/7/docs/api/

import java.awt.Frame;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.event.*;

public class RedRect extends Frame {

    public static void main(String[] args) {
        new RedRect();
    }

    RedRect(){
        super("RedRect");
        setSize(200,100);
        // add("Center", new CVRedRect());
        setVisible(true);
    }
}


// class CVRedRect extends Canvas {
    
//     public void paint(Graphics g){
//         Dimension d = getSize();
//         int maxX = d.width -1;
//         int maxY = d.height -1;
//         g.drawString("d.width = " + d.width, 10, 30);
//         g.drawString("d.height = " + d.height, 10, 60);
//         g.setColor(Color.red);
// g.drawLine(0,0, maxX,0);
// g.drawLine(maxX,0, maxX,maxY);
// g.drawLine(maxX,maxY, 0,maxY);
// g.drawLine(0,maxY, 0,0);

//         g.drawRect(0, 0, maxX, maxY);
// g.fillRect(0,0,maxX.maxY);
//     }
// }

// void board(Graphics g, int x, int y, int n, int w){
//     for (int i=0; i<n; i++)
//         for(int j=0; j<n; j++){
//             g.setColor((i+n-j) % 2 == 0 ? Color.lightGray : Color.darkGRay);
//             g.fillRect(x + i*w, y + j * w, w, w)
//         }
// }