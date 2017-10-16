import java.util.ArrayList;
import java.util.Random;


class PeaceDeck extends Deck{
	ArrayList<PeaceCard> Peacecard; 
	public PeaceDeck(){
			Peacecard = new ArrayList<PeaceCard>();
			for(CardSuit s : CardSuit.values()){
				for(CardValue v : CardValue.values()){
					Peacecard.add(new PeaceCard(s,v));
				}
			}
	}
	
	public Card draw() {

		Random rand = new Random();
		int  n = rand.nextInt(Peacecard.size());
		Card temp = Peacecard.get(n);
		Peacecard.remove(n);
		return temp;


	}

}
