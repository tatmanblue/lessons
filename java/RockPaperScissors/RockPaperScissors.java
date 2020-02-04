package cs145.examples.rps;

import java.util.Scanner;
import java.util.Random;

public class RockPaperScissors 
{
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
	    	  System.out.println("Please enter in a number");
	    	  computer = generator.nextInt(3) + 1;	    	  
	    	  user = keyboardIn.nextInt();
	    	  
		      //tell the player what was chosen
		      if(user == 1)//player is rock
		      {
		         System.out.println ("Player is rock");
		         System.out.println("Are you sure you want this? (y/n)");
		         conf = keyboardIn.next().charAt(0);//User Validates
		         if(conf == 'n')
		         {
		        	 System.out.println("re-enter number");
		        	 user = keyboardIn.nextInt();
		         }
		         else if(conf == 'y')
			        {
			        	System.out.println ("Player is rock");
			        }
		        	 
		      }
		      else if (user == 2)//player is paper
		      {
		         System.out.println ("Player is paper");
		         System.out.println("Are you sure you want this? (y/n)");
		         conf = keyboardIn.next().charAt(0);//User Validates
		         if(conf == 'n')
		        	 user = keyboardIn.nextInt();
		         else if(conf == 'y')
			        {
			        	System.out.println ("Player is paper");
			        }
		      }
		      else if (user == 3) //player is scissors
		      {
		        System.out.println ("Player is scissors");
		        System.out.println("Are you sure you want this? (y/n)");
		        conf = keyboardIn.next().charAt(0);//User Validates
		        if(conf == 'n')
		        	 user = keyboardIn.nextInt();
		        else if(conf == 'y')
		        {
		        	System.out.println ("Player is scissors");
		        }
		      }
		      else if (user >= 4)
		      {
		    	  System.out.println("You're going to end the game!");
		    	  System.out.println("Are you sure you want this? (y/n)");
			      conf = keyboardIn.next().charAt(0);//User Validates
			      if(conf == 'n')
			    	  user = keyboardIn.nextInt();
			      else if (conf == 'y')
			      {
			    	  System.out.println("Goodbye!");
			    	  break;
			      }
		      }
		      
		      
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
