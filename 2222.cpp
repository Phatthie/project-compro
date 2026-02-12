#include<iostream>
using namespace std;

int row=7,col=7;
int a[10][10][7][7];

void initSeat(int movieIndex,int showtimeIndex){
    for(int k=0;k<row;k++){
        for(int r=0;r<col;r++){
            a[movieIndex][showtimeIndex][k][r] = 0;
        }
    }
}

void showSeatPlan(int movieIndex,int showtimeIndex){
    for(int k=0;k<row;k++){
        for(int r=0;r<col;r++){
            if(a[movieIndex][showtimeIndex][k][r]==0) cout << "O ";
            else cout << "X ";
        }
        cout << endl;
    }
}

void resetSeat(int movieIndex,int showtimeIndex){
    for(int k=0;k<row;k++){
        for(int r=0;r<col;r++){
            a[movieIndex][showtimeIndex][k][r] = 0;
        }
    }
}

void showBookingSum(int movieIndex,int showtimeIndex){
    int available=0,booked=0;
    for(int k=0;k<row;k++){
        for(int r=0;r<col;r++){
            if(a[movieIndex][showtimeIndex][k][r]==0) available += 1;
            else booked += 1;
         }
    }
    cout << "available seat: " << available << "\nBooked seat: " << booked;
}

int main(){
    initSeat(0,0);
    showSeatPlan(0,0);
    showBookingSum(0,0);
    resetSeat(0,0);
}