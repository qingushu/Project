import java.util.*;

public class Deck {
	
	ArrayList<Card> card; 


	public Deck() {
		
		card = new ArrayList<Card>();
		for(CardSuit s : CardSuit.values()){
			for(CardValue v : CardValue.values()){
				card.add(new Card(s,v));
			}
			
		}

	}

	public Card draw() {

		Random rand = new Random();
		int  n = rand.nextInt(card.size());
		Card temp = card.get(n);
		card.remove(n);
		return temp;


	}


}
