/* ------------------------------------------------ 
 * Project : SpeechGrade
 * Description: Comparing the recent presidential announcement speeches and printing out a table sorting them 
 *				according to the F-K grade level test, with the lowest grade level at the top of the list, 
 *				and the highest grade-level at the bottom.
 * ------------------------------------------------
*/

#include <iostream>		//for input/output in C++
#include <stdio.h>		//for input/output in C
#include <stdlib.h>
#include <fstream>		//to open text file
using namespace std;


//displayIdentifyingInfo displays information about author and program
//the function does not return anything
void displayIdentifyingInfo()
{
	printf("Author: Bushra Baqui\n");
	printf("Program 5: SpeechGrade\n");
	printf("TA: Chenwei Zhang\n");
	printf ("Lab: Tues 9am\n");
	printf("April 4, 2016\n");
	printf("System: Windows 10, DevC++\n\n\n");
}//end of displayIdentifyingInfo()


/*-------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/


int main()
{
	displayIdentifyingInfo();
	
	// declare an input file 
	ifstream inFile;
	
	// declare array of filenames
	const char *filenames[ ] = {"BenCarson.txt", "BernieSanders.txt", "CarlyFiorina.txt", "ChrisChristie.txt", 
						  		"DonaldTrump.txt", "HillaryClinton.txt", "JamesWebb.txt", "JebBush.txt", 
								"JohnKasich.txt", "LindseyGraham.txt", "MarcoRubio.txt", "MikeHuckabee.txt", 
								"RandPaul.txt", "RickPerry.txt", "RickSantorum.txt", "ScottWalker.txt", "TedCruz.txt"}; 


	// Declaration of Variables
	char c;
	double gradeLevel = 0;
	double score[20];
	double temp;    		// variable temp is used to swap scores
	const char *temp2;		// variable temp2 is used to swap files 
 
	// step through each of the files
	for(int i=0; i<17; i++) 
	{
		int count1 = 0;		// counting total words in each file
		int count2 = 0;		// counting total sentences in each file
		int count3 = 0;		// counting total syllables in each file
		int count = 0;
		inFile.open(filenames[i]);  // open all files
   		
		c = inFile.get();	//get the next char
   		
		while (c != EOF)	//loops while file does not reach the end
		{
			//------------------conditions for checking words--------------------------------------------------
			
			//words are separated if there is whitespace, hypen, or quotes
			// isspace checks whether c is a white-space character.
			if (isspace(c) || c == '-' || c == '"' )  
			{
				count1++; 
			}
				 
			// words are separated if there is a period in between two numbers (e.g: 2.7 --> contains 2 words)
			if ((c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || 
				 c == '6' || c == '7' || c == '8' || c == '9') && inFile.peek() == '.')  
		    {
				count1++;
			}
		    	
		    // words are separated if there is a period between two alphabetical chracters (e.g: J.R --> contains 2 words)	
		    if (((c == (rand()%26+65)) || (c == (rand()%26+97))) && inFile.peek() == '.')
		    {
				count1++;
			}
		    
			//---------------------condition for checking sentences---------------------------------------------
			
			if (c == '.' || c == '?' || c == '!')
		    	count2++;
		    
			//------------------conditions for checking syllables------------------------------------------------
		   
		    // checks if number of syllables being the count of the number of vowels
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || 
				c == 'u' || c == 'A' || c == 'E' || c == 'I' || 
				c == 'O' || c == 'U' || c == 'y' || c == 'Y')
			{
				++count3;
				
				// the function peek() returns the next character in the input sequence, without extracting it
				// checks if two adjacent vowels within a word not at the end
				if (inFile.peek() == 'a' || inFile.peek() ==  'e' || inFile.peek() ==  'i' || inFile.peek() ==  'o' ||
					inFile.peek() == 'u' || inFile.peek() ==  'y' || inFile.peek() ==  'A' || inFile.peek() ==  'E' ||
					inFile.peek() == 'I' || inFile.peek() ==  'O' || inFile.peek() ==  'U' || inFile.peek() ==  'Y')
				{
					// checks if the character is not the end of the word
					if(inFile.peek() != ' ' || inFile.peek() != '-')
					{
						count3 = count3 - 1;
					}
				}
					
				// checks if a word ends with a vowel-consonant-'e' 
				// checks if the character is a consonant
				if (inFile.peek() != 'a' || inFile.peek() !=  'e' || inFile.peek() !=  'i' || inFile.peek() !=  'o' ||
					inFile.peek() != 'u' || inFile.peek() !=  'y' || inFile.peek() !=  'A' || inFile.peek() !=  'E' ||
					inFile.peek() != 'I' || inFile.peek() !=  'O' || inFile.peek() !=  'U' || inFile.peek() !=  'Y'	)
				{
					// checks if the next character of consonant is the character 'e
					if (inFile.peek() == 'e')
					{
						// checks if the character 'e' is the last character of the word
						if (inFile.peek() == ' ' || inFile.peek() == '-')
						{
							count3 = count3 - 1;
						}
					}
				}
					
				// checks if a word ends with a vowel-consonant-'es'  
				// checks if the character is a consonant  
				if (inFile.peek() != 'a' || inFile.peek() !=  'e' || inFile.peek() !=  'i' || inFile.peek() !=  'o' ||
					inFile.peek() != 'u' || inFile.peek() !=  'y' || inFile.peek() !=  'A' || inFile.peek() !=  'E' ||
					inFile.peek() != 'I' || inFile.peek() !=  'O' || inFile.peek() !=  'U' || inFile.peek() !=  'Y'	)
				{
					// checks if the next character of consonant is the character 'e'
					if (inFile.peek() == 'e')
					{
						// checks if the next character of 'e' is the character 's'
						if (inFile.peek() == 's')
						{
							// checks if the character 's' is the last character of the word
							if (inFile.peek() == ' ' || inFile.peek() == '-')
							{
								count3 = count3 - 1;
							}
						}
					}
				}
				
				// checks  if a word ends with a vowel and has more than one syllable
				if ((inFile.peek() == ' ' || inFile.peek() == '-') && (count > 1))
				{
					count3 = count3 - 1;
				}
				
			}// end of if (for checking syllables...
				     
			c = inFile.get();	//get the next character
   		
		}// end of While(....
   	
		inFile.close();		// close all files
		
		// Flesch-Kincaid (F-K) grade level test formula
		// count1 --> Total Words, count2 --> Total Sentences, count3 --> Total Syllables
		gradeLevel = (((double)count1/(double)count2)*0.39)+ (11.8 * ((double)count3/(double)count1)) - 15.59;
		
		// stores each file gradeLevel in score
		score[i] = gradeLevel;
		
	}// end of for(...
	
	printf ("Presidential Announcement Speech reading grade levels:\n");
	
	// bubble sort array to put the gradeLevel in ascending order
	for (int p = 0; p < 17; p++)
    {
        for (int q = p + 1; q < 17; q++)
        {
            if (score[p] < score[q])
            {
                // swap the score
				temp = score[p];
                score[p] = score[q];
                score[q] = temp;
                
                // swap the filenames alongside the score
                // this code will make sure the filenames stick to the scores
				temp2 = filenames[p];
                filenames[p] = filenames[q];
                filenames[q] = temp2;
                
            }
        }
    }
    
	for (int p = 0; p < 17; p++)
    {
        // printing the files associated to their scores upto 2 decimal places
		printf("%0.2f   %s\n", score[p], filenames[p]);    
    }
	
	return 0;	
}//end of main()

