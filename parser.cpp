#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
using namespace std;




//=================================================
//===============SCANNER===========================
//=================================================

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
// --------- DFAs ---------------------------------



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




// ------------ Scaner  -----------------------
ifstream fin;  // global stream for reading from the input file
// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: adam Burcombe
int scanner(tokentype& a, string& w)
{

  // ** Grab the next word from the file via fin
  fin >> w;
  // 1. If it is eofm, return right now.
  if(w == "eofm") 
    {
      a = EOFM;
      return 1;
    }

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
          a = ERROR;
	  return 0;
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

  return 1;
}//the end of scanner




//=================================================
// File parser.cpp written by Group Number: 11
//=================================================

//predeclarations
void story();
void s();
void afterSubject();
void afterNoun();
void afterObject();
void noun();
void verb();
void be();
void tense();
tokentype next_token();

// ----- Utility and Globals -----------------------------------

tokentype saved_token;
bool token_available = false;
bool error_found = false;
string saved_lexeme;


//syntaxerror1
//Done by: adam burcombe
void syntaxerror1(tokentype expected, string s)
{
  cout << "\nSYNTAX ERROR : expected " << tokenName[expected] << " but found " << s << "\n\n";
  
  //error found
  error_found = true;

  //eat up a token
  token_available = false;
  next_token();

  exit(1);
}


//syntaxerror2
//Done by: erik hernandez
void syntaxerror2(string s, string functionName) 
{
  cout << "\nSYNTAX ERROR: unexpected " << s << " found in " << functionName << "\n\n";

  //error found
  error_found = true;

  exit(1);
}

//------------------------------------------------------------------------------------



//match function
//Done by: erik hernandez & adam Burcombe
bool match(tokentype expected)
{
  if (next_token() != expected) 
    { 
      // mismatch has occurred with the next token
      // calls a syntax error function here to  generate a syntax error message here and do recovery
      syntaxerror1(expected, saved_lexeme);      
      return false;
    }else // match has occurred
    {
      token_available = false;  // eat up the token
      cout << "Matched " << tokenName[expected] << "\n";
      return true;  // say there was a match
    }
  
}


//grabs the next token if saved token has not been used yet
//done by:erik hernandez
tokentype next_token() 
{
  if (!token_available)// if there is no saved token yet 
    { 
      bool lexicalError;

      //first call scanner to grab new token
      lexicalError = scanner(saved_token, saved_lexeme);  

      cout << "Scanner called using word: " << saved_lexeme << "\n";

      if (!lexicalError) cout << "\nLexical error: " << saved_lexeme << " is not a valid token" << endl;

      if(saved_token == EOFM && !error_found){cout <<endl<< "Successfully parsed <story>." << endl;}

      token_available = true;  // mark that fact that you have saved it
    }
  return saved_token;  // return the saved token
}


// ----- RDP functions - one per non-term -------------------



//story RD function
//Grammar: <story>::=<s>{<s>} 
//stay in loop as long as possible start of <s> is the next_token 
//Done by: adam burcombe
void story()
{
  cout << "Processing <story>" << endl << endl;

  //call s
  s();
  
  //loop s
  while(true)
    {
      switch(next_token())
	{
	case CONNECTOR:
	case WORD1:
	case PRONOUN:
	  s();
	  break;
	case PERIOD:
	case WORD2:
	case VERB:
	case VERBNEG:
	case VERBPAST:
	case VERBPASTNEG:
	case IS:
	case WAS:
	case OBJECT:
	case SUBJECT:
	case DESTINATION:
	  //EAT A TOKEN AND CONTINUE
	  token_available = false;
	  break;
	default:
	  return;
	}
    }


}//END <STORY>


