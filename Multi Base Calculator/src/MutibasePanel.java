import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Iterator;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.JSlider;

/**
 *Display necessary calculator swing components including numbers and operators buttons, a slider for changing bases and a calculation display text area.
 *<p>
 *When user click buttons or scroll slider, different inner actionListener gets called and different behaviors gets performed. 
 *This class responsible for calculator GUI layout and swing component event handling, it neither remember stuff nor perform calculation, the actual calculation work goes to Base4CalcState class.
 *
 * @author Gushu Qin
 * @version 1.0
 */

public class MutibasePanel extends JPanel{

	private MultibaseCalcState calc = new MultibaseCalcState(); //this object will do the actual calculation. 
	private boolean clearPrev = false;
	private int value;//current base

	ArrayList <JButton> numberItem = new ArrayList<JButton>(); // store number buttons and clear button
    ArrayList <JButton> operatorItem = new ArrayList<JButton>();// store operator buttons

	JButton zero, 
	one, 
	two, 
	three, 
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	eleven,
	twelve,
	thirteen,
	fourteen,
	fifteen,
	plus, 
	minus, 
	multiply, 
	divide,
	equal,
	clear;
	JTextArea screen;
	JSlider slider;
	JLabel label; // display current base
	
	/**
	 * Set calculator layout, including number and operator buttons, base change slider and a text area for displaying operands and result.
	 * Buttons are encapsulate in ArrayList. Use iterator method to iterate through all the buttons when add them to the Panel and set them to be ActionListener.
	 * 
	 * @param none takes no parameter.
	 */
	
	MutibasePanel() {
		this.setLayout(new FlowLayout()); 

		zero = new JButton("0"); 
		one = new JButton("1");
		two = new JButton("2"); 
		three = new JButton("3"); 
		four = new JButton("4");
		five = new JButton("5");
		six = new JButton("6");
		seven = new JButton("7");
		eight = new JButton("8");
		nine = new JButton("9");
		ten = new JButton("A");
		eleven = new JButton("B");
		twelve = new JButton("C");
		thirteen = new JButton("D");
		fourteen = new JButton("E");
		fifteen = new JButton("F");
		plus = new JButton("+"); 
		minus = new JButton("-"); 
		multiply = new JButton("x"); 
		divide = new JButton("/"); 
		clear = new JButton("Clear");
		equal = new JButton("=");
		
		numberItem.add(zero);// add button to ArrayList.
		numberItem.add(one);
		numberItem.add(two);
		numberItem.add(three);
		numberItem.add(four);
		numberItem.add(five);
		numberItem.add(six);
		numberItem.add(seven);
		numberItem.add(eight);
		numberItem.add(nine);
		numberItem.add(ten);
		numberItem.add(eleven);
		numberItem.add(twelve);
		numberItem.add(thirteen);
		numberItem.add(fourteen);
		numberItem.add(fifteen);
		numberItem.add(clear);
		operatorItem.add(plus);
		operatorItem.add(minus);
		operatorItem.add(multiply);
		operatorItem.add(divide);
		operatorItem.add(equal);
		
		Iterator<JButton> numIterator = numberItem.iterator();// create iterator
		while(numIterator.hasNext()){ //iterate through all buttons in ArrayList
			JButton temp = numIterator.next();
			add(temp);// add button to Panel
			temp.addActionListener(new numberObserver());// set it to be a actionListener, create event when user click it.
		}
		
		Iterator<JButton> opIterator = operatorItem.iterator();
		while(opIterator.hasNext()){
			JButton temp = opIterator.next();
			add(temp);
			temp.addActionListener(new operatorObserver());
		}
		

		screen = new JTextArea (2, 10);
		add(screen);
		

		label = new JLabel("Current base: 16");
		add(label);
		
		slider = new JSlider(JSlider.HORIZONTAL,2, 16, 16 );// create slider between base 2 to 16, set initial slider position to 16.
		slider.setMajorTickSpacing(1);
		slider.setPaintTicks(true);
		add(slider);
		value = 16;// set initial base value to 16
		event e = new event();//create slider event
		slider.addChangeListener(e);//add slider event listener
	}
	
	
	
