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
int Mixmaster[59];
int _8Bits[59];
int Disco[59];
int Heartsteel[59];
int True_Damage[59];
int EDM[59];
int EMO[59];
int Country[59];
int Jazz[59];
int Pentakill[59];
int ILLBEATS[59];
int Punk[59];
int Hyperpop[59];

// new
int KDA[59];
int Maestro[59];
int Wildcard[59];


// classes1
int Sentinel[59];
int Bruiser[59];
int Rapidfire[59];
int BigShot[59];
int Mosher[59];
int Executioner[59];
int CrowdDiver[59];
int Dazzler[59];
int Guardian[59];
int Edgelord[59];
int Spellweaver[59];
int Superfan[59];
int Breakout[59];


// fix synerge
int mixmaster;
int _8bits;
int disco;
int heartsteel;
int true_Damage;
int eDM;
int eMO;
int country;
int jazz;
int pentakill;
int iLLBEATS;
int punk;
int hyperpop;
int sentinel;
int bruiser;
int rapidfire;
int bigShot;
int mosher;
int executioner;
int crowdDiver;
int dazzler;
int guardian;
int edgelord;
int spellweaver;
int superfan;
int breakout;
int kDA;
int maestro;
int wildcard;



// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {

    // origins
    Mixmaster[index] = mixmaster;
    _8Bits[index] = _8bits;
    Disco[index] = disco;
    Heartsteel[index] = heartsteel;
    True_Damage[index] = true_Damage;
    EDM[index] = eDM;
    EMO[index] = eMO;
    Country[index] = country;
    Jazz[index] = jazz;
    Pentakill[index] = pentakill;
    ILLBEATS[index] = iLLBEATS;
    Punk[index] = punk;
    Hyperpop[index] = hyperpop;
    KDA[index] = kDA;
    Maestro[index] = maestro;
    Wildcard[index] = wildcard;

    // classes
    Sentinel[index] = sentinel;
    Bruiser[index] = bruiser;
    BigShot[index] = bigShot;
    Rapidfire[index] = rapidfire;
    Mosher[index] = mosher;
    Executioner[index] = executioner;
    CrowdDiver[index] = crowdDiver;
    Dazzler[index] = dazzler;
    Guardian[index] = guardian;
    Edgelord[index] = edgelord;
    Spellweaver[index] = spellweaver;
    Superfan[index] = superfan;
    Breakout[index] = breakout;

}

