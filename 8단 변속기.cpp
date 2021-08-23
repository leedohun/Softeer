#include<iostream>

using namespace std;

int main(int argc, char** argv) {
        bool asc = true, des = true;

        for(int i = 1, j = 8; i <= 8; i++, j--){
                int DCT; cin >> DCT;

                if(DCT != i){
                        asc = false;
                }
                if(DCT != j){
                        des = false;
                }
        }

        if(asc){
                cout << "ascending";
        }
        else if(des){
                cout << "descending";
        }
        else{
                cout << "mixed";
        }

        return 0;
}
