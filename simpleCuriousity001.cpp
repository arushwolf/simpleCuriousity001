#include <iostream>
#include <sstream>

using namespace std;

void wordRemover(string& mainString, string& subString);
string numberIsolater(string s);
int wordCounter(string s);

int main()
{

	string userInput;
	getline(cin, userInput);
	int words = wordCounter(userInput);
	string* array = new string[words]; //this is a dynamic array created to store the integers...
	for (int i = 0; i < words; i++)
	{
		array[i] = "NULL";
		array[i] = numberIsolater(userInput);
	}

	for (int i = 0; i < words; i++)
	{
		if (array[i] != "NULL")
			cout << array[i] << endl;
	}

}

/*Ok, so I will first define the "numberIsolater" function,
as it is much more complicated than the "wordRemover" function*/

string numberIsolater(string s)
{
	stringstream stringS;

	stringS << s; //this should take the string and put it into the stream

	string word; //to store each individual word of the string
	int x; //to store an integer once found

	//this loop will run until the end of the string
	while (!stringS.eof())
	{
		stringS >> word; //as stated before, taking each word and storing it

		if (stringstream(word) >> x)
		{
			wordRemover(s, word);
			return word;
		}
	}
}

void wordRemover(string& mainString, string& subString)
{
	size_t pos = mainString.find(subString); //search for substring

	if (pos != string::npos)
		mainString.erase(pos, subString.length());//erase the substring once found
}

int wordCounter(string s)
{
	int words = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (isspace(s[i]))
			words++; //count the number of spaces
	}

	words++; //add one more to have an accurate count (assuming there is no extra spaces
	return words;
}