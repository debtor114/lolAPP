#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <queue>

// multi-threading
#include <atomic>
#include <mutex>
#include <thread>


using namespace std;

// 일반 챔피언 집합과 선택받은자 챔피언 집합
vector < tuple <string, string, string, string, string, int, string> > champions;

// 전설이 4렙, 6렙이하, 7렙이상 획득할 수 있는 챔피언 집합들
vector< tuple <string, string, string, string, string, int, string> > level4_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level6_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level7_up_champions;

// 경우의 수 계산 전에 선택한 챔피언 집합들
vector< tuple <string, string, string, string, string, int, string> > user_select_champ;


int selected_size; // 유저가 챔피언을 몇 개 선택했는지

// origin1
int Automata[60];
int Firelight[60];
int Rebel[60];
int Black_Rose[60];
int Experiment[60];
int Enforcer[60];
int Conqueror[60];
int Chem_Baron[60];
int Family[60];
int Scrap[60];
int Academy[60];
int Emissary[60];
int High_Roller[60];
int Junker_King[60];

// classes1
int Visionary[60];
int Pit_Fighter[60];
int Sorcerer[60];
int Watcher[60];
int Sniper[60];
int Artillerist[60];
int Bruiser[60];
int Form_Swapper[60];
int Dominator[60];
int Quickstriker[60];
int Ambusher[60];
int Sentinel[60];


// position

int Fronter[60];
int Backer[60];
int ANY[60];

// fix synerge
int automata;
int firelight;
int rebel;
int black_rose;
int experiment;
int enforcer;
int conqueror;
int chem_baron;
int family;
int scrap;
int academy;
int emissary;
int junker_king;
int high_roller;

int visionary;
int pit_fighter;
int sorcerer;
int watcher;
int sniper;
int artillerist;
int bruiser;
int form_swapper;
int dominator;
int quickstriker;
int ambusher;
int sentinel;

int fronter;
int backer;
int any;



// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {

    // origins
    Firelight[index] = firelight;
    Enforcer[index] = enforcer;
    Rebel[index] = rebel;
    Experiment[index] = experiment;
    Conqueror[index] = conqueror;
    Chem_Baron[index] = chem_baron;
    Family[index] = family;
    Black_Rose[index] = black_rose;
    Automata[index] = automata;
    Academy[index] = academy;
    Scrap[index] = scrap;
    Emissary[index] = emissary;
    High_Roller[index] = high_roller;
    Junker_King[index] = junker_king;


    // classes
    Visionary[index] = visionary;
    Quickstriker[index] = quickstriker;
    Sentinel[index] = sentinel;
    Pit_Fighter[index] = pit_fighter;
    Watcher[index] = watcher;
    Sorcerer[index] = sorcerer;
    Artillerist[index] = artillerist;
    Dominator[index] = dominator;
    Ambusher[index] = ambusher;
    Sniper[index] = sniper;
    Form_Swapper[index] = form_swapper;
    Bruiser[index] = bruiser;

    Fronter[index] = fronter;
    Backer[index] = backer;
    ANY[index] = any;

}

