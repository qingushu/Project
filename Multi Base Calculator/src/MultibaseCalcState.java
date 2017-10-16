import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.io.Writer;

/**
 *Base4CalcState not only perform the actual calculating work but also write all the calculation to a file named filename.txt.
 *<p>
 *It gets triggered in three cases. first, when user click "clear" button, the clear() method gets invoked, it erases all the current calculation work. 
 *besides that, when user clicked the operator button, operator actionListener will pass a operand and a operator to update() method and do the calculation work. 
 *Since the operatorListener pass one operand and one operator at a time, so the operand and operator are remembered in update() and wait for another operand.
 *In the third case, when user scroll the slider, change() method get invoked, it update the operand value in terms of current base value.
 *
 * @author Gushu Qin
 * @version 1.0
 */

public class MultibaseCalcState{
	private int value, result, base, curBase = 0;
	private boolean isReady, baseChange = false;
	private String firstOperand, secondOperand, firstOperator, secondOperator;


	MultibaseCalcState() { value = 0; }//constructor

	void clear() {
		value = 0;
		firstOperand = "";
		firstOperator = "";
		secondOperand = "";
		secondOperator = "";
	}
	
	
	/**
	 * inform operator Listener that a result is available to be display.
	 * 
	 * @return isReady indicate a result is available 
	 */
	
	boolean isValueReady(){
		return isReady;
	}
	
	
	/**
	 * setter method, indicate a result has been calculated
	 * 
	 * @param isR set the calculation result is ready 
	 */

	void setValueReady(boolean isR){ isReady = isR; }
	
	/**
	 * getter method, return the current result value
	 * 
	 * @return value current calculation result value 
	 */

	int currentValue() { return value; }


	/**
	 * store and adjust operand and operator value based on different operator.
	 * 
	 * @param textValue operand value
	 * @param operator operator value
	 * @param base1 current base value
	 */
	
	void update(String textValue, String operator, int base1){

		base = base1;
		if((firstOperand == null || firstOperand.isEmpty())){//if firstOperand does not contain any value, then assign the textValue to firstOperand

			firstOperand = textValue;
			firstOperator = operator;
		}

		else if((secondOperand == null || secondOperand.isEmpty()) && textValue != null){//if firstOperand contain value and secondOperand does not contain any value, then assign the textValue to secondOperand

			secondOperand = textValue;
			secondOperator = operator;
			deterFirst(firstOperator);// now that firstOperand, secondOperand, firstOperator and secondOperator all contains value, actual calculation can be perform
			deterSecond(secondOperator);
		}

		else
			firstOperator = operator;

	}
	
	
	/**
	 * when slider change it bases, number value in current base is updated by this method
	 * 
	 * @param cur number value based on current base
	 */

	void change(String cur){

		if(!(firstOperand == null || firstOperand.isEmpty()) && (secondOperand == null || secondOperand.isEmpty()))
			firstOperand = cur;

		else if (!(firstOperand == null || firstOperand.isEmpty()) && !(secondOperand == null || secondOperand.isEmpty()))
			secondOperand = cur;

		else
			;
	}
	
	/**
	 * Perform different operation between "=" and other operators. if the first operator is "=", the calculation can't be performed, so the first operand and operator will be replaced by the second operand and operator.
	 * otherwise it call calculation method to perform actual calculation.
	 * 
	 * @param operator the firstOperator 
	 */

	void deterFirst(String operator){


		if(!operator.equals("=")){
			value = calculate(firstOperand, secondOperand, operator);
			setValueReady(true);
			writeToFile(operator);
		}

		else{
			firstOperand = secondOperand;
			firstOperator = secondOperator;
			secondOperand = "";
			secondOperator = "";
		}
	}
	
	
	/**
	 * Perform different operation between "=" and other operators. if the second operator is not "=", then the current result and second operator become to the first operand and first operator for next calculation. 
	 * if the second operator is "=", then only the result save in first operand for next calculation 
	 * 
	 * @param operator the second operator
	 */

	void deterSecond(String operator){

		if(!operator.equals("=")){
			firstOperand = Integer.toString(result,base);
			firstOperator = secondOperator;
			secondOperand = "";
			secondOperator = "";
		}

		else{
			firstOperand = Integer.toString(result,base);;
			firstOperator = "";
			secondOperand = "";
			secondOperator = "";
		}
	}
	
	
	/**
	 * perform actual calculation.
	 * 
	 * @param num1 first operand
	 * @param num2 second operand
	 * @param operator first operator
	 */

	int calculate(String num1, String num2, String operator){

		int first, second;
		first = Integer.parseInt(num1, base);
		second = Integer.parseInt(num2, base);//convert operand in terms of current base

		if(operator.equals("+")){
			result = first + second;
			return Integer.parseInt(Integer.toString(result, base), base);
		}

		else if(operator.equals("-")){
			result = first - second;
			return Integer.parseInt(Integer.toString(result, base), base);
		}

		else if(operator.equals("x")){
			result = first * second;
			return Integer.parseInt(Integer.toString(result, base), base);
		}

		else{
			result = first / second;
			return Integer.parseInt(Integer.toString(result, base), base);
		}

	}
	
	
	
	/**
	 * write out calculation process to a text file named filename.txt
	 * 
	 * @param operator operator used in the calculation
	 */

	void writeToFile(String operator){
		if(base != curBase){//when base changes, display that change in the text file
			curBase = base;
			baseChange = true;
		}

		try (Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("filename.txt", true), "utf-8"))) {
			if(baseChange){
			writer.write("Current base is " + curBase + System.lineSeparator());
			baseChange = false;
		}
		writer.write(firstOperand + operator + secondOperand + " = " + Integer.toString(value, curBase) + "  " + System.lineSeparator());

		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
