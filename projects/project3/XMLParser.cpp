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
	//create an instance of the structure
	_TokenStruct_ myStruct;
	//create a boolean to make sure the tokens are valid
	bool validTest = true;
	//create a temporary string to hold in the appending chars
	string tempString;
	string tagName;
	//incrementing variable
	int i = 0;

	//look at the input string and systematically check for valid tokens
	if(inputString[i] == '<')
	{
	i++;	//makes i the char after '<'
		//make a while loop
		while (inputString[i]!= '>')
		{
			//append a string so that we can send it to the vector
			tempString+= inputString[i];	//concatonnates the string at every itteration
			i++;
		}
		//now we have a token
		//need to assing the tag the tag name
		int y = 0;
		while (tempString[y] != '>' || tempString[y] != '/' || tempString[y]!= ' ')
		{
			tagName+= tempString[y];	//update tagName
		} 
		//make sure the tag name doesnt start with illegal characters
		if (tagName[0]== ' ' || tagName[0]== '-' || tagName[0] == '.')
		{
			//invalid tag name, return false
			return false;
		}
		//Switch a case statment on numbers that it cant start with
		switch (tempString[0])
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

		//need to look through tag and make sure it doesnt contain illegal characters
		for (int a = 0; a <= tagName.length(); a++)
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
	}
	return false;
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

