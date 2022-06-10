#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

void login();
void reg();
void choose();
void main_choose();
void main_menu();
void flights();
void my_flights();
void admin_login();
void adminPanel();
void Add_Airline();
void Delete_Airline();
string take_pass();
string username;
vector<string>flight_details[4];
bool flag = true;

int main()
{

    cout << '\n' << '\n';

    cout << "\t\t\t *******************************************\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t** \t\t   HOMEPAGE\t\t   **\n";
    cout << "\t\t\t**\t\t ===========\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**   1.  LOGIN\t\t\t\t   **\n";
    cout << "\t\t\t**   2.  REGISTER   \t\t\t   **\n";
    cout << "\t\t\t**   3.  ADMIN \t\t\t\t   **\n";
    cout << "\t\t\t**   4.  EXIT \t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t *******************************************\n\n";

    if(flag)
    {
        int idx;
        string Flights;

        ifstream in;
        in.open("FLIGHTS.txt");

        if(in.is_open()){
            while(in.eof()==0){

                in >> Flights;
                if(Flights=="BD")idx = 0;
                else if(Flights=="DB") idx = 1;
                else if(Flights=="UK") idx = 2;
                else if(Flights=="US") idx = 3;
                while(true){
                    in >> Flights;
                    if(Flights=="#")break;
                    flight_details[idx].push_back(Flights);
                }
            }
            in.close();
        }
        else{
            ofstream out;
            out.open("FLIGHTS.txt");

            out << "BD" << '\n';
            out << "#" << '\n';
            out << "DB" << '\n';
            out << "#" << '\n';
            out << "UK" << '\n';
            out << "#" << '\n';
            out << "US" << '\n';
            out << "#" << '\n';
            out.close();
        }

        flag = false;
    }

    choose();

    getch();
}

void choose()
{

again_choose:
    cout << "\t\t\t\t Please enter your choice :: ";

    char choice;
    cin >> choice;

    switch(choice)
    {

    case '1':
        system("cls");
        login();
        break;
    case '2':
        system("cls");
        cin.ignore();
        reg();
        break;
    case '3':
        system("cls");
        admin_login();
    case '4':
        cout << "\n\t\t\t\t       ### THANK YOU ###\n\n";
        getch();

    default:
        cout << "\n\t\t\t\t Invalid input!!\n\n";
        goto again_choose;
    }

}

void main_choose()
{
again_choose:
    cout << "\t\t\t\t Please enter your choice :: ";

    char choice;
    cin >> choice;

    switch(choice)
    {

    case '1':
        system("cls");
        flights();
        break;
    case '2':
        system("cls");
        my_flights();
        break;
    case '3':
        system("cls");
        main();
        break;

    default:
        cout << "\n\t\t\t\t Invalid input!!\n\n";
        goto again_choose;
    }

}

void login()
{
again_choose:
    string password;

    cout << '\n' << '\n';

    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t * \t\t  LOGIN   \t       *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n";
    cout << "\n";
    cout << "\t\t\t   1. ENTER YOUR USERNAME :\n";
    cout << "\t\t\t      ";
    cin >> username;
    password = take_pass();

    ifstream in;
    in.open("security.txt");

    if(in.is_open())
    {

        string userID, pass;
        bool check = false;
        int cnt = 0;

        while(in.eof()==0)
        {
            in >> userID >> pass;
            if( (userID == username) && (pass == password))
            {
                check = true;
                break;
            }
        }

        in.close();

        if(check)
        {
            system("cls");
            cout << "\n\n\t\t\t\t  ** Login Successful!! **\n";
            main_menu();
        }
        else
        {
            system("cls");
            cout << "\n\n\t\t\t     ** Wrong Username or Password!! **\n";
            goto again_choose;
        }
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t     ** Wrong Username or Password!! **\n";
        goto again_choose;
    }


}

void admin_login(){

    admin_choose:
    string password;

    cout << '\n' << '\n';

    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t\tADMIN LOGIN   \t       *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n";
    cout << "\n";

    password = take_pass();

        if(password=="1234")
        {
            system("cls");
            cout << "\n\n\t\t\t\t  ** Login Successful!! **\n";
            adminPanel();
        }
        else
        {
            system("cls");
            cout << "\n\n\t\t\t           ** Wrong Password!! **\n";
            goto admin_choose;
        }

}

void reg()
{

    string name, userID, password, address, Number, Gender, CC_NO, ig;

    cout << '\n' << '\n';

    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t       REGISTRATION            *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t   1. ENTER YOUR NAME :  \n";
    cout << "\t\t\t      ";
    getline(cin, name);
    cout << "\t\t\t   2. ENTER YOUR ADDRESS : \n";
    cout << "\t\t\t      ";
    getline(cin, address);
    cout << "\t\t\t   3. ENTER YOUR CONTACT NUMBER :   \n";
    cout << "\t\t\t      ";
    getline(cin, Number);
    cout << "\t\t\t   4. ENTER YOUR GENDER :   \n";
    cout << "\t\t\t      ";
    getline(cin, Gender);
    cout << "\t\t\t   4. ENTER YOUR CREDIT CARD NO. :   \n";
    cout << "\t\t\t      ";
    getline(cin, CC_NO);
again:
    cout << "\t\t\t   5. ENTER YOUR USERNAME :   \n";
    cout << "\t\t\t      ";
    cin >> userID;
    cout << "\t\t\t   6. ENTER YOUR PASSWORD :  \n";
    cout << "\t\t\t      ";
    cin >> password;

    bool  checker = false;

    ifstream in;
    in.open("security.txt");

    if(in.is_open())
    {
        string id_check, pass_check;
        while(in.eof()==0)
        {
            in >> id_check >> pass_check;
            if(userID == id_check)
            {
                checker = true;
                break;
            }
        }
        in.close();
    }

    if(checker)
    {
        cout << "\n\n\t\t\t         ** This username has already been used!! **\n\n";
        goto again;

    }

    ofstream out;
    out.open("info.txt", ios::out | ios::app);

    out << "@Username-" + userID << '\n';
    out << name << '\n';
    out << address << '\n';
    out << Number << '\n';
    out << Gender << '\n';
    out << "###" << '\n';

    out.close();

    ofstream put;
    put.open("security.txt", ios::out | ios::app);
    put << userID << ' ' << password << '\n';

    put.close();

    char x;

    cout << "\n\n\t\t\t  ** Registration Successful!! **";
    cout << "\n\t\t\t  Go to Home page?";
    cout << "\n\t\t\t  Press 1 to proceed, others for exit";
    cout << "\n\t\t\t  :: ";
    cin >> x;

    if(x=='1')
    {
        system("cls");
        main();
    }
    else
    {
        cout << "\n\t\t\t\t      ### THANK YOU ### ";
    }

}