//s RD function
//Grammar: <s>::= CONNECTOR <noun> SUBJECT <after subject>
// Done by: adam burcombe
void s()
{
  cout << "Processing <s>" << endl;

  //call next token to initiate scanner
  switch(next_token())
    {

    case CONNECTOR:
      match(CONNECTOR);
      noun();
      match(SUBJECT);
      afterSubject();
      break;
    case WORD1:
    case ERROR:
    case PRONOUN:
      noun();
      match(SUBJECT);
      afterSubject();
      break;
    default:
      syntaxerror2(saved_lexeme, "s");
      break;

    }
}//end <s>

//after subject
//Grammar: <afterSubject>::= <ver><tense>PERIOD | <noun> <afterNoun>
//Done by: Erik Hernandez
void afterSubject()
{
  cout << "Processing <afterSubject>" << endl;

  switch (next_token()) 
    {
      //verb case
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;
      // <noun>
    case WORD1:
    case PRONOUN:
      noun();
      afterNoun();
      break;
      // else
    default:
      syntaxerror2(saved_lexeme, "afterSubject");
      break;
    }
  
}//end <afterSubject>


//after noun RD function
//Grammar: <afterNoun>::= <verb><tense>PERIOD | DESTINATION<verb><tense>PERIOD
//DONE BY: erik hernandez
void afterNoun()
{
  cout << "Processing <afterNoun>" << endl;
  switch (next_token()) 
    {
      // <be>
    case IS:
    case WAS:
      be();
      match(PERIOD);
      break;
      
      // DESTINATION
    case DESTINATION:
      match(DESTINATION);
      verb();
      tense();
      match(PERIOD);
      break;
      
      // OBJECT
    case OBJECT:
      match(OBJECT);
      afterObject();
      break;
    default:
      syntaxerror2(saved_lexeme, "afterNoun");
    }
  
  
}//end <afterNoun>



//after object RD function
//Grammar: <afterObject>::=<verb><tense>PERIOD | <noun> DESTINATION <verb><tense>PERIOD
//done by: erik hernandez
void afterObject()
{
  cout << "Processing <afterObject>" << endl;

   switch (next_token()) 
    {
      // <verb>
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;
      
      // <noun>
    case WORD1:
    case PRONOUN:
      noun();
      match(DESTINATION);
      verb();
      tense();
      match(PERIOD);
      break;
    default:
      syntaxerror2(saved_lexeme, "afterObject");
    }
  
}//end <afterObject>



//noun RD function
//Grammar: <noun>::= WORD1 | PRONOUN
//DONE BY: erik hernandez
void noun()
{
  cout << "Processing <noun>" << endl;


  switch (next_token()) 
    {
    case WORD1:
      match(WORD1);
      break;
    case PRONOUN:
      match(PRONOUN);
      break;
    default:
      syntaxerror2(saved_lexeme, "noun");
    }
  
}//END <noun>   



//verb RD function
//Grammar: <verb>::= WORD2
//DONE BY: ADAM BURCOMBE
void verb()
{
  cout << "Processing <verb>" << endl;

  match(WORD2);
}//END <VERB>


//be RD function
//Grammar: <be>::= IS | WAS
//done by: erik hernandez
void be()
{
  cout << "Processing <be>" << endl;


  switch (next_token()) 
    {
    case IS:
      match(IS);
      break;
    case WAS:
      match(WAS);
      break;
    default:
      syntaxerror2(saved_lexeme,"be");
    }
}

//tense RD function
//Grammar: <tense>::= VERBPAST | VERBPASTNEG | VERB | VERBNEG
//done by: erik hernandez
void tense()
{
  cout << "Processing <tense>" << endl;

  switch (next_token()) 
    {
    case VERBPAST:
      match(VERBPAST);
      break;
    case VERBPASTNEG:
      match(VERBPASTNEG);
      break;
    case VERB:
      match(VERB);
      break;
    case VERBNEG:
      match(VERBNEG);
      break;
    default:
      syntaxerror2(saved_lexeme,"tense");
    }
}









//---------------------------------------

// The new test driver to start the parser
// Done by:  adam burcombe
int main()
{
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  story();
  //** closes the input file 
  fin.close();
}
