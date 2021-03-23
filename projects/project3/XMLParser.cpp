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
			//start = i + 1;
			//check validity
			while (inputString[a] != '>')
			{
				tagName += inputString[a]; //adds the chars between < and > to tagName
				//increase a
				a++;
			}
			//now that we gave a potential tag, check to see if it is valid
			//SEE WHAT TYPE OF TAG IT IS
			//MAKE SURE IT DOES NOT CONTAIN ILLEGAL CHARACTERS
			//check for tag type

			//End tag
			if(tagName[0] == '/')
			{
				tagType = "END_TAG";
			}

			//Empty tag
			if(tagName[tagName.length()-1] == '/' )	//last character 
			{
				tagType = "EMPTY_TAG";
				//copy the string until the last elements
				string temp;
				for(int j  = 0; j < tagName.length()-1; j++)
				{
					temp[j] = tagName[j];
				}
				//remake tagName
				tagName = temp;
			}

			//Declaration
			if(tagName[0]== '?' && tagName[tagName.length()-1] == '?')
			//first element and last element are ?
			{
				tagType = "DECLARATION";
				//copy the tag name minus the ?
				string temp;
				for(int j = 1; j < tagName.length()-1; j++ )
				{
					temp[j-1] = tagName[j]; // copies the shortend string to temp
				}
				tagName = temp;
			}
		}
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

