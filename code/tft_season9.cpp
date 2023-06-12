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
vector < tuple <string, string, string, string, string, int> > champions;
vector < tuple <string, string, string, string, string, int> > selected_champions;

// 전설이 4렙, 6렙이하, 7렙이상 획득할 수 있는 챔피언 집합들
vector < tuple <string, string, string, string, string, int> > level4_down_champions;
vector < tuple <string, string, string, string, string, int> > level6_down_champions;
vector < tuple <string, string, string, string, string, int> > level7_up_champions;

// 경우의 수 계산 전에 선택한 챔피언 집합들
vector < tuple <string, string, string, string, string, int> > user_select_champ;


int selected_size; // 유저가 챔피언을 몇 개 선택했는지

// origin1
int Darkin[59];
int Demacia[59];
int Freljord[59];
int Ionia[59];
int Noxus[59];
int Piltover[59];
int Shadow_Isles[59];
int Shurima[59];
int Targon[59];
int Void[59];
int Wanderer[59];
int Yordle[59];
int Zaun[59];


// classes1
int Bastion[59];
int Bruiser[59];
int Challenger[59];
int Deadeye[59];
int Empress[59];
int Gunner[59];
int Invoker[59];
int Juggernaut[59];
int Multicaster[59];
int Redeemer[59];
int Rogue[59];
int Slayer[59];
int Sorcerer[59];
int Strategist[59];
int Technogenius[59];


// fix synerge
int darkin;
int demacia;
int freljord;
int ionia;
int noxus;
int piltover;
int shadow_Isles;
int shurima;
int targon;
int vvoid;
int wanderer;
int yordle;
int zaun;
int bastion;
int bruiser;
int challenger;
int deadeye;
int empress;
int gunner;
int invoker;
int juggernaut;
int multicaster;
int redeemer;
int rogue;
int slayer;
int sorcerer;
int strategist;
int technogenius;



// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {

    // origins
    Darkin[index] = darkin;
    Demacia[index] = demacia;
    Freljord[index] = freljord;
    Ionia[index] = ionia;
    Noxus[index] = noxus;
    Piltover[index] = piltover;
    Shadow_Isles[index] = shadow_Isles;
    Shurima[index] = shurima;
    Targon[index] = targon;
    Void[index] = vvoid;
    Wanderer[index] = wanderer;
    Yordle[index] = yordle;
    Zaun[index] = zaun;
    

    // classes
    Bastion[index] = bastion;
    Bruiser[index] = bruiser;
    Deadeye[index] = deadeye;
    Challenger[index] = challenger;
    Empress[index] = empress;
    Gunner[index] = gunner;
    Invoker[index] = invoker;
    Juggernaut[index] = juggernaut;
    Multicaster[index] = multicaster;
    Redeemer[index] = redeemer;
    Rogue[index] = rogue;
    Slayer[index] = slayer;
    Sorcerer[index] = sorcerer;
    Strategist[index] = strategist;
    Technogenius[index] = technogenius;

}

