#include<iostream>

void print(unsigned short board[9][9]){
    for(unsigned short i=0; i<9; i++){
        for(unsigned short j=0; j<9; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool isGood(unsigned short board[9][9]){
    unsigned short count[9] = {0,0,0,0,0,0,0,0,0};
    
    for(unsigned short column = 0; column < 9; column++){  //Check all columns
        for(unsigned short row = 0; row < 9; row++){
            count[board[row][column]-1]++; 
        }
        for(unsigned short count_i = 0; count_i < 9; count_i++){ 
            
            std::cout << count[count_i] << " ";
        }
        std::cout << "\n";
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Check for duplicates
            
            if(count[count_i]>1) return false;
        }
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Reset count
            count[count_i] = 0;
        }
    }
    std::cout << "\n";
    for(unsigned short row = 0; row < 9; row++){  //Check all rows
        for(unsigned short column = 0; column < 9; column++){
            count[board[row][column]-1]++; 
        }
        for(unsigned short count_i = 0; count_i < 9; count_i++){ 
            
            std::cout << count[count_i] << " ";
        }
        std::cout << "\n";
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Check for duplicates
            if(count[count_i]>1) return false;
        }
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Reset count
            count[count_i] = 0;
        }
    }
    std::cout << "\n";
    for(unsigned short rlower = 0, rupper = 2; rupper <= 8; rlower+=3, rupper+=3){
        for(unsigned short clower = 0, cupper = 2; cupper <= 8; clower+=3, cupper+=3){
            
            for(unsigned short row = rlower; row <= rupper; row++){ //Check 3x3 box
                for(unsigned short column = clower; column <= cupper; column++){
                    count[board[row][column]-1]++;
                }
            }
            for(unsigned short count_i = 0; count_i < 9; count_i++){ 
            
                std::cout << count[count_i] << " ";
            }
            std::cout << "\n";
            for(unsigned short count_i = 0; count_i < 9; count_i++){ //Check for duplicates
                if(count[count_i]>1) return false;
            }
            for(unsigned short count_i = 0; count_i < 9; count_i++){ //Reset count
                count[count_i] = 0;
            }
            
        }
    }
    std::cout << "\n";
    return true;
}

int main(){
    unsigned short board[9][9] = 
    {
        {0,0,0,0,2,0,3,0,1},
        {9,0,2,0,0,1,8,0,0},
        {0,5,6,7,0,3,2,0,0},
        {7,0,9,0,0,0,0,1,2},
        {7,0,0,0,0,0,0,0,6},
        {6,8,0,0,0,0,5,0,0},
        {0,0,5,3,0,2,6,7,0},
        {0,0,7,5,0,0,9,0,4},
        {3,0,8,0,6,0,0,0,0}
    };
    
    std::cout << "Expects 0: " << isGood(board) << "\n";
    board[3][0] = 0;
    std::cout << "Expects 1: " << isGood(board) << "\n";
    board[3][0] = 1;
    std::cout << "Expects 0: " << isGood(board) << "\n";
    board[3][0] = 8;
    std::cout << "Expects 0: " << isGood(board) << "\n";
    board[3][0] = 4;
    std::cout << "Expects 1: " << isGood(board) << "\n";
    //print(board);
    return 0;
}