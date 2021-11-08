#include <iostream>
#include <string>
using namespace std;
struct Aeroflot{
    char destination[100];
    char race_number[100];
    char plane_type[100];
};

static void search(int &counter, char *dest, bool &is_available, Aeroflot *race) {
    for( int k=0;k<7;k++){
        for(int i=0;i<strlen(dest);i++){
            if(race[k].destination[i]!=dest[i]){
                counter=1;
            }
        }
        if(counter==0){
            cout<<"The race is available:"<<endl<<
                "Destination: "<<race[k].destination<<endl<<
                "Race number: "<<race[k].race_number<<endl<<
                "Plane type: "<<race[k].plane_type<<endl;
            is_available=1;
        }
        counter=0;
    }
    if(is_available==0) cout<<"No races available!";
}

int main(){
    char dest[100];
    int counter=0;
    bool is_available=0;
    Aeroflot* race = new Aeroflot[7];
    for (int i = 0; i < 7; i++){
        cout << "Race " << i+1 <<endl;
        cout << "Destination:";
        cin>>race[i].destination;

        cout << "Race number:";
        cin>>race[i].race_number;

        cout<< "Plane type:";
        cin>>race[i].plane_type;
    }
    cout<<endl<<"Enter the destination you need:";
    cin>>dest;
    cout<<endl;
    search(counter, dest, is_available, race);

    return 0;
}
