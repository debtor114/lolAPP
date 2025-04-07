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
vector < tuple <string, string, string, string, string, int, string> > selected_champions;

// 전설이 4렙, 6렙이하, 7렙이상 획득할 수 있는 챔피언 집합들
vector< tuple <string, string, string, string, string, int, string> > level4_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level6_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level7_up_champions;

// 경우의 수 계산 전에 선택한 챔피언 집합들
vector< tuple <string, string, string, string, string, int, string> > user_select_champ;


int selected_size; // 유저가 챔피언을 몇 개 선택했는지

// origin1
int Porcelain[60];
int Dragonlord[60];
int Fated[60];
int Mythic[60];
int Fortune[60];
int Dryad[60];
int Ghostly[60];
int Heavenly[60];
int Inkshadow[60];
int Umbral[60];
int Storyweaver[60];
int Exalted[60];


// classes1
int Arcanist[60];
int Bruiser[60];
int Duelist[60];
int Behemoth[60];
int Lover[60];
int Sniper[60];
int Invoker[60];
int Warden[60];
int Trickshot[60];
int Great[60];
int Reaper[60];
int Altruist[60];
int Spirit_Walker[60];
int Sage[60];
int Artist[60];



// fix synerge
int porcelain;
int dragonlord;
int fated;
int mythic;
int fortune;
int dryad;
int ghostly;
int heavenly;
int inkshadow;
int umbral;
int stroyweaver;
int exalted;

int arcanist;
int bruiser;
int duelist;
int behemoth;
int lover;
int sniper;
int invoker;
int warden;
int trickshot;
int great;
int reaper;
int altruist;
int spirit_Walker;
int sage;
int artist;



// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {

    // origins
    Dragonlord[index] = dragonlord;
    Dryad[index] = dryad;
    Fated[index] = fated;
    Fortune[index] = fortune;
    Ghostly[index] = ghostly;
    Heavenly[index] = heavenly;
    Inkshadow[index] = inkshadow;
    Mythic[index] = mythic;
    Porcelain[index] = porcelain;
    Storyweaver[index] = stroyweaver;
    Umbral[index] = umbral;
    Exalted[index] = exalted;

    // classes
    Arcanist[index] = arcanist;
    Altruist[index] = altruist;
    Artist[index] = artist;
    Bruiser[index] = bruiser;
    Behemoth[index] = behemoth;
    Duelist[index] = duelist;
    Great[index] = great;
    Invoker[index] = invoker;
    Lover[index] = lover;
    Reaper[index] = reaper;
    Sage[index] = sage;
    Sniper[index] = sniper;
    Spirit_Walker[index] = spirit_Walker;
    Trickshot[index] = trickshot;
    Warden[index] = warden;

}

