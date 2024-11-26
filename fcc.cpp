#include <fstream>
#include <iostream>
#include <vector>
#include "fcc.h" 


bool more_to_read(std::ifstream& file) {
    file >> std::noskipws;
    while (file.peek() == ' ') {
        char discard;
        file >> discard;
    }
    return !(file.eof() || std::iscntrl(file.peek()));
}/*
 * <create_vector>
 *
 * <Converts a string in a text file to a vector>
 *
 * input: <Name of the file>
 * output: <Your text file string in the form of a vector>
 */
std::vector<std::string> create_vector(std::ifstream& file) {
    std::string word;
    std::vector<std::string> vector;
    while (more_to_read(file)) {
        file >> word;
        vector.push_back(word);
    }
        return vector;
}
int fcc(const std::string& fixme_filename, const std::string& typo_filename,
    const std::string& fixo_filename, std::string& fixed_sentence) {

        //Get File Insides
        std::ifstream fixme_file(fixme_filename);
        std::ifstream typo_file(typo_filename);
        std::ifstream fixo_file(fixo_filename);

        //Create Vectors
        std::vector<std::string> fixme_words = create_vector(fixme_file);
        std::vector<std::string> typo_words = create_vector(typo_file);
        std::vector<std::string> fixo_words = create_vector(fixo_file);
        if (typo_words.size() == fixo_words.size()) {
            //Temp Word Variables
            std::string fixme;
            std::string typo;
            std::string fixo;
            int c{ 0 };
            int x{ 0 };
            int counter{ 0 };
            while (!(counter == fixme_words.size())) {
                x = typo_words.size();
                fixme = fixme_words[counter];
                bool isfixed{ false };
                for (int i{ 0 }; i < x; i++) {
                    //Set temp words
                    typo = typo_words[i];
                    fixo = fixo_words[i];
                    if (fixme == typo) {
                        c++;
                        isfixed = true;
                        // Where the extra condition was added VV
                        if (fixed_sentence == "" || fixed_sentence == " ") {
                            fixed_sentence += fixo;
                        }
                        else {
                            fixed_sentence += " " + fixo;
                        }                        
                    }
                }
                //Was the word fixed?
                if (!(isfixed)) {
                    fixed_sentence += " " + fixme;
                }
                counter++;

            }

            
            if (!fixed_sentence.empty() && fixed_sentence.back() != '.') {                
                fixed_sentence.push_back('.');
            }
            else {
                fixed_sentence.erase(fixed_sentence.back());
            }

            return c;
        }
        else {
            return -1;
        }
    }
