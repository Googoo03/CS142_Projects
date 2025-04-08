#include <iostream>
#include <cassert>


template<class T>
class Queue{

    public:
        void push(T val){
            if(!(_n < _m-1)) Resize(_m*2);

            _n++;
            _arr[_n] = val;
            std::cout << "End _n: " << _n << " Pushed: " << val << std::endl;
        }

        T pop(){
            assert(_n > -1);
            T result = _arr[0];
            for(int i = 0; i < _n; ++i){
                _arr[i] = _arr[i+1];
            }
            _n--;
            return result;
        }

        bool Empty(){ return _n == 0;}

        int Get_Length (){ return _n;}

        int Get_Cap (){ return _m;}

        void Resize(int n){
            T* new_arr = new T[n];
            for(int i = 0; i < n; ++i){
                new_arr[i] = i < _m ? _arr[i] : (T)0;
            }
            delete[] _arr;
            _arr = new_arr;
            _m = n;
        }

        Queue(int m){
            _arr = new T[m];
            for(int i = 0; i < m; ++i) _arr[i] = (T)0;
            _m = m;
            _n = -1;
        }
        ~Queue(){ delete[] _arr;}

        //Gotta practice these cause you got rejected from General Atomics
        void operator=(Queue& v){
            int n = v.Get_Cap();

            //Resize and set values
            if(n != _m) Resize(v.Get_Cap());
                
            for(int i = 0; i < n; ++i) _arr[i] = v[i];
        }

        T& operator[] (int b){
            //std::cout << _m << std::endl;
            assert(b < _m && b > -1);
            return _arr[b];
        }

        friend std::ostream& operator<<(std::ostream& os, Queue& obj) {
            int m = obj.Get_Length();
            for(int i = 0; i <= m; ++i){
                os << obj[i] << " ";
            }
            return os;
        }

    private:
        int _m;
        int _n;
        T* _arr;

        

};

template<class T>
int BFS(int start, int end, Queue<T>& taken_sqrs){ return 0;}

int main(int argc, char* argv[]){
    int n;
    std::cin >> n;
    Queue<int> results(1);

    results.push(1);
    results.push(2);
    results.push(3);
    std::cout << results.pop() << std::endl;
    std::cout << results.pop() << std::endl;
    std::cout << results.pop() << std::endl;
    return 0;

    while(n != -1){
        Queue<int> taken_sqrs(n);
        for(int i = 0; i < n; ++i) std::cin >> taken_sqrs[i];

        int start, end;
        std::cin >> start >> end;
        results.push( BFS(start,end,taken_sqrs));

    }

    int i = 1;
    while(!results.Empty()){
        int moves = results.pop();
        std::cout << "Board " << i << ": ";
        if(moves != -1){
            std::cout << moves << "moves";
        }else{
            std::cout << "not reachable";
        }
        std::cout << std::endl;
    }
    //Declare a list structure (array or otherwise) full of taken squares

    //Fill up structure by feeding in lines of squares.

    //Execute BFS using the filled-structure, the start and end point

    //At the end of each test, add to a results queue, which will print results.
    return 0;
}