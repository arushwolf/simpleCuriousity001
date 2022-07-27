#include <iostream>
#include <sstream>

using namespace std;

//void wordRemover(string mainString, string subString);
void numberIsolater(string s);

int main()
{

	string userInput;
	getline(cin, userInput);
	cout << userInput << endl;
	numberIsolater(userInput);

}

/*Ok, so I will first define the "numberIsolater" function,
as it is much more complicated than the "wordRemover" function*/

void numberIsolater(string s)
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
			cout << x << " ";

		word = "";
	}
}