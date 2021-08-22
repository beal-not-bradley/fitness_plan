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
// How would I read in the options from a different file instead of hardcoding here? Header file? JSON?

//Question: Should I instantiate the random stuff with a class?
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

void make_csv(std::string lunch_row, std::string dinner_row, std::string workout_row)
{
	//TODO
	// GET CURRENT DATE/NEAREST MONDAY
	// CSV TITLE = fitness_plan_week_of_{monday_date}_to_{friday_date}
	std::ofstream outfile ("thisweek.csv");
	outfile << ",Monday,Tuesday,Wednesday,Thursday,Friday,\n";
	outfile << lunch_row;
	outfile << "\n";
	outfile << dinner_row;
	outfile << "\n";
	outfile << workout_row;
	outfile.close();
}

void get_options(std::vector<std::string> &options_vector, std::string menu_array[], int menu_size, std::mt19937 eng)
{	
	//I think I'm passing a pointer to the array here? 
	//Take 2 random entries from the vector
	//Add those to the menu array
	int chosen[menu_size];
	int count = 0;
	std::uniform_int_distribution<> distr(0, options_vector.size() - 1);
	for(int i = 0; i <= menu_size; i++)
	{	
		//get random number
		int myrando = distr(eng);
		//make sure it's different than the other random number we grab
		if (chosen[myrando] == 0)
		{
			chosen[myrando] = 1;
			//pull optino from options vector, add to menu array
			menu_array[count] = options_vector[myrando];
			count++;
		}	
	}
}

std::string make_rows(std::vector<std::string> &options_vector, std::string menu_array[], std::string row_name)
{
	//make rows
    std::string row_string = row_name.append(",");
    int option_num = 0;
    for (int i=0;i<5;i++){
    	if (i == 0){
    		row_string.append(menu_array[option_num]);
    		row_string.append(",");
    		option_num++;
    	}
    	else{
    		row_string.append(menu_array[option_num]);
    		row_string.append(",");
    		if (option_num == 1){
    			option_num--;
    		}
    		else{
    			option_num++;
    		}

    	}
    	if (i == 4){
    		row_string.append("\n");
    	}
    }
    return row_string;
}


int main()
{
	//instantiate length of options that I want
	const int menu_size = 2;

	// USE VECTORS HERE INSTEAD OF ARRAY SO WE DON'T NEED TO HAVE SIZE WHEN PASSING TO GET_OPTIONS
	//initialize lunch choices, and empty lunch menu arrays
	std::vector<std::string> lunch_options {"Taco Salad", "Soba + Shoyu Chicken", "Salmon + Broccoli + Sweet Potatoes"};
	//wtf is this shit
	//std::array<std::string, 2> lunch_menu {};
	std::string lunch_menu [menu_size];

	//initialize dinner choices, and empty dinner menu array
	std::vector<std::string> dinner_options {"Oyakodon + Miso Soup", "Kalbi Flank Steak Salad", "Curry Rice"};
	std::string dinner_menu [menu_size];

	//initialize workout choices and empty workout plan array
	std::vector<std::string> workout_options {"1 Mile: Oyster Point", "7 100yd Sprints: park", "Plyometrics/Agility: park"};
	std::string workout_plan [menu_size];

	//random chunk
	std::random_device rd; // obtain a random number
    std::mt19937 eng(rd()); // seed the generator

    //get lunch menu
    //get_options(lunch_options, lunch_menu, menu_size, eng);

    //get dinner menu
    //get_options(dinner_options, dinner_menu, menu_size, eng);

    //get workout plan
    get_options(workout_options, workout_plan, menu_size, eng);

    //make rows in string format "ROWNAME, OPTION, OPTION,...,\n"
    //std::string lunch_row = make_rows(lunch_options, lunch_menu, "LUNCH");
    //std::string dinner_row = make_rows(dinner_options, dinner_menu, "DINNER");
    std::string workout_row = make_rows(workout_options, workout_plan, "WORKOUTS");
    std::cout<<workout_row;

    //make_csv(lunch_row, dinner_row, workout_row);

    return 0;

}