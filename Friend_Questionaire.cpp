#include <iostream>
#include <cassert>
#include <string>

template<class T>
class VECTOR{
    private:
        int m;
        T* arr;

    public:

        int Get_Length (){ return m;}

        void Resize(int n){
            T* new_arr = new T[n];
            for(int i = 0; i < n; ++i){
                new_arr[i] = i < m ? arr[i] : (T)0;
            }
            delete[] arr;
            arr = new_arr;
        }

        VECTOR(int n){
            arr = new T[n];
            for(int i = 0; i < n; ++i) arr[i] = (T)0;
            m = n;
        }
        ~VECTOR(){ delete[] arr;}

        //Gotta practice these cause you got rejected from General Atomics
        void operator=(VECTOR& v){
            int n = v.Get_Length();

            //Resize and set values
            if(n != m) Resize(v.Get_Length());
                
            for(int i = 0; i < n; ++i) arr[i] = v[i];
        }

        T& operator[] (int b){
            assert(b < m && b > -1);
            return arr[b];
        }

        friend std::ostream& operator<<(std::ostream& os, VECTOR& obj) {
            int m = obj.Get_Length();
            for(int i = 0; i < m; ++i){
                os << obj[i] << " ";
            }
            return os;
        }

};


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

            std::cout << "Current iteration : " << j << " " << i << std::endl;
            std::cout << "---------------------" << std::endl;
            std::cout << prev_row << std::endl;
            std::cout << current_row << std::endl;
        }

        prev_row = current_row;
    }

    /*// For 0-th row
    for (int j = 0; j <= n; j++)
        prev[j] = j;

    // Rest of the rows 
    for (int i = 1; i <= m; i++)
    {
        curr[0] = i;  // j = 0
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else            
                curr[j] = 1 + min({curr[j - 1], prev[j], prev[j - 1]});
        }
        prev = curr;
    }
    return prev[n];*/

    return prev_row[n];
}

int main (int argc, char* argv[]) {

    std::string str1 = argv[1];
    std::string str2 = argv[2];
    std::cout << edit_distance(str1,str2) << std::endl;

    std::cout << "String 1 size: " << str1.size() << std::endl;
    std::cout << "String 2 size: " << str2.size() << std::endl;
    return 0;
}