#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

int main() {
    int model_year{};
    int accidents{};
    double msrp{};
    bool premium_option{};
    double Baseline_ResaleP{};
    double accidentsP{};
    double premium_optionP;
    double dappreciation;
    model_year = car_model_year();
    model_year = 2023 - model_year;
    int booli = { 1 };
    
    
    //Baseline Resale Percentage
    if (model_year >= 0 && model_year <= 4) {
        Baseline_ResaleP = { .85 };
    }
    else{
        if (model_year >= 5 && model_year <= 8) {
            Baseline_ResaleP = { .63 };
        }
        else {
            if (model_year == 9 or model_year == 10) {
                Baseline_ResaleP = { .45 };
            }
            else{
                booli = 0;
            }
        }
    }

    accidents = car_accidents();
    premium_option = car_has_premium_options();
    msrp = car_msrp();
    
    //Number of Accidents
    if (accidents == 0) {
        accidentsP = { 0.0 };
    }
    else {
        if (accidents == 1) {
            accidentsP = { 0.02 };
        }
        else {
            if (accidents == 2) {
                accidentsP = { 0.1 };
            }
            else {
                if (accidents == 3) {
                    accidentsP = { .2 };
                }
                else {
                    booli = 0;
                    
                }
            }
        }
    }

    //Premium Options
    if (premium_option == true) {
        premium_optionP = .05;
    }
    else {
        premium_optionP = 0.0;
    }
    
    //Calculations

    dappreciation = ((Baseline_ResaleP - accidentsP) + premium_optionP)*msrp;
    if (booli == 0) {
        print_ineligible_message();
    }
    else {
        print_eligible_message(dappreciation);
    }
    
    return 0;
}