void champions_info() {
    champions.push_back(make_tuple("나미", "Disco", "", "Dazzler", "", 1)); 
    champions.push_back(make_tuple("릴리아", "KDA", "", "Sentinel", "Superfan", 1)); 
    champions.push_back(make_tuple("바이", "Punk", "", "Mosher", "", 1)); 
    champions.push_back(make_tuple("애니", "EMO", "", "Spellweaver", "", 1)); 
    champions.push_back(make_tuple("야스오", "True_Damage", "", "Edgelord", "", 1)); 
    champions.push_back(make_tuple("올라프", "Pentakill", "", "Bruiser", "", 1)); 
    champions.push_back(make_tuple("이블린", "KDA", "", "CrowdDiver", "", 1)); 
    champions.push_back(make_tuple("징크스", "Punk", "", "Rapidfire", "", 1));
    champions.push_back(make_tuple("케넨", "True_Damage", "", "Sentinel", "Superfan", 1));
    champions.push_back(make_tuple("코르키", "_8Bits", "", "BigShot", "", 1)); 
    champions.push_back(make_tuple("크산테", "Heartsteel", "", "Sentinel", "", 1)); 
    champions.push_back(make_tuple("타릭", "Disco", "", "Guardian", "", 1));
    champions.push_back(make_tuple("탐켄치", "Country", "", "Bruiser", "", 1)); 

    champions.push_back(make_tuple("가렌", "_8Bits", "", "Sentinel", "", 2)); 
    champions.push_back(make_tuple("그라가스", "Disco", "", "Bruiser", "Spellweaver", 2)); 
    champions.push_back(make_tuple("나르", "Pentakill", "", "Superfan", "Mosher", 2)); 
    champions.push_back(make_tuple("바드", "Jazz", "", "Dazzler", "", 2));
    champions.push_back(make_tuple("세나", "True_Damage", "", "Rapidfire", "", 2)); 
    champions.push_back(make_tuple("세라핀", "KDA", "", "Spellweaver", "", 2)); 
    champions.push_back(make_tuple("아펠리오스", "Heartsteel", "", "Rapidfire", "", 2)); 
    champions.push_back(make_tuple("잭스", "EDM", "", "Mosher", "", 2)); 
    champions.push_back(make_tuple("카이사", "KDA", "", "BigShot", "", 2));
    champions.push_back(make_tuple("카타리나", "Country", "", "CrowdDiver", "", 2));
    champions.push_back(make_tuple("케일", "Pentakill", "", "Edgelord", "", 2));
    champions.push_back(make_tuple("트위치", "Punk", "", "Executioner", "", 2)); 
    champions.push_back(make_tuple("판테온", "Punk", "", "Guardian", "", 2)); 

    champions.push_back(make_tuple("니코", "KDA", "", "Guardian", "Superfan", 3));
    champions.push_back(make_tuple("럭스", "EDM", "", "Dazzler", "", 3)); 
    champions.push_back(make_tuple("룰루", "Hyperpop", "", "Spellweaver", "", 3)); 
    champions.push_back(make_tuple("리븐", "_8Bits", "", "Edgelord", "", 3)); 
    champions.push_back(make_tuple("모데카이저", "Country", "", "Sentinel", "", 3)); 
    champions.push_back(make_tuple("미스포춘", "Jazz", "", "BigShot", "", 3));
    champions.push_back(make_tuple("벡스", "EMO", "", "Executioner", "", 3)); 
    champions.push_back(make_tuple("사미라", "Country", "", "Executioner", "", 3)); 
    champions.push_back(make_tuple("세트", "Heartsteel", "", "Bruiser", "Mosher", 3)); 
    champions.push_back(make_tuple("아무무", "EMO", "", "Guardian", "", 3)); 
    champions.push_back(make_tuple("에코", "True_Damage", "", "Sentinel", "Spellweaver", 3)); 
    champions.push_back(make_tuple("요네", "Heartsteel", "", "CrowdDiver", "Edgelord", 3));
    champions.push_back(make_tuple("우르곳", "Country", "", "Mosher", "", 3));

    champions.push_back(make_tuple("블리츠크랭크", "Disco", "", "Sentinel", "", 4)); 
    champions.push_back(make_tuple("비에고", "Pentakill", "", "Edgelord", "", 4)); 
    champions.push_back(make_tuple("뽀삐", "EMO", "", "Mosher", "", 4)); 
    champions.push_back(make_tuple("쓰레쉬", "Country", "", "Guardian", "", 4)); 
    champions.push_back(make_tuple("아리", "KDA", "", "Spellweaver", "", 4));
    champions.push_back(make_tuple("아칼리T", "True_Damage", "", "Breakout", "Executioner", 4)); 
    champions.push_back(make_tuple("아칼리K", "KDA", "", "Breakout", "Executioner", 4)); 
    champions.push_back(make_tuple("이즈리얼", "Heartsteel", "", "BigShot", "", 4)); 
    champions.push_back(make_tuple("자크", "EDM", "", "Bruiser", "", 4)); 
    champions.push_back(make_tuple("제드", "EDM", "", "CrowdDiver", "", 4)); 
    champions.push_back(make_tuple("카서스", "Pentakill", "", "Executioner", "", 4)); 
    champions.push_back(make_tuple("케이틀린", "_8Bits", "", "Rapidfire", "", 4)); 
    champions.push_back(make_tuple("트페", "Disco", "", "Dazzler", "", 4)); 

    champions.push_back(make_tuple("루시안", "Jazz", "", "Rapidfire", "", 5)); 
    champions.push_back(make_tuple("소나", "Mixmaster", "", "Spellweaver", "", 5)); 
    champions.push_back(make_tuple("요릭", "Pentakill", "", "Guardian", "Mosher", 5)); 
    champions.push_back(make_tuple("일라오이", "ILLBEATS", "", "Bruiser", "", 5)); 
    champions.push_back(make_tuple("직스", "Hyperpop", "", "Dazzler", "", 5)); 
    champions.push_back(make_tuple("진", "Maestro", "", "BigShot", "", 5)); 
    champions.push_back(make_tuple("케인", "Heartsteel", "Wildcard", "Edgelord", "", 5)); 
    champions.push_back(make_tuple("키아나", "True_Damage", "", "CrowdDiver", "", 5)); 
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
    cout << "ex) 2믹스마스터, 디스코" << endl;
    cout << " => \"2믹스마스터\" 입력후 enter" << endl;
    cout << " => \"1디스코\" 입력후 enter" << endl;
    cout << " => \"END\"입력후 enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "믹스마스터") mixmaster += num;
        else if (traits == "8비트") _8bits += num;
        else if (traits == "디스코") disco += num;
        else if (traits == "Heartsteel") heartsteel += num;
        else if (traits == "TrueDamage") true_Damage += num;
        else if (traits == "EDM") eDM += num;
        else if (traits == "이모코어") eMO += num;
        else if (traits == "컨트리") country += num;
        else if (traits == "재즈") jazz += num;
        else if (traits == "펜타킬") pentakill += num;
        else if (traits == "일류비트") iLLBEATS += num;
        else if (traits == "펑크") punk += num;
        else if (traits == "하이퍼팝") hyperpop += num;
        else if (traits == "KDA") kDA += num;
        else if (traits == "마에스트로") maestro += num;
        else if (traits == "와일드카드") wildcard += num;
  
        // classes
        else if (traits == "감시자") sentinel += num;
        else if (traits == "난동꾼") bruiser += num;
        else if (traits == "속사포") rapidfire += num;
        else if (traits == "거물") bigShot += num;
        else if (traits == "춤꾼") mosher += num;
        else if (traits == "처형자") executioner += num;
        else if (traits == "스테이지다이버") crowdDiver += num;
        else if (traits == "현혹술사") dazzler += num;  
        else if (traits == "수호자") guardian += num;
        else if (traits == "이단아") edgelord += num;
        else if (traits == "주문술사") spellweaver += num;
        else if (traits == "열혈팬") superfan += num;
        else if (traits == "빅히트") breakout += num;
    }
    

}