	/**
	 * Inner class handle slider event.
	 * when user scroll slider, this class is invoked.
	 */
	
	class event implements ChangeListener{
		@Override
		
		/**
		 * when user scroll the slider, current displaying number will change in terms of the new base and label will display current base accordingly.
		 * slider listener will call calc.change() method to reflect the changes in current calculation. 
		 * 
		 * @param e event object, created and pass to stateChanged whenever user scroll the slider
		 */
		
		public void stateChanged(ChangeEvent e) {

		    int curvalue = slider.getValue();// curvalue is the new base after change, value is the previous base
		    if(curvalue != value && !screen.getText().equals("")){
		    	 screen.setText(Integer.toString(Integer.parseInt(screen.getText(), value), curvalue));// change the number value displayed on the text area in terms of new base
		    }
		    
		    value = curvalue;//set previous base to new base
			label.setText("Current base " + value);
			calc.change(screen.getText());// reflect the number value change in calculation process.
	
			Iterator<JButton> numIterator = numberItem.iterator();// create ArrayList iterator
			
			int i = 0;
			while(numIterator.hasNext()){
				if(i < value || numberItem.get(i) == clear)//iterate through the number buttons to make the button enable or disable in terms of the current base.
					(numIterator.next()).setEnabled(true);
				else
					(numIterator.next()).setEnabled(false);
				i++;
			}
		}
	}
	
	
	
	/**
	 * Inner class handle number and clear button's event.
	 * when user click number buttons from 0 to 15 or the "clear" button, this class is invoked.
	 */
	
	class numberObserver implements ActionListener{
		
		/**
		 * number button event create different result base on the last button user clicked and the number in the current text area. 
		 * <p>
		 * when user click "clear" button, text area will be set to 0 and it calls calc.clear() to erase the current calculation work. 
		 * if user clicked a number button right after clicking a operator button, displaying number will be erased and new number will be set to the text area. 
		 * if the current number on text area is 0, the 0 will be erase and new number will be set to the text area.
		 * in other case, number will append on text area.
		 * 
		 *@param event object generated by numbers or "clear" buttons when user click it.
		 */
		
		public void actionPerformed(ActionEvent event){
			
			if("Clear".equals(event.getActionCommand())){
				screen.setText("0");
				calc.clear();
			}
			
			else if(clearPrev){
				screen.setText(event.getActionCommand());
				clearPrev = false;//flag variable, represent whether the last button user clicked is a operator button or not. If it is clearprev is true, if the previous button user clicked is number button, clearprev is false.
			} 
			
			else if("0".equals(screen.getText()))
				screen.setText(event.getActionCommand());
			
			else
				screen.append(event.getActionCommand());
		}
	}
	
	
	/**
	 * Inner class handle operator button's event.
	 * when user click operator buttons, this class is invoked.
	 */

	class operatorObserver implements ActionListener{
		
		/**
		 * operator buttons trigger the actual calculation work, it'll pass different parameter value to MultibaseCalcState class based on what kinds of button user clicked right before user click the operator button. 
		 * <p>
		 * if user click a number button before clicking the operator button, it's normal, so this method will pass the operand value, operator value and current base to clacState.
		 * if user click another operators button before clicking the operator button, means that user want to replace the previous operator value with the new operator value , so this method will not pass operand but only the new operator value user clicked.
		 * the result of the calculation will also be displayed in the text area by this method. When it gets the calculation finish signal from CalcState, it will display the calculation result according to the current calculator base.
		 * 
		 *@param event object generated by operator button when user click it.
		 */
		
		public void actionPerformed(ActionEvent event){
	
			if(clearPrev)//if the last button clicked is a operator button
				calc.update(null,event.getActionCommand(), value);//only update the operator 
			else
				calc.update(screen.getText(),event.getActionCommand(), value);	// update both parameter value and operator value
			
			clearPrev = true;
			
			if(calc.isValueReady()){
				screen.setText(Integer.toString(calc.currentValue(), value));// display the calculation result.
				calc.setValueReady(false);
			}			
		}
	}
	
}
	
	


