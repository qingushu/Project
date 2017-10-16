public class Card {
	
	protected CardSuit suit;
	
	protected CardValue value;
	
	public Card(CardSuit s, CardValue v){
		suit = s;
		value = v;
	}
	public Card(){}
	
	public String toString() {
		CardValue v = this.getCardValue();
		CardSuit s = this.getCardSuit();
		String m = v + " " + "of" + " " + s;
		return m;
	}
	
	
	public boolean winner(Card c) {
		CardSuit s1 = getCardSuit();
		CardSuit s2 = c.getCardSuit();
		CardValue v1 = this.getCardValue();
		CardValue v2 = c.getCardValue();
		
		if(v1.compareTo(v2) > 0)
			return true;
		else if(v1.compareTo(v2) == 0 && s1.compareTo(s2) > 0)
			return true;
		else
			return false;
	}

	


	
	public CardSuit getCardSuit( ){
		return suit;
	}
	

	
	public CardValue getCardValue( ){
		return value;
	}
	
}
