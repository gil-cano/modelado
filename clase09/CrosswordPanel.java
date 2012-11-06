import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import java.lang.Runnable;


import java.awt.Dimension;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;


public class CrosswordPanel extends JPanel implements MouseListener, KeyListener {

    boolean b = true;
    int px = 0;  // coordenada x de mouse click 
    int py = 0;  // coordenada y de mouse click
    char key = ' ';
    
    public CrosswordPanel(){
        setPreferredSize(new Dimension(400,400));
        addMouseListener(this);
        addKeyListener(this);
    }

    public void paint(Graphics g){
        int y1 = 0;
        int y2 = getHeight()/2;
        if (b) {
            y1 = getHeight()/2;
            y2 = 0; 
        }
        g.setColor(Color.WHITE);
        g.fillRect(0, y1, getWidth(), getHeight()/2);
        g.setColor(Color.BLACK);
        g.fillRect(0, y2, getWidth(), getHeight()/2);
        g.setColor(Color.RED);
        g.setFont(new Font("SansSerif", Font.BOLD, 24));
        g.drawString("x = " + px, 10, 30);
        g.drawString("y = " + py, 10, getHeight()/2 + 30);

        g.drawString("key = " + key, 200, getHeight()/2 + 30);
    }

    public void mouseClicked(MouseEvent e){
        b = !b;
        px = e.getX();
        py = e.getY();
        requestFocusInWindow();
        repaint();
    }

    public void mouseEntered(MouseEvent e){}
    public void mouseExited(MouseEvent e){}
    public void mousePressed(MouseEvent e){}
    public void mouseReleased(MouseEvent e){}


    public void keyPressed(KeyEvent e){}
    public void keyReleased(KeyEvent e){}
    public void keyTyped(KeyEvent e){
        key = e.getKeyChar();
        repaint();
    }

    private static void createAndShowGUI(){
        JFrame frame = new JFrame("Crossword");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(new CrosswordPanel(), BorderLayout.CENTER);

        JPanel textPanel = new JPanel();
        textPanel.setLayout(new BorderLayout());
        textPanel.add(new JLabel("Horizontal"), BorderLayout.NORTH);
        textPanel.add(new JLabel("Vertical"), BorderLayout.SOUTH);
        frame.add(textPanel, BorderLayout.SOUTH);

        frame.pack();
        frame.setVisible(true);        
    }

    public static void main(String[] args) {
        // registramos un evento para el "Event Dispatch Thread"
        SwingUtilities.invokeLater(new Runnable(){
            public void run(){
                createAndShowGUI();
            }
        });
    }
}
