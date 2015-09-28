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
        }/*
        for(unsigned short count_i = 0; count_i < 9; count_i++){ 
            
            std::cout << count[count_i] << " ";
        }
        std::cout << "\n";*/
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Check for duplicates
            
            if(count[count_i]>1) return false;
        }
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Reset count
            count[count_i] = 0;
        }
    }
    //std::cout << "\n";
    for(unsigned short row = 0; row < 9; row++){  //Check all rows
        for(unsigned short column = 0; column < 9; column++){
            count[board[row][column]-1]++; 
        }/*
        for(unsigned short count_i = 0; count_i < 9; count_i++){ 
            
            std::cout << count[count_i] << " ";
        }
        std::cout << "\n";*/
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Check for duplicates
            if(count[count_i]>1) return false;
        }
        for(unsigned short count_i = 0; count_i < 9; count_i++){ //Reset count
            count[count_i] = 0;
        }
    }
    //std::cout << "\n";
    for(unsigned short rlower = 0, rupper = 2; rupper <= 8; rlower+=3, rupper+=3){
        for(unsigned short clower = 0, cupper = 2; cupper <= 8; clower+=3, cupper+=3){
            
            for(unsigned short row = rlower; row <= rupper; row++){ //Check 3x3 box
                for(unsigned short column = clower; column <= cupper; column++){
                    count[board[row][column]-1]++;
                }
            }/*
            for(unsigned short count_i = 0; count_i < 9; count_i++){ 
            
                std::cout << count[count_i] << " ";
            }
            std::cout << "\n";*/
            for(unsigned short count_i = 0; count_i < 9; count_i++){ //Check for duplicates
                if(count[count_i]>1) return false;
            }
            for(unsigned short count_i = 0; count_i < 9; count_i++){ //Reset count
                count[count_i] = 0;
            }
            
        }
    }
    //std::cout << "\n";
    return true;
}

void solve(bool occupied[9][9], unsigned short board[9][9], int i, int j, int value = 1){
    //int l; std::cin.ignore(); std::cin >> l;
    static bool solved = false;
    
    if(occupied[i][j]) {
        j++;
        if(j==9){i++; j=0;}
        if (i==9 && j==0) return;
        solve(occupied, board, i, j);
    } else{
        board[i][j] = value;
        //std::cout << "\n";
        //print(board);
        //std::cout << "\n" << isGood(board) << "\n";
        if(isGood(board)){
            int a ,b;
            b = j+1;
            a = i;
            if(b==9){a++; b=0;}
            if (a==9 && b==0){ solved = true; return;}
            solve(occupied, board, a, b);
            if(solved) return;
            if(value == 9){board[i][j] = 0; return;}
            solve(occupied, board, i, j, value + 1);
        } else {
            if(value == 9){board[i][j] = 0; return;}
            solve(occupied, board, i, j, value + 1);
        }
    }    
}

int main(){
    unsigned short board[9][9] = 
    {
        {0,0,0,0,2,0,3,0,1},
        {9,0,2,0,0,1,8,0,0},
        {0,5,6,7,0,3,2,0,0},
        {0,0,9,0,0,0,0,1,2},
        {7,0,0,0,0,0,0,0,6},
        {6,8,0,0,0,0,5,0,0},
        {0,0,5,3,0,2,6,7,0},
        {0,0,7,5,0,0,9,0,4},
        {3,0,8,0,6,0,0,0,0}
    };
    
    bool occupied[9][9] = 
    {
        {0,0,0,0,2,0,3,0,1},
        {9,0,2,0,0,1,8,0,0},
        {0,5,6,7,0,3,2,0,0},
        {0,0,9,0,0,0,0,1,2},
        {7,0,0,0,0,0,0,0,6},
        {6,8,0,0,0,0,5,0,0},
        {0,0,5,3,0,2,6,7,0},
        {0,0,7,5,0,0,9,0,4},
        {3,0,8,0,6,0,0,0,0}
    };
    print(board);
    solve(occupied, board, 0, 0);
    print(board);
    return 0;
}