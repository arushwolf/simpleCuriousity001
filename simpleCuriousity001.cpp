#include <iostream>
#include <sstream>

using namespace std;

void wordRemover(string& mainString, string& subString);
string numberIsolater(string s);
int wordCounter(string s);
int numberCounter(string s);

int main()
{

	string userInput = "xoxo: 1, 2. 3' 4;";
	//getline(cin, userInput);
	int numbers = numberCounter(userInput);
	string* array = new string[numbers]; //this is a dynamic array created to store the integers...
	for (int i = 0; i < numbers; i++)
	{
		array[i] = numberIsolater(userInput);
		wordRemover(userInput, array[i]);
	}

	for (int i = 0; i < numbers; i++)
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
			return word;
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
	int w = 0;

	for (int i = 0; i < s.length(); i++)
		if (isspace(s[i]))
			w++; //count the number of spaces

	w++; //add one more to have an accurate count (assuming there is no extra spaces
	return w;
}

int numberCounter(string s)
{
	int n = 0;

	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]))
			n++;

	return n;
}