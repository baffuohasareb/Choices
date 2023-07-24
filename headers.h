#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Profile{
    private:
        string name, gamedata; 
        int assigned_line;
    public: 
        void set_name(string name){
            this -> name = name; 
        }

        string get_name(){
            return this -> name;
        }
        
        void set_line(int line_number){
            assigned_line = line_number; 
        }

        int get_line(){
            return assigned_line; 
        }

       void set_gameData(string gamedata){
            this -> gamedata = gamedata; 
       }

       string get_gameData(){
         return this -> gamedata; 
       }
};


class Manager{
    private: 
        int profile_count;
    public: 
     
    

     // validates user input
     int check_input(string message, string error_message, int start, int end){
        int option; 
        bool data_is_valid;
        do{
            cout << message; 
            cin >> option; 
            if(cin.fail()){
                cin.clear();
                fflush(stdin);
            }
            data_is_valid = (option >= start && option <= end); // checks if option is with the bounds
            if(!data_is_valid){
            cout << error_message; 
        }
        }while(!data_is_valid);

        return option; 
     }
            

     // adds data to a file
     void append_to_file(string filename, string data){
        fstream file;
        file.open(filename, ios::app);
        if(file.is_open()){
            file << data;
        }
        file.close();
     }
     
     // show the profiles in the game, also counts profiles
     void show_profiles(string filename, bool assign_numbers){
        fstream file; 
        int line_number = 1;
        file.open(filename, ios::in);
        if(file.is_open()){
            string line; 
            while(getline(file, line)){
                if(assign_numbers){
                    cout << "\t\t\t\t" << line_number << " - " << line << "\n";
                    line_number++; 
                }
                else{
                    cout << line << "\n";
                }
            }
        }

        profile_count = line_number - 1;
        file.close();
     }
     
     void readlines(string filename, int start, int end){
        fstream file; 
        file.open(filename, ios::in);
        int line_number = 1; 
        if(file.is_open()){
            string line; 
            system("cls");
            while(getline(file, line)){
                if(line_number >= start && line_number <= end){
                  type(line, 15); 
                }
                if(line_number > end)break; 
                line_number++; 
            }
        }
        file.close(); 
     }
     // gets data from a particular line of a file
     string readline(string filename, int line_number){
         fstream file;
         int i = 1; 
         string line; 
         file.open(filename, ios::in);
         if(file.is_open()){
            while(getline(file, line)){
                if(line_number == i){
                    break;
                }
                else{
                    i++;
                }
            }
         }
         file.close(); 
         return line;
     }  


     // returns number of profiles
     int getCount(){
        return profile_count;
     }

     void remove(string filename, int assigned_line){
      fstream file; 
      vector<string> gamedatas; 
      file.open(filename, ios::in);
      if(file.is_open()){
        string line;
        while(getline(file, line)){
            gamedatas.push_back(line);
        }
      } 
      file.close();
      file.open(filename, ios::out);
      file << ""; 
      gamedatas.at(assigned_line - 1) = "\0"; // strings can be set equal to each other
      file.close();
      file.open(filename, ios::app);
      for(string element:gamedatas){
        if(element.length() == 0)continue;
        file << element.append("\n");
      }
     }

     void set_gameData(string filename, int assigned_line,  string data){
      fstream file; 
      vector<string> gamedatas;
      file.open(filename, ios::in);
      if(file.is_open()){
        string line;
        while(getline(file, line)){
            gamedatas.push_back(line);
        }
      } 
      file.close(); 
      file.open(filename, ios::out);
      file << ""; 
      file.close();
      file.open(filename, ios::app); 
      gamedatas.at(assigned_line - 1) = data;
      for(string element: gamedatas){
        file << element.append("\n"); 
      }
      file.close();
     }

    void type(string message, int wait_time){
        for(int i=0; i < message.length(); i++){
            cout << message.at(i); 
            Sleep(wait_time);
        }
        cout << "\n"; 
    }
}; 