string take_pass()
{

    cout << "\t\t\t   2. ENTER YOUR PASSWORD :   \t\t\t   \n";
    cout << "\t\t\t      ";

    string TakenPass;

    while(true)
    {
        char ch;
        ch = getch();
        if(ch<32)
        {
            return TakenPass;
        }
        cout << "*";
        TakenPass.push_back(ch);
    }

}

void adminPanel(){

    cout << '\n' << '\n';

    cout << "\t\t\t *******************************************\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t** \t\t  Admin Panel\t\t   **\n";
    cout << "\t\t\t**\t\t ============\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t *******************************************" << '\n';
    cout << "\t\t\t    ## Flight Details: \n";
    cout << "\t\t\t       ->> Bangladesh Airlines\t   \n";
            if(flight_details[0].size()==0){
                cout << "\t\t\t          No flights for this airline!      \n";
            }
            else{
                for(int i = 0; i<flight_details[0].size(); i++){
                    cout << "\t\t\t         " << i+1 << ". " << flight_details[0][i] << "  \t   \n";
                }
            }
    cout << "\n\t\t\t       ->> Dubai Airlines  \t\t   \n";
            if(flight_details[1].size()==0){
                cout << "\t\t\t          No flights for this airline!   \t   \n";
            }
            else{
                for(int i = 0; i<flight_details[1].size(); i++){
                    cout << "\t\t\t     " << i+1 << ". " << flight_details[1][i] << "\n";
                }
            }
    cout << "\n\t\t\t       ->> UK Airlines  \t\t   \n";
            if(flight_details[2].size()==0){
                cout << "\t\t\t          No flights for this airline!   \n";
            }
            else{
                for(int i = 0; i<flight_details[2].size(); i++){
                    cout << "\t\t\t        " << i+1 << ". " << flight_details[2][i] << " \n";
                }
            }
    cout << "\n\t\t\t       ->> US Airlines   \n";
            if(flight_details[3].size()==0){
                cout << "\t\t\t          No flights for this airline!  \n";
            }
            else{
                for(int i = 0; i<flight_details[3].size(); i++){
                    cout << "\t\t\t          " << i+1 << ". " << flight_details[3][i] << "\n";
                }
            }

    cout << '\n';

    cout << "\t\t\t**\t     (i) Add Flights              **\n";
    cout << "\t\t\t**\t    (ii) Delete Flights           **\n";
    cout << "\t\t\t**\t   (iii) Homepage                 **\n";

    select_again:
    cout << "\t\t\t**\t   Enter 1 or 2 or 3 of your coice :: ";

        int select;
        cin >> select;
        if(select==1){
            Add_Airline();
        }
        else if(select==2){
            Delete_Airline();
        }
        else if(select==3){
            system("cls");
            main();
        }
        else{
            goto select_again;
        }
    cout << "\t\t\t *******************************************\n\n";


}

