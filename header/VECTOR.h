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