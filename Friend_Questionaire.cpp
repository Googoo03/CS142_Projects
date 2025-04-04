#include <iostream>
#include <cassert>
#include <string>
#include <VECTOR.h>


typedef VECTOR<int> IVEC;




int edit_distance(std::string& str1, std::string& str2){
    int m = str1.size(), n = str2.size();
    IVEC current_row(n+1);
    IVEC prev_row(n+1);

    for(int i = 0; i <= n; ++i) prev_row[i] = i;
    
    for(int i = 1; i <= m; ++i){
        
        current_row[0] = i;

        for(int j = 1; j <= n; ++j){

            if(str1[i-1] == str2[j-1]){
                current_row[j] = prev_row[j-1];
            }else{
                current_row[j] = std::min(current_row[j-1], std::min(prev_row[j-1],prev_row[j]) ) + 1;
            }

            /*
            std::cout << "Current iteration : " << j << " " << i << std::endl;
            std::cout << "---------------------" << std::endl;
            std::cout << prev_row << std::endl;
            std::cout << current_row << std::endl;
            */
        }

        prev_row = current_row;
    }
    return prev_row[n];
}

int main (int argc, char* argv[]) {
    /*
    std::string str1 = argv[1];
    std::string str2 = argv[2];
    std::cout << edit_distance(str1,str2) << std::endl;

    std::cout << "String 1 size: " << str1.size() << std::endl;
    std::cout << "String 2 size: " << str2.size() << std::endl;
    */
    std::string str1;
    std::string str2;
    int n;

    std::cin >> n;
    std::cin >> str1;
    std::cin >> str2;
    
    std::cout << edit_distance(str1,str2) << std::endl;
    return 0;
}