// 선택이 완료된 조합의 시너지 점수를 계산하는 함수
int synerge_check(int index) {
    int synerge_count = 0;
    // 1 : 1-2
    // 1-2-3-4 : 2 4 11 17
    // 2-3-4-5: 5 10 15 22
    // 2-4-6: 5 12 25-30
    // 2-4-6-8: 5 10 15 33
    // 2-4-6-9: 5 12 25 43
    // 3-4-5-6: 8 13 18 25
    // 3-5: 8 15
    // 3-5-7: 8 15 30-33
    // 3-5-7-9: 8 15 28 45
    // 3-5-7-10: 8 15 30 45
    // 3-6: 8 18
    // 3-6-8: 8 16 40
    // 3-6-9: 8 16 45


    // origin
    if (_8Bits[index] >= 2 && _8Bits[index] < 4) synerge_count += 5;
    else if (_8Bits[index] >= 4 && _8Bits[index] < 6) synerge_count += 12;  
    else if (_8Bits[index] >= 6) synerge_count += 30;

    if (EDM[index] >= 2 && EDM[index] < 3) synerge_count += 5;
    else if (EDM[index] >= 3 && EDM[index] < 4) synerge_count += 10;
    else if (EDM[index] >= 4 && EDM[index] < 5) synerge_count += 15;
    else if (EDM[index] >= 5) synerge_count += 22; 

    if (Heartsteel[index] >= 3 && Heartsteel[index] < 5) synerge_count += 8; 
    else if (Heartsteel[index] >= 5 && Heartsteel[index] < 7) synerge_count += 14; 
    else if (Heartsteel[index] >= 7 && Heartsteel[index] < 10) synerge_count += 30; 
    else if (Heartsteel[index] >= 10) synerge_count += 45;

    if (KDA[index] >= 3 && KDA[index] < 5) synerge_count += 8; 
    else if (KDA[index] >= 5 && KDA[index] < 7) synerge_count += 14; 
    else if (KDA[index] >= 7 && KDA[index] < 10) synerge_count += 30; 
    else if (KDA[index] >= 10) synerge_count += 45;

    if (True_Damage[index] >= 2 && True_Damage[index] < 4) synerge_count += 5; 
    else if (True_Damage[index] >= 4 && True_Damage[index] < 6) synerge_count += 12; 
    else if (True_Damage[index] >= 6 && True_Damage[index] < 9) synerge_count += 25; 
    else if (True_Damage[index] >= 9) synerge_count += 43;
    
    if (Disco[index] >= 3 && Disco[index] < 4) synerge_count += 8;
    else if (Disco[index] >= 4 && Disco[index] < 5) synerge_count += 13;
    else if (Disco[index] >= 5 && Disco[index] < 6) synerge_count += 18;
    else if (Disco[index] >= 6) synerge_count += 25;

    if (Maestro[index] == 1) synerge_count += 1;  
    if (Mixmaster[index] == 1) synerge_count += 1;  
    if (Wildcard[index] == 1) synerge_count += 1;
  
    if (EMO[index] >= 2 && EMO[index] < 4) synerge_count += 5;
    else if (EMO[index] >= 4 && EMO[index] < 6) synerge_count += 12;
    else if (EMO[index] >= 6) synerge_count += 27;  

    if (ILLBEATS[index] == 1) synerge_count += 2;
    
    if (Jazz[index] >= 2 && Jazz[index] < 3) synerge_count += 5;
    else if (Jazz[index] >= 3 && Jazz[index] < 4) synerge_count += 10;
    else if (Jazz[index] >= 4) synerge_count += 15;  

    if (Country[index] >= 3 && Country[index] < 5) synerge_count += 8; 
    else if (Country[index] >= 5 && Country[index] < 7) synerge_count += 15; 
    else if (Country[index] >= 7) synerge_count += 33;

    if (Punk[index] >= 2 && Punk[index] < 4) synerge_count += 5;
    else if (Punk[index] >= 4 && Punk[index] < 6) synerge_count += 12;
    else if (Punk[index] >= 6) synerge_count += 27;

    if (Pentakill[index] >= 3 && Pentakill[index] < 5) synerge_count += 8;
    else if (Pentakill[index] >= 5 && Pentakill[index] < 7) synerge_count += 15; 
    else if (Pentakill[index] >= 7 && Pentakill[index] < 10) synerge_count += 30; 
    else if (Pentakill[index] >= 10) synerge_count += 45;

    if (Hyperpop[index] >= 1 && Hyperpop[index] < 2) synerge_count += 2;
    else if (Hyperpop[index] >= 2 && Hyperpop[index] < 3) synerge_count += 4;
    else if (Hyperpop[index] >= 3 && Hyperpop[index] < 4) synerge_count += 11;
    else if (Hyperpop[index] >= 4) synerge_count += 17;


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

    // classes
    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge_count += 5;
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge_count += 10;
    else if (Sentinel[index] >= 6 && Sentinel[index] < 8) synerge_count += 15;
    else if (Sentinel[index] >= 8) synerge_count += 35;

    if (BigShot[index] >= 2 && BigShot[index] < 4) synerge_count += 2;
    else if (BigShot[index] >= 4 && BigShot[index] < 6) synerge_count += 10;
    else if (BigShot[index] >= 6) synerge_count += 26;

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 5;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 12;
    else if (Bruiser[index] >= 6) synerge_count += 25;

    if (Breakout[index] == 1) synerge_count += 1;

    if (Rapidfire[index] >= 2 && Rapidfire[index] < 4) synerge_count += 5;
    else if (Rapidfire[index] >= 4 && Rapidfire[index] < 6) synerge_count += 12;
    else if (Rapidfire[index] >= 6) synerge_count += 27;

    if (Guardian[index] >= 2 && Guardian[index] < 4) synerge_count += 5;
    else if (Guardian[index] >= 4 && Guardian[index] < 6) synerge_count += 12;
    else if (Guardian[index] >= 6) synerge_count += 25;

    if (CrowdDiver[index] >= 2 && CrowdDiver[index] < 4) synerge_count += 2;
    else if (CrowdDiver[index] >= 4 && CrowdDiver[index] < 6) synerge_count += 10;
    else if (CrowdDiver[index] >= 6) synerge_count += 27;  

    if (Superfan[index] >= 3 && Superfan[index] < 4) synerge_count += 8;
    else if (Superfan[index] >= 4 && Superfan[index] < 5) synerge_count += 11;
    else if (Superfan[index] >= 5) synerge_count += 19; 

    if (Edgelord[index] >= 3 && Edgelord[index] < 5) synerge_count += 8;
    else if (Edgelord[index] >= 5 && Edgelord[index] < 7) synerge_count += 15;
    else if (Edgelord[index] >= 7) synerge_count += 31;

    if (Spellweaver[index] >= 3 && Spellweaver[index] < 5) synerge_count += 8;
    else if (Spellweaver[index] >= 5 && Spellweaver[index] < 7) synerge_count += 15;
    else if (Spellweaver[index] >= 7 && Spellweaver[index] < 10) synerge_count += 30;
    else if (Spellweaver[index] >= 10) synerge_count += 45;   

    if (Executioner[index] >= 2 && Executioner[index] < 3) synerge_count += 5;
    else if (Executioner[index] >= 4 && Executioner[index] < 6) synerge_count += 12;
    else if (Executioner[index] >= 6) synerge_count += 25; 

    if (Mosher[index] >= 2 && Mosher[index] < 4) synerge_count += 5;
    else if (Mosher[index] >= 4 && Mosher[index] < 6) synerge_count += 12;
    else if (Mosher[index] >= 6) synerge_count += 25; 

    if (Dazzler[index] >= 2 && Dazzler[index] < 4) synerge_count += 5;
    else if (Dazzler[index] >= 4 && Dazzler[index] < 6) synerge_count += 12;
    else if (Dazzler[index] >= 6) synerge_count += 27; 

    return synerge_count;
}

