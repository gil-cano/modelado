import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;
import java.lang.Runnable;

public class Main {

    private static void createAndShowGUI(){
        // Creamos y configuramos la vantana
        JFrame frame = new JFrame("Crossword");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Agregamos varios componentes
        JLabel label = new JLabel("Hola Mundo!!");
        frame.add(label, BorderLayout.NORTH);
        JLabel label2 = new JLabel("Hello World!!");
        frame.add(label2, BorderLayout.CENTER);

        // Despliega la ventana
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