#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class Number
{
public:
    std::string toWord(const std::string number)
    {
        number.length() / 3;
        return "";
    }

    std::string toWordsHundreds(std::string number)
    {
        std::string word("");

        //pad it with 0's
        while(number.length() < 3)
            number = "0" + number;

        //parse hundreds place
        parseHundreds(number, word);

        //parse tens place
        parseTens(number, word);

        //parse ones place
        parseOnes(number, word);

        return word;
    }

    std::string toWordsHundreds(int num)
    {
        if(num > 999)
            return "you are a faggit!";
        char buff[4];
        itoa(num, buff, 10);
        std::string number(buff);
        std::string word("");

        //pad it with 0's
        while(number.length() < 3)
            number = "0" + number;

        //parse hundreds place
        parseHundreds(number, word);

        //parse tens place
        parseTens(number, word);

        //parse ones place
        parseOnes(number, word);

        return word;
    }

private:
    bool tensPlaceIsOne = false;
    const char* const ten = "ten";
    const char* const hundred = "hundred";
    const char* const _and = "and";
    const char* const y = "y";
    const char* const ty = "ty";

    const char* const one = "one";
    const char* const two = "two";
    const char* const three = "three";
    const char* const four = "four";
    const char* const five = "five";
    const char* const six = "six";
    const char* const seven = "seven";
    const char* const eight = "eight";
    const char* const nine = "nine";

    const char* const eleven = "eleven";
    const char* const twelve = "twelve";
    const char* const thirteen = "thirteen";
    const char* const fourteen = "fourteen";
    const char* const fifteen = "fifteen";
    const char* const sixteen = "sixteen";
    const char* const seventeen = "seventeen";
    const char* const eighteen = "eighteen";
    const char* const nineteen = "nineteen";

    const char* const twenty = "twenty";
    const char* const thirty = "thirty";
    const char* const forty = "forty";
    const char* const fifty = "fifty";

    void parseHundreds(const std::string& number, std::string& word)
    {
        switch(number[0])
        {
        case '0': //do nothing
            break;
        case '1': 
            word = word + " " + one + " " + hundred + " " + _and;
            break;
        case '2':
            word = word + " " + two + " " + hundred + " " + _and;
            break;
        case '3':
            word = word + " " + three + " " + hundred + " " + _and;
            break;
        case '4':
            word = word + " " + four + " " + hundred + " " + _and;
            break;
        case '5':
            word = word + " " + five + " " + hundred + " " + _and;
            break;
        case '6':
            word = word + " " + six + " " + hundred + " " + _and;
            break;
        case '7':
            word = word + " " + seven + " " + hundred + " " + _and;
            break;
        case '8':
            word = word + " " + eight + " " + hundred + " " + _and;
            break;
        case '9':
            word = word + " " + nine + " " + hundred + " " + _and;
            break;
        default:
            std::cout << "tf did you just do to make this happen?";
        }
    }

    void parseTens(const std::string& number, std::string& word)
    {
        switch(number[1])
        {
        case '0': //do nothing
            break;
        case '1': parseTeens(number, word);
            break;
        case '2': word = word + " " + twenty;
            break;
        case '3': word = word + " " + thirty;
            break;
        case '4': word = word + " " + forty;
            break;
        case '5': word = word + " " + fifty;
            break;
        case '6': word = word + " " + six + ty;
            break;
        case '7': word = word + " " + seven +ty;
            break;
        case '8': word = word + " " + eight + y;
            break;
        case '9': word = word + " " + nine + ty;
            break;
        default:
            std::cout << "how tf";
        }
    }

    void parseTeens(const std::string& number, std::string& word)
    {
        tensPlaceIsOne = true;
        switch(number[2])
        {
        case '0': word = word + " " + ten;
            break;
        case '1': word = word + " " + eleven;
            break;
        case '2': word = word + " " + twelve;
            break;
        case '3': word = word + " " + thirteen;
            break;
        case '4': word = word + " " + fourteen;
            break;
        case '5': word = word + " " + fifteen;
            break;
        case '6': word = word + " " + sixteen;
            break;
        case '7': word = word + " " + seventeen;
            break;
        case '8': word = word + " " + eighteen;
            break;
        case '9': word = word + " " + nineteen;
            break;
        default:
            std::cout << "how tf";
        }
    }

    void parseOnes(const std::string& number, std::string& word)
    {
        if(tensPlaceIsOne)
        {
            tensPlaceIsOne = false;
            return;
        }

        switch(number[2])
        {
        case '0': //do nothing
            break;
        case '1': word = word + " " + one;
            break;
        case '2': word = word + " " + two;
            break;
        case '3': word = word + " " + three;
            break;
        case '4': word = word + " " + four;
            break;
        case '5': word = word + " " + five;
            break;
        case '6': word = word + " " + six;
            break;
        case '7': word = word + " " + seven;
            break;
        case '8': word = word + " " + eight;
            break;
        case '9': word = word + " " + nine;
            break;
        default:
            std::cout << "how tf";
        }
    }
};

int main()
{
    Number num;
    std::ofstream output;
    output.open("output.txt");

    for(int i = 1;i <= 999;i++)
        output << num.toWordsHundreds(i) << std::endl;

    return 0;
}