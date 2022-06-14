#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <stdlib.h>
//#include <Windows.h>// !!!!!! in windows uncomment it .!!!!!!!!!!!  lines:621,622
using namespace std;
struct user{
    string username;
    string password;
    int level=1;
    short coin=0;
    short wordAdd=0;
    short chance=0;
};
void main_menu();
void internal_menu();
void signup();
void login();
void ranking();
void challange();
void continue_game(user sign);
void choose_level(user sign);
void wheel_of_luck(user login);
void edit_profile(user);
short n;
int numUsers=0;
//************************************************************************************************************************//
int main(){
    ifstream getData("user.txt");
    getData >> numUsers ;
    main_menu();
    cin>>n;
    system("clear");
    while (true){
        switch (n){
        case 1://Signup
            cout<<"you entered "<<" \""<< " Signup "<<"\""<<endl;
            signup();
            break;
        case 2://Login
            cout<<"you entered "<<" \""<< " Login "<<"\""<<endl;
            login();
            break;
        
        case 3: //Rank 
            cout<<"you entered "<<" \""<< " Rank "<<"\""<<endl;
            ranking();
            break;
        case 4://Challange
            cout<<"you entered "<<" \""<<" Challange "<<"\""<<endl;
            challange();
            break;
        case 5://Exit
            cout<<"Bye!"<<endl;
            return 0;
            break;
        }
        if (n!=1 && n!=2&& n!=3&& n!=4&& n!=5)
        cout<<"error! you entered "<<n<<" try again."<<endl;
        main_menu();
        cin>>n;
        system("clear");
    }      
}
//************************************************************************************************************************//      main_menu
void main_menu(){
    cout<<"Welcome to this game : "<<endl;
    cout<<"********** Main Menu **********"<<endl;
    cout<<"1. Signup "<<endl;
    cout<<"2. Login "<<endl;
    cout<<"3. Rank "<<endl;
    cout<<"4. Challange "<<endl;
    cout<<"5. Exit "<<endl;
    cout<<"Please enter your choice(from 1 to 5) : \n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     signup
void signup(){
    user sign;
    string temp;
    cout<<"If you want to back menu write \"*\""<<endl;
    cout<<" Write a username : ";
    cin>>sign.username;
    if (sign.username == "*"){
        return;    
    }
    fstream check_repeat("user.txt");
    while (check_repeat >> temp){
        if (temp == sign.username){
            cout<<"Sorry! Your username selected before."<<endl;
            check_repeat.close();
            check_repeat.open("user.txt");
            cout<<" Write a username : ";
            cin>>sign.username; 
        }
    }
    check_repeat.close();
    cout<<" Write a password : ";
    cin>>sign.password;
    fstream write("user.txt",ios::app);
    write <<sign.username <<'\t'<<sign.password<<'\t'<<sign.level<<'\t'
          <<sign.coin<<'\t'<<sign.wordAdd<<'\t'<<sign.chance<<endl;
    write.close();
    fstream filein("user.txt"),fileout("temp.txt");
    int Temp;
    while (filein >> Temp) {
        if (Temp == numUsers) {
            fileout << ++numUsers <<"\n";
        }
        else {
            fileout <<Temp;
        }
    }
    filein.close();
    fileout.close();
    fileout.open("temp.txt");
    filein.open("user.txt");
    string strTemp;
    while (fileout >> strTemp) {
    filein << strTemp <<"\n";
    }
    fileout.close();
    filein.close();
    cout<<"You were signed up successfully"<<endl;
    internal_menu();
    cin>>n;
    system ("clear");
    while (true){
        switch (n){
        case 1://Continue game
            cout<<"you entered "<<" \""<< " Continue game "<<"\""<<endl;
            continue_game(sign);
            break;
        case 2://Choose level
            cout<<"you entered "<<" \""<< " Choose level "<<"\""<<endl;
            choose_level(sign);
            break;
        
        case 3: //Wheel Of Luck
            cout<<"you entered "<<" \""<< " Wheel Of Luck "<<"\""<<endl;
            wheel_of_luck(sign);
            return;
            break;
        case 4://Edit profile
            cout<<"you entered "<<" \""<<" Edit profile "<<"\""<<endl;
            edit_profile(sign);
            break;
        case 5://Logout
            cout<<"Bye! See you later."<<endl;
            return;
            break;
        }
        if (n!=1 && n!=2&& n!=3&& n!=4&& n!=5)
        cout<<"error! you entered "<<n<<" try again."<<endl;
        internal_menu();
        cin>>n;
        system("clear");
    } 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     login
void login(){
    user login;
    cout<<"If you want to back menu write \"*\""<<endl;
    cout<<"Enter your username : ";
    cin>> login.username;
    if (login.username == "*"){
        return ;    
    }
    cout<<"Enter your password : ";
    cin>> login.password;
    fstream check_password("user.txt");
    string strTemp;
    while (check_password >> strTemp){
        if (strTemp == login.username){
            check_password >>strTemp;
            if (strTemp == login.password){
               // check_password >> login.level;
               internal_menu();
               cin>>n;
               system ("clear");
                   while (true){
                        switch (n){
                        case 1://Continue game          //done
                            cout<<"you entered "<<" \""<< " Continue game "<<"\""<<endl;
                            continue_game(login);
                            break;
                        case 2://Choose level          //done
                            cout<<"you entered "<<" \""<< " Choose level "<<"\""<<endl;
                            choose_level(login);
                            break;
                        
                        case 3: //Wheel Of Luck          //done
                            cout<<"you entered "<<" \""<< " Wheel Of Luck "<<"\""<<endl;
                            wheel_of_luck(login);
                            break;
                        case 4://Edit profile          //done
                            cout<<"you entered "<<" \""<<" Edit profile "<<"\""<<endl;
                            edit_profile(login);
                        case 5://Logout          //done
                        cout<<"Bye! See you later."<<endl;
                            return;
                            break;
                        }
                        if (n!=1 && n!=2&& n!=3&& n!=4&& n!=5)
                        cout<<"error! you entered "<<n<<" try again."<<endl;
                        internal_menu();
                        cin>>n;
                        system("clear");
                    } 
            }
            else{
                cout<<"your password is WRONG!"<<endl;
                cout<<"try again"<<endl;
                check_password.close();
                check_password.open("user.txt");
                cout<<"Enter your password : ";
                cin>> login.password;
            }   
        }
    }
    cout<<"your username is WRONG!"<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     ranking
void ranking(){
    fstream show_list("user.txt");
    string temp;
    int x=0;
    bool b=0;
    show_list >> numUsers;
    user rank[numUsers];
    int count=0;
    int sortarray[numUsers];
    string temper[numUsers];
    for (int j = 0; j < numUsers; j++){
        show_list >> rank[j].username;
        show_list >> rank[j].password;
        show_list >> rank[j].level;
        sortarray[j] = rank[j].level;
        show_list >> rank[j].coin;
        show_list >> rank[j].wordAdd;
        show_list >> rank[j].chance;
    }
    for (int b = 0; b < numUsers-1; b++){
        for (int j = 0; j < numUsers-b-1; j++){
            if (sortarray[j]<sortarray[j+1])
            {
                swap(sortarray[j],sortarray[j+1]);
            }  
        } 
    }
    for (int j = 0; j < numUsers; j++){
        for (int c = 0; c < numUsers; c++){
            if (sortarray[j] == rank[c].level){
                cout<<rank[c].username <<'\t'<<rank[c].password<<'\t'<<rank[c].level<<'\t'
                    <<rank[c].coin<<'\t'<<rank[c].wordAdd<<'\t'<<rank[c].chance<<endl;
            }
        }
    }
    show_list.close(); 
    return ; 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     challange
void challange(){
    string player1,player2;
    int score1=0,score2=0;
    int seasons;
    string word[16];
    string word_temp[16];
    string word_extra[16];
    cout<<"Enter your name player1 : ";
    cin>>player1;
    cout<<"Enter your name player2 : ";
    cin>>player2;
    fstream read_level("levels.txt");
    read_level>>seasons;
    int level[seasons];
    for (int i = 0; i < seasons; i++){
        read_level>>level[i];
    }
    int sumlevel=0;
    for (int j = 0; j < seasons; j++)
    {
        sumlevel += level[j];
    }
    srand(time(0));
    int i = rand() % sumlevel + 1;
    int num1,num2;
    string temp;
    for (int a = 0; a < i; a++)
    {
        read_level >> word[0];
        read_level >> num1;
        read_level >> num2;
        for (int i = 1; i <= num1+num2; i++){
            read_level>> word[i];
        }
    }
    read_level.close();
   int numcpy=num1+num2;
   int numcpy1 = numcpy;
   int l,length;
    while (numcpy1!=0)
    {
        system("clear");
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<"player1 : "<<player1<<"     "<<" score : "<<score1<<"    |     "<<"player2 : "<<player2<<"     "<<"score : "<<score2<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<word[0]<<endl;
        for (int line = 1; line <= numcpy; line++){
            if (word[line]==word_temp[line]){
                cout<<word_temp[line];
            }
            else{
                for (int c = 0; c < word[line].length(); c++){
                    cout<<"-";
                }
            }
            cout<<endl;
        }
        cout<<"if you want go back to internal menu enter \"*\" ."<<endl;
        cout<<"if you want another order of letters enter \"$\" ."<<endl;
        cout<<"enter word player1: ";
        cin>>temp;
        if (temp=="*"){
            system("clear");
            cout<<"Player 2: "<<"\""<<player2<<"\""<<" WON the game :)"<<endl;
            return;
        }
        // if (temp=="$"){    // another order for another player
        //     swap(word[0][l],word[0][length]);
        //     l++;
        //     length--;
        //     cin>>temp;  
        // }
        for (int k = 1; k <numcpy+1 ; k++){
            if (temp==word[k]){
                word_temp[k] = temp;
                numcpy1--;
                score1 += word[k].length();
                system("clear");
            }
        }
        system("clear");
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<"player1 : "<<player1<<'\t'<<" score : "<<score1<<"    |     "<<"player2 : "<<player2<<"     "<<"score : "<<score2<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<word[0]<<endl;
        for (int line = 1; line <= numcpy; line++){
            if (word[line]==word_temp[line]){
                cout<<word_temp[line];
            }
            else{
                for (int c = 0; c < word[line].length(); c++){
                    cout<<"-";
                }
            }
            cout<<endl;
        }
        cout<<"if you want go back to internal menu enter \"*\" ."<<endl;
        cout<<"if you want another order of letters enter \"$\" ."<<endl;
        cout<<"enter word player2: ";
        cin>>temp;
        if (temp=="*"){
            system("clear");
            cout<<"Player 1: "<<"\""<<player1<<"\""<<" WON the game :)"<<endl;
            return;
        }
        // if (temp=="$"){      // another order for another player
        //     swap(word[0][l],word[0][length]);
        //     l++;
        //     length--;
        // }
        for (int k = 1; k <numcpy+1 ; k++){
            if (temp==word[k]){
                word_temp[k] = temp;
                numcpy1--;
                score2 += word[k].length();
                system("clear");
            }
        }
    }
    if (score1>score2){
        cout<<"Player1 WON the game ."<<endl;
    }
    else if (score2>score1){
        cout<<"Player2 WON the game ."<<endl;
    }
    else{
        cout<<"Player1 = Player2 ."<<endl;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     internal_menu
void internal_menu(){
    cout<<"********** Internal Menu **********"<<endl;
    cout<<"1. Continue game "<<endl;
    cout<<"2. Choose level "<<endl;
    cout<<"3. Wheel Of Luck "<<endl;
    cout<<"4. Edit profile "<<endl;
    cout<<"5. Logout "<<endl;
    cout<<"Please enter your choice(from 1 to 5) : \n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     continue_game
void continue_game(user sign){
    string ttemp;
    int inttemp;
    string word[15];
    string word_temp[15];
    string word_extra[10];
    bool help[15]={0};
    fstream load_game("saveGame.bin");
    //int i=1;
    fstream read_info("user.txt");
    string str;
    while (str!=sign.username){
        read_info >> str;
    }
    read_info >>str;
    read_info >>str;
    sign.level = stoi(str);
    read_info >>str;
    sign.coin = stoi(str);
    read_info >>str;
    sign.wordAdd = stoi(str);
    read_info >>str;
    sign.chance = stoi(str);
    read_info.close();
    int j;
    while (load_game >> ttemp){
        if(ttemp == to_string(sign.level)+sign.username+"help:"){    
            load_game>>inttemp;
            j=inttemp;
            help[j]=1;    
        }
        else if (ttemp == to_string(sign.level)+sign.username+"word:"){
            load_game>>inttemp;
            j =inttemp;
            load_game>>ttemp;
            word_temp[j] = ttemp;
        } 
        else if (ttemp == to_string(sign.level)+sign.username+"word_extra:"){
            load_game>>inttemp;
            j = inttemp;
            word_extra[j] = "0";
        }   
    }
    load_game.close();
    while (true){
        int seasons;
        fstream read_levels("levels.txt");
        read_levels>>seasons;
        int level[seasons];
        for (int i = 0; i < seasons; i++){
            read_levels>>level[i];
        }
        int num1,num2;
        int sumlevel=0;
        string temp;
        for (int a = 0; a < sign.level; a++)
        {
            read_levels >> word[0];
            read_levels >> num1;
            read_levels >> num2;
            for (int i = 1; i <= num1; i++){
                read_levels>> word[i];
            }
            for (int j = 1; j <= num2; j++){
                if (word_extra[j]!="0"){
                read_levels>> word_extra[j];
                } 
            }
            getline(read_levels,temp);
        }
        read_levels.close();
        int numcpy=num1;
        for (int i = 0; i < numcpy; i++){
            if (word_temp[i]!=""){
                num1--;
            } 
        }
        int season=1;
        for (int x = 0; x < seasons; x++){
            sumlevel+=level[x];
            if (sign.level>sumlevel){
                season=x+2;
            }
        }
        int length = word[0].length()-1;
        int l=0;
        while (num1!=0){
            cout<<"----------------------------------------------------------------------------"<<endl;
            cout<<"season: "<<season<<"\tlevel: "<<sign.level<<"\tcoin: "<<sign.coin<<"\t\textra words: "<<sign.wordAdd<<endl;
            cout<<"----------------------------------------------------------------------------"<<endl;
            cout<<word[0]<<endl;
            cout<<".............."<<endl;
            for (int line = 1; line <= numcpy; line++){
                if (word[line]==word_temp[line]){
                    cout<<word_temp[line];
                }
                else if (help[line]==1){
                    cout<<word[line][0];
                    for (int c = 0; c < word[line].length()-1; c++){
                                cout<<"-";
                            }
                }
                else{
                    for (int c = 0; c < word[line].length(); c++){
                        cout<<"-";
                    }
                }
                cout<<endl;
            }
            cout<<"if you want go back to internal menu enter \"*\" ."<<endl;
            cout<<"if you want another order of letters enter \"$\" ."<<endl;
            cout<<"if you need help enter \"#\" ."<<endl;
            cout<<"enter word : ";
            cin>>temp;
            if (temp=="*")
            {
                fstream filein("user.txt"),fileout("temp.txt");
                string temper;
                int count = 0;
                filein >> numUsers;
                fileout << numUsers <<endl;
                getline(filein,temp);
                while (count!=numUsers) {
                    filein >> temper;
                    if (temper == sign.username) {
                        fileout << sign.username<<'\t'<<sign.password <<'\t'<<sign.level<<'\t'
                                <<sign.coin<<'\t'<<sign.wordAdd<<'\t'<<sign.chance<<endl;
                        filein>>temp;
                        filein>>temp;
                        filein>>temp;
                        filein>>temp;
                        filein>>temp;
                    }
                            
                    else {
                        getline(filein,temp);
                        fileout <<temper<< temp<<endl;
                    }
                    count++;
                }
                filein.close();
                fileout.close();
                count=0;
                fileout.open("temp.txt");
                filein.open("user.txt");
                string strTemp;
                fileout >> strTemp;
                filein << strTemp<<endl;
                getline(fileout,strTemp);
                while (count!=numUsers) {
                    getline(fileout,strTemp);
                    filein << strTemp<<endl;
                    count++;
                }
                fileout.close();
                filein.close();
                fstream saveGame("saveGame.bin",ios::app);
                for (int i = 1; i <= numcpy; i++){
                    if (help[i]==1){
                        saveGame <<sign.level<<sign.username<<"help:"<<endl;
                        saveGame <<i<<endl;
                        saveGame << word_temp[i]<<endl;
                    }
                    else if (word_temp[i]==word[i]){
                        saveGame <<sign.level<<sign.username<<"word:"<<endl;
                        saveGame <<i<<endl;
                        saveGame << word_temp[i]<<endl;
                    }   
                }
                for (int j = 1; j <= num2; j++){
                    if (word_extra[j] == ""){
                       saveGame <<sign.level<<sign.username<<"word_extra:"<<endl;
                       saveGame << j<<endl;
                    }  
                }
                saveGame.close();
                return;
            }
            if (temp=="$"){
                system("clear");
                swap(word[0][l],word[0][length]);
                l++;
                length--;
            }
            else if (temp=="#")
            {
                bool b=0;
                
                if (sign.coin>=80)
                {
                    system("clear");
                    sign.coin-=80;
                    cout<<"----------------------------------------------------------------------------"<<endl;
                    cout<<"season: "<<season<<"\tlevel: "<<sign.level<<"\tcoin: "<<sign.coin<<"\t\textra words: "<<sign.wordAdd<<endl;
                    cout<<"----------------------------------------------------------------------------"<<endl;
                    cout<<word[0]<<endl;
                    cout<<".............."<<endl;
                    for (int line = 1; line <= numcpy; line++){
                        if (word[line]==word_temp[line]){
                            cout<<word_temp[line];
                        }
                        else if(b==0){
                            help[line]=1;
                            cout<<word[line][0];
                            b=1;
                            for (int c = 0; c < word[line].length()-1; c++){
                                cout<<"-";
                            }
                        }
                        else{
                            for (int c = 0; c < word[line].length(); c++){
                                cout<<"-";
                            }
                        }
                    cout<<endl;
                    }
                    b=0;
                    cout<<"enter word : ";
                    cin>>temp;
                }
                else{
                    cout<<"Sorry! Your coin is not enough ."<<endl;
                    cout<<"enter word : ";
                    cin>>temp;
                }   
            }
            bool t=1;
            for (int k = 1; k <(numcpy+num2+1) ; k++){
                if (temp==word[k]){
                    word_temp[k] = temp;
                    num1--;
                    system("clear");
                    t=0;
                }
                else if(temp==word_extra[k]){
                    cout<<"\""<<temp<<"\""<<"is extra word"<<endl;
                    t=0;
                    //sleep(2000);
                    //system("CLS");
                    word_extra[k]="";
                    sign.wordAdd+=1;
                    if (sign.wordAdd==6){
                        sign.coin+=50;
                        sign.wordAdd=0;
                        cout<<"I have gift for you!!"<<endl;
                        cout<<"+50 coin"<<endl;
                    }    
                }
            }
            if (t==1){
                cout<<"sorry try again"<<endl;
            }    
        }
        system("clear");
        sign.coin+=100;
        cout<<"this level has finished.$$"<<endl;
        for (int i = 0; i <= numcpy; i++){
            word_temp[i]="";
        }
        ++sign.level;
        num1=numcpy;
        cout<<"gift : +100 coins ."<<endl;
        for (int m = 0; m < 15; m++){
            help[m]=0;
        }
        for (int  l = seasons-1; l >= 0; l--){
            if (sign.level==level[l]+1){
                cout<<"This season is finished.$$"<<endl;
                cout<<"gift : +1 wheel chance ."<<endl;
                sign.chance+=1;
                season+=1;
            }
        }
        
    }
        // string temp;
        // fstream filein1("user.txt"),fileout1("temp.txt");
        // //int i;
        // string temper;
        // int count = 0;
        // filein1 >> i;
        // fileout1<< i<<endl;
        // getline(filein1,temp);
        // while (count!=i) {
        //     filein1 >> temper;
        //     if (temper == sign.username) {
        //         fileout1 << sign.username<<'\t'<<sign.password <<'\t'<<++sign.level<<'\t'
        //                  <<sign.coin<<'\t'<<sign.wordAdd<<'\t'<<sign.chance<<endl;
        //         filein1>>temp;
        //         filein1>>temp;
        //         filein1>>temp;
        //         filein1>>temp;
        //         filein1>>temp;
        //     }           
        //     else {
        //         getline(filein1,temp);
        //         fileout1 <<temper<< temp<<endl;
        //     }
        //     count++;
        // }
        // filein1.close();
        // fileout1.close();
        // count=0;
        // fileout1.open("temp.txt");
        // filein1.open("user.txt");
        // string strTemp;
        // fileout1 >> strTemp;
        // filein1 << strTemp<<endl;
        // getline(fileout1,strTemp);
        // while (count!=i) {
        //     getline(fileout1,strTemp);
        //     filein1 << strTemp<<endl;
        //     count++;
        // }
        // fileout1.close();
        // filein1.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     choose_level
void choose_level(user login){
    int level_choose;
    string ttemp;
    int inttemp;
    string word[15];
    string word_temp[15];
    string word_extra[10];
    int seasons;
    int i=1;
    while (true){
        bool help[15]={0};
        fstream read_info("user.txt");
        string str;
        while (str!=login.username){
            read_info >> str;
        }
        read_info >>str;
        read_info >>str;
        login.level = stoi(str);
        read_info >>str;
        login.coin = stoi(str);
        read_info >>str;
        login.wordAdd = stoi(str);
        read_info >>str;
        login.chance = stoi(str);
        read_info.close();
        cout<<"You can choose from 1 to "<<login.level<<" : ";
        cin>>level_choose;
        while (level_choose> login.level && level_choose<1){
            cout<<"Sorry!! your number is not available write a valid number : ";
            cin>>level_choose;
        }
        fstream read_levels("levels.txt");
        read_levels>>seasons;
        int level[seasons];
        for (int i = 0; i < seasons; i++){
            read_levels>>level[i];
        }
        int num1,num2;
        int sumlevel=0;
        string temp;
        for (int a = 0; a < level_choose; a++){
            read_levels >> word[0];
            read_levels >> num1;
            read_levels >> num2;
            for (int i = 1; i <= num1; i++){
                    read_levels>> word[i];
            }
            for (int j = 1; j <= num2; j++){
                    read_levels>> word_extra[j];
            }
        }
        read_levels.close();
        int numcpy=num1;
        int season=1;
        for (int x = 0; x < seasons; x++){
            sumlevel+=level[x];
            if (level_choose>sumlevel){
                season=x+2;
            }  
        }
        int length = word[0].length()-1;
        int l=0;
        while (num1!=0){
            cout<<"season: "<<season<<"\tlevel: "<<level_choose<<"\tcoin: "<<login.coin<<"\t\textra words: "<<login.wordAdd<<endl;
            cout<<word[0]<<endl;
            for (int line = 1; line <= numcpy; line++){
                if (word[line]==word_temp[line]){
                    cout<<word_temp[line];
                }
                else if (help[line]==1){
                    cout<<word[line][0];
                    for (int c = 0; c < word[line].length()-1; c++){
                                cout<<"-";
                            }
                }
                else{
                    for (int c = 0; c < word[line].length(); c++){
                        cout<<"-";
                    }
                }
                cout<<endl;
            }
            cout<<"if you want go back to internal menu enter \"*\" ."<<endl;
            cout<<"if you want another order of letters enter \"$\" ."<<endl;
            cout<<"if you need help enter \"#\" ."<<endl;
            cout<<"enter word : ";
            cin>>temp;
            if (temp=="*"){
                fstream filein1("user.txt"),fileout1("temp.txt");
                string temper;
                int count = 0;
                filein1 >> numUsers;
                fileout1<< numUsers<<endl;
                getline(filein1,temp);
                while (count!=numUsers) {
                    filein1 >> temper;
                    if (temper == login.username) {
                        fileout1 << login.username<<'\t'<<login.password <<'\t'<<login.level<<'\t'
                                <<login.coin<<'\t'<<login.wordAdd<<'\t'<<login.chance<<endl;
                        filein1>>temp;
                        filein1>>temp;
                        filein1>>temp;
                        filein1>>temp;
                        filein1>>temp;
                    }
                            
                    else {
                        getline(filein1,temp);
                        fileout1 <<temper<< temp<<endl;
                    }
                    count++;
                }
                filein1.close();
                fileout1.close();
                count=0;
                fileout1.open("temp.txt");
                filein1.open("user.txt");
                string strTemp;
                fileout1 >> strTemp;
                filein1 << strTemp<<endl;
                getline(fileout1,strTemp);
                while (count!=numUsers) {
                    getline(fileout1,strTemp);
                    filein1 << strTemp<<endl;
                    count++;
                }
                fileout1.close();
                filein1.close();
                return;
            }
            if (temp=="$"){
               
                swap(word[0][l],word[0][length]);
                l++;
                length--;   
            }
            if (temp=="#")
            {
                bool b=0;
                if (login.coin>=80)
                {
                    system("clear");
                    login.coin-=80;
                    cout<<"season: "<<season<<"\tlevel: "<<level_choose<<"\tcoin: "<<login.coin<<"\t\textra words: "<<login.wordAdd<<endl;
                    cout<<word[0]<<endl;
                    for (int line = 1; line <= numcpy; line++){
                        if (word[line]==word_temp[line]){
                            cout<<word_temp[line];
                        }
                        else if(b==0){
                            help[line]=1;
                            cout<<word[line][0];
                            b=1;
                            for (int c = 0; c < word[line].length()-1; c++){
                                cout<<"-";
                            }
                        }
                        else{
                            for (int c = 0; c < word[line].length(); c++){
                                cout<<"-";
                            }
                        }
                    cout<<endl;
                    }
                    b=0;
                    cout<<"enter word : ";
                    cin>>temp;
                }
                else
                {
                    cout<<"Sorry! Your coin is not enough ."<<endl;
                    cout<<"enter word : ";
                    cin>>temp;
                }   
            }
            for (int k = 1; k <(numcpy+num2+1) ; k++){
                if (temp==word[k]){
                    word_temp[k] = temp;
                    num1--;
                    system("clear");
                }
                else if(temp==word_extra[k]){
                    cout<<word_extra[k]<<" is extra word"<<endl;
                    word_extra[k]="";
                    if (login.wordAdd==6)
                    {
                        cout<<"good!!"<<endl;
                    }    
                }
            }
        }
        cout<<"this level is finished.$$"<<endl;
        for (int  i = seasons; i > 0; i--)
        {
            if (level_choose>level[i])
            {
                cout<<"This season is finished.$$"<<endl;
                cout<<"gift : +1 wheel chance ."<<endl;
                season+=1;
            }
        }
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     wheel_of_luck
void wheel_of_luck(user login){
    int num;
    fstream read_info("user.txt");
    string str;
    while (str!=login.username){
        read_info >> str;
    }
    read_info >>str;
    read_info >>str;
    login.level = stoi(str);
    read_info >>str;
    login.coin = stoi(str);
    read_info >>str;
    login.wordAdd = stoi(str);
    read_info >>str;
    login.chance = stoi(str);
    read_info.close();
    cout<<"your chance : "<<"\""<<login.chance<<"\""<<endl;
    cout<<"1. 50  coins 30%"<<endl;
    cout<<"2. 70  coins 20%"<<endl;
    cout<<"3. 90  coins 20%"<<endl;
    cout<<"4. 110 coins 15%"<<endl;
    cout<<"5. 150 coins 10%"<<endl;
    cout<<"6. 220 coins  5%"<<endl;
    cout<<"----------------"<<endl;
    cout<<"1. if you want back to internal menu write \"1\" "<<endl;
    cout<<"2. take your chance write a number \"2\""<<endl;
    cout<<"take your number : ";
    cin>>num;
    while (num!=1 && num!=2)
    {
        cout<<"Sorry!! your number is not available write a valid number : ";
        cin>>num;
    }
    system("clear");
    if (num==1){
        return;
    }
    else if(login.chance==0){
        cout<<"sorry!! your chance is \"0\""<<endl;
        return;
    }
    else{
        srand(time(0));
        int i = rand() % 20 + 1;
        if (i<=6){
            cout<<"You won \" +50 coins \""<<endl;
            i=50;
        }
        else if (i<=10){
            cout<<"You won \" +70 coins \""<<endl;
            i=70;
        }
        else if (i<=14){
            cout<<"You won \" +90 coins \""<<endl;
            i=90;
        }
        else if (i<=17){
            cout<<"You won \" +110 coins \""<<endl;
            i=110;
        }
        else if (i<=19){
            cout<<"You won \" +150 coins \""<<endl;
            i=150;
        }
        else if (i==20){
            cout<<"You won \" +220 coins \""<<endl;
            i=220;
        }
        fstream filein1("user.txt"),fileout1("temp.txt");
        int j;
        string temper;
        string temp;
        int count = 0;
        filein1 >> j;
        fileout1<< j<<endl;
        getline(filein1,temp);
        while (count!=j) {
            filein1 >> temper;
            if (temper == login.username) {
                login.coin+=i;
                fileout1 << login.username<<'\t'<<login.password <<'\t'<<login.level<<'\t'
                        <<login.coin<<'\t'<<login.wordAdd<<'\t'<<--login.chance<<endl;
                filein1>>temp;
                filein1>>temp;
                filein1>>temp;
                filein1>>temp;
                filein1>>temp;
            }       
            else {
                getline(filein1,temp);
                fileout1 <<temper<< temp<<endl;
            }
            count++;
        }
        filein1.close();
        fileout1.close();
        count=0;
        fileout1.open("temp.txt");
        filein1.open("user.txt");
        string strTemp;
        fileout1 >> strTemp;
        filein1 << strTemp<<endl;
        getline(fileout1,strTemp);
        while (count!=j) {
            getline(fileout1,strTemp);
            filein1 << strTemp<<endl;
            count++;
        }
        fileout1.close();
        filein1.close(); 
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     edit_profile
void edit_profile(user sign){
    user edit;
    int count=0;
    cout<<"Enter your password : ";
    cin>>edit.password;
    while (true){
        if (edit.password == sign.password){
            cout<<"Enter your new username : ";
            cin>>edit.username;
            string temp;
            string temper;
            fstream check_repeat("user.txt");
            while (check_repeat >> temp){
                if (temp == edit.username){
                    cout<<"Sorry! Your username selected before."<<endl;
                    check_repeat.close();
                    check_repeat.open("user.txt");
                    cout<<" Write a new username : ";
                    cin>>edit.username; 
                }
            }
            check_repeat.close();
            cout<<"Enter your new password : ";
            cin>>edit.password;
            fstream filein("user.txt"),fileout("temp.txt");
            int i;
            filein >> i;
            fileout << i<<endl;
            getline(filein,temp);
            while (count!=i) {
                filein >> temper;
                if (temper == sign.username) {
                    fileout << edit.username<<'\t'<<edit.password <<'\t'<<sign.level<<'\t'
                            <<sign.coin<<'\t'<<sign.wordAdd<<'\t'<<sign.chance<<endl;
                    filein>>temp;
                    filein>>temp;
                    filein>>temp;
                    filein>>temp;
                    filein>>temp;
                }         
                else {
                    getline(filein,temp);
                    fileout <<temper<< temp<<endl;
                }
                count++;
            }
            filein.close();
            fileout.close();
            count=0;
            fileout.open("temp.txt");
            filein.open("user.txt");
            string strTemp;
            fileout >> strTemp;
            filein << strTemp<<endl;
            getline(fileout,strTemp);
            while (count!=i) {
                getline(fileout,strTemp);
                filein << strTemp<<endl;
                count++;
            }
            fileout.close();
            filein.close();
            system("clear");
            cout<<"your account has edited seccessfuly ."<<endl;
            return;
        }
        else{
            cout<<"Your password is WRONG!!"<<endl;
            cout<<"Enter your password : ";
            cin>>edit.password;
        }
    }  
}