void champions_info() {
    champions.push_back(make_tuple("카시오페아", "Noxus", "Shurima", "Invoker", "", 1)); 
    champions.push_back(make_tuple("초가스", "Void", "", "Bruiser", "", 1)); 
    champions.push_back(make_tuple("이렐리아", "Ionia", "", "Challenger", "", 1)); 
    champions.push_back(make_tuple("진", "Ionia", "", "Deadeye", "", 1)); 
    champions.push_back(make_tuple("케일", "Demacia", "", "Slayer", "", 1)); 
    champions.push_back(make_tuple("말자하", "Void", "", "Sorcerer", "", 1)); 
    champions.push_back(make_tuple("마오카이", "Shadow_Isles", "", "Bastion", "", 1));
    champions.push_back(make_tuple("뽀삐", "Demacia", "Yordle", "Bastion", "", 1));
    champions.push_back(make_tuple("오리아나", "Piltover", "", "Sorcerer", "", 1)); 
    champions.push_back(make_tuple("레넥톤", "Shurima", "", "Bruiser", "", 1)); 
    champions.push_back(make_tuple("사미라", "Noxus", "", "Challenger", "", 1));
    champions.push_back(make_tuple("트리스타나", "Yordle", "", "Gunner", "", 1)); 
    champions.push_back(make_tuple("비에고", "Shadow_Isles", "", "Rogue", "", 1)); 

    champions.push_back(make_tuple("애쉬", "Freljord", "", "Deadeye", "", 2)); 
    champions.push_back(make_tuple("갈리오", "Demacia", "", "Invoker", "", 2)); 
    champions.push_back(make_tuple("징크스", "Zaun", "", "Gunner", "", 2)); 
    champions.push_back(make_tuple("카사딘", "Void", "", "Bastion", "", 2));
    champions.push_back(make_tuple("클레드", "Noxus", "Yordle", "Slayer", "", 2)); 
    champions.push_back(make_tuple("소라카", "Targon", "", "Invoker", "", 2)); 
    champions.push_back(make_tuple("세트", "Ionia", "", "Juggernaut", "", 2)); 
    champions.push_back(make_tuple("스웨인", "Noxus", "", "Sorcerer", "Strategist", 2)); 
    champions.push_back(make_tuple("탈리야", "Shurima", "", "Multicaster", "", 2));
    champions.push_back(make_tuple("티모", "Yordle", "", "Multicaster", "Strategist", 2));
    champions.push_back(make_tuple("바이", "Piltover", "", "Bruiser", "", 2));
    champions.push_back(make_tuple("워윅", "Zaun", "", "Challenger", "Juggernaut", 2)); 
    champions.push_back(make_tuple("제드", "Ionia", "", "Rogue", "Slayer", 2)); 

    champions.push_back(make_tuple("아크샨", "Shurima", "", "Deadeye", "", 3));
    champions.push_back(make_tuple("다리우스", "Noxus", "", "Juggernaut", "", 3)); 
    champions.push_back(make_tuple("에코", "Piltover", "Zaun", "Rogue", "", 3)); 
    champions.push_back(make_tuple("가렌", "Demacia", "", "Juggernaut", "", 3)); 
    champions.push_back(make_tuple("제이스", "Piltover", "", "Gunner", "", 3)); 
    champions.push_back(make_tuple("칼리스타", "Shadow_Isles", "", "Challenger", "", 3));
    champions.push_back(make_tuple("카르마", "Ionia", "", "Invoker", "", 3)); 
    champions.push_back(make_tuple("카타리나", "Noxus", "", "Rogue", "", 3)); 
    champions.push_back(make_tuple("리산드라", "Freljord", "", "Invoker", "", 3)); 
    champions.push_back(make_tuple("렉사이", "Void", "", "Bruiser", "", 3)); 
    champions.push_back(make_tuple("소나", "Demacia", "", "Multicaster", "", 3)); 
    champions.push_back(make_tuple("타릭", "Targon", "", "Bastion", "Sorcerer", 3));
    champions.push_back(make_tuple("벨코즈", "Void", "", "Multicaster", "Sorcerer", 3));

    champions.push_back(make_tuple("아펠리오스", "Targon", "", "Deadeye", "", 4)); 
    champions.push_back(make_tuple("아지르", "Shurima", "", "Strategist", "", 4)); 
    champions.push_back(make_tuple("그웬", "Shadow_Isles", "", "Slayer", "", 4)); 
    champions.push_back(make_tuple("자르반", "Demacia", "", "Strategist", "", 4)); 
    champions.push_back(make_tuple("카이사", "Void", "", "Challenger", "", 4));
    champions.push_back(make_tuple("럭스", "Demacia", "", "Sorcerer", "", 4)); 
    champions.push_back(make_tuple("나서스", "Shurima", "", "Juggernaut", "", 4)); 
    champions.push_back(make_tuple("세주아니", "Freljord", "", "Bruiser", "", 4)); 
    champions.push_back(make_tuple("쉔", "Ionia", "", "Bastion", "Invoker", 4)); 
    champions.push_back(make_tuple("우르곳", "Zaun", "", "Deadeye", "", 4)); 
    champions.push_back(make_tuple("야스오", "Ionia", "", "Challenger", "", 4)); 
    champions.push_back(make_tuple("제리", "Zaun", "", "Gunner", "", 4)); 

    champions.push_back(make_tuple("아트록스", "Darkin", "", "Juggernaut", "Slayer", 5)); 
    champions.push_back(make_tuple("아리", "Ionia", "", "Sorcerer", "", 5)); 
    champions.push_back(make_tuple("하이머딩거", "Piltover", "Yordle", "Technogenius", "", 5)); 
    champions.push_back(make_tuple("크산테", "Shurima", "", "Bastion", "", 5)); 
    champions.push_back(make_tuple("라이즈", "Wanderer", "", "Invoker", "", 5)); 
    champions.push_back(make_tuple("세나", "Shadow_Isles", "", "Gunner", "Redeemer", 5)); 
    champions.push_back(make_tuple("사이온", "Noxus", "", "Bruiser", "", 5)); 
    champions.push_back(make_tuple("벨베즈", "Void", "", "Empress", "", 5)); 
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
    cout << "증강체나 특성의 고서로 부터 얻은 시너지를 적용합니다." << endl;
    cout << "특성을 한개 씩 나열해주세요" << endl;
    cout << "ex) 2그림자군도, 아이오니아" << endl;
    cout << " => \"2그림자군도\" 입력후 enter" << endl;
    cout << " => \"1아이오니아\" 입력후 enter" << endl;
    cout << " => \"END\"입력후 enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "다르킨") darkin += num;
        else if (traits == "데마시아") demacia += num;
        else if (traits == "프렐요드") freljord += num;
        else if (traits == "아이오니아") ionia += num;
        else if (traits == "녹서스") noxus += num;
        else if (traits == "필트오버") piltover += num;
        else if (traits == "그림자군도") shadow_Isles += num;
        else if (traits == "슈리마") shurima += num;
        else if (traits == "타곤") targon += num;
        else if (traits == "공허") vvoid += num;
        else if (traits == "방랑자") wanderer += num;
        else if (traits == "요들") yordle += num;
        else if (traits == "자운") zaun += num;
  
        // classes
        else if (traits == "요새") bastion += num;
        else if (traits == "난동꾼") bruiser += num;
        else if (traits == "도전자") challenger += num;
        else if (traits == "백발백중") deadeye += num;
        else if (traits == "여제") empress += num;
        else if (traits == "사수") gunner += num;
        else if (traits == "기원자") invoker += num;
        else if (traits == "전쟁기계") juggernaut += num;
        else if (traits == "연쇄마법사") multicaster += num;  
        else if (traits == "구원자") redeemer += num;
        else if (traits == "불한당") rogue += num;
        else if (traits == "학살자") slayer += num;
        else if (traits == "마법사") sorcerer += num;
        else if (traits == "전략가") strategist += num;
        else if (traits == "발명의대가") technogenius += num;
    }
    

}

