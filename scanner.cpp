#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 11 
//=====================================================



//my functions
//written by: adam Burcombe


//check for vowel
//takes a char
//returns true if char is a vowel
bool isVow(char ch)
{
  if(ch == 'a'||ch == 'i'||ch == 'u'||ch == 'e'||ch == 'o'||ch == 'I'||ch == 'E')
    {
      return true;
    }
  else return false;
}


//check for consonant set 1
// b g h k m n p r
//params: char
//return true if consonant
bool isCon_1(char ch)
{
  if(ch == 'b'||ch == 'g'||ch == 'h'||ch == 'k'||ch == 'm'||ch == 'n'||ch == 'p'||ch == 'r')
    {
      return true;
    }else return false;
}

//check for consonant set 2
// d j w y z
//params: char
//return true if consonant
bool isCon_2(char ch)
{
  if(ch == 'd'||ch == 'j'||ch == 'w'||ch == 'y'||ch == 'z')
    {
      return true;
    }else return false;
}




// --------- DFAs ---------------------------------

// ** WORD DFA
// ** Done by:adam Burcombe
// ** RE:   (vowel | vowel n | consonant vowel | consonant vowel n |
//           consonant-pair vowel | consonant-pair vowel n)^+              
 
bool word (string s)
{
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') 
    {

      if (state == 0 && isVow(s[charpos]))//q0 to qV (vowel)
	//go to staate qV(a final state)
	state = 1;
      else
	if (state == 0 && isCon_2(s[charpos])) //q0 to qSA 
	  {
	    //go to state qSA
	    state = 3;
	  }
	else 
	  if(state == 0 && isCon_1(s[charpos]))//state q0 to qY
	    {
	      //go to qY
	      state = 4;
	    }
	  else 
	    if(state == 0 && s[charpos] == 't') //q0 to qT
	      {
		//to qT
		state = 5;
	      }
	    else
	      if(state == 0 && s[charpos] == 's') //q0 to qS
		{
		  //to qS
		  state = 6;
		}
	      else
		if(state == 0 && s[charpos] == 'c') //q0 to qC
		  {
		    //to qC
		    state = 7;
		  }
		else
		  if (state == 1 && s[charpos] == 'n' ) //qV to qN (vowel n)
		    {
		      //go to state qN(final state)
		      state = 2;
		    }
		  else
		    if (state == 1 && isCon_2(s[charpos]) ) //qV to qSA
		      {
			//go to qSA
			state = 3;
		      }
		    else
		      if (state == 1 && isCon_1(s[charpos]) ) //qV to qY
			{
			  //go to state qY
			  state = 4;
			}
		      else
			if(state == 1 && s[charpos] == 't') //qV to qT
			  {
			    //to qT
			    state = 5;
			  }
			else
			  if(state == 1 && s[charpos] == 's') //qV to qS
			    {
			      //to qS
			      state = 6;
			    }
			  else
			    if(state == 1 && s[charpos] == 'c') //qV to qC
			      {
				//to qC
				state = 7;
			      }
			    else 
			      if(state == 1 && isVow(s[charpos])) //qV to qV
				{
				  //loop
				  state = 1;
				}
			      else
				if(state == 2 && isVow(s[charpos]))//qN to qV
				  {
				    state = 1;
				  }
			      else 
				if(state == 2 && isCon_2(s[charpos]))//qN to qSA
				  {
				    //to qSA
				    state = 3;
				  }
				else
				  if(state == 2 && isCon_1(s[charpos]))//qN to qY
				    {
				      //to qY
				      state = 4;
				    }
				  else
				    if(state == 2 && s[charpos] == 't') //qN to qT
				      {
					//to qT
					state = 5;
				      }
				    else
				      if(state == 2 && s[charpos] == 's') //qN to qS
					{
					  //to qS
					  state = 6;
					}
				      else
					if(state == 2 && s[charpos] == 'c') //qN to qC
					  {
					    //to qC
					    state = 7;
					  }
					else
					  if(state == 3 && isVow(s[charpos]) )//state qSA to qV
					    {
					      //to qV
					      state = 1;
					    }
					  else 
					    if(state == 4 && isVow(s[charpos])) //qY to qV
					      {
						state = 1;
					      }
					    else
					      if(state == 4 && s[charpos] == 'y' )//state qY to qSA
						{
						  //to qSA
						  state = 3;
						}
					      else
						if(state == 5 && isVow(s[charpos]) )//state qT to qV
						  {
						    //to qV
						    state = 1;
						  }
						else
						  if(state == 5 && s[charpos] == 's' )//state qT to qSA
						    {
						      //to qSA
						      state = 3;
						    }
						  else
						    if(state == 6 && isVow(s[charpos]) )//state qS to qV
						      {
							//to qV
							state = 1;
						      }
						    else
						      if(state == 6 && s[charpos] == 'h' )//state qT to qSA
							{
							  //to qSA
							  state = 3;
							}
						      else
							if(state == 7 && s[charpos] == 'h' )//state qC to qSA
							  {
							    //to qSA
							    state = 3;
							  }
							else
							  {
							    //cout << "I am stuck in state " << state << endl;
							    return false;
							  }

      
      //add to charpos once per loop
      charpos++;
    }//end of while
  
  
  // where did I end up????
  if (state == 2 || state == 1) return(true);  // end in a final state
  else return(false);
}


