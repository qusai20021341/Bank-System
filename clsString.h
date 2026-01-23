#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;
public:
	clsString()
	{
		_Value = "";
	}
	clsString(string value)
	{
		_Value = value;
	}
	void SetValue(string value)
	{
		_Value = value;
	}
	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;

	static short CountWords(string str)//static to make it possible to reach it without creating object
	{
		int Count = 0;
		string delim = " ";
		short pos;
		string sWord;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			sWord = str.substr(0, pos);
			if (sWord != "")
			{
				Count++;
			}
			str.erase(0, pos + delim.length());
		}
		if (str != "")
		{
			Count++;
		}

		return Count;

	}
	short CountWords()//public method to be reached from objects only , and it pass the object value to the satatic function(the logic is inside the statci function)
	{
		return CountWords(_Value);
	}
	static void PrintFirstLetterOfEachWord(string Name)
	{
		cout << "First Letters of this string:" << endl;
		cout << Name[0] << endl;
		for (int i = 1; i < Name.length(); i++)
		{
			if (Name[i] == ' ')
			{
				cout << Name[i + 1] << endl;
			}
		}
	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}
	static void UpperCaseFirstLetters(string& message)
	{

		message[0] = toupper(message[0]);

		for (int i = 1; i < message.length(); i++)
		{
			if (message[i] == ' ' && message[i + 1] != ' ')
			{
				message[i + 1] = toupper(message[i + 1]);
			}

		}

	}
	void UpperCaseFirstLetters()
	{
		UpperCaseFirstLetters(_Value);
	}
	static void LowerCaseFirstLetters(string& Name)
	{

		bool FirstLetter = true;
		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && FirstLetter)
			{
				Name[i] = tolower(Name[i]);
			}
			Name[i] == ' ' ? FirstLetter = true : FirstLetter = false;
		}
	}
	void LowerCaseFirstLetters()
	{
		LowerCaseFirstLetters(_Value);
	}
	static void UpperCaseAllLetters(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				str[i] = toupper(str[i]);
			}
		}
	}
	
	void UpperCaseAllLetters()
	{
		UpperCaseAllLetters(_Value);
	}
	static void LowerCaseAllLetters(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				str[i] = tolower(str[i]);
			}
		}
	}
	void LowerCaseAllLetters()
	{
		LowerCaseAllLetters(_Value);
	}
	static char InvertCharCase(char C)
	{
		if (C == toupper(C))
		{
			C = tolower(C);
		}
		else
		{
			C = toupper(C);
		}
		return C;

	}
	static void InvertAllLettersCase(string& str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = InvertCharCase(str[i]);
		}

	}
	void InvertAllLettersCase()
	{
		InvertAllLettersCase(_Value);
	}
	static short CountCapitalLetters(string str)
	{
		int CapitalLettersCount = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] = isalpha(str[i]) && str[i] == toupper(str[i]))
			{
				CapitalLettersCount++;
			}

		}
		return CapitalLettersCount;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}
	static short CountSmallLetters(string str)
	{
		int SmallLettersCount = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] = isalpha(str[i]) && str[i] == tolower(str[i]))
			{
				SmallLettersCount++;
			}

		}
		return SmallLettersCount;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}
	static short LetterCount(string str, char Letter)
	{
		short LetterCount = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == Letter)
			{
				LetterCount++;
			}

		}
		return LetterCount;

	}
	short LetterCount(char Letter)
	{
		return LetterCount(_Value, Letter);
	}
	static short LetterCountMatchCase(string str, char Letter)
	{
		short LetterCount = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == toupper(Letter) || str[i] == tolower(Letter))
			{
				LetterCount++;
			}

		}
		return LetterCount;
	}
	short LetterCountMatchCase(char Letter)
	{
		return LetterCountMatchCase(_Value, Letter);
	}
	static bool IsVowel(char C)
	{
		string vowels = "aeiou";
		for (int i = 0; i < vowels.length(); i++)
		{
			if (tolower(C) == vowels[i])
			{
				return true;
			}
		}
		return false;
	}
	static short CountVowel(string str)
	{
		short VowelCount = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (IsVowel(str[i]))
			{
				VowelCount++;
			}
		}
		return VowelCount;
	}
	short CountVowel()
	{
		return CountVowel(_Value);
	}
	static void PrintAllVowel(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (IsVowel(str[i]))
			{
				cout << str[i] << "  ";
			}
		}
		cout << endl;
	}
	void PrintAllVowel()
	{
		PrintAllVowel(_Value);
	}
	static void PrintEachWord(string str)
	{
		string delim = " ";
		short pos = 0;
		string sWord;
		cout << "your string words are:" << endl;
		while ((pos = str.find(delim)) != string::npos)
		{
			sWord = str.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			str.erase(0, pos + delim.length());
		}
		if (str != "")
		{
			cout << str << endl;
		}

	}
	void PrintEachWord()
	{
		PrintEachWord(_Value);
	}
	static vector<string> Split(string str, string delim)
	{
		vector<string> Words;
		short pos = 0;
		string sWord = "";

		while ((pos = str.find(delim)) != string::npos)
		{
			sWord = str.substr(0, pos);
			if (sWord != "")
			{
				Words.push_back(sWord);
			}
			str.erase(0, pos + delim.length());
		}
		if (str != "")
		{
			Words.push_back(str);
		}
		return Words;
	}
	vector<string> Split(string delim = " ")
	{
		return Split(_Value, delim);
	}
	static void TrimLeft(string& str)
	{
		short Counter = 0;
		if (str[0] == ' ')
		{

			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] != ' ')
					break;
				else
					Counter++;
			}
			str = str.erase(0, Counter);
		}
	}
	void TrimLeft()
	{
		TrimLeft(_Value);
	}
	static void TrimRight(string& str)
	{
		short Counter = 0;
		short LastIndex = str.length() - 1;
		if (str[LastIndex] != ' ')
		{
			str = str;
		}
		else {
			for (int i = LastIndex; i > 0; i--)
			{
				if (str[i] != ' ')
					break;
				else
					str.pop_back();
			}
		}

	}
	void TrimRight()
	{
		TrimRight(_Value);
	}
	static void Trim(string& str)
	{
		TrimLeft(str);
		TrimRight(str);
	}
	void Trim()
	{
		TrimLeft(_Value);
		TrimRight(_Value);
	}
	static string JoinString(vector<string> Words, string sep)
	{
		string JoinedString = "";

		for (string word : Words)
		{
			JoinedString += word;
			if (word != Words.back())
			{
				JoinedString += sep;
			}
		}
		return JoinedString;

	}
	static string JoinString(string Words[], short size, string sep)
	{
		string JoinedString = "";

		for (int i = 0; i < size; i++)
		{
			JoinedString += Words[i];
			if (Words[i] != Words[size - 1])
			{
				JoinedString += sep;
			}
		}
		return JoinedString;
	}
	static void ReverceString(string& str)
	{
		vector<string>StringWords = Split(str, " ");
		str.clear();
		for (int i = StringWords.size() - 1; i >= 0; i--)
		{
			str.append(StringWords[i] + " ");
		}
	}
	void ReverceString()
	{
		ReverceString(_Value);
	}
	static void ReplaceWord(string& str, string ToReplace, string ReplacesWord) {
		short pos = str.find(ToReplace);
		while (pos != string::npos)
		{
			str.replace(pos, ToReplace.length(), ReplacesWord);
			pos = str.find(ToReplace);
		}

	}
	void ReplaceWord(string ToReplace, string ReplacesWord)
	{
		ReplaceWord(_Value, ToReplace, ReplacesWord);
	}
	static void RemovePunctuation(string& str)
	{
		for (int i = 0; i < str.length(); i++) {
			if (ispunct(str[i]))
			{
				str.erase(i, 1);
			}
		}
	}
	void RemovePunctuation()
	{
		RemovePunctuation(_Value);
	}



};