void Add_Airline(){
add_again:
    cout << "\n\n\t\t\t Select Airline: " << '\n';
    cout << "\t\t\t 1. Bangladesh Airlines " << '\n';
    cout << "\t\t\t 2. Dubai Airlines " << '\n';
    cout << "\t\t\t 3. UK Airlines " << '\n';
    cout << "\t\t\t 4. US Airlines " << '\n';
    cout << "\t\t\t Enter number :: " ;

    int select;
    cin >> select;
    if(select<1 || select >4)goto add_again;

    string flight_file, flight_name, flight_date, flight_duration, flight_time, flight_cost;
    flight_name_again:
    cout <<  "\n\t\t\t Enter New flight Name: ";
    cin >> flight_name;
    bool check = false;
    string checkstr;

    ifstream in;
    in.open("BDflightRecords.txt");

    while(in.eof()==0){
        in >> checkstr;
        if(checkstr==flight_name){
            check=true;
            break;
        }
    }
    in.close();
    if(check){
        cout << "\n\t\t\t Name has already been used! try another name.\n";
        goto flight_name_again;
    }

    in.open("DBflightRecords.txt");

    while(in.eof()==0){
        in >> checkstr;
        if(checkstr==flight_name){
            check=true;
            break;
        }
    }
    in.close();
    if(check){
        cout << "\n\t\t\t Name has already been used! try another name.\n";
        goto flight_name_again;
    }

    in.open("UKflightRecords.txt");

    while(in.eof()==0){
        in >> checkstr;
        if(checkstr==flight_name){
            check=true;
            break;
        }
    }
    in.close();
    if(check){
        cout << "\n\t\t\t Name has already been used! try another name.\n";
        goto flight_name_again;
    }

    in.open("USflightRecords.txt");

    while(in.eof()==0){
        in >> checkstr;
        if(checkstr==flight_name){
            check=true;
            break;
        }
    }
    in.close();
    if(check){
        cout << "\n\t\t\t Name has already been used! try another name.\n";
        goto flight_name_again;
    }

    file_again:
    cout <<  "\t\t\t Enter New flight file Name: ";
    cin >> flight_file;

    check = false;

    in.open("FLIGHTS.txt");

    while(in.eof()==0){
        in >> checkstr;
        if(checkstr==flight_file){
            check = true;
            break;
        }
    }

    if(check){
        cout << "\n\t\t\t File name has already been used! try another name.\n";
        goto file_again;
    }

    cout <<  "\t\t\t Enter New flight date: ";
    cin >> flight_date;
    cout <<  "\t\t\t Enter New flight Duration: ";
    cin >> flight_duration;
    cout <<  "\t\t\t Enter New flight Time: ";
    cin >> flight_time;
    cout <<  "\t\t\t Enter New flight cost: ";
    cin >> flight_cost;

    switch(select){

case 1:
    {
        ofstream outt;
        outt.open("BDflightRecords.txt", ios::out | ios::app);

        outt << flight_file << '\n';
        outt << flight_name << '\n';
        outt << flight_date << '\n';
        outt << flight_duration << '\n';
        outt << flight_time << '\n';
        outt << flight_cost << '\n';


        outt.close();
        break;
    }

case 2:
    {
        ofstream outta;
        outta.open("DBflightRecords.txt", ios::out | ios::app);

        outta << flight_file << '\n';
        outta << flight_name << '\n';
        outta << flight_date << '\n';
        outta << flight_duration << '\n';
        outta << flight_time << '\n';
        outta << flight_cost << '\n';

        outta.close();
        break;
    }

case 3:
    {
        ofstream outtaa;
        outtaa.open("UKflightRecords.txt", ios::out | ios::app);

        outtaa << flight_file << '\n';
        outtaa << flight_name << '\n';
        outtaa << flight_date << '\n';
        outtaa << flight_duration << '\n';
        outtaa << flight_time << '\n';
        outtaa << flight_cost << '\n';


        outtaa.close();
        break;
    }

case 4:
    {
        ofstream outttt;
        outttt.open("USflightRecords.txt", ios::out | ios::app);

        outttt << flight_file << '\n';
        outttt << flight_name << '\n';
        outttt << flight_date << '\n';
        outttt << flight_duration << '\n';
        outttt << flight_time << '\n';
        outttt << flight_cost << '\n';

        outttt.close();
        break;
    }

    }

    if(select==1){
        flight_details[0].push_back(flight_file);
    }
    else if(select==2){
        flight_details[1].push_back(flight_file);
    }
    else if(select==3){
        flight_details[2].push_back(flight_file);
    }
    else if(select==4){
        flight_details[3].push_back(flight_file);
    }

    ofstream out;
    out.open("FLIGHTS.txt");

    out << "BD" << '\n';
    for(int i = 0; i<flight_details[0].size(); i++){
        out << flight_details[0][i] << '\n';
    }
    out << "#" << '\n';

    out << "DB" << '\n';
    for(int i = 0; i<flight_details[1].size(); i++){
        out << flight_details[1][i] << '\n';
    }
    out << "#" << '\n';

    out << "UK" << '\n';
    for(int i = 0; i<flight_details[2].size(); i++){
        out << flight_details[2][i] << '\n';
    }
    out << "#" << '\n';

    out << "US" << '\n';
    for(int i = 0; i<flight_details[3].size(); i++){
        out << flight_details[3][i] << '\n';
    }
    out << "#" << '\n';

    out.close();

    system("cls");

    adminPanel();

}

