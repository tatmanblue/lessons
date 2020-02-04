package cs145.examples.rps;

import java.util.Scanner;
import java.util.Random;

public class RockPaperScissors 
{
	public static int getUserInput()
	{
		int choice = -1;
		bool askForInput = true;
		while (askForInput == true)
		{
			System.out.println("Please enter in a number");
			choice = keyboardIn.nextInt();
			switch (choice)
			{
				case 1:
					System.out.println ("Player is rock");
					break;
				case 2:
					System.out.println ("Player is paper");
					break;
				case 3:
					System.out.println ("Player is scissor");
					break;
				default:
					break;
			}

			System.out.println("Are you sure you want this? (y/n)");
			char conf = keyboardIn.next().charAt(0);//User Validates
			if(conf == 'y')
			{
				askForInput = false;
			}
		}

		return choice;
	}
	
	//there are errors in this program
	/**
	 * @param args
	 */
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
	      int computer;
	      int user = 1;
	      boolean play = true;
	      char conf  = 'y';
	      //assigning the computer a selection
	      Random generator = new Random();

	      
	      //getting the user selection
	      Scanner keyboardIn = new Scanner(System.in);
	      
	      while(user > 0)
	      {
	    	  computer = generator.nextInt(3) + 1;	    	  
	    	  user = RockPaperScissors.getUserInput();

		      //tell the player what the computer has chosen
		      if(computer == 1)//computer is rock
		      {
		         System.out.println ("Computer is rock");
		      }
		      else if (computer == 2)//computer is paper
		      {
		         System.out.println ("Computer is paper");
		      }
		      else if (computer == 3)//computer is scissors
		      {
		         System.out.println ("Computer is scissors");
		      }
		      
		      
		      //determine winner
		      if (user == computer) //tie
		      {
		         System.out.println("It is a tie");
		      }
		      else if (user < computer) //player is rock
		      {
		         System.out.println("Computer wins");
		      }
		      else //computer is scissors
		      {
		         System.out.println("Player wins");
		      }
		      System.out.println();
	      }
	      keyboardIn.close();
	      
	}
}
