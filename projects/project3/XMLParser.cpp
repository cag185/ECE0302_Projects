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
	//create and instance of the structure
	TokenStruct myStruct;
	//create strings to help later
	string tempString, tagName, tagType;
	//int to start and stop tag
	int start, stop, a;
	//loop from the start of the string to the end of the string
	for(int i = 0; i < inputString.length(); i++)
	{
		//check for the start of a tag
		if(inputString[i] == '<')
		{
			a= i + 1;
			//check validity
			while (inputString[a] != '>')
			{
				tempString += inputString[a]; //adds the chars between < and > to tempString
				//increase a
				a++;
			}
			//now that we gave a potential tag, check to see if it is valid
			//SEE WHAT TYPE OF TAG IT IS
			//MAKE SURE IT DOES NOT CONTAIN ILLEGAL CHARACTERS
			//check for tag type

			//End tag -- determines type of token and token name
			if(tempString[0] == '/')
			{
				tagType = "END_TAG";
				for(int j  = 1; j < tempString.length(); j++)
				{
					tagName+= tempString[j];	//fixes tagName
				}
			}
			//Empty tag -- determines type of token and token name
			else if(tempString[tempString.length()-1] == '/' )	//last character 
			{
				tagType = "EMPTY_TAG";
				//copy the string until the last elements
				for(int j  = 0; j < tempString.length()-1; j++)
				{
					tagName+=  tempString[j];
				}
				
			}
			//Declaration -- determines type of token and token name
			else if(tempString[0]== '?' && tempString[tempString.length()-1] == '?')
			//first element and last element are ?
			{
				tagType = "DECLARATION";
				//copy the tag name minus the ?
			
				for(int j = 1; j < tempString.length()-1; j++ )
				{
					tagName+= tempString[j]; // copies the shortend string to tagName
				}
				
			}
			//Start tag
			else
			{
				//tag should defualt to a start tag -- still have to test if valid
				int j = 0;
				while (tempString[j] != ' ' && tempString[j] != '/')
				{
					tagName += tempString[j];
				}
			}
			//from here we know that the tag is a type of a certain tag and we also 
			//know the name of the tag
			//need to run the tag through the various tests

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
					break;
			}

			//NEED TO MAKE SURE THE NORMAL TAGNAMES DONT CONTAIN WEIRD CHARACTERS (not including content tag)
			
			//need to look through tag and make sure it doesnt contain illegal characters

			for (int a = 0; a < tagName.length(); a++)
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

				}
			}

				if(tagType == "END_TAG")
			{
				myStruct.tokenType = END_TAG;
			}
			else if (tagType == "START_TAG")
			{
				myStruct.tokenType = START_TAG;
			}
			else if(tagType == "EMPTY_TAG")
			{
				myStruct.tokenType = EMPTY_TAG;
			}
			else if (tagType == "DECLARATION")
			{
				myStruct.tokenType = DECLARATION;
			}
			else
			{
				return false;
			}
			//also need to send the name of the tag
			myStruct.tokenString = tagName;
			//push the structure to the vector
			tokenizedInputVector.push_back(myStruct);
		}

		//if the characters are a part of content instead of normal tags
		if(inputString[i] == '>')
		{
			a = i+1;
			while (inputString[a] != '<')
			{
				tagName += inputString[a];	//make tag name equal the content
			}
			
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
			}
		}
		//AT END OF EACH ITTERATION
		
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