void Delete_Airline(){
do_again:
    cout << "\t\t\t Select Airline: " << '\n';
    cout << "\t\t\t 1. Bangladesh Airlines " << '\n';
    cout << "\t\t\t 2. Dubai Airlines " << '\n';
    cout << "\t\t\t 3. UK Airlines " << '\n';
    cout << "\t\t\t 4. US Airlines " << '\n';
    cout << "\t\t\t Enter number :: " ;

    int select;
    cin >> select;

    if(select<1 || select >4)goto do_again;

do2_again:
    cout << "\t\t\t Enter number of flight:: " ;
    int select2;
    cin >> select2;
    if(select2<1 || select2>flight_details[(select-1)].size()) goto do2_again;
    string temp = flight_details[select-1][select2-1];

    auto it = find(flight_details[select-1].begin(), flight_details[select-1].end(), temp);

    flight_details[select-1].erase(it);

    ofstream out;
    out.open("FLIGHTS.txt");

    out << "BD" << '\n';
    for(int i = 0; i<flight_details[0].size(); i++){

        out << flight_details[0][i] << '\n';
    }
    out << "#" << '\n';

    out << "DB" << '\n';
    for(int i = 0; i<flight_details[1].size(); i++){

        out << flight_details[1][i] << '\n';
    }
    out << "#" << '\n';

    out << "UK" << '\n';
    for(int i = 0; i<flight_details[2].size(); i++){

        out << flight_details[2][i] << '\n';
    }
    out << "#" << '\n';

    out << "US" << '\n';
    for(int i = 0; i<flight_details[3].size(); i++){

        out << flight_details[3][i] << '\n';
    }
    out << "#" << '\n';

    out.close();

    vector<string>f_file;
    vector<string>f_name;
    vector<string>f_date;
    vector<string>f_time;
    vector<string>f_duration;
    vector<string>f_cost;
    string ss;

    switch(select){

case 1:
    {
        int i = 0;
        ifstream inn;
        inn.open("BDflightRecords.txt");

        while(inn.eof()==0){
            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;
            f_name.push_back(ss);
            inn >> ss;
            f_date.push_back(ss);
            inn >> ss;
            f_duration.push_back(ss);
            inn >> ss;
            f_time.push_back(ss);
            inn >> ss;
            f_cost.push_back(ss);
        }
        inn.close();

        ofstream outtt;
        outtt.open("BDflightRecords.txt");


        while(i<f_file.size()){
            if(f_file[i]==temp){
                    i++;
                    continue;
            }
            outtt << f_file[i] << '\n';
            outtt << f_name[i] << '\n';
            outtt << f_date[i] << '\n';
            outtt << f_duration[i] << '\n';
            outtt << f_time[i] << '\n';
            outtt << f_cost[i] << '\n';
            i++;
        }

        outtt.close();
        break;
    }

case 2:
    {
        int i = 0;
        ifstream inn;
        inn.open("DBflightRecords.txt");

        while(inn.eof()==0){
            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;
            f_name.push_back(ss);
            inn >> ss;
            f_date.push_back(ss);
            inn >> ss;
            f_duration.push_back(ss);
            inn >> ss;
            f_time.push_back(ss);
            inn >> ss;
            f_cost.push_back(ss);
        }
        inn.close();

        ofstream outtt;
        outtt.open("DBflightRecords.txt");

        while(i<f_file.size()){
            if(f_file[i]==temp){
                    i++;
                    continue;
            }
            outtt << f_file[i] << '\n';
            outtt << f_name[i] << '\n';
            outtt << f_date[i] << '\n';
            outtt << f_duration[i] << '\n';
            outtt << f_time[i] << '\n';
            outtt << f_cost[i] << '\n';
            i++;
        }
        outtt.close();
        break;
    }

case 3:
    {
        int i = 0;
        ifstream inn;
        inn.open("UKflightRecords.txt");

        while(inn.eof()==0){
            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;
            f_name.push_back(ss);
            inn >> ss;
            f_date.push_back(ss);
            inn >> ss;
            f_duration.push_back(ss);
            inn >> ss;
            f_time.push_back(ss);
            inn >> ss;
            f_cost.push_back(ss);
        }
        inn.close();

        ofstream outtt;
        outtt.open("UKflightRecords.txt");

        while(i<f_file.size()){
            if(f_file[i]==temp){
                    i++;
                    continue;
            }
            outtt << f_file[i] << '\n';
            outtt << f_name[i] << '\n';
            outtt << f_date[i] << '\n';
            outtt << f_duration[i] << '\n';
            outtt << f_time[i] << '\n';
            outtt << f_cost[i] << '\n';
            i++;
        }
        outtt.close();
        break;
    }

case 4:
    {
       int i = 0;
       ifstream inn;
        inn.open("USflightRecords.txt");

        while(inn.eof()==0){
            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;
            f_name.push_back(ss);
            inn >> ss;
            f_date.push_back(ss);
            inn >> ss;
            f_duration.push_back(ss);
            inn >> ss;
            f_time.push_back(ss);
            inn >> ss;
            f_cost.push_back(ss);
        }
        inn.close();

        ofstream outtt;
        outtt.open("USflightRecords.txt");


        while(i<f_file.size()){
            if(f_file[i]==temp){
                    i++;
                    continue;
            }
            outtt << f_file[i] << '\n';
            outtt << f_name[i] << '\n';
            outtt << f_date[i] << '\n';
            outtt << f_duration[i] << '\n';
            outtt << f_time[i] << '\n';
            outtt << f_cost[i] << '\n';
            i++;
        }
        outtt.close();
        break;
    }

    }
    system("cls");
    cout << "\n\t\t\t\t  **Deleted Successfully!**";



    ofstream outa;
    outa.open(temp);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<4; j++)
        {
            out << 1 << ' ';

        }
        out << '\n';
    }
    outa.close();

    adminPanel();
}


void main_menu()
{

    cout << '\n' << '\n';

    cout << "\t\t\t *******************************************\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t** \t\t  Main Menu\t\t   **\n";
    cout << "\t\t\t**\t\t ===========\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**   1. TICKET COUNTER \t\t           **\n";
    cout << "\t\t\t**   2. MY FLIGHTS & TICKETS  \t\t   **\n";
    cout << "\t\t\t**   3. LOGOUT \t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t *******************************************\n\n";

    main_choose();

}

