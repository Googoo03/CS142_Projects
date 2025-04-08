#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <algorithm>

inline int _dis(int a, int b){ return a > b ? a-b : b-a;}

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


int main(int argc, char* argv[]){
    int current{},prev{},prev_alt{},altitude{};

    int n;

    std::cin >> n; //take in the number of stairs, guaranteed n >= 5

    //do a majority system for initial step
    int step1{-1}, step2{-1}, count1{},count2{};

    VECTOR<int> vec(n);
    for(int i = 0; i < n; ++i){
        std::cin >> vec[i];
    }

    int inc_count=  0;
    int standard_altitude = 0;
    std::vector<int> all_found{};
    for(int i = 1; i < n; ++i){
        //Set variables
        prev = vec[i-1];
        current = vec[i];
        altitude = _dis(prev,current);

        if(!std::count(all_found.begin(),all_found.end(),altitude)){
            all_found.push_back(altitude);
            continue;
        }

        standard_altitude = altitude;
        break;

    }

    //std::cout << "Standard altitude: " << standard_altitude << std::endl;

    for(int i = 1; i < n; ++i){
        //Set variables
        prev = vec[i-1];
        current = vec[i];
        altitude = _dis(prev,current);

        if(altitude == standard_altitude) continue;

        //Found stair
        if(i==1 && _dis(vec[i],vec[i+1]) == standard_altitude ){
            std::cout << 1 << std::endl;
        }else{
            std::cout << i+1 << std::endl;
        }
        
        break;

    }
    
    return 0;

}