void champions_info() {
    champions.push_back(make_tuple("아무무", "Automata", "", "Watcher", "", 1, "Fronter")); 
    champions.push_back(make_tuple("파우더", "Family", "Scrap", "Ambusher", "", 1, "Backer")); 
    champions.push_back(make_tuple("다리우스", "Conqueror", "", "Watcher", "", 1, "Fronter")); 
    champions.push_back(make_tuple("드레이븐", "Conqueror", "", "Pit_Fighter", "", 1, "Backer")); 
    champions.push_back(make_tuple("스탭", "Enforcer", "", "Bruiser", "", 1, "Fronter")); 
    champions.push_back(make_tuple("이렐리아", "Rebel", "", "Sentinel", "", 1, "Fronter")); 
    champions.push_back(make_tuple("럭스", "Academy", "", "Sorcerer", "", 1, "Backer"));
    champions.push_back(make_tuple("모르가나", "Black_Rose", "", "Visionary", "", 1, "Backer"));
    champions.push_back(make_tuple("바이올렛", "Family", "", "Pit_Fighter", "", 1, "Fronter")); 
    champions.push_back(make_tuple("메디", "Enforcer", "", "Sniper", "", 1, "Backer")); 
    champions.push_back(make_tuple("신지드", "Chem_Baron", "", "Sentinel", "", 1, "Fronter"));
    champions.push_back(make_tuple("트런들", "Scrap", "", "Bruiser", "", 1, "Fronter")); 
    champions.push_back(make_tuple("벡스", "Rebel", "", "Visionary", "", 1, "Backer")); 
    champions.push_back(make_tuple("자이라", "Experiment", "", "Sorcerer", "", 1, "Backer")); 

    champions.push_back(make_tuple("아칼리", "Rebel", "", "Quickstriker", "", 2, "Fronter")); 
    champions.push_back(make_tuple("카밀", "Enforcer", "", "Ambusher", "", 2, "Fronter")); 
    champions.push_back(make_tuple("레오나", "Academy", "", "Sentinel", "", 2, "Fronter")); 
    champions.push_back(make_tuple("녹턴", "Automata", "", "Quickstriker", "", 2, "Fronter"));
    champions.push_back(make_tuple("벤더", "Family", "", "Watcher", "", 2, "Fronter")); 
    champions.push_back(make_tuple("렐", "Conqueror", "", "Sentinel", "Visionary", 2, "Fronter")); 
    champions.push_back(make_tuple("세트", "Rebel", "", "Bruiser", "", 2, "Fronter")); 
    champions.push_back(make_tuple("트리스타나", "Emissary", "", "Artillerist", "", 2, "Backer")); 
    champions.push_back(make_tuple("우르곳", "Experiment", "", "Artillerist", "Pit_Fighter", 2, "Fronter"));
    champions.push_back(make_tuple("블라디미르", "Black_Rose", "", "Watcher", "Sorcerer", 2, "Fronter"));
    champions.push_back(make_tuple("제리", "Firelight", "", "Sniper", "", 2, "Backer"));
    champions.push_back(make_tuple("직스", "Scrap", "", "Dominator", "", 2, "Backer"));
    champions.push_back(make_tuple("레나타", "Chem_Baron", "", "Visionary", "", 2, "Backer"));


    champions.push_back(make_tuple("로리스", "Enforcer", "", "Sentinel", "", 3, "Fronter"));
    champions.push_back(make_tuple("블리츠크랭크", "Automata", "", "Dominator", "", 3, "Fronter")); 
    champions.push_back(make_tuple("카시오페아", "Black_Rose", "", "Dominator", "", 3, "Backer")); 
    champions.push_back(make_tuple("레니", "Chem_Baron", "", "Bruiser", "", 3, "Fronter")); 
    champions.push_back(make_tuple("이즈리얼", "Academy", "Rebel", "Artillerist", "", 3, "Backer")); 
    champions.push_back(make_tuple("스카", "Firelight", "", "Watcher", "", 3, "Fronter"));
    champions.push_back(make_tuple("갱플랭크", "Scrap", "", "Pit_Fighter", "Form_Swapper", 3, "ANY")); 
    champions.push_back(make_tuple("스미치", "Chem_Baron", "", "Ambusher", "", 3, "Fronter")); 
    champions.push_back(make_tuple("코그모", "Automata", "", "Sniper", "", 3, "Backer")); 
    champions.push_back(make_tuple("나미", "Emissary", "", "Sorcerer", "", 3, "Backer")); 
    champions.push_back(make_tuple("누누", "Experiment", "", "Bruiser", "Visionary", 3, "Fronter")); 
    champions.push_back(make_tuple("스웨인", "Conqueror", "", "Sorcerer", "Form_Swapper", 3, "ANY"));
    champions.push_back(make_tuple("트페", "Enforcer", "", "Quickstriker", "", 3, "Backer"));

    champions.push_back(make_tuple("암베사", "Conqueror", "Emissary", "Quickstriker", "", 4, "Fronter")); 
    champions.push_back(make_tuple("코르키", "Scrap", "", "Artillerist", "", 4, "Backer")); 
    champions.push_back(make_tuple("문도", "Experiment", "", "Dominator", "", 4, "Fronter")); 
    champions.push_back(make_tuple("에코", "Firelight", "Scrap", "Ambusher", "", 4, "Fronter")); 
    champions.push_back(make_tuple("가렌", "Emissary", "", "Watcher", "", 4, "Fronter"));
    champions.push_back(make_tuple("엘리스", "Black_Rose", "", "Bruiser", "Form_Swapper", 4, "ANY")); 
    champions.push_back(make_tuple("하이머딩거", "Academy", "", "Visionary", "", 4, "Backer")); 
    champions.push_back(make_tuple("일라오이", "Rebel", "", "Sentinel", "", 4, "Fronter")); 
    champions.push_back(make_tuple("실코", "Chem_Baron", "", "Dominator", "", 4, "Backer")); 
    champions.push_back(make_tuple("트위치", "Experiment", "", "Sniper", "", 4, "Backer")); 
    champions.push_back(make_tuple("바이", "Enforcer", "", "Pit_Fighter", "", 4, "Fronter")); 
    champions.push_back(make_tuple("조이", "Rebel", "", "Sorcerer", "", 4, "Backer")); 

    champions.push_back(make_tuple("케이틀린", "Enforcer", "", "Sniper", "", 5, "Backer")); 
    champions.push_back(make_tuple("제이스", "Academy", "", "Form_Swapper", "", 5, "ANY")); 
    champions.push_back(make_tuple("징크스", "Rebel", "", "Ambusher", "", 5, "Backer")); 
    champions.push_back(make_tuple("르블랑", "Black_Rose", "", "Sorcerer", "", 5, "Backer")); 
    champions.push_back(make_tuple("세비카", "Chem_Baron", "High_Roller", "Pit_Fighter", "", 5, "Fronter")); 
    champions.push_back(make_tuple("말자하", "Automata", "", "Visionary", "", 5, "Backer")); 
    champions.push_back(make_tuple("모데카이저", "Conqueror", "", "Dominator", "", 5, "Fronter")); 
    champions.push_back(make_tuple("럼블", "Junker_Kings", "Scrap", "Sentinel", "", 5, "Fronter")); 
}



