#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{ 26 };

int number_from_letter(char letter) {
    int offset = letter - (int)'a';
    if (offset < 0 || offset >= ALPHABET_LENGTH) {
        std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
        assert(false);
    }
    return offset;
}

char letter_from_number(int number) {

    if (number < 0 || number >= ALPHABET_LENGTH) {
        std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
        assert(false);
    }

    const char alphabet[] = { 'a',
     'b',
     'c',
     'd',
     'e',
     'f',
     'g',
     'h',
     'i',
     'j',
     'k',
     'l',
     'm',
     'n',
     'o',
     'p',
     'q',
     'r',
     's',
     't',
     'u',
     'v',
     'w',
     'x',
     'y',
     'z' };
    return alphabet[number];
}
int main() {
    std::fstream input_file{};
    input_file.open("input.txt");

    //Variables
    char direction{};
    int increm{};
    char character{'a'};

    //Set Variables from input file
    if (input_file >> direction) {
        
        if (input_file >> increm) {
            //Directional if statement
            if (direction == 'l' || direction == 'r') {
                //l = left
                if (direction == 'l') {
                    while (!std::iscntrl(input_file.peek()) && !input_file.eof()) {

                        input_file >> character;
                        int intchar{};
                        intchar = number_from_letter(character);
                        intchar -= increm;

                        intchar %= 26;
                        if (intchar < 0) {
                            intchar += 26;
                            character = letter_from_number(intchar);
                            std::cout << character;
                        }
                        else {
                            character = letter_from_number(intchar);
                            std::cout << character;
                        }

                    }
                    std::cout << "\n";
                    return 0;
                }



                //r = right
                if (direction == 'r') {
                    while (!std::iscntrl(input_file.peek()) && !input_file.eof()) {

                        input_file >> character;
                        int intchar{};
                        intchar = number_from_letter(character);
                        intchar += increm;
                        intchar %= 26;
                        character = letter_from_number(intchar);
                        std::cout << character;

                    }
                    

                }

            }
            else {
                std::cout << "Oops: Invalid direction in the input file.\n";
            }
        }
        else {
            std::cout << "Oops: Could not read the shift number from the input file.\n";
        }
    }
    else {
        std::cout << "Oops: Could not read the direction from the input file.\n";
    }
    input_file.close();
    
    return 0;
}