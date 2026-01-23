#pragma once
#include<iostream>
#include "clsDate.h"
using namespace std;
class clsUtil
{
public:
	static int ReadPositiveNumber(string Message)
	{
		int number;
		do
		{
			cout << Message << endl;
			cin >> number;
		} while (number < 0);
		return number;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChars = 5 };
	static int RandomNumber(int From, int To)
	{

		return rand() % (To - From + 1) + From;

	}
	static char RandomChar(enCharType Type)
	{
		if (Type == enCharType::CapitalLetter)
		{
			return char(rand() % (90 - 65 + 1) + 65);
		}
		else if (Type == enCharType::SamallLetter) {
			return  char(rand() % (122 - 97 + 1) + 97);
		}
		else if (Type == enCharType::SpecialCharacter)
		{
			string special = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
			return special[rand() % special.length()];
		}
		else if (Type == enCharType::Digit)
		{
			return char(RandomNumber(0, 9) + '0');
		}
		else if (Type == enCharType::MixChars)
		{
			string allChars =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"
				"0123456789"
				"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

			return allChars[rand() % allChars.length()];
		}

	}
	static string GenerateRandomWord(short Length, enCharType CharType)
	{
		string Word;


		for (int i = 1; i <= Length; i++)
		{
			Word = Word + RandomChar(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharType Type)
	{
		string Key = "";

		Key = GenerateRandomWord(4, Type) + "-";
		Key = Key + GenerateRandomWord(4, Type) + "-";
		Key = Key + GenerateRandomWord(4, Type) + "-";
		Key = Key + GenerateRandomWord(4, Type);

		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharType Type)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(Type) << endl;
		}
	}
	static void Swap(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(float& num1, float& num2)
	{
		float temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(string& str1, string& str2)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}
	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate tempDate = Date1;
		Date1 = Date2;
		Date2 = tempDate;
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			int index1 = RandomNumber(1, arrLength) - 1;
			int index2 = RandomNumber(1, arrLength) - 1;
			Swap(arr[index1], arr[index2]);
		}
	}
	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			int index1 = RandomNumber(1, arrLength) - 1;
			int index2 = RandomNumber(1, arrLength) - 1;
			Swap(arr[index1], arr[index2]);
		}
	}
	static void FillArrayWithRandomNumbers(int array[100], int length, int From, int To)
	{
		for (int i = 0; i < length; i++)
		{
			array[i] = RandomNumber(From, To);
		}

	}
	static void FillArrayWithRandomKeys(string array[100], int length, enCharType Type)
	{
		for (int i = 0; i < length; i++)
		{
			array[i] = GenerateKey(Type);
		}
	}
	static void FillArrayWithRandomWords(string array[100], int length, int numberOfCharacters, enCharType Type)
	{
		for (int i = 0; i < length; i++)
		{
			array[i] = GenerateRandomWord(numberOfCharacters, Type);
		}
	}
	static string Tabs(int NumberOfTabs)
	{
		string tabs;
		for (int i = 0; i < NumberOfTabs; i++)
		{
			tabs += "		";
		}
		return tabs;
	}
	static string Encryption(string Text, int encryptionKey=2)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char(int(Text[i]) + encryptionKey);
		}
		return Text;
	}
	static string Decryption(string Text, int encryptionKey=2)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char(int(Text[i]) - encryptionKey);
		}
		return Text;
	}
	static string NumberToText(long long Number) {
		if (Number == 0) return "";
		string Ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
			  "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

		string Tens[] = { "", "", "Twenty-", "Thirty-", "Forty-", "Fifty-", "Sixty-", "Seventy-", "Eighty-", "Ninety-" };

		if (Number < 20)
			return Ones[Number] + string(" ");
		if (Number < 100)
			return Tens[Number / 10] + NumberToText(Number % 10);
		if (Number < 1000)
			return Ones[Number / 100] + string(" Hundred ") + NumberToText(Number % 100);
		if (Number < 10000)
			return Ones[Number / 1000] + string(" Thousand ") + NumberToText(Number % 1000);
		if (Number < 1000000)
			return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
		if (Number < 1000000000)
			return NumberToText(Number / 1000000) + " Milion " + NumberToText(Number % 1000000);
		if (Number < 1000000000000)
			return NumberToText(Number / 1000000000) + " Bilion " + NumberToText(Number % 1000000000);
		return "";
	}



};