// 초반부에 있었던 챔피언 집합들을 만들어주는 함수
void makingChampionList(int argc, char** argv) {
    if (argc >= 4) {
        for (int i = 3; i < argc; i++) {
            // 유저가 선택한 일반 챔피언
            for (int j = 0; j < champions.size(); j++) {
                if(argv[i] == get<0>(champions[j])) {
                    user_select_champ.push_back(champions[j]);
                }
            }
   
        }
        if (user_select_champ.size() < argc - 3) {
            cout << "선택한 챔피언이 존재하지 않습니다.\n오탈자가 있는지 확인해주세요\n";
            for (int i = 3; i < argc; i++) {
                cout << argv[i] << " ";
                //cout << get<0>(user_select_champ[j]) << " ";
            }
            exit(0);
        }
    }

    selected_size = user_select_champ.size();

    // 유저가 선택한 챔피언(user_select_champ)이 선택될 챔피언 집합(level4_down_champions.. etc..)에 중복 포함되는 걸 방지
    bool flag;
    for (int i = 0; i < champions.size(); i++) {    
        flag = true;    
        for (int j = 0; j < selected_size; j++) {
            if (get<0>(champions[i]) == get<0>(user_select_champ[j])) {
                flag = false;
                break;
            }
        }

        if (flag) {
            if (get<5>(champions[i]) < 4) level4_down_champions.push_back(champions[i]);
            if (get<5>(champions[i]) < 5) level6_down_champions.push_back(champions[i]);
            level7_up_champions.push_back(champions[i]);
        }
    }
    
}

void addCharcteristic() {
    cout << "추가 시너지를 적용합니다." << endl;
    cout << "특성을 한개 씩 나열해주세요" << endl;
    cout << "ex) 2정복자, 1지배자" << endl;
    cout << " => \"2정복자\" 입력후 enter" << endl;
    cout << " => \"1지배자\" 입력후 enter" << endl;
    cout << " => \"END\"입력후 enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "자동기계") automata += num;
        else if (traits == "점화단") firelight += num;
        else if (traits == "반군") rebel += num;
        else if (traits == "검은장미단") black_rose += num;
        else if (traits == "실험체") experiment += num;
        else if (traits == "집행자") enforcer += num;
        else if (traits == "정복자") conqueror += num;
        else if (traits == "화공남작") chem_baron += num;
        else if (traits == "가족") family += num;
        else if (traits == "고물상") scrap += num;
        else if (traits == "아카데미") academy += num;
        else if (traits == "사절") emissary += num;
        else if (traits == "고물의왕") junker_king += num;
        else if (traits == "도박꾼") high_roller += num;

        // classes
        else if (traits == "선도자") visionary += num;
        else if (traits == "투사") pit_fighter += num;
        else if (traits == "마법사") sorcerer += num;
        else if (traits == "주시자") watcher += num;
        else if (traits == "저격수") sniper += num;
        else if (traits == "포수") artillerist += num;
        else if (traits == "난동꾼") bruiser += num;
        else if (traits == "형태전환자") form_swapper += num;  
        else if (traits == "지배자") dominator += num;
        else if (traits == "기동타격대") quickstriker += num;
        else if (traits == "매복자") ambusher += num;
        else if (traits == "감시자") sentinel += num;

    }
    

}