void champions_info() {
    champions.push_back(make_tuple("아리", "Fated", "", "Arcanist", "", 1, "")); 
    champions.push_back(make_tuple("초가스", "Mythic", "", "Behemoth", "", 1, "")); 
    champions.push_back(make_tuple("케이틀린", "Ghostly", "", "Sniper", "", 1, "")); 
    champions.push_back(make_tuple("다리우스", "Umbral", "", "Duelist", "", 1, "")); 
    champions.push_back(make_tuple("코부코", "Fortune", "", "Bruiser", "", 1, "")); 
    champions.push_back(make_tuple("가렌", "Storyweaver", "", "Warden", "", 1, "")); 
    champions.push_back(make_tuple("잭스", "Inkshadow", "", "Warden", "", 1, ""));
    champions.push_back(make_tuple("카직스", "Heavenly", "", "Reaper", "", 1, ""));
    champions.push_back(make_tuple("코그모", "Mythic", "", "Invoker", "Sniper", 1, "")); 
    champions.push_back(make_tuple("말파이트", "Heavenly", "", "Behemoth", "", 1, "")); 
    champions.push_back(make_tuple("렉사이", "Dryad", "", "Bruiser", "", 1, ""));
    champions.push_back(make_tuple("시비르", "Storyweaver", "", "Trickshot", "", 1, "")); 
    champions.push_back(make_tuple("야스오", "Fated", "", "Duelist", "", 1, "")); 

    champions.push_back(make_tuple("아트록스", "Ghostly", "Inkshadow", "Bruiser", "", 2, "")); 
    champions.push_back(make_tuple("나르", "Dryad", "", "Warden", "", 2, "")); 
    champions.push_back(make_tuple("잔나", "Dragonlord", "", "Invoker", "", 2, "")); 
    champions.push_back(make_tuple("킨드레드", "Dryad", "Fated", "Reaper", "", 2, ""));
    champions.push_back(make_tuple("럭스", "Porcelain", "", "Arcanist", "", 2, "")); 
    champions.push_back(make_tuple("리븐", "Storyweaver", "", "Altruist", "Bruiser", 2, "")); 
    champions.push_back(make_tuple("세나", "Inkshadow", "", "Sniper", "", 2, "")); 
    champions.push_back(make_tuple("쉔", "Ghostly", "", "Behemoth", "", 2, "")); 
    champions.push_back(make_tuple("티모", "Fortune", "", "Trickshot", "", 2, ""));
    champions.push_back(make_tuple("요릭", "Umbral", "", "Behemoth", "", 2, ""));
    champions.push_back(make_tuple("자이라", "Storyweaver", "", "Sage", "", 2, ""));
    champions.push_back(make_tuple("니코", "Heavenly", "Mythic", "Arcanist", "", 2, ""));
    champions.push_back(make_tuple("키아나", "Heavenly", "", "Duelist", "", 2, ""));

    champions.push_back(make_tuple("알룬", "Umbral", "", "Invoker", "", 3, ""));
    champions.push_back(make_tuple("아무무", "Porcelain", "", "Warden", "", 3, "")); 
    champions.push_back(make_tuple("아펠리오스", "Fated", "", "Sniper", "", 3, "")); 
    champions.push_back(make_tuple("바드", "Mythic", "", "Trickshot", "", 3, "")); 
    champions.push_back(make_tuple("다이애나", "Dragonlord", "", "Sage", "", 3, "")); 
    champions.push_back(make_tuple("일라오이", "Ghostly", "", "Arcanist", "Warden", 3, ""));
    champions.push_back(make_tuple("소라카", "Heavenly", "", "Altruist", "", 3, "")); 
    champions.push_back(make_tuple("탐켄치", "Mythic", "", "Bruiser", "", 3, "")); 
    champions.push_back(make_tuple("쓰레쉬", "Fated", "", "Behemoth", "", 3, "")); 
    champions.push_back(make_tuple("트리스타나", "Fortune", "", "Duelist", "", 3, "")); 
    champions.push_back(make_tuple("볼리베어", "Inkshadow", "", "Duelist", "", 3, "")); 
    champions.push_back(make_tuple("요네", "Umbral", "", "", "Reaper", 3, ""));
    champions.push_back(make_tuple("조이", "Fortune", "Storyweaver", "Arcanist", "", 3, ""));

    champions.push_back(make_tuple("애니", "Fortune", "", "Invoker", "", 4, "")); 
    champions.push_back(make_tuple("애쉬", "Porcelain", "", "Sniper", "", 4, "")); 
    champions.push_back(make_tuple("갈리오", "Storyweaver", "", "Bruiser", "", 4, "")); 
    champions.push_back(make_tuple("카이사", "Inkshadow", "", "Trickshot", "", 4, "")); 
    champions.push_back(make_tuple("케인", "Ghostly", "", "Reaper", "", 4, ""));
    champions.push_back(make_tuple("리신", "Dragonlord", "", "Duelist", "", 4, "")); 
    champions.push_back(make_tuple("릴리아", "Mythic", "", "Invoker", "", 4, "")); 
    champions.push_back(make_tuple("모르가나", "Ghostly", "", "Sage", "", 4, "")); 
    champions.push_back(make_tuple("노틸러스", "Mythic", "", "Warden", "", 4, "")); 
    champions.push_back(make_tuple("오른", "Dryad", "", "Behemoth", "", 4, "")); 
    champions.push_back(make_tuple("사일러스", "Umbral", "", "Bruiser", "", 4, "")); 
    champions.push_back(make_tuple("신드라", "Fated", "", "Arcanist", "", 4, "")); 

    champions.push_back(make_tuple("아지르", "Dryad", "", "Invoker", "", 5, "")); 
    champions.push_back(make_tuple("흐웨이", "Mythic", "", "Artist", "", 5, "")); 
    champions.push_back(make_tuple("이렐리아", "Storyweaver", "", "Duelist", "", 5, "")); 
    champions.push_back(make_tuple("리산드라", "Porcelain", "", "Arcanist", "", 5, "")); 
    champions.push_back(make_tuple("라칸", "Dragonlord", "", "Altruist", "Lovers", 5, "")); 
    champions.push_back(make_tuple("세트", "Fated", "Umbral", "Warden", "", 5, "")); 
    champions.push_back(make_tuple("우디르", "Inkshadow", "", "Behemoth", "Spirit_walker", 5, "")); 
    champions.push_back(make_tuple("오공", "Heavenly", "", "Great", "Sage", 5, "")); 
    champions.push_back(make_tuple("자야", "Dragonlord", "", "Trickshot", "Lovers", 5, ""));
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
    cout << "ex) 2도자기, 이타심" << endl;
    cout << " => \"2도자기\" 입력후 enter" << endl;
    cout << " => \"1이타심\" 입력후 enter" << endl;
    cout << " => \"END\"입력후 enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "도자기") porcelain += num;
        else if (traits == "용군주") dragonlord += num;
        else if (traits == "필연") fated += num;
        else if (traits == "신화") mythic += num;
        else if (traits == "행운") fortune += num;
        else if (traits == "숲지기") dryad += num;
        else if (traits == "혼령") ghostly += num;
        else if (traits == "천계") heavenly += num;
        else if (traits == "먹그림자") inkshadow += num;
        else if (traits == "암영") umbral += num;
        else if (traits == "이야기꾼") stroyweaver += num;
        else if (traits == "귀인") exalted += num;

        // classes
        else if (traits == "비전마법사") arcanist += num;
        else if (traits == "난동꾼") bruiser += num;
        else if (traits == "결투가") duelist += num;
        else if (traits == "거대괴수") behemoth += num;
        else if (traits == "연인") lover += num;
        else if (traits == "저격수") sniper += num;
        else if (traits == "기원자") invoker += num;
        else if (traits == "파수꾼") warden += num;
        else if (traits == "재주꾼") trickshot += num;  
        else if (traits == "호걸") great += num;
        else if (traits == "사신") reaper += num;
        else if (traits == "이타심") altruist += num;
        else if (traits == "정령주술사") spirit_Walker += num;
        else if (traits == "학자") sage += num;
        else if (traits == "예술가") artist += num;
    }
    

}


