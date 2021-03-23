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
	string tagType;
	//incrementing variable
	int i = 0;

	//look at the input string and systematically check for valid tokens
	if(inputString[i] == '<')
	{
		i++;	//makes i the char after '<'
	}

	//COULD HAVE A FEW DIFFERENT CASES
	//START TAG --	<element>
	//END TAG --	</element>
	//EMPTY TAG -- 	<element/>
	//Declaration -- <? some data ?>

	//easiest to check for end tag
		
	//make a while loop
	while (inputString[i]!= '>')
	{
		//append a string so that we can send it to the vector
		tempString+= inputString[i];	//concatonnates the string at every itteration
		i++;
	}
	//now we have a token
	//if the token begins with '/' we know it is an end tag
	switch(tempString[0])
	{
		case '/':
			//myStruct.tokenType = END_TAG;
			tagType = "END_TAG";
			break;
	}

	//case where tag is not end tag or declaration
	if(tempString[0] == '<' && tempString[1]!= '/' && tempString[1]!= '?')		//basically rules out end tags and declarations
	{
	//need to assing the tag the tag name. FOR the start tag and empty tag this works but not for 
		//declarations or end tags
		int y = 0;
		while (tempString[y] != '>' || tempString[y] != '/' || tempString[y]!= ' ')
		{
			tagName+= tempString[y];	//update tagName //	WONT WORK FOR END TAGS -- </HEAD>
		} 
	}

	//case of end tag
	if(tagType== "END_TAG")
	{
		int y = 1;
		while (tempString[y] != '>' || tempString[y] != '/' || tempString[y]!= ' ')
		{
			tagName+= tempString[y];	//update tagName-- works for end tags
		} 
	}

	//case of declaration
	if(tempString[0]== '?')		//if we  have a declaration
	{
		int y = 1;
		while (tempString[y] != '>' || tempString[y] != '/' || tempString[y]!= ' ' || tempString[y]!= '?')
		{
			tagName+= tempString[y];	//update tagName-- works for declaration
		} 

		//update the type of tag 
		//myStruct.tokenType = DECLARATION;
		tagType = "DECLARATION";
	}

	//to test if we have a start-tag vs empty-tag
	if(tempString[tagName.length()] == '/')
	{
		//if the character after the end of the tag is '/'
		tagType = "EMPTY_TAG	";
		//myStruct.tokenType = EMPTY_TAG;
	}
	else if(tempString[tagName.length()] == '>')
	{
		//if the next char is a >
		tagType = "START_TAG";
		//myStruct.tokenType = START_TAG;
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
	//at this point, the tag should be valid in its own (not counting its repeated tag) 
	//if content is blank, dont add as a token
	//no two angle brackets in a row
	//need to define the type and send the tagName

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
	

	//also need to send the name of the tag
	myStruct.tokenString = tagName;

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

