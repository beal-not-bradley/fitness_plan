#include <iostream>
#include <random>
#include <array>
#include <fstream>

// The purpose of this program is to randomize a set of 2 lunch options, 2 dinner options, and 2 running options for one 5-day week.
// Lunch, dinner, and running workouts should not occur back-to-back ([L1, L2, L1, L2, L1] is fine, [L1, L1, L2, L2, L2] is not)
// 

// The eating and running plan for the week will then be output as a CSV, and emailed to the user

// TODO
// Keep track of the calories for each meal option, and add those to the input so we can keep track of caloric intake

// TODO
// Put on a cron job so I don't have to run this code every week

// Question:
// How would I read in the options from a different file? Header file? JSON?
// class RandomIndex {
//     std::mt19937 eng;
//     std::uniform_int_distribution<> distr;
// public:
//     guessGetRandomIndex(int lower, int upper) 
//         : eng(std::random_device()())
//         , distr(lower, upper)
//     {}

//     int operator()() { 
//          return distr(eng);
//     }
// };

void make_csv()
{
//TODO
// GET CURRENT DATE/NEAREST MONDAY
// CSV TITLE = fitness_plan_week_of_{monday_date}_to_{friday_date}
std::ofstream outfile ("thisweek.csv");
outfile << "Monday,Tuesday,Wednesday,Thursday,Friday,\n";
outfile.close();
}

void get_options(std::array<std::string,3> options_array, std::string menu_array, std::mt19937 eng)
{
	//I think I'm passing a pointer to the array here? 
	//Take 2 random entries from the array
	//Add those to the menu array

	std::uniform_int_distribution<> distr(0, options_array.size() - 1);
	std::cout << options_array[distr(eng)] << std::endl;

}

int main()
{
	make_csv();
	// USE VECTORS HERE INSTEAD OF ARRAY SO WE DON'T NEED TO HAVE SIZE WHEN PASSING TO GET_OPTIONS
	//initialize lunch choices, and empty lunch menu arrays
	std::array<std::string, 3> lunch_options {"Taco Salad", "Soba + Shoyu Chicken", "Salmon, Broccoli, Sweet Potatoes"};
	std::array<std::string, 2> lunch_menu {};

	//initialize dinner choices, and empty dinner menu array
	std::array<std::string, 3> dinner_options {"Oyakodon + Miso Soup", "Kalbi Flank Steak Salad", "Curry Rice"};
	std::array<std::string, 2> dinner_menu {};

	//initialize workout choices and empty workout plan array
	std::array<std::string, 3> workout_options {"1 Mile, Oyster Point", "7 100yd Sprints, park", "Plyometrics/Agility, park"};
	std::array<std::string, 2> workout_plan {};

	//random chunk
	std::random_device rd; // obtain a random number
    std::mt19937 eng(rd()); // seed the generator

    get_options(lunch_options);

    return 0;

}