#include "headers.h"


int main(){
    int option;
    Profile profile;
    Manager manager;
    Styles style;

    cout << style.landing_page;
    manager.type(style.loading, 200);
    system("cls");

    start:
    cout << style.main_menu;
    option = manager.check_input(style.home_header, style.error_msg, 1, 2);
    system("cls");
    if(option == 1){
        string name; 
        cout << style.new_profile << "\n\t\t\t\t\tEnter profile name >> ";
        getline(cin >> ws, name);
        system("cls");
        cout << "\n\t\t\t\t\tmessage: profile '" << name << "' created successfully\n\n";
        manager.append_to_file("profiles.txt", name.append("\n"));
        manager.append_to_file("gamedata.txt", "00\n");
        goto start; 
    }
    else{
        cout << style.load_game << style.choose_profile; 
        manager.show_profiles("profiles.txt", true);
        if(manager.getCount() == 0){
            cout << style.no_profiles;
            goto start;
        }
        option = manager.check_input(
            "\n\n\t\t\t\t\t>> ", 
            "\n\t\t\t\t\tmessage: no such profile available\n",
            1, manager.getCount()
            );

        profile.set_name(manager.readline("profiles.txt", option));
        profile.set_line(option);
    }

    system("cls");

    cout << style.welcome << style.selected_profile << "\t\t\t\t\t" << profile.get_name() << endl; 
    option = manager.check_input(style.actions ,"\n\t\t\t\t\tmessage: invalid action\n", 1, 2);

    if(option == 2){
        manager.remove("profiles.txt", profile.get_line());
        manager.remove("gamedata.txt", profile.get_line());
        cout << "\t\t\t\t\tprofile '" << profile.get_name() << "' deleted successfully\n";
    }
    else{
        string checkpoint, file = "story.txt", temporary_gamedata; 
        bool get_saved_data = true; 
        int quit = 0; 
        do{

        if(get_saved_data){
                temporary_gamedata = manager.readline("gamedata.txt", profile.get_line());
                profile.set_gameData(temporary_gamedata);
                get_saved_data = false;
        }
        
        // contains 16 different outcomes
        if(profile.get_gameData() == "00"){ manager.readlines(file, 3, 7); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "1";}
        else if(profile.get_gameData() == "11"){ manager.readlines(file, 11, 15); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "2";}
        else if(profile.get_gameData() == "12"){ manager.readlines(file, 20, 25); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "7";}
        else if(profile.get_gameData() == "21"){ manager.readlines(file, 31, 39); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "3";}
        else if(profile.get_gameData() == "22"){ manager.readlines(file, 43, 44); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "31"){ manager.readlines(file, 49, 58); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "4";}
        else if(profile.get_gameData() == "32"){ manager.readlines(file, 62, 63); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "41"){ manager.readlines(file, 70, 71); checkpoint = "-1"; } // end
        else if(profile.get_gameData() == "42"){ manager.readlines(file, 74, 81); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "5";}
        else if(profile.get_gameData() == "51"){ manager.readlines(file, 87, 94); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "6";}
        else if(profile.get_gameData() == "52"){ manager.readlines(file, 97, 99); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "61"){ manager.readlines(file, 106, 110); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "62"){ manager.readlines(file, 114, 117); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "71"){ manager.readlines(file, 124, 133); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "8";}
        else if(profile.get_gameData() == "72"){ manager.readlines(file, 136, 146); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "13";}
        else if(profile.get_gameData() == "81"){ manager.readlines(file, 152, 157); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "9";}
        else if(profile.get_gameData() == "82"){ manager.readlines(file, 160, 164); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "12";}
        else if(profile.get_gameData() == "91"){ manager.readlines(file, 168, 173); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "10";} 
        else if(profile.get_gameData() == "92"){ manager.readlines(file, 176, 179); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "101"){ manager.readlines(file, 184, 189); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "11";} 
        else if(profile.get_gameData() == "102"){ manager.readlines(file, 192, 195); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "111"){ manager.readlines(file, 200, 207);checkpoint = "-1";} // end
        else if(profile.get_gameData() == "112"){ manager.readlines(file, 211, 215);checkpoint = "-1";} // end
        else if(profile.get_gameData() == "121"){ manager.readlines(file, 220, 224);checkpoint = "-1";} // end
        else if(profile.get_gameData() == "122"){ manager.readlines(file, 228, 230);checkpoint = "-1";} // end
        else if(profile.get_gameData() == "131"){ manager.readlines(file, 235, 242); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "14";} 
        else if(profile.get_gameData() == "132"){ manager.readlines(file, 245, 247); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "141"){ manager.readlines(file, 252, 259); option = manager.check_input("3-quit\n\n>> ", "", 1, 3); checkpoint = "15";} 
        else if(profile.get_gameData() == "142"){ manager.readlines(file, 262, 265); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "151"){ manager.readlines(file, 270, 272); checkpoint = "-1";} // end
        else if(profile.get_gameData() == "152"){ manager.readlines(file, 276, 278); checkpoint = "-1";} // end
        else{
            quit = 1;
            cout << style.the_end;
        }

        
        if(option == 3){
            quit = 1; 
            int second_option = manager.check_input("\nDo you want to save game ?\n1-Yes\n2-No\n\n>> ", "", 1, 2);
            if(second_option == 1){
                manager.set_gameData("gamedata.txt", profile.get_line(), temporary_gamedata);
                cout << "\nmessage: game saved successfully\n"; 
            }
        }
        else{
            temporary_gamedata = checkpoint.append(to_string(option));
            profile.set_gameData(temporary_gamedata);
        }

        }while(quit == 0);
    }
    return 0;
}

