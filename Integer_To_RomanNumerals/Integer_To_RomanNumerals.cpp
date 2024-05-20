// Integer_To_RomanNumerals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class romanType 
{
public:
    // Constructors
    romanType() : romanNumeral(""), number(0) {}


    // Setters
    void setRomanNumber(const string& romNum);
    void setNumber(int num);

    // Getters
    string getRomanNumber() const { return romanNumeral; }
    int getNumber() const { return number; }

    // Member functions
    void romanNum_To_Integer();
    void integer_To_romanNum();

private:
    string romanNumeral;
    int number;

    map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
};

int main() 
{
    romanType roman;
    string romNum;
    int num;

    cout << "Enter a Roman numeral: ";
    cin >> romNum;
    roman.setRomanNumber(romNum);
    roman.romanNum_To_Integer();
    cout << romNum << " as an integer is " << roman.getNumber() << endl;

    cout << "Enter a positive integer: ";
    cin >> num;
    roman.setNumber(num);
    roman.integer_To_romanNum();
    cout << num << " in Roman numeral is: " << roman.getRomanNumber() << endl;

    return 0;
}

void romanType::setRomanNumber(const string& romNum) {
    romanNumeral = romNum;
}

void romanType::setNumber(int num) 
{
    number = num;
}

void romanType::romanNum_To_Integer() 
{
    int result = 0;
    for (size_t i = 0; i < romanNumeral.length(); i++) 
    {
        if (i + 1 < romanNumeral.length() && romanMap[romanNumeral[i]] < romanMap[romanNumeral[i + 1]]) 
        {
            result += romanMap[romanNumeral[i + 1]] - romanMap[romanNumeral[i]];
            i++; // Skip next character
        }
        else 
        {
            result += romanMap[romanNumeral[i]];
        }
    }
    number = result;
}

void romanType::integer_To_romanNum() 
{
    int numCopy = number;
    romanNumeral = "";

    map<int, string> numberMap = 
    {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (const auto& pair : numberMap) 
    {
        while (numCopy >= pair.first) 
        {
            romanNumeral += pair.second;
            numCopy -= pair.first;
        }
    }
}
