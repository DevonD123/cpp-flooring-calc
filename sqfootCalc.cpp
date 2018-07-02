#include <iostream>
using namespace std;

class Room{
    private:
        int width;
        int height;
    public:
        Room();
        ~Room();

       void setRoomW(int w);
       void setRoomH(int h);

       int calcSqFoot();
};

Room::Room(){
    width = 10;
    height = 10; 
}
Room::~Room(){

}
void Room::setRoomH(int h){
    height = h;
}
void Room::setRoomW(int w){
    width = w;
}
int Room::calcSqFoot(){
    return height * width;
}

int main(){
    int pieceL, pieceW, numbPer;
    int sqftPerPack = 0;
    int numbRooms;
    int roomW;
    int roomL;
    int tSqft = 0;
    cout << "############# CALCULATE THE AMOUNT OF FLOORING NEEDED ################\n";
    cout << "disclaimer only works for square rooms \n";
    //below is to get infor for per package sqft
    cout << "enter hardwood floor strip length :";
    cin >> pieceL;
    cout << "enter hardwood floor strip width (not thickness) :";
    cin >> pieceW;
    cout << "Number of strips per package :";
    cin >> numbPer;
    sqftPerPack = (pieceL*pieceW)*numbPer;
    //get number of rooms for for loop
    cout << "enter # of room's you are looking to floor :";
    cin >> numbRooms;
    //call class and add to sqt sum
    for(int i = 0; i < numbRooms; i++){
        Room r;
        cout << "input room #"<< i+1 << " width :";
        cin >> roomW;
        // cout << "roomnumb:" << numbRooms << endl;
        r.setRoomW(roomW);
        cout << "input room #"<< i+1 << " length :";
        cin >> roomL;
        r.setRoomH(roomL);
        tSqft += r.calcSqFoot();
    }
    //divide Tsqft by package
    cout << "########### SQFT NEEDED ###################### \n";
    cout << "the square footage you are looking to floor is:" <<tSqft <<" sq feet" << endl;
    cout << "########### packages needed (1 extra for odd angles) ###################### \n";
    cout << "the total number of flooring you need to purchase is:"<< (tSqft/sqftPerPack)+1 << endl;
    return 0;
}