// 선택이 완료된 조합의 시너지 점수를 계산하는 함수
int synerge_check(int index) {
    int synerge_count = 0;
    // 1 : 3
    // 2-3-4: 5 10 18
    // 2-4-6: 5 12 25
    // 2-4-6-8: 5 10 15 33
    // 3-5: 8 15
    // 3-5-7: 8 15 30
    // 3-5-7-9: 8 14 28 45
    // 3-6: 8 18
    // 3-6-8: 8 16 40
    // 3-6-9: 8 16 45


    // origin
    if (Demacia[index] >= 3 && Demacia[index] < 5) synerge_count += 8;
    else if (Demacia[index] >= 5 && Demacia[index] < 7) synerge_count += 14;  
    else if (Demacia[index] >= 7 && Demacia[index] < 9) synerge_count += 28;  
    else if (Demacia[index] >= 9) synerge_count += 45;

    if (Darkin[index] == 1) synerge_count += 3;
  
    if (Freljord[index] >= 2 && Freljord[index] < 3) synerge_count += 5;
    else if (Freljord[index] >= 3 && Freljord[index] < 4) synerge_count += 10;  
    else if (Freljord[index] >= 4) synerge_count += 18;

    if (Ionia[index] >= 3 && Ionia[index] < 6) synerge_count += 8; 
    else if (Ionia[index] >= 6 && Ionia[index] < 9) synerge_count += 16; 
    else if (Ionia[index] >= 9) synerge_count += 45;

    if (Noxus[index] >= 3 && Noxus[index] < 6) synerge_count += 8; 
    else if (Noxus[index] >= 6 && Noxus[index] < 9) synerge_count += 16; 
    else if (Noxus[index] >= 9) synerge_count += 45;
    
    if (Piltover[index] >= 3 && Piltover[index] < 6) synerge_count += 8;
    else if (Piltover[index] >= 6) synerge_count += 18; 

    if (Shadow_Isles[index] >= 2 && Shadow_Isles[index] < 4) synerge_count += 5;
    else if (Shadow_Isles[index] >= 4 && Shadow_Isles[index] < 4) synerge_count += 12;
    else if (Shadow_Isles[index] >= 6) synerge_count += 25;  

    if (Shurima[index] >= 3 && Shurima[index] < 5) synerge_count += 8; 
    else if (Shurima[index] >= 5 && Shurima[index] < 7) synerge_count += 14; 
    else if (Shurima[index] >= 7 && Shurima[index] < 9) synerge_count += 28; 
    else if (Shurima[index] >= 9) synerge_count += 45;

    if (Targon[index] >= 2 && Targon[index] < 3) synerge_count += 5;
    else if (Targon[index] >= 3 && Targon[index] < 4) synerge_count += 10;
    else if (Targon[index] >= 4) synerge_count += 20;  

    if (Void[index] >= 3 && Void[index] < 6) synerge_count += 8;
    else if (Void[index] >= 6 && Void[index] < 8) synerge_count += 16; 
    else if (Void[index] >= 8) synerge_count += 40;

    if (Wanderer[index] == 1) synerge_count += 3;

    if (Yordle[index] >= 3 && Yordle[index] < 5) synerge_count += 8;
    else if (Yordle[index] >= 5) synerge_count += 15;

    if (Zaun[index] >= 2 && Zaun[index] < 4) synerge_count += 5;
    else if (Zaun[index] >= 4 && Zaun[index] < 6) synerge_count += 12;
    else if (Zaun[index] >= 6) synerge_count += 25;



    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge_count += 5;
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge_count += 10;
    else if (Bastion[index] >= 6 && Bastion[index] < 8) synerge_count += 15;
    else if (Bastion[index] >= 8) synerge_count += 33;

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 5;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 12;
    else if (Bruiser[index] >= 6) synerge_count += 25;

    if (Challenger[index] >= 2 && Challenger[index] < 4) synerge_count += 5;
    else if (Challenger[index] >= 4 && Challenger[index] < 6) synerge_count += 10;
    else if (Challenger[index] >= 6 && Challenger[index] < 8) synerge_count += 15;
    else if (Challenger[index] >= 8) synerge_count += 33;

    if (Deadeye[index] >= 2 && Deadeye[index] < 4) synerge_count += 5;
    else if (Deadeye[index] >= 4 && Deadeye[index] < 6) synerge_count += 12;
    else if (Deadeye[index] >= 6) synerge_count += 25;

    if (Empress[index] == 1 ) synerge_count += 3;

    if (Gunner[index] >= 2 && Gunner[index] < 4) synerge_count += 5;
    else if (Gunner[index] >= 4 && Gunner[index] < 6) synerge_count += 12;
    else if (Gunner[index] >= 6) synerge_count += 25; 

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge_count += 5;
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge_count += 12;
    else if (Invoker[index] >= 6) synerge_count += 25; 

    if (Juggernaut[index] >= 2 && Juggernaut[index] < 4) synerge_count += 5;
    else if (Juggernaut[index] >= 4 && Juggernaut[index] < 6) synerge_count += 12;
    else if (Juggernaut[index] >= 6) synerge_count += 25;  

    if (Multicaster[index] >= 2 && Multicaster[index] < 4) synerge_count += 5;
    else if (Multicaster[index] >= 4) synerge_count += 12;  

    if (Redeemer[index] == 1) synerge_count += 3;  

    if (Rogue[index] >= 2 && Rogue[index] < 4) synerge_count += 10;
    else if (Rogue[index] >= 4) synerge_count += 20;

    if (Slayer[index] >= 2 && Slayer[index] < 3) synerge_count += 5;
    else if (Slayer[index] >= 3 && Slayer[index] < 4) synerge_count += 10;
    else if (Slayer[index] >= 4 && Slayer[index] < 5) synerge_count += 15;
    else if (Slayer[index] >= 5 && Slayer[index] < 6) synerge_count += 25;
    else if (Slayer[index] >= 6) synerge_count += 30;

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge_count += 5;
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge_count += 10;
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge_count += 15;
    else if (Sorcerer[index] >= 8) synerge_count += 33;   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge_count += 5;
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge_count += 10;
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge_count += 15;
    else if (Strategist[index] >= 5) synerge_count += 27; 

    if (Technogenius[index] == 1) synerge_count += 3; 

    return synerge_count;
}