// 선택이 완료된 조합의 시너지 점수를 계산하는 함수
int synerge_check(int index) {
    int synerge_count = 0;
    // 1 : 1-2
    // 1-2-3-4 : 2 4 11 17
    // 2-3-4-5: 5 10 15 22
    // 2-4-6: 5 12 25-30
    // 2-4-6-8: 5 10 15 33-35
    // 2-4-6-9: 5 12 25 43
    // 3-4-5 :  8 13 18-22
    // 3-4-5-6: 8 13 18 25
    // 3-5: 8 15
    // 3-5-7: 8 15 30-33
    // 3-5-7-9: 8 15 28 45
    // 3-5-7-10: 8 15 30 45
    // 3-6: 8 18
    // 3-6-8: 8 16 40
    // 3-6-9: 8 16 45


    // origin
    if (Automata[index] >= 2 && Automata[index] < 4) synerge_count += 5;
    else if (Automata[index] >= 4 && Automata[index] < 6) synerge_count += 10;  
    else if (Automata[index] >= 6) synerge_count += 15;

    if (Firelight[index] >= 2 && Firelight[index] < 3) synerge_count += 5;
    else if (Firelight[index] >= 3 && Firelight[index] < 4) synerge_count += 10;  
    else if (Firelight[index] >= 4) synerge_count += 15;  

    if (Rebel[index] >= 3 && Rebel[index] < 5) synerge_count += 8; 
    else if (Rebel[index] >= 5 && Rebel[index] < 7) synerge_count += 15; 
    else if (Rebel[index] >= 7 && Rebel[index] < 10) synerge_count += 30; 
    else if (Rebel[index] >= 10) synerge_count += 45;

    if (Black_Rose[index] >= 3 && Black_Rose[index] < 4) synerge_count += 7; 
    else if (Black_Rose[index] >= 4 && Black_Rose[index] < 5) synerge_count += 12; 
    else if (Black_Rose[index] >= 5 && Black_Rose[index] < 7) synerge_count += 15; 
    else if (Black_Rose[index] >= 7) synerge_count += 30; 

    if (Experiment[index] >= 3 && Experiment[index] < 5) synerge_count += 8; 
    else if (Experiment[index] >= 5 && Experiment[index] < 7) synerge_count += 15; 
    else if (Experiment[index] >= 7) synerge_count += 30;
    
    if (Enforcer[index] >= 2 && Enforcer[index] < 4) synerge_count += 5;
    else if (Enforcer[index] >= 4 && Enforcer[index] < 6) synerge_count += 10;
    else if (Enforcer[index] >= 6 && Enforcer[index] < 8) synerge_count += 15;
    else if (Enforcer[index] >= 8 && Enforcer[index] < 10) synerge_count += 31;
    else if (Enforcer[index] >= 10) synerge_count += 42;  

    if (Conqueror[index] >= 2 && Conqueror[index] < 4) synerge_count += 5; 
    else if (Conqueror[index] >= 4 && Conqueror[index] < 6) synerge_count += 10; 
    else if (Conqueror[index] >= 6 && Conqueror[index] < 8) synerge_count += 15; 
    else if (Conqueror[index] >= 9) synerge_count += 38;

    if (Chem_Baron[index] >= 3 && Chem_Baron[index] < 4) synerge_count += 9;
    else if (Chem_Baron[index] >= 4 && Chem_Baron[index] < 5) synerge_count += 14;
    else if (Chem_Baron[index] >= 5 && Chem_Baron[index] < 6) synerge_count += 20;
    else if (Chem_Baron[index] >= 6 && Chem_Baron[index] < 7) synerge_count += 26;
    else if (Chem_Baron[index] >= 7) synerge_count += 33;  

    if (Family[index] >= 3 && Family[index] < 4) synerge_count += 7;
    else if (Family[index] >= 4 && Family[index] < 5) synerge_count += 13; 
    else if (Family[index] >= 5) synerge_count += 16;

    if (Scrap[index] >= 2 && Scrap[index] < 4) synerge_count += 5; 
    else if (Scrap[index] >= 4 && Scrap[index] < 6) synerge_count += 12; 
    else if (Scrap[index] >= 6 && Scrap[index] < 8) synerge_count += 25; 
    else if (Scrap[index] >= 9) synerge_count += 38;

    if (Academy[index] >= 3 && Academy[index] < 4) synerge_count += 8; 
    else if (Academy[index] >= 4 && Academy[index] < 5) synerge_count += 13; 
    else if (Academy[index] >= 5 && Academy[index] < 6) synerge_count += 18; 
    else if (Academy[index] >= 6) synerge_count += 25;

    if (Emissary[index] >= 1 && Emissary[index] < 2) synerge_count += 8; 
    else if (Emissary[index] >= 2 && Emissary[index] < 4) synerge_count -= 3;
    else if (Emissary[index] >= 4) synerge_count += 15;

    if (High_Roller[index] == 1) synerge_count += 2;  
    if (Junker_King[index] == 1 ) synerge_count += 2;

    // classes
    // 1 : 1-2
    // 1-2-3-4 : 2 4 11 17
    // 2-3-4-5: 5 10 15 22
    // 2-4-6: 5 12 25-30
    // 2-4-6-8: 5 10 15 33-35
    // 2-4-6-9: 5 12 25 43
    // 3-4-5 :  8 13 18-22
    // 3-4-5-6: 8 13 18 25
    // 3-5: 8 15
    // 3-5-7: 8 15 30-33
    // 3-5-7-9: 8 15 28 45
    // 3-5-7-10: 8 15 30 45
    // 3-6: 8 18
    // 3-6-8: 8 16 40
    // 3-6-9: 8 16 45

    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge_count += 5;
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge_count += 12;
    else if (Sentinel[index] >= 6) synerge_count += 25;

    if (Visionary[index] >= 2 && Visionary[index] < 4) synerge_count += 5;
    else if (Visionary[index] >= 4 && Visionary[index] < 6) synerge_count += 10;
    else if (Visionary[index] >= 6 && Visionary[index] < 8) synerge_count += 15;
    else if (Visionary[index] >= 8) synerge_count += 31;

    if (Pit_Fighter[index] >= 2 && Pit_Fighter[index] < 4) synerge_count += 5;
    else if (Pit_Fighter[index] >= 4 && Pit_Fighter[index] < 6) synerge_count += 10;
    else if (Pit_Fighter[index] >= 6 && Pit_Fighter[index] < 8) synerge_count += 15;
    else if (Pit_Fighter[index] >= 8) synerge_count += 33;

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge_count += 5;
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge_count += 10;
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge_count += 15;
    else if (Sorcerer[index] >= 8) synerge_count += 32;

    if (Watcher[index] >= 2 && Watcher[index] < 4) synerge_count += 5;
    else if (Watcher[index] >= 4 && Watcher[index] < 6) synerge_count += 12;
    else if (Watcher[index] >= 6) synerge_count += 25;

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge_count += 5;
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge_count += 12;
    else if (Sniper[index] >= 6) synerge_count += 25; 

    if (Artillerist[index] >= 2 && Artillerist[index] < 3) synerge_count += 5;
    else if (Artillerist[index] >= 4 && Artillerist[index] < 6) synerge_count += 12;
    else if (Artillerist[index] >= 6) synerge_count += 25; 

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 5;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 12;
    else if (Bruiser[index] >= 6) synerge_count += 25;  

    if (Form_Swapper[index] >= 2 && Form_Swapper[index] < 4) synerge_count += 5;
    else if (Form_Swapper[index] >= 4) synerge_count += 12;  

    if (Dominator[index] >= 2 && Dominator[index] < 4) synerge_count += 5;
    else if (Dominator[index] >= 4 && Dominator[index] < 6) synerge_count += 12;
    else if (Dominator[index] >= 6) synerge_count += 25; 

    if (Quickstriker[index] >= 2 && Quickstriker[index] < 3) synerge_count += 5;
    else if (Quickstriker[index] >= 3 && Quickstriker[index] < 4) synerge_count += 10;
    else if (Quickstriker[index] >= 4) synerge_count += 18;

    if (Ambusher[index] >= 2 && Ambusher[index] < 3) synerge_count += 5;
    else if (Ambusher[index] >= 3 && Ambusher[index] < 4) synerge_count += 10;
    else if (Ambusher[index] >= 4 && Ambusher[index] < 5) synerge_count += 15;
    else if (Ambusher[index] >= 5) synerge_count += 22; 


    // if (Fronter[index] - Backer[index] + ANY[index] >= 3 && Fronter[index] - Backer[index] + ANY[index] < 8) synerge_count += 10;
    // else if (Fronter[index] - Backer[index] + ANY[index] >= 1 && Fronter[index] - Backer[index] + ANY[index] < 3) synerge_count += 5;
    // else if (Fronter[index] - Backer[index] + ANY[index] < 1) synerge_count += 2;


    return synerge_count;
}

