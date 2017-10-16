class PeaceCard extends Card{
	
	public PeaceCard(CardSuit s, CardValue v){
		suit = s;
		value = v;
		
	}


	public boolean winner(Card c) {
		CardSuit s1 = getCardSuit();
		CardSuit s2 = c.getCardSuit();
		CardValue v1 = getCardValue();
		CardValue v2 = c.getCardValue();
		
		if(v1.compareTo(v2) < 0)
			return true;
		else if(v1.compareTo(v2) == 0 && s1.compareTo(s2) < 0)
			return true;
		else
			return false;
	}
}