// 선택이 완료된 조합의 시너지를 계산하는 함수
void synerge_add(tuple <string, string, string, string, string, int> &champion, int index) {
    string origin1 = get<1>(champion);
    string origin2 = get<2>(champion);
    string classes1 = get<3>(champion);
    string classes2 = get<4>(champion);

    // origin1
    if (origin1 == "Darkin") Darkin[index]++;
    else if (origin1 == "Demacia") Demacia[index]++;
    else if (origin1 == "Freljord") Freljord[index]++;
    else if (origin1 == "Ionia") Ionia[index]++;
    else if (origin1 == "Noxus") Noxus[index]++;
    else if (origin1 == "Piltover") Piltover[index]++;
    else if (origin1 == "Shadow_Isles") Shadow_Isles[index]++;
    else if (origin1 == "Shurima") Shurima[index]++;
    else if (origin1 == "Targon") Targon[index]++;
    else if (origin1 == "Void") Void[index]++;
    else if (origin1 == "Wanderer") Wanderer[index]++;
    else if (origin1 == "Yordle") Yordle[index]++;
    else if (origin1 == "Zaun") Zaun[index]++;
    

    // origin2
    if (origin2 == "Darkin") Darkin[index]++;
    else if (origin2 == "Demacia") Demacia[index]++;
    else if (origin2 == "Freljord") Freljord[index]++;
    else if (origin2 == "Ionia") Ionia[index]++;
    else if (origin2 == "Noxus") Noxus[index]++;
    else if (origin2 == "Piltover") Piltover[index]++;
    else if (origin2 == "Shadow_Isles") Shadow_Isles[index]++;
    else if (origin2 == "Shurima") Shurima[index]++;
    else if (origin2 == "Targon") Targon[index]++;
    else if (origin2 == "Void") Void[index]++;
    else if (origin2 == "Wanderer") Wanderer[index]++;
    else if (origin2 == "Yordle") Yordle[index]++;
    else if (origin2 == "Zaun") Zaun[index]++;


    // classes1
    if (classes1 == "Bastion") Bastion[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "Challenger") Challenger[index]++;
    else if (classes1 == "Deadeye") Deadeye[index]++;
    else if (classes1 == "Empress") Empress[index]++;
    else if (classes1 == "Gunner") Gunner[index]++;
    else if (classes1 == "Invoker") Invoker[index]++;
    else if (classes1 == "Juggernaut") Juggernaut[index]++;
    else if (classes1 == "Multicaster") Multicaster[index]++;  
    else if (classes1 == "Redeemer") Redeemer[index]++;
    else if (classes1 == "Rogue") Rogue[index]++;
    else if (classes1 == "Slayer") Slayer[index]++;
    else if (classes1 == "Sorcerer") Sorcerer[index]++;
    else if (classes1 == "Strategist") Strategist[index]++;
    else if (classes1 == "Technogenius") Technogenius[index]++;


    // classes2, 특성이 2개 있는 챔피언들 처리
    if (classes2 == "Bastion") Bastion[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "Challenger") Challenger[index]++;
    else if (classes2 == "Deadeye") Deadeye[index]++;
    else if (classes2 == "Empress") Empress[index]++;
    else if (classes2 == "Gunner") Gunner[index]++;
    else if (classes2 == "Invoker") Invoker[index]++;
    else if (classes2 == "Juggernaut") Juggernaut[index]++;
    else if (classes2 == "Multicaster") Multicaster[index]++;  
    else if (classes2 == "Redeemer") Redeemer[index]++;
    else if (classes2 == "Rogue") Rogue[index]++;
    else if (classes2 == "Slayer") Slayer[index]++;
    else if (classes2 == "Sorcerer") Sorcerer[index]++;
    else if (classes2 == "Strategist") Strategist[index]++;
    else if (classes2 == "Technogenius") Technogenius[index]++;



}