class Styles{
    public:
        string landing_page = "\t .----------------.   .----------------.   .----------------.   .----------------.   .----------------.   .----------------.   .----------------. \n"
                        "\t| .--------------. | | .--------------. | | .--------------. | | .--------------. | | .--------------. | | .--------------. | | .--------------. |\n"
                        "\t| |     ______   | | | |  ____  ____  | | | |     ____     | | | |     _____    | | | |     ______   | | | |  _________   | | | |    _______   | |\n"
                        "\t| |   .' ___  |  | | | | |_   ||   _| | | | |   .'    `.   | | | |    |_   _|   | | | |   .' ___  |  | | | | |_   ___  |  | | | |   /  ___  |  | |\n"
                        "\t| |  / .'   \\_|  | | | |   | |__| |   | | | |  /  .--.  \\  | | | |      | |     | | | |  / .'   \\_|  | | | |   | |_  \\_|  | | | |  |  (__ \\_|  | |\n"
                        "\t| |  | |         | | | |   |  __  |   | | | |  | |    | |  | | | |      | |     | | | |  | |         | | | |   |  _|  _   | | | |   '.___`-.   | |\n"
                        "\t| |  \\ `.___.'\\  | | | |  _| |  | |_  | | | |  \\  `--'  /  | | | |     _| |_    | | | |  \\ `.___.'\\  | | | |  _| |___/ |  | | | |  |`\\____) |  | |\n"
                        "\t| |   `._____.'  | | | | |____||____| | | | |   `.____.'   | | | |    |_____|   | | | |   `._____.'  | | | | |_________|  | | | |  |_______.'  | |\n"
                        "\t| |              | | | |              | | | |              | | | |              | | | |              | | | |              | | | |              | |\n"
                        "\t| '--------------' | | '--------------' | | '--------------' | | '--------------' | | '--------------' | | '--------------' | | '--------------' |\n"
                        "\t '----------------'   '----------------'   '----------------'   '----------------'   '----------------'   '----------------'   '----------------' \n\n\n\n"
                        "\t\t\t\t\t\t                                     /\\              \n"
                        "\t\t\t\t\t\t                                    /  \\             \n"
                        "\t\t\t\t\t\t                                   / /\\ \\           \n"
                        "\t\t\t\t\t\t       ______                     / /__\\ \\          \n"
                        "\t\t\t\t\t\t      /      \\              _____/________\\_____     \n"
                        "\t\t\t\t\t\t     (   ()   )            /                    \\    \n"
                        "\t\t\t\t\t\t      \\_    _/            /                      \\   \n"
                        "\t\t\t\t\t\t        |  |             /________________________\\  \n"
                        "\t\t\t\t\t\t        |  |                |                  |      \n"
                        "\t\t\t\t\t\t        |  |                | ||     ||     || |      \n"
                        "\t\t\t\t\t\t        |  |                | ||     ||     || |      \n"
                        "\t\t\t\t\t\t        |  |____            | ||     ||     || |      \n"
                        "\t\t\t\t\t\t        |    ___|           | ||     __     || |      \n"
                        "\t\t\t\t\t\t        |   |___            | ||    |  |    || |      \n"
                        "\t\t\t\t\t\t        |_______|           | ||    |  |    || |      \n"
                        "\t\t\t\t\t\t                            | ||    |  |    || |      \n"
                        "\t\t\t\t\t\t                            |_______|__|_______|      \n\n\n"
                        "\t\t\t\t\t\t\t                    LOADING                         \n\t\t\t\t\t\t\t\t      ";

    string loading = "********************\n";


    string  main_menu = "\t\t\t\t\t___  ___  ___  _____ _   _   ___  ___ _____ _   _ _   _ \n"
                        "\t\t\t\t\t|  \\/  | / _ \\|_   _| \\ | |  |  \\/  ||  ___| \\ | | | | |\n"
                        "\t\t\t\t\t| .  . |/ /_\\ \\ | | |  \\| |  | .  . || |__ |  \\| | | | |\n"
                        "\t\t\t\t\t| |\\/| ||  _  | | | | . ` |  | |\\/| ||  __|| . ` | | | |\n"
                        "\t\t\t\t\t| |  | || | | |_| |_| |\\  |  | |  | || |___| |\\  | |_| |\n"
                        "\t\t\t\t\t\\_|  |_/\\_| |_/\\___/\\_| \\_/  \\_|  |_/\\____/\\_| \\_/\\___/ \n\n";

    string home_header = "\t\t\t\t\t _______________________________________________________\n"
                        "\t\t\t\t\t|                                                       |\n"
                        "\t\t\t\t\t|       Choose an option                                |\n"
                        "\t\t\t\t\t|                                                       |\n"
                        "\t\t\t\t\t|                                                       |\n"
                        "\t\t\t\t\t|       1 - New Game: start a whole new game            |\n"
                        "\t\t\t\t\t|                                                       |\n"
                        "\t\t\t\t\t|       2 - Load Game: continue your adventure          |\n"
                        "\t\t\t\t\t|_______________________________________________________|\n\n"
                        "\t\t\t\t\t>> ";


    string error_msg = "\n\n"
                    "\t\t\t\t\t\t  ................................\n"
                    "\t\t\t\t\t\t  .   ERROR!!!                   .\n"
                    "\t\t\t\t\t\t  .                              .\n"
                    "\t\t\t\t\t\t  .   No such option available   .\n"
                    "\t\t\t\t\t\t  ................................\n";