// 선택이 완료된 조합의 시너지를 계산하는 함수
void synerge_add(tuple <string, string, string, string, string, int, string> &champion, int index) {
    string origin1 = get<1>(champion);
    string origin2 = get<2>(champion);
    string classes1 = get<3>(champion);
    string classes2 = get<4>(champion);
    string BNF = get<6>(champion);

    // origin1
    if (origin1 == "Automata") Automata[index]++;
    else if (origin1 == "Firelight") Firelight[index]++;
    else if (origin1 == "Rebel") Rebel[index]++;
    else if (origin1 == "Black_Rose") Black_Rose[index]++;
    else if (origin1 == "Experiment") Experiment[index]++;
    else if (origin1 == "Enforcer") Enforcer[index]++;
    else if (origin1 == "Conqueror") Conqueror[index]++;
    else if (origin1 == "Chem_Baron") Chem_Baron[index]++;
    else if (origin1 == "Family") Family[index]++;
    else if (origin1 == "Scrap") Scrap[index]++;
    else if (origin1 == "Academy") Academy[index]++;
    else if (origin1 == "Junker_King") Junker_King[index]++;
    else if (origin1 == "Emissary") Emissary[index]++; 
    else if (origin1 == "High_Roller") High_Roller[index]++;

    // origin2
    if (origin2 == "Automata") Automata[index]++;
    else if (origin2 == "Firelight") Firelight[index]++;
    else if (origin2 == "Rebel") Rebel[index]++;
    else if (origin2 == "Black_Rose") Black_Rose[index]++;
    else if (origin2 == "Experiment") Experiment[index]++;
    else if (origin2 == "Enforcer") Enforcer[index]++;
    else if (origin2 == "Conqueror") Conqueror[index]++;
    else if (origin2 == "Chem_Baron") Chem_Baron[index]++;
    else if (origin2 == "Family") Family[index]++;
    else if (origin2 == "Scrap") Scrap[index]++;
    else if (origin2 == "Academy") Academy[index]++;
    else if (origin2 == "Junker_King") Junker_King[index]++;
    else if (origin2 == "Emissary") Emissary[index]++;
    else if (origin2 == "High_Roller") High_Roller[index]++;

    // classes1
    if (classes1 == "Visionary") Visionary[index]++;
    else if (classes1 == "Sorcerer") Sorcerer[index]++;
    else if (classes1 == "Watcher") Watcher[index]++;
    else if (classes1 == "Sniper") Sniper[index]++;
    else if (classes1 == "Artillerist") Artillerist[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "Form_Swapper") Form_Swapper[index]++;  
    else if (classes1 == "Dominator") Dominator[index]++;
    else if (classes1 == "Quickstriker") Quickstriker[index]++;
    else if (classes1 == "Ambusher") Ambusher[index]++;
    else if (classes1 == "Sentinel") Sentinel[index]++;
    else if (classes1 == "Pit_Fighter") Pit_Fighter[index]++;


    // classes2, 특성이 2개 있는 챔피언들 처리
    if (classes2 == "Visionary") Visionary[index]++;
    else if (classes2 == "Sorcerer") Sorcerer[index]++;
    else if (classes2 == "Watcher") Watcher[index]++;
    else if (classes2 == "Sniper") Sniper[index]++;
    else if (classes2 == "Artillerist") Artillerist[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "Form_Swapper") Form_Swapper[index]++;  
    else if (classes2 == "Dominator") Dominator[index]++;
    else if (classes2 == "Quickstriker") Quickstriker[index]++;
    else if (classes2 == "Ambusher") Ambusher[index]++;
    else if (classes2 == "Sentinel") Sentinel[index]++;
    else if (classes2 == "Pit_Fighter") Pit_Fighter[index]++;

    // 앞 뒷 처리
    if (BNF == "Fronter") Fronter[index]++;
    else if (BNF == "Backer") Backer[index]++;
    else if (BNF == "ANY") ANY[index]++;
}