int twostar_champion_cost(tuple <string, string, string, string, string, int> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    // origin
    if (Demacia[index] >= 3 && Demacia[index] < 5) synerge.append("3데마시아 ");  
    else if (Demacia[index] >= 5 && Demacia[index] < 7) synerge.append("5데마시아 ");  
    else if (Demacia[index] >= 7 && Demacia[index] < 9) synerge.append("7데마시아 ");  
    else if (Demacia[index] >= 9) synerge.append("9데마시아 ");

    if (Darkin[index] == 1) synerge.append("1다르킨 ");
  
    if (Freljord[index] >= 2 && Freljord[index] < 3) synerge.append("2프렐요드 ");
    else if (Freljord[index] >= 3 && Freljord[index] < 4) synerge.append("3프렐요드 ");  
    else if (Freljord[index] >= 4) synerge.append("4프렐요드 ");

    if (Ionia[index] >= 3 && Ionia[index] < 6) synerge.append("3아이오니아 "); 
    else if (Ionia[index] >= 6 && Ionia[index] < 9) synerge.append("6아이오니아 "); 
    else if (Ionia[index] >= 9) synerge.append("9아이오니아 ");

    if (Noxus[index] >= 3 && Noxus[index] < 6) synerge.append("3녹서스 "); 
    else if (Noxus[index] >= 6 && Noxus[index] < 9) synerge.append("6녹서스 "); 
    else if (Noxus[index] >= 9) synerge.append("9녹서스 ");
    
    if (Piltover[index] >= 3 && Piltover[index] < 6) synerge.append("3필트오버 ");
    else if (Piltover[index] >= 6) synerge.append("6필트오버 "); 

    if (Shadow_Isles[index] >= 2 && Shadow_Isles[index] < 4) synerge.append("2그림자군도 ");
    else if (Shadow_Isles[index] >= 4 && Shadow_Isles[index] < 4) synerge.append("4그림자군도 ");
    else if (Shadow_Isles[index] >= 6) synerge.append("6그림자군도 ");  

    if (Shurima[index] >= 3 && Shurima[index] < 5) synerge.append("3슈리마 "); 
    else if (Shurima[index] >= 5 && Shurima[index] < 7) synerge.append("5슈리마 "); 
    else if (Shurima[index] >= 7 && Shurima[index] < 9) synerge.append("7슈리마 "); 
    else if (Shurima[index] >= 9) synerge.append("9슈리마 ");

    if (Targon[index] >= 2 && Targon[index] < 3) synerge.append("2타곤 ");
    else if (Targon[index] >= 3 && Targon[index] < 4) synerge.append("3타곤 ");
    else if (Targon[index] >= 4) synerge.append("4타곤 ");  

    if (Void[index] >= 3 && Void[index] < 6) synerge.append("3공허 ");
    else if (Void[index] >= 6 && Void[index] < 8) synerge.append("6공허 "); 
    else if (Void[index] >= 8) synerge.append("8공허 ");

    if (Wanderer[index] == 1) synerge.append("1방랑자 ");

    if (Yordle[index] >= 3 && Yordle[index] < 5) synerge.append("3요들 ");
    else if (Yordle[index] >= 5) synerge.append("5요들 ");

    if (Zaun[index] >= 2 && Zaun[index] < 4) synerge.append("2자운 ");
    else if (Zaun[index] >= 4 && Zaun[index] < 6) synerge.append("4자운 ");
    else if (Zaun[index] >= 6) synerge.append("6자운 ");



    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge.append("2요새 ");
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge.append("4요새 ");
    else if (Bastion[index] >= 6 && Bastion[index] < 8) synerge.append("6요새 ");
    else if (Bastion[index] >= 8) synerge.append("8요새 ");

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2난동꾼 ");
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4난동꾼 ");
    else if (Bruiser[index] >= 6) synerge.append("6난동꾼 ");

    if (Challenger[index] >= 2 && Challenger[index] < 4) synerge.append("2도전자 ");
    else if (Challenger[index] >= 4 && Challenger[index] < 6) synerge.append("4도전자 ");
    else if (Challenger[index] >= 6 && Challenger[index] < 8) synerge.append("6도전자 ");
    else if (Challenger[index] >= 8) synerge.append("8도전자 ");

    if (Deadeye[index] >= 2 && Deadeye[index] < 4) synerge.append("2백발백중 ");
    else if (Deadeye[index] >= 4 && Deadeye[index] < 6) synerge.append("4백발백중 ");
    else if (Deadeye[index] >= 6) synerge.append("6백발백중 ");

    if (Empress[index] == 1 ) synerge.append("1여제 ");

    if (Gunner[index] >= 2 && Gunner[index] < 4) synerge.append("2사수 ");
    else if (Gunner[index] >= 4 && Gunner[index] < 6) synerge.append("4사수 ");
    else if (Gunner[index] >= 6) synerge.append("6사수 "); 

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge.append("2기원자 ");
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge.append("4기원자 ");
    else if (Invoker[index] >= 6) synerge.append("6기원자 "); 

    if (Juggernaut[index] >= 2 && Juggernaut[index] < 4) synerge.append("2전쟁기계 ");
    else if (Juggernaut[index] >= 4 && Juggernaut[index] < 6) synerge.append("4전쟁기계 ");
    else if (Juggernaut[index] >= 6) synerge.append("6전쟁기계 ");  

    if (Multicaster[index] >= 2 && Multicaster[index] < 4) synerge.append("2연쇄마법사 ");
    else if (Multicaster[index] >= 4) synerge.append("4연쇄마법사 ");  

    if (Redeemer[index] == 1) synerge.append("1구원자 ");  

    if (Rogue[index] >= 2 && Rogue[index] < 4) synerge.append("2불한당 ");
    else if (Rogue[index] >= 4) synerge.append("4불한당 ");

    if (Slayer[index] >= 2 && Slayer[index] < 3) synerge.append("2학살자 ");
    else if (Slayer[index] >= 3 && Slayer[index] < 4) synerge.append("3학살자 ");
    else if (Slayer[index] >= 4 && Slayer[index] < 5) synerge.append("4학살자 ");
    else if (Slayer[index] >= 5 && Slayer[index] < 6) synerge.append("5학살자 ");
    else if (Slayer[index] >= 6) synerge.append("6학살자 ");

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge.append("2마법사 ");
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge.append("4마법사 ");
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge.append("6마법사 ");
    else if (Sorcerer[index] >= 8) synerge.append("8마법사 ");   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge.append("2책략가 ");
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge.append("3책략가 ");
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge.append("4책략가 ");
    else if (Strategist[index] >= 5) synerge.append("5책략가 "); 

    if (Technogenius[index] == 1) synerge.append("1발명의대가 "); 

    return synerge;
}


vector <int> pick[59];

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
