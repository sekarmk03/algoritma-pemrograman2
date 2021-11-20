#include "header.h"

int Cek(int arr[3][2]){
    if(arr[0][0] == arr[1][0] == arr[2][0]){
        // horizontal
    } else if(arr[0][1] == arr[1][1] == arr[2][1]){
        // vertikal
    } else if((arr[1][0] == arr[0][0] + 1) && (arr[2][0] == arr[1][0] + 1)){
        
    }
}