// 선택이 완료된 조합의 시너지를 계산하는 함수
void synerge_add(tuple <string, string, string, string, string, int> &champion, int index) {
    string origin1 = get<1>(champion);
    string origin2 = get<2>(champion);
    string classes1 = get<3>(champion);
    string classes2 = get<4>(champion);

    // origin1
    if (origin1 == "Mixmaster") Mixmaster[index]++;
    else if (origin1 == "_8Bits") _8Bits[index]++;
    else if (origin1 == "Disco") Disco[index]++;
    else if (origin1 == "Heartsteel") Heartsteel[index]++;
    else if (origin1 == "True_Damage") True_Damage[index]++;
    else if (origin1 == "EDM") EDM[index]++;
    else if (origin1 == "EMO") EMO[index]++;
    else if (origin1 == "Country") Country[index]++;
    else if (origin1 == "Jazz") Jazz[index]++;
    else if (origin1 == "Pentakill") Pentakill[index]++;
    else if (origin1 == "ILLBEATS") ILLBEATS[index]++;
    else if (origin1 == "Punk") Punk[index]++;
    else if (origin1 == "Hyperpop") Hyperpop[index]++;
    else if (origin1 == "KDA") KDA[index]++;
    else if (origin1 == "Maestro") Maestro[index]++;
    else if (origin1 == "Wildcard") Wildcard[index]++;
    
    // origin2
    if (origin2 == "Mixmaster") Mixmaster[index]++;
    else if (origin2 == "_8Bits") _8Bits[index]++;
    else if (origin2 == "Disco") Disco[index]++;
    else if (origin2 == "Heartsteel") Heartsteel[index]++;
    else if (origin2 == "True_Damage") True_Damage[index]++;
    else if (origin2 == "EDM") EDM[index]++;
    else if (origin2 == "EMO") EMO[index]++;
    else if (origin2 == "Country") Country[index]++;
    else if (origin2 == "Jazz") Jazz[index]++;
    else if (origin2 == "Pentakill") Pentakill[index]++;
    else if (origin2 == "ILLBEATS") ILLBEATS[index]++;
    else if (origin2 == "Punk") Punk[index]++;
    else if (origin2 == "Hyperpop") Hyperpop[index]++;
    else if (origin2 == "KDA") KDA[index]++;
    else if (origin2 == "Maestro") Maestro[index]++;
    else if (origin2 == "Wildcard") Wildcard[index]++;


    // classes1
    if (classes1 == "Sentinel") Sentinel[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "Rapidfire") Rapidfire[index]++;
    else if (classes1 == "BigShot") BigShot[index]++;
    else if (classes1 == "Mosher") Mosher[index]++;
    else if (classes1 == "Executioner") Executioner[index]++;
    else if (classes1 == "CrowdDiver") CrowdDiver[index]++;
    else if (classes1 == "Dazzler") Dazzler[index]++;  
    else if (classes1 == "Guardian") Guardian[index]++;
    else if (classes1 == "Edgelord") Edgelord[index]++;
    else if (classes1 == "Spellweaver") Spellweaver[index]++;
    else if (classes1 == "Superfan") Superfan[index]++;
    else if (classes1 == "Breakout") Breakout[index]++;


    // classes2, 특성이 2개 있는 챔피언들 처리
    if (classes2 == "Sentinel") Sentinel[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "Rapidfire") Rapidfire[index]++;
    else if (classes2 == "BigShot") BigShot[index]++;
    else if (classes2 == "Mosher") Mosher[index]++;
    else if (classes2 == "Executioner") Executioner[index]++;
    else if (classes2 == "CrowdDiver") CrowdDiver[index]++;
    else if (classes2 == "Dazzler") Dazzler[index]++;  
    else if (classes2 == "Guardian") Guardian[index]++;
    else if (classes2 == "Edgelord") Edgelord[index]++;
    else if (classes2 == "Spellweaver") Spellweaver[index]++;
    else if (classes2 == "Superfan") Superfan[index]++;
    else if (classes2 == "Breakout") Breakout[index]++;

}


