// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here 
XMLParser::XMLParser()
{
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	//std:: cout << "this is char at 39: " << std:: endl;
	//std::cout << inputString[39] << std::endl;
	//create and instance of the structure
	TokenStruct myStruct;
	//create strings to help later
	string tempString, tagName, decTagName, tagType, strLengthTrack;
	//int to start and stop tag
	int start, stop, a;
	int cursor = 0;
	//variable to determine if the tag should be tested or not
	bool test = false;
	//loop from the start of the string to the end of the string
	std:: cout << "The length of the string is : " << inputString.length() << std::endl;
	while(cursor < inputString.length())
	{
		//clear the strings
		tempString = "";
		tagName = "";
		tagType = "";
		decTagName = "";
		//check for the start of a tag
		if(inputString[cursor] == '<')
		{
			a= cursor + 1;
			//check validity
			while (inputString[cursor] != '>' )
			{
				while(inputString[a] != '>')
				{
					tempString += inputString[a]; //adds the chars between < and > to tempString
					strLengthTrack += inputString[a]; // used for tracking
					//increase a
					a++;
				}
				//need to update cursor, but sometimes next char is \n
				std::cout << "TempString: " << tempString << std::endl;
				
				if(isspace(inputString[cursor+1]))
				{
					cursor ++;
				}
				else
				{
					//cursor++;	//moves cursor to the position after closing bracket
				}
				std:: cout << "The pos of the cursor: " << cursor << std::endl;
				std::cout << "The char at the cursor: " << inputString[cursor] << std::endl;
				std::cout << "this is the potential tag" << std::endl;
				std::cout << tempString << std::endl;
				//now that we gave a potential tag, check to see if it is valid
				//SEE WHAT TYPE OF TAG IT IS
				//MAKE SURE IT DOES NOT CONTAIN ILLEGAL CHARACTERS
				//check for tag type

				//End tag -- determines type of token and token name -- should be ok
				if(tempString[0] == '/')
				{
					tagType = "END_TAG";
					test = true;
					for(int j  = 1; j < tempString.length(); j++)
					{
						tagName+= tempString[j];	//fixes tagName
					}
					//testing for correct output
					std::cout << tagName << std::endl;
				}
				//Empty tag -- determines type of token and token name
				else if(tempString[tempString.length()-1] == '/' )	//last character 
				{
					tagType = "EMPTY_TAG";
					test = true;
					//copy the string until the last elements
					for(int j  = 0; j < tempString.length()-1; j++)
					{
						tagName+=  tempString[j];
					}
					//testing for correct output
					std::cout << tagName << std::endl;
				}
				//Declaration -- determines type of token and token name
				else if(tempString[0]== '?' && tempString[tempString.length()-1] == '?')
				//first element and last element are ?
				{
					tagType = "DECLARATION";
					test = false;
					//copy the tag name minus the ?
					int count = 0;
					//tag name should be the whole string minus the ??
					int b = 0;
					//while (tempString[b] != ' ' && tempString[b]!= '/')
					//{
					//	count++;
					//	b++;
					//}
					//for(int j = 1; j <= count; j++ )
					for (int j = 1;  j < tempString.length()-1; j++)
					{
						tagName+= tempString[j]; // copies the shortend string to tagName
					}
					//testing for correct output
					std::cout << tagName << std::endl;
				}
				//Start tag
				else
				{
					tagType = "START_TAG";
					test = true;
					//tag should defualt to a start tag -- still have to test if valid
					//tagName = tempString;
					//testing for correct output
					std::cout << tagName << std::endl;
					std::cout << "Tag Type: " << tagType << std::endl;
				}

				//update the token name and token type

				if(tagType == "END_TAG")
				{
					std::cout << "Token is EndTag" << std:: endl;
					myStruct.tokenType = END_TAG;
				}
				else if (tagType == "START_TAG")
				{
					std::cout << "Token is StartTag" << std:: endl;
					myStruct.tokenType = START_TAG;
				}
				else if(tagType == "EMPTY_TAG")
				{
					std::cout << "Token is EmptyTag" << std:: endl;
					myStruct.tokenType = EMPTY_TAG;
				}
				else if (tagType == "DECLARATION")
				{
					std::cout << "Token is Declaration" << std:: endl;
					myStruct.tokenType = DECLARATION;
				}
				//also need to send the name of the tag
				myStruct.tokenString = tagName;


				//from here we know that the tag is a type of a certain tag and we also 
				//know the name of the tag
				//need to run the tag through the various tests
				if(test == true)	//we SHOULD test
				{
					//NEED TO MAKE SURE THE TAG DOESNT START WITH ILLEGAL CHARACTERS
					if (tagName[0]== ' ' || tagName[0]== '-' || tagName[0] == '.')
					{
						//invalid tag name, return false
						return false;
					}
					//Switch a case statment on numbers that it cant start with
					switch (tagName[0])
					{
						case '0':
							return false;
							break;
						case '1':
							return false;
							break;
						case '2':
							return false;
							break;
						case '3':
							return false;
							break;
						case '4':
							return false;
							break;
						case '5':
							return false;
							break;
						case '6':
							return false;
							break;
						case '7':
							return false;
							break;
						case '8':
							return false;
							break;
						case '9':
							return false;
							break;
						default:
							//do nothing
							std:: cout << "there are no illegal characters at first index" << std::endl;
							break;
					}

					//NEED TO MAKE SURE THE NORMAL TAGNAMES DONT CONTAIN WEIRD CHARACTERS (not including content tag)
					//print of what the tags are
					//std::cout << "Tag: " << tagType << std:: endl;
					//need to look through tag and make sure it doesnt contain illegal characters
					
					for (int a = 0; a < tagName.length()-1; a++)
					{
						//make a char hold the character at the index
						char ch = tagName[a];

						//switch through a case statement
						switch (ch)
						{
							case '!' :
								return false;
								break;
							case '"' :
								return false;
								break;
							case '#' :
								return false;
								break;
							case '$' :
								return false;
								break;
							case '%' :
								return false;
								break;
							case '&' :
								return false;
								break;				
							case '\'' :
								return false;
								break;	
							case '(' :
								return false;
								break;	
							case ')' :
								return false;
								break;	
							case '*' :
								return false;
								break;	
							case '+' :
								return false;
								break;	
							case ',' :
								return false;
								break;
							case '/' :
								return false;
								break;
							case ';' :
								return false;
								break;
							case '<' :
								return false;
								break;
							case '=' :
								return false;
								break;
							case '>' :
								return false;
								break;
							case '?' :
								return false;
								break;
							case '@' :
								return false;
								break;
							case '[' :
								return false;
								break;
							case '\\' :
								return false;
								break;
							case ']' :
								return false;
								break;
							case '^' :
								return false;
								break;
							case '`' :
								return false;
								break;
							case '{' :
								return false;
								break;
							case '|' :
								return false;
								break;
							case '}' :
								return false;
								break;
							case '~' :
								return false;
								break;
							case ' ' :
								return false;
								break;						
							default:
								//do nothing
								break;
						}
						//std::cout << "test again a: " << a <<  std::endl;
					}
					std:: cout << "there are no illegal characters" << std:: endl;
				}
				//need to update the vector here and in the content section
				//push the structure to the vector
				std::cout << "test" << std::endl;
				tokenizedInputVector.push_back(myStruct);
				std:: cout << "successfully pushed back to vector" << std:: endl;
			}
			std::cout << "We have broken out of the loop" << std::endl;
		}

		//CONTENT
		//if the characters are a part of content instead of normal tags
		/*if(inputString[cursor] != '<' && inputString[cursor] != '>')
		{
			a = cursor;
			while (inputString[a] != '<')
			{
				tagName += inputString[a];	//make tag name equal the content
			}
			//testing for correct output
				std::cout << tagName << std::endl;
			//keep adding to tag
			//after tag name is compelete, design a test to make sure it is not all white space
			//if its good, allow it to store in the vector and make the type 'content'
			int tempInt = tagName.length();
			int numSpace = 0;
			for (int b = 0; b < tempInt; b++)
			{
				if(isspace(tagName[b]))
					numSpace++;
			}
			if(numSpace < tempInt)
			{
				//we can make this tag a tag
				myStruct.tokenString = tagName;
				myStruct.tokenType = CONTENT;

				//need to push the structure to the vector
				tokenizedInputVector.push_back(myStruct);
				std:: cout << "successfully pushed back to vector" << std:: endl;
			}	
		} */
		//AT END OF EACH ITTERATION
		cursor++;
	}
	return true;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}