// ** WORD1 DFA
// ** Done by:adam Burcombe
// ** RE:   (vowel | vowel n | consonant vowel | consonant vowel n |
//           consonant-pair vowel | consonant-pair vowel n)^+
bool word1 (string s)
{
  
  if(word(s))
    {
      //find last char in s
      int i = s.size();
      char ch = s[i-1];

      //if the last char in string is E or I then return false
      if(ch == 'E' || ch == 'I')return false;
      else return true;
    }
  else return false;
}


// ** WORD2 DFA
// ** Done by:adam Burcombe
// ** RE:   (vowel | vowel n | consonant vowel | consonant vowel n |
//           consonant-pair vowel | consonant-pair vowel n)^+
bool word2(string s)
{
  //since this is called after word1 one we can assume that if it passes word() it is
  //in state qV with E or I ending making it word2
  if(word(s))return true;
  else return false;
  
}



// ** PERIOD DFA 
// ** Done by: Erik
bool PeriodToken(string s)
{
  if(s == ".")
    return true;
  else
    return false;
}






// -----  Tables -------------------------------------

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype { WORD1, WORD2, PERIOD, ERROR,
		 VERB,VERBNEG,VERBPAST,VERBPASTNEG,
		 IS,WAS,OBJECT,SUBJECT,DESTINATION,
		 PRONOUN, CONNECTOR, EOFM   };

string tokenName[30] = { "WORD1","WORD2", "PERIOD", "ERROR",
			 "VERB","VERBNEG","VERBPAST","VERBPASTNEG",
			 "IS","WAS","OBJECT","SUBJECT","DESTINATION",
			 "PRONOUN", "CONNECTOR", "EOFM"  };// for the display names oftokens - must be in the same order as the tokentype.

string reservedWords[20] = { "masu","masen","mashita","masendeshita",
			     "desu","deshita","o","wa","ni","watashi",
			     "anata","kare","kanojo","sore","mata",
			     "soshite","shikashi","dakara","eofm" };

tokentype reservedTokens[20] = { VERB,VERBNEG,VERBPAST,VERBPASTNEG,
				 IS,WAS,OBJECT,SUBJECT,DESTINATION,
				 PRONOUN,PRONOUN,PRONOUN,PRONOUN,
				 PRONOUN,CONNECTOR,CONNECTOR,
				 CONNECTOR,CONNECTOR,EOFM };




// ------------ Scaner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: adam Burcombe
int scanner(tokentype& a, string& w)
{

  // ** Grab the next word from the file via fin
  fin >> w;
  // 1. If it is eofm, return right now.   
  if(w == "eofm")return 0;

  /* 
  2. Call the token functions one after another (if-then-else)
     And generate a lexical error message if both DFAs failed.
     Let the token_type be ERROR in that case.

  3. Then, make sure WORDs are checked against the reservedwords list
     If not reserved, token_type is WORD1 or WORD2.

  4. Return the token type & string  (pass by reference)
  */

  if (PeriodToken(w))
    {a = PERIOD; }
  else
    if( word1(w) )
      { a = WORD1; }
    else 
      if( word2(w) )
	{a = WORD2; }
      else
	{
	  //gernerate lexical error
	  cout << "Lexical error: " << w << " is not a valid token" << endl;
	  a = ERROR;
	}

  //check the reserved words list
  if(a == WORD1 || a == WORD2)
    {
      for(int i = 0; i < 19; i++)
	{
	  if (w == reservedWords[i])
	    {
	      //set token type
	      a = reservedTokens[i];
	    }
	}
    }

  
}//the end of scanner








// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Rika
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner
       if (theword == "eofm") break;  // stop now


       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end