void addExaltedChamp() {
    cout << "귀인 챔피언을 추가합니다." << endl;
    cout << "챔피언을 한개 씩 나열해주세요" << endl;
    cout << "ex) 럭스, 초가스, 요네, " << endl;
    cout << " => \"럭스\" 입력후 enter" << endl;
    cout << " => \"초가스\" 입력후 enter" << endl;
    cout << " => 전부 입력 후 \"END\" enter" << endl;

    while(1) {
        string champ;
        cin >> champ;
        if (champ == "END") break;

        for (int i = 0; i < 60; i++) {
            if (get<0>(champions[i]) == champ) {
                get<6>(champions[i]) = "Exalted";
                // cout << "귀인등록완료 : " << get<0>(champions[i]) << endl;
            }
        }
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
    if (Porcelain[index] >= 2 && Porcelain[index] < 4) synerge_count += 5;
    else if (Porcelain[index] >= 4 && Porcelain[index] < 6) synerge_count += 10;  
    else if (Porcelain[index] >= 6) synerge_count += 15;

    if (Dragonlord[index] >= 2 && Dragonlord[index] < 3) synerge_count += 5;
    else if (Dragonlord[index] >= 3 && Dragonlord[index] < 4) synerge_count += 10;  
    else if (Dragonlord[index] >= 4 && Dragonlord[index] < 5) synerge_count += 15;  
    else if (Dragonlord[index] >= 5) synerge_count += 22;

    if (Fated[index] >= 3 && Fated[index] < 5) synerge_count += 8; 
    else if (Fated[index] >= 5 && Fated[index] < 7) synerge_count += 15; 
    else if (Fated[index] >= 7 && Fated[index] < 10) synerge_count += 30; 
    else if (Fated[index] >= 10) synerge_count += 45;

    if (Mythic[index] >= 3 && Mythic[index] < 5) synerge_count += 8; 
    else if (Mythic[index] >= 5 && Mythic[index] < 7) synerge_count += 15; 
    else if (Mythic[index] >= 7 && Mythic[index] < 10) synerge_count += 30; 
    else if (Mythic[index] >= 10) synerge_count += 45;

     if (Fortune[index] >= 3 && Fortune[index] < 5) synerge_count += 8; 
    else if (Fortune[index] >= 5 && Fortune[index] < 7) synerge_count += 15; 
    else if (Fortune[index] >= 7) synerge_count += 30;
    
    if (Dryad[index] >= 2 && Dryad[index] < 4) synerge_count += 5;
    else if (Dryad[index] >= 4 && Dryad[index] < 4) synerge_count += 12;
    else if (Dryad[index] >= 6) synerge_count += 25;  

    if (Ghostly[index] >= 2 && Ghostly[index] < 4) synerge_count += 5; 
    else if (Ghostly[index] >= 4 && Ghostly[index] < 6) synerge_count += 10; 
    else if (Ghostly[index] >= 6 && Ghostly[index] < 8) synerge_count += 15; 
    else if (Ghostly[index] >= 8) synerge_count += 33;

    if (Heavenly[index] >= 2 && Heavenly[index] < 3) synerge_count += 5;
    else if (Heavenly[index] >= 3 && Heavenly[index] < 4) synerge_count += 9;
    else if (Heavenly[index] >= 4 && Heavenly[index] < 5) synerge_count += 14;
    else if (Heavenly[index] >= 5 && Heavenly[index] < 6) synerge_count += 20;
    else if (Heavenly[index] >= 6 && Heavenly[index] < 7) synerge_count += 26;
    else if (Heavenly[index] >= 7) synerge_count += 33;  

    if (Inkshadow[index] >= 3 && Inkshadow[index] < 5) synerge_count += 8;
    else if (Inkshadow[index] >= 5 && Inkshadow[index] < 7) synerge_count += 15; 
    else if (Inkshadow[index] >= 7) synerge_count += 31;

    if (Umbral[index] >= 2 && Umbral[index] < 4) synerge_count += 5; 
    else if (Umbral[index] >= 4 && Umbral[index] < 6) synerge_count += 12; 
    else if (Umbral[index] >= 6 && Umbral[index] < 8) synerge_count += 25; 
    else if (Umbral[index] >= 9) synerge_count += 43;

    if (Storyweaver[index] >= 3 && Storyweaver[index] < 5) synerge_count += 8; 
    else if (Storyweaver[index] >= 5 && Storyweaver[index] < 7) synerge_count += 15; 
    else if (Storyweaver[index] >= 7 && Storyweaver[index] < 10) synerge_count += 30; 
    else if (Storyweaver[index] >= 10) synerge_count += 45;

    if (Exalted[index] >= 3 && Exalted[index] < 5) synerge_count += 8; 
    else if (Exalted[index] >= 5) synerge_count += 15;

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
    if (Great[index] == 1) synerge_count += 2;  
    if (Lover[index] == 1 ) synerge_count += 2;
    if (Artist[index] == 1) synerge_count += 2; 
    if (Spirit_Walker[index] == 1) synerge_count += 2;

    if (Arcanist[index] >= 2 && Arcanist[index] < 4) synerge_count += 5;
    else if (Arcanist[index] >= 4 && Arcanist[index] < 6) synerge_count += 10;
    else if (Arcanist[index] >= 6 && Arcanist[index] < 8) synerge_count += 15;
    else if (Arcanist[index] >= 8) synerge_count += 31;

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 5;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 10;
    else if (Bruiser[index] >= 6 && Bruiser[index] < 8) synerge_count += 15;
    else if (Bruiser[index] >= 8) synerge_count += 31;

    if (Duelist[index] >= 2 && Duelist[index] < 4) synerge_count += 5;
    else if (Duelist[index] >= 4 && Duelist[index] < 6) synerge_count += 10;
    else if (Duelist[index] >= 6 && Duelist[index] < 8) synerge_count += 15;
    else if (Duelist[index] >= 8) synerge_count += 32;

    if (Behemoth[index] >= 2 && Behemoth[index] < 4) synerge_count += 5;
    else if (Behemoth[index] >= 4 && Behemoth[index] < 6) synerge_count += 12;
    else if (Behemoth[index] >= 6) synerge_count += 25;

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge_count += 5;
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge_count += 12;
    else if (Sniper[index] >= 6) synerge_count += 25; 

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge_count += 5;
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge_count += 12;
    else if (Invoker[index] >= 6) synerge_count += 25; 

    if (Warden[index] >= 2 && Warden[index] < 4) synerge_count += 5;
    else if (Warden[index] >= 4 && Warden[index] < 6) synerge_count += 12;
    else if (Warden[index] >= 6) synerge_count += 25;  

    if (Trickshot[index] >= 2 && Trickshot[index] < 4) synerge_count += 5;
    else if (Trickshot[index] >= 4) synerge_count += 12;  

    if (Reaper[index] >= 2 && Reaper[index] < 4) synerge_count += 5;
    else if (Reaper[index] >= 4) synerge_count += 12;

    if (Altruist[index] >= 2 && Altruist[index] < 3) synerge_count += 5;
    else if (Altruist[index] >= 3 && Altruist[index] < 4) synerge_count += 10;
    else if (Altruist[index] >= 4) synerge_count += 15;

    if (Sage[index] >= 2 && Sage[index] < 3) synerge_count += 5;
    else if (Sage[index] >= 3 && Sage[index] < 4) synerge_count += 10;
    else if (Sage[index] >= 4 && Sage[index] < 5) synerge_count += 15;
    else if (Sage[index] >= 5) synerge_count += 22; 

    return synerge_count;
}

// 선택이 완료된 조합의 시너지를 계산하는 함수
void synerge_add(tuple <string, string, string, string, string, int, string> &champion, int index) {
    string origin1 = get<1>(champion);
    string origin2 = get<2>(champion);
    string classes1 = get<3>(champion);
    string classes2 = get<4>(champion);
    string origin3 = get<6>(champion);

    // origin1
    if (origin1 == "Porcelain") Porcelain[index]++;
    else if (origin1 == "Dragonlord") Dragonlord[index]++;
    else if (origin1 == "Fated") Fated[index]++;
    else if (origin1 == "Mythic") Mythic[index]++;
    else if (origin1 == "Fortune") Fortune[index]++;
    else if (origin1 == "Dryad") Dryad[index]++;
    else if (origin1 == "Ghostly") Ghostly[index]++;
    else if (origin1 == "Heavenly") Heavenly[index]++;
    else if (origin1 == "Inkshadow") Inkshadow[index]++;
    else if (origin1 == "Umbral") Umbral[index]++;
    else if (origin1 == "Storyweaver") Storyweaver[index]++;
    

    // origin2
    if (origin2 == "Porcelain") Porcelain[index]++;
    else if (origin2 == "Dragonlord") Dragonlord[index]++;
    else if (origin2 == "Fated") Fated[index]++;
    else if (origin2 == "Mythic") Mythic[index]++;
    else if (origin2 == "Fortune") Fortune[index]++;
    else if (origin2 == "Dryad") Dryad[index]++;
    else if (origin2 == "Ghostly") Ghostly[index]++;
    else if (origin2 == "Heavenly") Heavenly[index]++;
    else if (origin2 == "Inkshadow") Inkshadow[index]++;
    else if (origin2 == "Umbral") Umbral[index]++;
    else if (origin2 == "Storyweaver") Storyweaver[index]++;


    // classes1
    if (classes1 == "Arcanist") Arcanist[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "Duelist") Duelist[index]++;
    else if (classes1 == "Behemoth") Behemoth[index]++;
    else if (classes1 == "Lover") Lover[index]++;
    else if (classes1 == "Sniper") Sniper[index]++;
    else if (classes1 == "Invoker") Invoker[index]++;
    else if (classes1 == "Warden") Warden[index]++;
    else if (classes1 == "Trickshot") Trickshot[index]++;  
    else if (classes1 == "Great") Great[index]++;
    else if (classes1 == "Reaper") Reaper[index]++;
    else if (classes1 == "Altruist") Altruist[index]++;
    else if (classes1 == "Spirit_Walker") Spirit_Walker[index]++;
    else if (classes1 == "Sage") Sage[index]++;
    else if (classes1 == "Artist") Artist[index]++;


    // classes2, 특성이 2개 있는 챔피언들 처리
    if (classes2 == "Arcanist") Arcanist[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "Duelist") Duelist[index]++;
    else if (classes2 == "Behemoth") Behemoth[index]++;
    else if (classes2 == "Lover") Lover[index]++;
    else if (classes2 == "Sniper") Sniper[index]++;
    else if (classes2 == "Invoker") Invoker[index]++;
    else if (classes2 == "Warden") Warden[index]++;
    else if (classes2 == "Trickshot") Trickshot[index]++;  
    else if (classes2 == "Great") Great[index]++;
    else if (classes2 == "Reaper") Reaper[index]++;
    else if (classes2 == "Altruist") Altruist[index]++;
    else if (classes2 == "Spirit_Walker") Spirit_Walker[index]++;
    else if (classes2 == "Sage") Sage[index]++;
    else if (classes2 == "Artist") Artist[index]++;

    // 귀인 처리
    if (origin3 == "Exalted") Exalted[index]++;

}


int twostar_champion_cost(tuple <string, string, string, string, string, int, string> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    if (Porcelain[index] >= 2 && Porcelain[index] < 4) synerge.append("2도자기 ");
    else if (Porcelain[index] >= 4 && Porcelain[index] < 6) synerge.append("4도자기 ");   
    else if (Porcelain[index] >= 6) synerge.append("6도자기 "); 

    if (Dragonlord[index] >= 2 && Dragonlord[index] < 3) synerge.append("2용군주 "); 
    else if (Dragonlord[index] >= 3 && Dragonlord[index] < 4) synerge.append("3용군주 ");   
    else if (Dragonlord[index] >= 4 && Dragonlord[index] < 5) synerge.append("4용군주 ");   
    else if (Dragonlord[index] >= 5) synerge.append("5용군주 "); 

    if (Fated[index] >= 3 && Fated[index] < 5) synerge.append("3필연 ");  
    else if (Fated[index] >= 5 && Fated[index] < 7) synerge.append("5필연 ");  
    else if (Fated[index] >= 7 && Fated[index] < 10) synerge.append("7필연 ");  
    else if (Fated[index] >= 10) synerge.append("10필연 "); 

    if (Mythic[index] >= 3 && Mythic[index] < 5) synerge.append("3신화 ");  
    else if (Mythic[index] >= 5 && Mythic[index] < 7) synerge.append("5신화 ");  
    else if (Mythic[index] >= 7 && Mythic[index] < 10) synerge.append("7신화 ");  
    else if (Mythic[index] >= 10) synerge.append("10신화 "); 

     if (Fortune[index] >= 3 && Fortune[index] < 5) synerge.append("3행운 ");  
    else if (Fortune[index] >= 5 && Fortune[index] < 7) synerge.append("5행운 ");  
    else if (Fortune[index] >= 7) synerge.append("7행운 "); 
    
    if (Dryad[index] >= 2 && Dryad[index] < 4) synerge.append("2숲지기 "); 
    else if (Dryad[index] >= 4 && Dryad[index] < 4) synerge.append("4숲지기 "); 
    else if (Dryad[index] >= 6) synerge.append("6숲지기 ");   

    if (Ghostly[index] >= 2 && Ghostly[index] < 4) synerge.append("2혼령 ");  
    else if (Ghostly[index] >= 4 && Ghostly[index] < 6) synerge.append("4혼령 ");  
    else if (Ghostly[index] >= 6 && Ghostly[index] < 8) synerge.append("6혼령 ");  
    else if (Ghostly[index] >= 8) synerge.append("8혼령 "); 

    if (Heavenly[index] >= 2 && Heavenly[index] < 3) synerge.append("2천계 "); 
    else if (Heavenly[index] >= 3 && Heavenly[index] < 4) synerge.append("3천계 "); 
    else if (Heavenly[index] >= 4 && Heavenly[index] < 5) synerge.append("4천계 "); 
    else if (Heavenly[index] >= 5 && Heavenly[index] < 6) synerge.append("5천계 "); 
    else if (Heavenly[index] >= 6 && Heavenly[index] < 7) synerge.append("6천계 "); 
    else if (Heavenly[index] >= 7) synerge.append("7천계 ");   

    if (Inkshadow[index] >= 3 && Inkshadow[index] < 5) synerge.append("3먹그림자 "); 
    else if (Inkshadow[index] >= 5 && Inkshadow[index] < 7) synerge.append("5먹그림자 ");  
    else if (Inkshadow[index] >= 7) synerge.append("7먹그림자 "); 

    if (Umbral[index] >= 2 && Umbral[index] < 4) synerge.append("2암영 ");  
    else if (Umbral[index] >= 4 && Umbral[index] < 6) synerge.append("4암영 ");  
    else if (Umbral[index] >= 6 && Umbral[index] < 8) synerge.append("6암영 ");  
    else if (Umbral[index] >= 9) synerge.append("9암영 "); 

    if (Storyweaver[index] >= 3 && Storyweaver[index] < 5) synerge.append("3이야기꾼 ");  
    else if (Storyweaver[index] >= 5 && Storyweaver[index] < 7) synerge.append("5이야기꾼 ");  
    else if (Storyweaver[index] >= 7 && Storyweaver[index] < 10) synerge.append("7이야기꾼 ");  
    else if (Storyweaver[index] >= 10) synerge.append("10이야기꾼 "); 

    if (Exalted[index] >= 3 && Exalted[index] < 5) synerge.append("3귀인 ");  
    else if (Exalted[index] >= 5) synerge.append("5귀인 "); 


    // classes
    if (Great[index] == 1) synerge.append("1호걸 ");   
    if (Lover[index] == 1 ) synerge.append("1연인 "); 
    if (Artist[index] == 1) synerge.append("1예술가 ");  
    if (Spirit_Walker[index] == 1) synerge.append("1정령주술사 "); 

    if (Arcanist[index] >= 2 && Arcanist[index] < 4) synerge.append("2비전마법사 "); 
    else if (Arcanist[index] >= 4 && Arcanist[index] < 6) synerge.append("4비전마법사 "); 
    else if (Arcanist[index] >= 6 && Arcanist[index] < 8) synerge.append("6비전마법사 "); 
    else if (Arcanist[index] >= 8) synerge.append("8비전마법사 "); 

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2난동꾼 "); 
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4난동꾼 "); 
    else if (Bruiser[index] >= 6 && Bruiser[index] < 8) synerge.append("6난동꾼 "); 
    else if (Bruiser[index] >= 8) synerge.append("8난동꾼 "); 

    if (Duelist[index] >= 2 && Duelist[index] < 4) synerge.append("2결투가 "); 
    else if (Duelist[index] >= 4 && Duelist[index] < 6) synerge.append("4결투가 "); 
    else if (Duelist[index] >= 6 && Duelist[index] < 8) synerge.append("6결투가 "); 
    else if (Duelist[index] >= 8) synerge.append("8결투가 "); 

    if (Behemoth[index] >= 2 && Behemoth[index] < 4) synerge.append("2거대괴수 "); 
    else if (Behemoth[index] >= 4 && Behemoth[index] < 6) synerge.append("4거대괴수 "); 
    else if (Behemoth[index] >= 6) synerge.append("6거대괴수 "); 

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge.append("2저격수 "); 
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge.append("4저격수 "); 
    else if (Sniper[index] >= 6) synerge.append("6저격수 ");  

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge.append("2기원자 "); 
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge.append("4기원자 "); 
    else if (Invoker[index] >= 6) synerge.append("6기원자 ");  

    if (Warden[index] >= 2 && Warden[index] < 4) synerge.append("2파수꾼 "); 
    else if (Warden[index] >= 4 && Warden[index] < 6) synerge.append("4파수꾼 "); 
    else if (Warden[index] >= 6) synerge.append("6파수꾼 ");   

    if (Trickshot[index] >= 2 && Trickshot[index] < 4) synerge.append("2재주꾼 "); 
    else if (Trickshot[index] >= 4) synerge.append("4재주꾼 ");   

    if (Reaper[index] >= 2 && Reaper[index] < 4) synerge.append("2사신 "); 
    else if (Reaper[index] >= 4) synerge.append("4사신 "); 

    if (Altruist[index] >= 2 && Altruist[index] < 3) synerge.append("2이타심 "); 
    else if (Altruist[index] >= 3 && Altruist[index] < 4) synerge.append("3이타심 "); 
    else if (Altruist[index] >= 4) synerge.append("4이타심 "); 

    if (Sage[index] >= 2 && Sage[index] < 3) synerge.append("2현자 "); 
    else if (Sage[index] >= 3 && Sage[index] < 4) synerge.append("3현자 "); 
    else if (Sage[index] >= 4 && Sage[index] < 5) synerge.append("4현자 "); 
    else if (Sage[index] >= 5) synerge.append("5현자 ");  

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
    addExaltedChamp();
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