int twostar_champion_cost(tuple <string, string, string, string, string, int, string> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    if (Automata[index] >= 2 && Automata[index] < 4) synerge.append("2자동기계 ");
    else if (Automata[index] >= 4 && Automata[index] < 6) synerge.append("4자동기계 ");   
    else if (Automata[index] >= 6) synerge.append("6자동기계 "); 

    if (Firelight[index] >= 3 && Firelight[index] < 4) synerge.append("3점화단 ");   
    else if (Firelight[index] >= 4 && Firelight[index] < 5) synerge.append("4점화단 ");   
    else if (Firelight[index] >= 5) synerge.append("5점화단 "); 

    if (Rebel[index] >= 3 && Rebel[index] < 5) synerge.append("3반군 ");  
    else if (Rebel[index] >= 5 && Rebel[index] < 7) synerge.append("5반군 ");  
    else if (Rebel[index] >= 7 && Rebel[index] < 10) synerge.append("7반군 ");  
    else if (Rebel[index] >= 10) synerge.append("10반군 "); 

    if (Black_Rose[index] >= 3 && Black_Rose[index] < 5) synerge.append("3검은장미단 ");  
    else if (Black_Rose[index] >= 5 && Black_Rose[index] < 7) synerge.append("5검은장미단 ");  
    else if (Black_Rose[index] >= 7 && Black_Rose[index] < 10) synerge.append("7검은장미단 ");  
    else if (Black_Rose[index] >= 10) synerge.append("10검은장미단 "); 

     if (Experiment[index] >= 3 && Experiment[index] < 5) synerge.append("3실험체 ");  
    else if (Experiment[index] >= 5 && Experiment[index] < 7) synerge.append("5실험체 ");  
    else if (Experiment[index] >= 7) synerge.append("7실험체 "); 
    
    if (Enforcer[index] >= 2 && Enforcer[index] < 4) synerge.append("2집행자 "); 
    else if (Enforcer[index] >= 4 && Enforcer[index] < 4) synerge.append("4집행자 "); 
    else if (Enforcer[index] >= 6 && Enforcer[index] < 8) synerge.append("6집행자 "); 
    else if (Enforcer[index] >= 8 && Enforcer[index] < 10) synerge.append("8집행자 "); 
    else if (Enforcer[index] >= 10) synerge.append("10집행자 ");   

    if (Conqueror[index] >= 2 && Conqueror[index] < 4) synerge.append("2정복자 ");  
    else if (Conqueror[index] >= 4 && Conqueror[index] < 6) synerge.append("4정복자 ");  
    else if (Conqueror[index] >= 6 && Conqueror[index] < 8) synerge.append("6정복자 ");  
    else if (Conqueror[index] >= 9) synerge.append("9정복자 "); 

    if (Chem_Baron[index] >= 2 && Chem_Baron[index] < 3) synerge.append("2화공남작 "); 
    else if (Chem_Baron[index] >= 3 && Chem_Baron[index] < 4) synerge.append("3화공남작 "); 
    else if (Chem_Baron[index] >= 4 && Chem_Baron[index] < 5) synerge.append("4화공남작 "); 
    else if (Chem_Baron[index] >= 5 && Chem_Baron[index] < 6) synerge.append("5화공남작 "); 
    else if (Chem_Baron[index] >= 6 && Chem_Baron[index] < 7) synerge.append("6화공남작 "); 
    else if (Chem_Baron[index] >= 7) synerge.append("7화공남작 ");   

    if (Family[index] >= 2 && Family[index] < 3) synerge.append("2가족 "); 
    else if (Family[index] >= 3 && Family[index] < 4) synerge.append("3가족 ");  
    else if (Family[index] >= 4) synerge.append("4가족 "); 

    if (Scrap[index] >= 2 && Scrap[index] < 4) synerge.append("2고물상 ");  
    else if (Scrap[index] >= 4 && Scrap[index] < 6) synerge.append("4고물상 ");  
    else if (Scrap[index] >= 6 && Scrap[index] < 8) synerge.append("6고물상 ");  
    else if (Scrap[index] >= 9) synerge.append("9고물상 "); 

    if (Academy[index] >= 3 && Academy[index] < 4) synerge.append("3아카데미 ");  
    else if (Academy[index] >= 4 && Academy[index] < 5) synerge.append("4아카데미 ");  
    else if (Academy[index] >= 5 && Academy[index] < 6) synerge.append("5아카데미 ");  
    else if (Academy[index] >= 6) synerge.append("6아카데미 "); 

    if (Emissary[index] >= 1 && Emissary[index] < 2) synerge.append("1사절 ");  
    else if (Emissary[index] >= 2 && Emissary[index] < 3) synerge.append(" ");  
    else if (Emissary[index] >= 4) synerge.append("4사절 "); 

    if (High_Roller[index] == 1) synerge.append("1도박꾼 ");   
    if (Junker_King[index] == 1 ) synerge.append("1고물의왕 "); 

    // classes  
    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge.append("2감시자 "); 
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge.append("4감시자 "); 
    else if (Sentinel[index] >= 6) synerge.append("6감시자 "); 

    if (Visionary[index] >= 2 && Visionary[index] < 4) synerge.append("2선도자 "); 
    else if (Visionary[index] >= 4 && Visionary[index] < 6) synerge.append("4선도자 "); 
    else if (Visionary[index] >= 6 && Visionary[index] < 8) synerge.append("6선도자 "); 
    else if (Visionary[index] >= 8) synerge.append("8선도자 "); 

    if (Pit_Fighter[index] >= 2 && Pit_Fighter[index] < 4) synerge.append("2투사 "); 
    else if (Pit_Fighter[index] >= 4 && Pit_Fighter[index] < 6) synerge.append("4투사 "); 
    else if (Pit_Fighter[index] >= 6 && Pit_Fighter[index] < 8) synerge.append("6투사 "); 
    else if (Pit_Fighter[index] >= 8) synerge.append("8투사 "); 

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge.append("2마법사 "); 
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge.append("4마법사 "); 
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge.append("6마법사 "); 
    else if (Sorcerer[index] >= 8) synerge.append("8마법사 "); 

    if (Watcher[index] >= 2 && Watcher[index] < 4) synerge.append("2주시자 "); 
    else if (Watcher[index] >= 4 && Watcher[index] < 6) synerge.append("4주시자 "); 
    else if (Watcher[index] >= 6) synerge.append("6주시자 "); 

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge.append("2저격수 "); 
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge.append("4저격수 "); 
    else if (Sniper[index] >= 6) synerge.append("6저격수 ");  

    if (Artillerist[index] >= 2 && Artillerist[index] < 3) synerge.append("2포수 "); 
    else if (Artillerist[index] >= 4 && Artillerist[index] < 6) synerge.append("4포수 "); 
    else if (Artillerist[index] >= 6) synerge.append("6포수 ");  

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2난동꾼 "); 
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4난동꾼 "); 
    else if (Bruiser[index] >= 6) synerge.append("6난동꾼 ");   

    if (Form_Swapper[index] >= 2 && Form_Swapper[index] < 4) synerge.append("2형태전환자 "); 
    else if (Form_Swapper[index] >= 4) synerge.append("4형태전환자 ");   

    if (Dominator[index] >= 2 && Dominator[index] < 4) synerge.append("2지배자 "); 
    else if (Dominator[index] >= 4 && Dominator[index] < 6) synerge.append("4지배자 ");
    else if (Dominator[index] >= 6) synerge.append("6지배자 "); 

    if (Quickstriker[index] >= 2 && Quickstriker[index] < 3) synerge.append("2기동타격대 "); 
    else if (Quickstriker[index] >= 3 && Quickstriker[index] < 4) synerge.append("3기동타격대 "); 
    else if (Quickstriker[index] >= 4) synerge.append("4기동타격대 "); 

    if (Ambusher[index] >= 2 && Ambusher[index] < 3) synerge.append("2매복자 "); 
    else if (Ambusher[index] >= 3 && Ambusher[index] < 4) synerge.append("3매복자 "); 
    else if (Ambusher[index] >= 4 && Ambusher[index] < 5) synerge.append("4매복자 "); 
    else if (Ambusher[index] >= 5) synerge.append("5매복자 ");  

    //position
    if (Fronter[index] >= 1 && Fronter[index] < 2)  synerge.append("1");   
    else if (Fronter[index] >= 2 && Fronter[index] < 3) synerge.append("2"); 
    else if (Fronter[index] >= 3 && Fronter[index] < 4) synerge.append("3"); 
    else if (Fronter[index] >= 4 && Fronter[index] < 5) synerge.append("4"); 
    else if (Fronter[index] >= 5 && Fronter[index] < 6) synerge.append("5"); 
    else if (Fronter[index] >= 6 && Fronter[index] < 7) synerge.append("6"); 
    else if (Fronter[index] >= 7 && Fronter[index] < 8) synerge.append("7"); 
    else if (Fronter[index] >= 8 && Fronter[index] < 9) synerge.append("8"); 
    else if (Fronter[index] >= 9 && Fronter[index] < 10) synerge.append("9"); 
    else if (Fronter[index] >= 10) synerge.append("10"); 

    if (Backer[index] >= 1 && Backer[index] < 2)  synerge.append("/1");   
    else if (Backer[index] >= 2 && Backer[index] < 3) synerge.append("/2"); 
    else if (Backer[index] >= 3 && Backer[index] < 4) synerge.append("/3"); 
    else if (Backer[index] >= 4 && Backer[index] < 5) synerge.append("/4"); 
    else if (Backer[index] >= 5 && Backer[index] < 6) synerge.append("/5"); 
    else if (Backer[index] >= 6 && Backer[index] < 7) synerge.append("/6"); 
    else if (Backer[index] >= 7 && Backer[index] < 8) synerge.append("/7"); 
    else if (Backer[index] >= 8 && Backer[index] < 9) synerge.append("/8"); 
    else if (Backer[index] >= 9 && Backer[index] < 10) synerge.append("/9"); 
    else if (Backer[index] >= 10) synerge.append("/10 "); 

    if (ANY[index] >= 1 && ANY[index] < 2)  synerge.append("/1");   
    else if (ANY[index] >= 2 && ANY[index] < 3) synerge.append("/2"); 
    else if (ANY[index] >= 3 && ANY[index] < 4) synerge.append("/3"); 
    else if (ANY[index] >= 4 && ANY[index] < 5) synerge.append("/4"); 
    else if (ANY[index] >= 5 && ANY[index] < 6) synerge.append("/5"); 
    else if (ANY[index] >= 6 && ANY[index] < 7) synerge.append("/6"); 
    else if (ANY[index] >= 7 && ANY[index] < 8) synerge.append("/7"); 
    else if (ANY[index] >= 8 && ANY[index] < 9) synerge.append("/8"); 
    else if (ANY[index] >= 9 && ANY[index] < 10) synerge.append("/9"); 
    else if (ANY[index] >= 10) synerge.append("/10"); 

    return synerge;
}