    string new_profile = "\t\t\t\t\t _____                _           _   _                   _   _               \n"
                        "\t\t\t\t\t/  __ \\              | |         | \\ | |                 | | | |              \n"
                        "\t\t\t\t\t| /  \\/_ __ ___  __ _| |_ ___    |  \\| | _____      __   | | | |___  ___ _ __ \n"
                        "\t\t\t\t\t| |   | '__/ _ \\/ _` | __/ _ \\   | . ` |/ _ \\ \\ /\\ / /   | | | / __|/ _ \\ '__|\n"
                        "\t\t\t\t\t| \\__/\\ | |  __/ (_| | ||  __/   | |\\  |  __/\\ V  V /    | |_| \\__ \\  __/ |   \n"
                        "\t\t\t\t\t \\____/_|  \\___|\\__,_|\\__\\___|   \\_| \\_/\\___| \\_/\\_/      \\___/|___/\\___|_|   \n";


    string load_game = "\t\t\t\t\t _     _____  ___ ______     _____   ___  ___  ___ _____ \n"
                    "\t\t\t\t\t| |   |  _  |/ _ \\|  _  \\   |  __ \\ / _ \\ |  \\/  ||  ___|\n"
                    "\t\t\t\t\t| |   | | | / /_\\ \\ | | |   | |  \\// /_\\ \\| .  . || |__  \n"
                    "\t\t\t\t\t| |   | | | |  _  | | | |   | | __ |  _  || |\\/| ||  __| \n"
                    "\t\t\t\t\t| |___\\ \\_/ / | | | |/ /    | |_\\ \\| | | || |  | || |___ \n"
                    "\t\t\t\t\t\\_____/\\___/\\_| |_/___/      \\____/\\_| |_/\\_|  |_/\\____/ \n\n";

    string choose_profile = "\t\t\t\t\t\t=====================================\n"
                            "\t\t\t\t\t\t            CHOOSE A PROFILE         \n"
                            "\t\t\t\t\t\t=====================================\n\n";

    string no_profiles = "\t\t\t\t\t\t\tNo profiles created yet. \n"
                        "\t\t\t\t\t\t\tStart a new game instead.\n\n";

    string selected_profile = "\n\n"
                            "\t\t\t\t\tSELECTED PROFILE:\n"
                            "\t\t\t\t\t=================\n";

    string welcome = "\t\t\t\t\t _    _ _____ _     _____ ________  ___ _____   ______  ___  _____  _   __   _ \n"
                    "\t\t\t\t\t| |  | |  ___| |   /  __ \\  _  |  \\/  ||  ___|  | ___ \\/ _ \\/  __ \\| | / /  | |\n"
                    "\t\t\t\t\t| |  | | |__ | |   | /  \\/ | | | .  . || |__    | |_/ / /_\\ \\ /  \\/| |/ /   | |\n"
                    "\t\t\t\t\t| |/\\| |  __|| |   | |   | | | | |\\/| ||  __|   | ___ \\  _  | |    |    \\   | |\n"
                    "\t\t\t\t\t\\  /\\  / |___| |___| \\__/\\ \\_/ / |  | || |___   | |_/ / | | | \\__/\\| |\\  \\  |_|\n"
                    "\t\t\t\t\t \\/  \\/\\____/\\_____/\\____/\\___/\\_|  |_/\\____/   \\____/\\_| |_/\\____/\\_| \\_/  (_)\n";

    string actions = "\n\t\t\t\t\tWhat would you like to do\?\n"
                    "\t\t\t\t\t __________________________________________ \n"
                    "\t\t\t\t\t|                                          |\n"
                    "\t\t\t\t\t|         1 - Continue to game             |\n"
                    "\t\t\t\t\t|         2 - Delete profile               |\n"
                    "\t\t\t\t\t|__________________________________________|\n"
                    "\t\t\t\t\t>> ";

    string the_end = "\t\t\t\t _________    ____  ____    ________          ________    ____  _____    ______    \n"
                    "\t\t\t\t|  _   _  |  |_   ||   _|  |_   __  |        |_   __  |  |_   \\|_   _|  |_   _ `.  \n"
                    "\t\t\t\t|_/ | | \\_|    | |__| |      | |_ \\_|          | |_ \\_|    |   \\ | |      | | `. \\ \n"
                    "\t\t\t\t    | |        |  __  |      |  _| _           |  _| _     | |\\ \\| |      | |  | | \n"
                    "\t\t\t\t   _| |_      _| |  | |_    _| |__/ |         _| |__/ |   _| |_\\   |_    _| |_.' / \n"
                    "\t\t\t\t  |_____|    |____||____|  |________|        |________|  |_____|\\____|  |______.'  \n\n";
};

#endif 