void flights()
{
    cout << '\n' << '\n';
    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t         Airlines              *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n\n";

    int choice, choice1;
    string get;
    string flightN[]= {"Bangladesh", "Dubai", "UK", "USA"};
    for(int a=0; a<4; a++)
    {
        cout << "\t\t\t    " << (a+1)<<".Flight to "<<flightN[a]<<"\n";
    }

    cout << "\n\t\t\t Press the number of the country of which\n\t\t\t you want to book the flight:: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t Welcome to Bangladesh Airlines!      *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        vector<string>f_file;
        vector<string>f_name;
        vector<string>f_date;
        vector<string>f_time;
        vector<string>f_duration;
        vector<string>f_cost;

        string ss;
        ifstream inn;
        inn.open("BDflightRecords.txt");

        if(inn.is_open()){
            while(inn.eof()==0){

            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;

            f_name.push_back(ss);
            inn >> ss;

            f_date.push_back(ss);
            inn >> ss;

            f_duration.push_back(ss);
            inn >> ss;

            f_time.push_back(ss);
            inn >> ss;

            f_cost.push_back(ss);
            }
            inn.close();
        }


        if(f_file.size()==0){
            cout << "\t\t\t No Flights for this airline!\n";
            cout << "\t\t\t Press any button to go to main menu:: ";
            string mm;
            cin >> mm;
            system("cls");
            main_menu();
        }
        else
        {
            for(int i = 0; i<f_file.size(); i++){
            cout<<"\n\t\t\t " << i+1 << ". " << f_name[i] <<" \n";
            cout<<"\t\t\t \t"<< f_date[i] << ' ' << f_time[i] << ' ' << f_duration[i] << "  Tk. " << f_cost[i] << '\n';
            }
            select_aggain:

                            cout<<"\n\t\t\t Select the flight you want to book : ";

                            cin>>choice1;

                            if(choice1<1 || choice > f_file.size()){
                                cout << "\t\t\t\n Invalid Input\n";
                                goto select_aggain;
                            }
                            else {

                                string targeT = f_file[choice1-1];

                                cout<<"\n\t\t\t Available Seats :: \n\n";

                                ifstream in;
                                in.open(targeT);

                                int seat[10][4];

                                if(in.is_open())
                                {


                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            in >> seat[i][j];

                                            if(seat[i][j])
                                            {
                                                cout << (i+1) << (char) ('A'+j) ;
                                                if(i<9)cout << "   ";
                                                else cout << "  ";
                                            }
                                            else
                                            {
                                                cout << "N/A  ";
                                            }
                                        }
                                        cout << '\n';
                                    }

                                    in.close();
                                }
                                else
                                {

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            seat[i][j] = 1;
                                            out << 1 << ' ';

                                            cout << (i+1) << (char)('A'+j);
                                            if(i<9)cout << "   ";
                                            else cout << "  ";
                                        }
                                        out << '\n';
                                        cout << '\n';
                                    }
                                    out.close();
                                }

                                string seat_num;

                    seat_plan:

                                cout << "\n\n\t\t\t Enter your seat number : ";

                                cin >> seat_num;

                                if(seat_num.size()==3)
                                {
                                    if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                                    {
                                        cout << "\n\t\t\t Wrong input!\n";
                                        goto seat_plan;
                                    }
                                }

                                else if(seat_num.size()!=2)
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan;
                                }

                                int digit;
                                if(seat_num.size()==3)
                                {
                                    digit = 9;
                                }
                                else
                                {
                                    digit = seat_num[0] - '0' - 1;
                                }
                                int ch = seat_num.back() - 'A';

                                if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan;
                                }
                                else if(seat[digit][ch]==0)
                                {
                                    cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                                    goto seat_plan;
                                }
                                else
                                {

                                    cout << "\n\t\t\t Congratulation! You have successfully";
                                    cout << "\n\t\t\t booked the flight " <<  f_name[choice1-1];
                                    cout << "\n\t\t\t You can go back to menu and take the ticket.\n";

                                    seat[digit][ch] = 0 ;

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {

                                            out << seat[i][j] << ' ';

                                        }
                                        out << '\n';

                                    }
                                    out.close();

                                    ofstream newout;
                                    newout.open("seats.txt", ios::out | ios::app);

                                    newout << "@Username-"+username << '\n';;
                                    newout << seat_num << '\n';
                                    newout << targeT << '\n';
                                    newout << f_name[choice1-1] << '\n';
                                    newout << f_date[choice1-1] << '\n';
                                    newout << f_time[choice1-1] << '\n';
                                    newout << f_cost[choice1-1] << '\n';

                                    newout.close();

                                    cout << "\n\t\t\t Press any button to go back to main menu.\n";
                                    cout << "\t\t\t ::";
                                    string xx;
                                    cin >> xx;
                                    system("cls");
                                    main_menu();
                                }
                            }

        }
        break;
      }

        case 2:
        {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t Welcome to Dubai Airlines!      *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        vector<string>f_file;
        vector<string>f_name;
        vector<string>f_date;
        vector<string>f_time;
        vector<string>f_duration;
        vector<string>f_cost;

        string ss;
        ifstream inn;
        inn.open("DBflightRecords.txt");

        if(inn.is_open())
        {
            while(inn.eof()==0){

            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;

            f_name.push_back(ss);
            inn >> ss;

            f_date.push_back(ss);
            inn >> ss;

            f_duration.push_back(ss);
            inn >> ss;

            f_time.push_back(ss);
            inn >> ss;

            f_cost.push_back(ss);
        }
        inn.close();
        }


        if(f_file.size()==0){
            cout << "\t\t\t No Flights for this airline!\n";
            cout << "\t\t\t Press any button to go to main menu:: ";
            string mm;
            cin >> mm;
            system("cls");
            main_menu();
        }
        else
        {
            for(int i = 0; i<f_file.size(); i++){
            cout<<"\n\t\t\t " << i+1 << ". " << f_file[i] <<" \n";
            cout<<"\t\t\t \t"<< f_date[i] << ' ' << f_time[i] << ' ' << f_duration[i] << "  Tk. " << f_cost[i] << '\n';
            }
            select_aggain2:

                            cout<<"\n\t\t\t Select the flight you want to book : ";

                            cin>>choice1;

                            if(choice1<1 || choice > f_file.size()){
                                cout << "\t\t\t\n Invalid Input\n";
                                goto select_aggain2;
                            }
                            else {

                                string targeT = f_file[choice1-1];

                                cout<<"\n\t\t\t Available Seats :: \n\n";

                                ifstream in;
                                in.open(targeT);

                                int seat[10][4];

                                if(in.is_open())
                                {


                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            in >> seat[i][j];

                                            if(seat[i][j])
                                            {
                                                cout << (i+1) << (char) ('A'+j) ;
                                                if(i<9)cout << "   ";
                                                else cout << "  ";
                                            }
                                            else
                                            {
                                                cout << "N/A  ";
                                            }
                                        }
                                        cout << '\n';
                                    }

                                    in.close();
                                }
                                else
                                {

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            seat[i][j] = 1;
                                            out << 1 << ' ';

                                            cout << (i+1) << (char)('A'+j);
                                            if(i<9)cout << "   ";
                                            else cout << "  ";
                                        }
                                        out << '\n';
                                        cout << '\n';
                                    }
                                    out.close();
                                }

                                string seat_num;

                    seat_plan2:

                                cout << "\n\n\t\t\t Enter your seat number : ";

                                cin >> seat_num;

                                if(seat_num.size()==3)
                                {
                                    if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                                    {
                                        cout << "\n\t\t\t Wrong input!\n";
                                        goto seat_plan2;
                                    }
                                }

                                else if(seat_num.size()!=2)
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan2;
                                }

                                int digit;
                                if(seat_num.size()==3)
                                {
                                    digit = 9;
                                }
                                else
                                {
                                    digit = seat_num[0] - '0' - 1;
                                }
                                int ch = seat_num.back() - 'A';

                                if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan2;
                                }
                                else if(seat[digit][ch]==0)
                                {
                                    cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                                    goto seat_plan2;
                                }
                                else
                                {

                                    cout << "\n\t\t\t Congratulation! You have successfully";
                                    cout << "\n\t\t\t booked the flight " <<  f_name[choice1-1];
                                    cout << "\n\t\t\t You can go back to menu and take the ticket.\n";

                                    seat[digit][ch] = 0 ;

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {

                                            out << seat[i][j] << ' ';

                                        }
                                        out << '\n';

                                    }
                                    out.close();

                                    ofstream newout;
                                    newout.open("seats.txt", ios::out | ios::app);

                                    newout << "@Username-"+username << '\n';;
                                    newout << seat_num << '\n';
                                    newout << targeT << '\n';
                                    newout << f_name[choice1-1] << '\n';
                                    newout << f_date[choice1-1] << '\n';
                                    newout << f_time[choice1-1] << '\n';
                                    newout << f_cost[choice1-1] << '\n';

                                    newout.close();

                                    cout << "\t\t\t\n Press any button to go back to main menu.\n";
                                    cout << "\t\t\t ::";
                                    string xx;
                                    cin >> xx;
                                    system("cls");
                                    main_menu();
                                }
                            }

            }
            break;
          }
        case 3:
        {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t Welcome to UK Airlines!      *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        vector<string>f_file;
        vector<string>f_name;
        vector<string>f_date;
        vector<string>f_time;
        vector<string>f_duration;
        vector<string>f_cost;

        string ss;
        ifstream inn;
        inn.open("UKflightRecords.txt");

        if(inn.is_open())
        {
            while(inn.eof()==0){

            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;

            f_name.push_back(ss);
            inn >> ss;

            f_date.push_back(ss);
            inn >> ss;

            f_duration.push_back(ss);
            inn >> ss;

            f_time.push_back(ss);
            inn >> ss;

            f_cost.push_back(ss);
        }
        inn.close();
        }


        if(f_file.size()==0){
            cout << "\t\t\t No Flights for this airline!\n";
            cout << "\t\t\t Press any button to go to main menu:: ";
            string mm;
            cin >> mm;
            system("cls");
            main_menu();
        }
        else
        {
            for(int i = 0; i<f_file.size(); i++){
            cout<<"\n\t\t\t " << i+1 << ". " << f_file[i] <<" \n";
            cout<<"\t\t\t \t"<< f_date[i] << ' ' << f_time[i] << ' ' << f_duration[i] << "  Tk. " << f_cost[i] << '\n';
            }
            select_aggain3:

                            cout<<"\n\t\t\t Select the flight you want to book : ";

                            cin>>choice1;

                            if(choice1<1 || choice > f_file.size()){
                                cout << "\t\t\t\n Invalid Input\n";
                                goto select_aggain3;
                            }
                            else {

                                string targeT = f_file[choice1-1];

                                cout<<"\n\t\t\t Available Seats :: \n\n";

                                ifstream in;
                                in.open(targeT);

                                int seat[10][4];

                                if(in.is_open())
                                {


                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            in >> seat[i][j];

                                            if(seat[i][j])
                                            {
                                                cout << (i+1) << (char) ('A'+j) ;
                                                if(i<9)cout << "   ";
                                                else cout << "  ";
                                            }
                                            else
                                            {
                                                cout << "N/A  ";
                                            }
                                        }
                                        cout << '\n';
                                    }

                                    in.close();
                                }
                                else
                                {

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            seat[i][j] = 1;
                                            out << 1 << ' ';

                                            cout << (i+1) << (char)('A'+j);
                                            if(i<9)cout << "   ";
                                            else cout << "  ";
                                        }
                                        out << '\n';
                                        cout << '\n';
                                    }
                                    out.close();
                                }

                                string seat_num;

                    seat_plan3:

                                cout << "\n\n\t\t\t Enter your seat number : ";

                                cin >> seat_num;

                                if(seat_num.size()==3)
                                {
                                    if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                                    {
                                        cout << "\n\t\t\t Wrong input!\n";
                                        goto seat_plan3;
                                    }
                                }

                                else if(seat_num.size()!=2)
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan3;
                                }

                                int digit;
                                if(seat_num.size()==3)
                                {
                                    digit = 9;
                                }
                                else
                                {
                                    digit = seat_num[0] - '0' - 1;
                                }
                                int ch = seat_num.back() - 'A';

                                if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan3;
                                }
                                else if(seat[digit][ch]==0)
                                {
                                    cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                                    goto seat_plan3;
                                }
                                else
                                {

                                    cout << "\n\t\t\t Congratulation! You have successfully";
                                    cout << "\n\t\t\t booked the flight " <<  f_name[choice1-1];
                                    cout << "\n\t\t\t You can go back to menu and take the ticket.\n";

                                    seat[digit][ch] = 0 ;

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {

                                            out << seat[i][j] << ' ';

                                        }
                                        out << '\n';

                                    }
                                    out.close();

                                    ofstream newout;
                                    newout.open("seats.txt", ios::out | ios::app);

                                    newout << "@Username-"+username << '\n';;
                                    newout << seat_num << '\n';
                                    newout << targeT << '\n';
                                    newout << f_name[choice1-1] << '\n';
                                    newout << f_date[choice1-1] << '\n';
                                    newout << f_time[choice1-1] << '\n';
                                    newout << f_cost[choice1-1] << '\n';

                                    newout.close();

                                    cout << "\n\t\t\t Press any button to go back to main menu. \n";
                                    cout << "\t\t\t ::";
                                    string xx;
                                    cin >> xx;
                                    system("cls");
                                    main_menu();
                                }
                            }

                }
                break;
              }

        case 4:
        {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t Welcome to US Airlines!      *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        vector<string>f_file;
        vector<string>f_name;
        vector<string>f_date;
        vector<string>f_time;
        vector<string>f_duration;
        vector<string>f_cost;

        string ss;
        ifstream inn;
        inn.open("USflightRecords.txt");

        if(inn.is_open())
        {
            while(inn.eof()==0){

            inn >> ss;
            if(inn.eof())break;
            f_file.push_back(ss);
            inn >> ss;

            f_name.push_back(ss);
            inn >> ss;

            f_date.push_back(ss);
            inn >> ss;

            f_duration.push_back(ss);
            inn >> ss;

            f_time.push_back(ss);
            inn >> ss;

            f_cost.push_back(ss);
        }
        inn.close();
        }


        if(f_file.size()==0){
            cout << "\t\t\t No Flights for this airline!\n";
            cout << "\t\t\t Press any button to go to main menu:: ";
            string mm;
            cin >> mm;
            system("cls");
            main_menu();
        }
        else
        {
            for(int i = 0; i<f_file.size(); i++){
            cout<<"\n\t\t\t " << i+1 << ". " << f_file[i] <<" \n";
            cout<<"\t\t\t \t"<< f_date[i] << ' ' << f_time[i] << ' ' << f_duration[i] << "  Tk. " << f_cost[i] << '\n';
            }
            select_aggain4:

                            cout<<"\n\t\t\t Select the flight you want to book : ";

                            cin>>choice1;

                            if(choice1<1 || choice > f_file.size()){
                                cout << "\t\t\t\n Invalid Input\n";
                                goto select_aggain4;
                            }
                            else {

                                string targeT = f_file[choice1-1];

                                cout<<"\n\t\t\t Available Seats :: \n\n";

                                ifstream in;
                                in.open(targeT);

                                int seat[10][4];

                                if(in.is_open())
                                {


                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            in >> seat[i][j];

                                            if(seat[i][j])
                                            {
                                                cout << (i+1) << (char) ('A'+j) ;
                                                if(i<9)cout << "   ";
                                                else cout << "  ";
                                            }
                                            else
                                            {
                                                cout << "N/A  ";
                                            }
                                        }
                                        cout << '\n';
                                    }

                                    in.close();
                                }
                                else
                                {

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {
                                            seat[i][j] = 1;
                                            out << 1 << ' ';

                                            cout << (i+1) << (char)('A'+j);
                                            if(i<9)cout << "   ";
                                            else cout << "  ";
                                        }
                                        out << '\n';
                                        cout << '\n';
                                    }
                                    out.close();
                                }

                                string seat_num;

                    seat_plan4:

                                cout << "\n\n\t\t\t Enter your seat number : ";

                                cin >> seat_num;

                                if(seat_num.size()==3)
                                {
                                    if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                                    {
                                        cout << "\n\t\t\t Wrong input!\n";
                                        goto seat_plan4;
                                    }
                                }

                                else if(seat_num.size()!=2)
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan4;
                                }

                                int digit;
                                if(seat_num.size()==3)
                                {
                                    digit = 9;
                                }
                                else
                                {
                                    digit = seat_num[0] - '0' - 1;
                                }
                                int ch = seat_num.back() - 'A';

                                if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
                                {
                                    cout << "\n\t\t\t Wrong input!\n";
                                    goto seat_plan4;
                                }
                                else if(seat[digit][ch]==0)
                                {
                                    cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                                    goto seat_plan4;
                                }
                                else
                                {

                                    cout << "\n\t\t\t Congratulation! You have successfully";
                                    cout << "\n\t\t\t booked the flight " <<  f_name[choice1-1];
                                    cout << "\n\t\t\t You can go back to menu and take the ticket. \n";

                                    seat[digit][ch] = 0 ;

                                    ofstream out;
                                    out.open(targeT);

                                    for(int i=0; i<10; i++)
                                    {
                                        cout << "\t\t\t\t ";
                                        for(int j=0; j<4; j++)
                                        {

                                            out << seat[i][j] << ' ';

                                        }
                                        out << '\n';

                                    }
                                    out.close();

                                    ofstream newout;
                                    newout.open("seats.txt", ios::out | ios::app);

                                    newout << "@Username-"+username << '\n';;
                                    newout << seat_num << '\n';
                                    newout << targeT << '\n';
                                    newout << f_name[choice1-1] << '\n';
                                    newout << f_date[choice1-1] << '\n';
                                    newout << f_time[choice1-1] << '\n';
                                    newout << f_cost[choice1-1] << '\n';

                                    newout.close();

                                    cout << "\t\t\t\n Press any button to go back to main menu.\n";
                                    cout << "\t\t\t ::";
                                    string xx;
                                    cin >> xx;
                                    system("cls");
                                    main_menu();
                                }
                            }

                    }
                    break;
                  }
        default:
            {
                system("cls");
                cout << "\t\t\t\n  Invalid Input!";
                flights();
            }
    }
}