vector <int> pick[60];

// pq로 minHeap을 사용해서 탐색, 저장, 정렬에 log(N)의 시간복잡도를 갖는다, 따로 정렬할 필요 X
priority_queue < tuple <int, int, string, string > > overall_combination;
int level;

// mutex
recursive_mutex m;

void combination_level4_down(int index, int thread_index) {
    string selected_champ;
    int cost = 0;
    if(pick[thread_index].size() == level - selected_size) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(level4_down_champions[pick[thread_index][i]], thread_index); 
            cost += twostar_champion_cost(level4_down_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(level4_down_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            cost += twostar_champion_cost(user_select_champ[i]);
            selected_champ.append(get<0>(user_select_champ[i]));
            selected_champ.append(" ");
        }  

        int synerge_value = synerge_check(thread_index);

        string synerge = "";
        synerge = synerge_print(thread_index);
    
        // critical section
        m.lock();
        if (synerge.length() != 0)
            overall_combination.push(make_tuple(synerge_value, cost, selected_champ, synerge));
        m.unlock();
        
        init(thread_index);
        return;
    }

    for(int i = index; i < level4_down_champions.size(); i++) {
        pick[thread_index].push_back(i);
        combination_level4_down(i+1, thread_index);
        pick[thread_index].pop_back();
        if (pick[thread_index].size() == 0) return;
        
    }
}

