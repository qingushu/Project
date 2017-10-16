import java.util.*;

public class MainDriver {

	static final int HANDS = 52;
	
	public static void main(String[] args) {
		
		System.out.println("Which game do you try to play, type 1 for war game, type 2 for peace game");
		Scanner g = new Scanner(System.in);
		int n = g.nextInt();
		g.close();
		
		if(n == 1){
			System.out.println("Welcome to war game");
			WarDeck player1 = new WarDeck();
			WarDeck player2 = new WarDeck();
			Card c1, c2;
			int player1Score = 0, player2Score = 0;
			
			for(int i = 0; i < HANDS; i++){
				c1 = player1.draw();
				System.out.println(c1.toString());
				c2 = player2.draw();
				System.out.println(c2.toString());
				
				boolean isWin;
				isWin =c1.winner(c2);
					if(isWin){
						player1Score++;
						System.out.println("player1 win");
					}
					else{
						player2Score++;
						System.out.println("player2 win");
					}
			}
			System.out.printf("Final score: Player 1--%d; Player 2--%d", player1Score, player2Score);
			
		}else if(n == 2){
			System.out.println("Welcome to peace game");
			PeaceDeck player1 = new PeaceDeck();
			PeaceDeck player2 = new PeaceDeck();
			Card c1, c2;
			int player1Score = 0, player2Score = 0;
			
			for(int i = 0; i < HANDS; i++){
				c1 = player1.draw();
				System.out.println(c1.toString());
				c2 = player2.draw();
				System.out.println(c2.toString());
				
				boolean isWin;
				isWin =c1.winner(c2);
					if(isWin){
						player1Score++;
						System.out.println("player1 win");
					}
					else{
						player2Score++;
						System.out.println("player2 win");
					}
			}
			System.out.printf("Final score: Player 1--%d; Player 2--%d", player1Score, player2Score);
			
		}else {
			
			System.out.println("Sorry, no such game");
		}
				
		
	}

}
