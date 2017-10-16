import javax.swing.JFrame;

/**
 * A simple Multibase calculator.
 * It calculate two integers with any base between 2 and 16 then store the result to a file.
 *  
 * @author Gushu Qin
 * @version 1.0
 */

public class MutibaseCalculator {
	/**
	 * main calls the createAndShowGUI method to set up calculator's GUI interface.
	 * @param args main does not take any parameter.
	 */

	public static void main(String[] args) {
		createAndShowGUI();
	}

	private static void createAndShowGUI() {
		/**
		 * called by main to make a top level GUI container then display it.
		 * 
		 * @param none takes no parameter.
		 */
		
		JFrame frame = new JFrame("Base 2 to 16 Calculator");
		frame.add(new MutibasePanel());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(400, 400);
		frame.setVisible(true);
	}
}