void combination_level6_down(int index, int thread_index) {
    string selected_champ;
    int cost = 0;
    if(pick[thread_index].size() == level - selected_size) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(level6_down_champions[pick[thread_index][i]], thread_index); 
            cost += twostar_champion_cost(level6_down_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(level6_down_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            cost += twostar_champion_cost(user_select_champ[i]);
            selected_champ.append(get<0>(user_select_champ[i]));
            selected_champ.append(" ");
        }  
    
        int synerge_value = synerge_check(thread_index);

        string synerge = "";
        synerge = synerge_print(thread_index);
    
        // critical section
        m.lock();
        if (synerge.length() != 0)
            overall_combination.push(make_tuple(synerge_value, cost, selected_champ, synerge));
        m.unlock();

        init(thread_index);
        return;
    }

    for(int i = index; i < level6_down_champions.size(); i++) {
        pick[thread_index].push_back(i);
        combination_level6_down(i+1, thread_index);
        pick[thread_index].pop_back();
        if (pick[thread_index].size() == 0) return;
        
    }
}

void combination_level7_up(int index, int thread_index) {
    string selected_champ;
    int cost = 0;
    if(pick[thread_index].size() == level - selected_size) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(level7_up_champions[pick[thread_index][i]], thread_index);
            cost += twostar_champion_cost(level7_up_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(level7_up_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            cost += twostar_champion_cost(user_select_champ[i]);
            selected_champ.append(get<0>(user_select_champ[i]));
            selected_champ.append(" ");
        }  

        int synerge_value = synerge_check(thread_index);

        string synerge = "";
        synerge = synerge_print(thread_index);
    
        // critical section
        m.lock();
        if (synerge.length() != 0)
            overall_combination.push(make_tuple(synerge_value, cost, selected_champ, synerge));
        m.unlock();

        init(thread_index);
        return;
    }

    for(int i = index; i < level7_up_champions.size(); i++) {
        pick[thread_index].push_back(i);
        combination_level7_up(i+1, thread_index);
        pick[thread_index].pop_back();
        if (pick[thread_index].size() == 0) return;
        
    }
}


// runner
int main (int argc, char** argv) {
    time_t start, end;
    double result;
    ios::sync_with_stdio(false);

    level = stoi(argv[1]);
    

    // champ vector creation
    champions_info();
    makingChampionList(argc, argv);
    addCharcteristic();
 

    vector <thread> threads;

    start = time(NULL);
    cout << "Processing... " << endl;


    // level check
    if (level <= 4) {
        if (selected_size == level) combination_level4_down(0, 0);
        else {
            for (int i = 0; i <= level4_down_champions.size()-level+selected_size; i++) {
                threads.push_back(thread(combination_level4_down, i, i));
            }

            for (int i = 0; i < threads.size(); i++) {
                if (threads[i].joinable())
                    threads[i].join();
            }
        }
    }

    else if (level > 4 && level <= 6) {
        if (selected_size == level) combination_level6_down(0, 0);
        else {
            for (int i = 0; i <= level6_down_champions.size()-level+selected_size; i++) {
                threads.push_back(thread(combination_level6_down, i, i));
            }

            for (int i = 0; i < threads.size(); i++) {
                if (threads[i].joinable())
                    threads[i].join();
            }
        }
    }

    else {
        if (selected_size == level) combination_level7_up(0, 0);
        else {
            for (int i = 0; i <= level7_up_champions.size()-level+selected_size; i++) {
                threads.push_back(thread(combination_level7_up, i, i));       
            }

            for (int i = 0; i < threads.size(); i++) {
                if (threads[i].joinable())
                    threads[i].join();
            }
        }
    }

    
    end = time(NULL);
    cout << "calculation time: " << (double)(end - start) << "\n";

    // print
    cout << "총 갯수: " << overall_combination.size() << "\n";
    cout << "최고 시너지 점수: " << get<0>(overall_combination.top()) << "\n";
    cout << "LEVEL" << level << " 조합" << "\n";

    int loop = stoi(argv[2]) < overall_combination.size() ? stoi(argv[2]) : overall_combination.size();

    for (int i = 0; i < loop; i++) {
        cout << "조합 " << i+1 << "\n";
        cout << "  챔피언: " << get<2>(overall_combination.top()) << "\n";
        cout << "  시너지: " << get<3>(overall_combination.top()) << "\n";
        cout << "  시너지 점수: " << get<0>(overall_combination.top()) << "\n";
        cout << "  코스트: " << get<1>(overall_combination.top()) << "\n\n\n";
        overall_combination.pop();
    }

    
    return 0;

}
