#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

std::string LastToken(std::string& str, char delimiter);

int main(int argc, char* argv[]){
    std::string team1;
    int team1_score{};
    std::string team2;
    int team2_score{};
    std::string input;

    std::cin >> team1 >> team2; //set teams

    //std::cout << team1 << " " << team2 << std::endl;

    std::getline(std::cin, input);
    while(LastToken(input,' ') != "Snitch"){
        //std::cout << LastToken(input,' ') << std::endl;
        if(input == team1){
            team1_score += 10;
        }else if(input == team2){
            team2_score += 10;
        }

        std::getline(std::cin, input);
    }

    //Snitch was caught, add points to correct team
    if(input.substr(0,team1.length()) == team1){
        team1_score += 150;
    }else{
        team2_score += 150;
    }


    //Display points
    if(team1_score != team2_score){
        std::cout << ((team1_score > team2_score) ? team1 : team2) << " wins" << std::endl;
    }else{
        std::cout << "Tie" << std::endl;
    }
    std::cout << (team1_score > team2_score ? team1_score : team2_score) << "-" << (team1_score > team2_score ? team2_score : team1_score) << std::endl;

    return 0;
}

std::string LastToken(std::string& str, char delimiter){
    std::string result;
    int start = str.length()-1;
    int size = 1;

    while(str[start] != delimiter && start >= 0){start --; size++;}

    start++; size --;
    result = str.substr(start,size);
    return result;
}

