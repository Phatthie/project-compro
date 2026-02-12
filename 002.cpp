#include<iostream>
using namespace std;

int row=7,col=7;


struct Showtimes{
    bool seat[7][7];
};

struct Movies{
    Showtimes showtime[10];
};

Movies N[10];

void showSeatPlan(int movieIndex,int showtimeIndex){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!N[movieIndex].showtime[showtimeIndex].seat[i][j]) cout << "O ";
            else cout << "X ";
        }
        cout << endl;
    }
}

void resetSeat(int movieIndex,int showtimeIndex){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            N[movieIndex].showtime[showtimeIndex].seat[i][j]=false;
        }
    }
}

void showBookingSum(int movieIndex,int showtimeIndex){
    int available=0,booked=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!N[movieIndex].showtime[showtimeIndex].seat[i][j]) available+=1;
            else booked+=1;
        }
    }
    cout << "Available seat: " << available << "\nBooked seat: " << booked;
}

void Book(int movieIndex,int showtimeIndex,int row,int col){
    if(!N[movieIndex].showtime[showtimeIndex].seat[row][col]) N[movieIndex].showtime[showtimeIndex].seat[row][col] = true;
    else cout << "The seat is not available\n";
}

int main(){
    int mov,showt,row,col;
    cout << "select movie: ";
    cin >> mov;
    cout << "select showtime: ";
    cin >> showt;
    resetSeat(mov,showt);
    showSeatPlan(mov,showt);
    cout << "select seat: ";
    while(cin >> row >> col){
        if(row!=999 || col!=999){
            Book(mov,showt,row,col);
            showSeatPlan(mov,showt);
            showBookingSum(mov,showt);
            cout << "\nselect seat or type 999 to exit: ";
        }else break;
    }
}