int twostar_champion_cost(tuple <string, string, string, string, string, int> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    if (_8Bits[index] >= 2 && _8Bits[index] < 4) synerge.append("2 8비트 ");
    else if (_8Bits[index] >= 4 && _8Bits[index] < 6) synerge.append("4 8비트 ");
    else if (_8Bits[index] >= 6) synerge.append("6 8비트 ");

    if (EDM[index] >= 2 && EDM[index] < 3) synerge.append("2EDM ");
    else if (EDM[index] >= 3 && EDM[index] < 4) synerge.append("3EDM ");
    else if (EDM[index] >= 4 && EDM[index] < 5) synerge.append("4EDM ");
    else if (EDM[index] >= 5) synerge.append("5EDM ");

    if (Heartsteel[index] >= 3 && Heartsteel[index] < 5) synerge.append("3Heartsteel ");
    else if (Heartsteel[index] >= 5 && Heartsteel[index] < 7) synerge.append("5Heartsteel ");
    else if (Heartsteel[index] >= 7 && Heartsteel[index] < 10)  synerge.append("7Heartsteel ");
    else if (Heartsteel[index] >= 10) synerge.append("10Heartsteel ");

    if (KDA[index] >= 3 && KDA[index] < 5) synerge.append("3KDA ");
    else if (KDA[index] >= 5 && KDA[index] < 7) synerge.append("5KDA ");
    else if (KDA[index] >= 7 && KDA[index] < 10) synerge.append("7KDA "); 
    else if (KDA[index] >= 10) synerge.append("10KDA ");

    if (True_Damage[index] >= 2 && True_Damage[index] < 4) synerge.append("2TrueDamage ");
    else if (True_Damage[index] >= 4 && True_Damage[index] < 6) synerge.append("4TrueDamage ");
    else if (True_Damage[index] >= 6 && True_Damage[index] < 9) synerge.append("6TrueDamage ");
    else if (True_Damage[index] >= 9) synerge.append("9TrueDamage ");
    
    if (Disco[index] >= 3 && Disco[index] < 4) synerge.append("3디스코 ");
    else if (Disco[index] >= 4 && Disco[index] < 5) synerge.append("4디스코 ");
    else if (Disco[index] >= 5 && Disco[index] < 6) synerge.append("5디스코 ");
    else if (Disco[index] >= 6) synerge.append("6디스코 ");

    if (Maestro[index] == 1) synerge.append("1마에스트로 ");
    if (Mixmaster[index] == 1) synerge.append("1믹스마스터 ");
    if (Wildcard[index] == 1) synerge.append("1와일드카드 ");
  
    if (EMO[index] >= 2 && EMO[index] < 4) synerge.append("2이모코어 ");
    else if (EMO[index] >= 4 && EMO[index] < 6) synerge.append("4이모코어 ");
    else if (EMO[index] >= 6) synerge.append("6이모코어 ");  

    if (ILLBEATS[index] == 1) synerge.append("1일류비트 ");
    
    if (Jazz[index] >= 2 && Jazz[index] < 3) synerge.append("2재즈 ");
    else if (Jazz[index] >= 3 && Jazz[index] < 4) synerge.append("3재즈 ");
    else if (Jazz[index] >= 4) synerge.append("4재즈 ");

    if (Country[index] >= 3 && Country[index] < 5) synerge.append("3컨트리 ");
    else if (Country[index] >= 5 && Country[index] < 7) synerge.append("5컨트리 ");
    else if (Country[index] >= 7) synerge.append("7컨트리 ");

    if (Punk[index] >= 2 && Punk[index] < 4) synerge.append("2펑크 ");
    else if (Punk[index] >= 4 && Punk[index] < 6) synerge.append("4펑크 ");
    else if (Punk[index] >= 6) synerge.append("6펑크 ");

    if (Pentakill[index] >= 3 && Pentakill[index] < 5) synerge.append("3펜타킬 ");
    else if (Pentakill[index] >= 5 && Pentakill[index] < 7) synerge.append("5펜타킬 "); 
    else if (Pentakill[index] >= 7 && Pentakill[index] < 10) synerge.append("7펜타킬 ");
    else if (Pentakill[index] >= 10) synerge.append("10펜타킬 ");

    if (Hyperpop[index] >= 1 && Hyperpop[index] < 2) synerge.append("1하이퍼팝 ");
    else if (Hyperpop[index] >= 2 && Hyperpop[index] < 3) synerge.append("2하이퍼팝 ");
    else if (Hyperpop[index] >= 3 && Hyperpop[index] < 4) synerge.append("3하이퍼팝 ");
    else if (Hyperpop[index] >= 4) synerge.append("4하이퍼팝 ");


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

    // classes
    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge.append("2감시자 ");
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge.append("4감시자 ");
    else if (Sentinel[index] >= 6 && Sentinel[index] < 8) synerge.append("6감시자 ");
    else if (Sentinel[index] >= 8) synerge.append("8감시자 ");

    if (BigShot[index] >= 2 && BigShot[index] < 4) synerge.append("2거물 ");
    else if (BigShot[index] >= 4 && BigShot[index] < 6) synerge.append("4거물 ");
    else if (BigShot[index] >= 6) synerge.append("6거물 ");

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2싸움꾼 ");
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4싸움꾼 ");
    else if (Bruiser[index] >= 6) synerge.append("6싸움꾼 ");

    if (Breakout[index] == 1) synerge.append("1빅히트 ");

    if (Rapidfire[index] >= 2 && Rapidfire[index] < 4) synerge.append("2속사포 ");
    else if (Rapidfire[index] >= 4 && Rapidfire[index] < 6) synerge.append("4속사포 ");
    else if (Rapidfire[index] >= 6) synerge.append("6속사포 ");

    if (Guardian[index] >= 2 && Guardian[index] < 4) synerge.append("2수호자 ");
    else if (Guardian[index] >= 4 && Guardian[index] < 6) synerge.append("4수호자 ");
    else if (Guardian[index] >= 6) synerge.append("6수호자 ");

    if (CrowdDiver[index] >= 2 && CrowdDiver[index] < 4) synerge.append("2스테이지다이버 ");
    else if (CrowdDiver[index] >= 4 && CrowdDiver[index] < 6) synerge.append("4스테이지다이버 ");
    else if (CrowdDiver[index] >= 6) synerge.append("6스테이지다이버 ");

    if (Superfan[index] >= 3 && Superfan[index] < 4) synerge.append("3열혈팬 ");
    else if (Superfan[index] >= 4 && Superfan[index] < 5) synerge.append("4열혈팬 ");
    else if (Superfan[index] >= 5) synerge.append("5열혈팬 ");

    if (Edgelord[index] >= 3 && Edgelord[index] < 5) synerge.append("3이단아 ");
    else if (Edgelord[index] >= 5 && Edgelord[index] < 7) synerge.append("5이단아 ");
    else if (Edgelord[index] >= 7) synerge.append("7이단아 ");

    if (Spellweaver[index] >= 3 && Spellweaver[index] < 5) synerge.append("3주문술사 ");
    else if (Spellweaver[index] >= 5 && Spellweaver[index] < 7) synerge.append("5주문술사 ");
    else if (Spellweaver[index] >= 7 && Spellweaver[index] < 10) synerge.append("7주문술사 ");
    else if (Spellweaver[index] >= 10)  synerge.append("10주문술사 "); 

    if (Executioner[index] >= 2 && Executioner[index] < 3)  synerge.append("2처형자 ");
    else if (Executioner[index] >= 4 && Executioner[index] < 6)  synerge.append("4처형자 ");
    else if (Executioner[index] >= 6)  synerge.append("6처형자 ");

    if (Mosher[index] >= 2 && Mosher[index] < 4) synerge.append("2춤꾼 ");
    else if (Mosher[index] >= 4 && Mosher[index] < 6) synerge.append("4춤꾼 ");
    else if (Mosher[index] >= 6) synerge.append("6춤꾼 ");

    if (Dazzler[index] >= 2 && Dazzler[index] < 4) synerge.append("2현혹술사 ");
    else if (Dazzler[index] >= 4 && Dazzler[index] < 6) synerge.append("4현혹술사 ");
    else if (Dazzler[index] >= 6) synerge.append("6현혹술사 ");


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