void my_flights(){

    cout << '\n' << '\n';
    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t      Your Tickets             *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n\n";

    string NAME, ADDRESS, PHONE, GENDER, ss;
    string current_user = "@Username-"+username;

    ifstream in;
    in.open("info.txt");

    while(in.eof()==0){
        in >> ss;
        if(ss==current_user){
            getline(in, NAME);
            getline(in, NAME);
            getline(in, ADDRESS);
            getline(in, PHONE);
            getline(in, GENDER);
            break;
        }
    }

    in.close();

    cout << "\t\t\t\t      :: Profile :: ";
    cout << "\n\n\t\t\t    Name: " << NAME << '\n';
    cout << "\t\t\t    Address: " << ADDRESS << '\n';
    cout << "\t\t\t    Phone: " << PHONE << '\n';
    cout << "\t\t\t    Gender: " << GENDER << '\n' << '\n';

    string inf;
    vector<string>userID;
    vector<string>seat_no;
    vector<string>file_Name;
    vector<string>plane_name;
    vector<string>Date;
    vector<string>Time;
    vector<string>cost;

    int cnt = 0;

    in.open("seats.txt");

    while(in.eof()==0){
        in >> inf;
        if(in.eof())break;
        if(inf==current_user){
            cnt++;
        }
            userID.push_back(inf);

            in >> inf;
            seat_no.push_back(inf);

            in >> inf;
            file_Name.push_back(inf);

            in >> inf;
            plane_name.push_back(inf);

            in >> inf;
            Date.push_back(inf);

            in >> inf;
            Time.push_back(inf);

            in >> inf;
            cost.push_back(inf);

    }
    in.close();

    if(cnt==0){
        string s;
        cout << "\t\t\t No Booking Tickets!\n\n";
        cout << "\t\t\t Press 1 to go to main menu, others for exit.";
        cout << "\n\t\t\t :: ";
        cin >> s;
        if(s=="1"){
            system("cls");
            main_menu();
        }
        else{
            cout << "\t\t\t\t  ***Thank You***\n";
            getch();
        }
    }

    int num = 1;

    vector<int>ticket_count;

    for(int i=0; num<=cnt; i++){
            if(userID[i]==current_user){
                ticket_count.push_back(i);
                cout <<"\t\t\t #Ticket: " << num << '\n';
                cout << "\t\t\t Flight : " << plane_name[i] << '\n';
                cout << "\t\t\t Seat No: " << seat_no[i] << '\n';
                cout << "\t\t\t Date: " << Date[i] << '\n';
                cout <<  "\t\t\t Time: " << Time[i] << '\n';
                cout << "\t\t\t Charge: " << cost[i] << '\n' << '\n';
                num++;
            }
    }

    cout << '\n';

    string x;
    cout << "\t\t\tDo you want to cancel any flight? You will get only 60% return\n";
    cout << "\t\t\tIf yes, press 1, others to print tickets\n";
    cout << "\t\t\t::";
    cin >> x;

    if(x=="1"){
        tick:
        int tickets;
        cout << "\n\t\t\tEnter the Tickets No.: ";
        cin >> tickets;

        if(!(tickets<=cnt && tickets >= 1)){
            cout << "\n\t\t\tInvalid input!";
            goto tick;
        }

        string st = seat_no[ticket_count[tickets-1]];
        string fly = file_Name[ticket_count[tickets-1]];


                ifstream in;
                in.open(fly);

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open(fly);

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

        out.open("seats.txt");

        int i = 0;

        while(i<userID.size()){
            if(i==ticket_count[tickets-1]){
                i++;
                continue;
            }

            out << userID[i] << '\n';
            out << seat_no[i] << '\n';
            out << plane_name[i] << '\n';
            out << Date[i] << '\n';
            out << Time[i] << '\n';
            out << cost[i] << '\n';
            out << "###" << '\n';
            i++;
        }

        out.close();

        cout << "\t\t\tTicket has been cancelled!\n";
        cout << "\t\t\tYou will get your refund soon...\n";
        cout << "\t\t\tPress 1 to go to main menu, others for exit.\n\n";
        cout << "\t\t\t:::";
        cin >> x;
        if(x=="1"){
            system("cls");
            main_menu();
        }
        else{
           cout << "\n\t\t\t***Happy Flying!***" << '\n';
           getch();
        }
        getch();

    }
    else{
        cout << "\n\t\t\t***Happy Flying!***" << '\n';
        exit(0);
    }

}
