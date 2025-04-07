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
int AminaSquad[61];
int Cyberboss[61];
int Exotech[61];
int GoldenOx[61];
int Nitro[61];
int Boombot[61];
int Syndicate[61];
int StreetDemon[61];
int Cyper[61];
int DivineCorp[61];
int Virus[61];
int SoulKiller[61];
int Overload[61];
int GodofNW[61];


// classes1
int Bastion[61];
int Bruiser[61];
int Slayer[61];
int Strategist[61];
int AMP[61];
int Dynamo[61];
int Executioner[61];
int Marksman[61];
int Rapidfire[61];
int Techie[61];
int Vanguard[61];

// position

int Fronter[60];
int Backer[60];
int ANY[60];

// fix synerge
int aminaSquad;
int cyberboss;
int exotech;
int goldenOx;
int nitro;
int boombot;
int syndicate;
int cyper;
int streetDemon;
int divineCorp;
int overload;
int virus;
int soulKiller;
int godofNW;


int bastion;
int bruiser;
int amp;
int dynamo;
int rapidfire;
int executioner;
int marksman;
int vanguard;
int slayer;
int techie;
int strategist;

int fronter;
int backer;
int any;


// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {

    // origins
    GodofNW[index] = godofNW;
    AminaSquad[index] = aminaSquad;
    Cyberboss[index] = cyberboss;
    Exotech[index] = exotech;
    GoldenOx[index] = goldenOx;
    Nitro[index] = nitro;
    Boombot[index] = boombot;
    Syndicate[index] = syndicate;
    Cyper[index] = cyper;
    StreetDemon[index] = streetDemon;
    DivineCorp[index] = divineCorp;
    Virus[index] = virus;
    Overload[index] = overload;
    SoulKiller[index] = soulKiller;


    // classes
    Bastion[index] = bastion;
    Bruiser[index] = bruiser;
    Dynamo[index] = dynamo;
    AMP[index] = amp;
    Rapidfire[index] = rapidfire;
    Executioner[index] = executioner;
    Marksman[index] = marksman;
    Vanguard[index] = vanguard;
    Slayer[index] = slayer;
    Techie[index] = techie;
    Strategist[index] = strategist;

    Fronter[index] = fronter;
    Backer[index] = backer;

}

void champions_info() {
    champions.push_back(make_tuple("알리스타", "GoldenOx", "", "Bruiser", "", 1, "Fronter")); 
    champions.push_back(make_tuple("문도박사", "StreetDemon", "", "Bruiser", "Slayer", 1, "Fronter")); 
    champions.push_back(make_tuple("잭스", "Exotech", "", "Bastion", "", 1, "Fronter")); 
    champions.push_back(make_tuple("모르가나", "DivineCorp", "", "Dynamo", "", 1, "Backer")); 
    champions.push_back(make_tuple("세라핀", "AminaSquad", "", "Techie", "", 1, "Backer")); 
    champions.push_back(make_tuple("자이라", "StreetDemon", "", "Techie", "", 1, "Backer")); 
    champions.push_back(make_tuple("코그모", "Boombot", "", "Rapidfire", "", 1, "Backer"));
    champions.push_back(make_tuple("사일러스", "AminaSquad", "", "Vanguard", "", 1, "Fronter"));
    champions.push_back(make_tuple("니달리", "Nitro", "", "AMP", "", 1, "Fronter")); 
    champions.push_back(make_tuple("샤코", "Syndicate", "", "Slayer", "", 1, "Fronter")); 
    champions.push_back(make_tuple("킨드레드", "Nitro", "", "Marksman", "Rapidfire", 1, "Backer"));
    champions.push_back(make_tuple("뽀삐", "Cyberboss", "", "Bastion", "", 1, "Fronter")); 
    champions.push_back(make_tuple("바이", "Cyper", "", "Vanguard", "", 1, "Fronter")); 

    champions.push_back(make_tuple("베이가", "Cyberboss", "", "Techie", "", 2, "Backer")); 
    champions.push_back(make_tuple("베인", "AminaSquad", "", "Slayer", "", 2, "Backer")); 
    champions.push_back(make_tuple("트페", "Syndicate", "", "Rapidfire", "", 2, "Backer")); 
    champions.push_back(make_tuple("에코", "StreetDemon", "", "Strategist", "", 2, "Fronter"));
    champions.push_back(make_tuple("그레이브즈", "GoldenOx", "", "Executioner", "", 2, "Fronter")); 
    champions.push_back(make_tuple("르블랑", "Cyper", "", "Strategist", "", 2, "Backer")); 
    champions.push_back(make_tuple("진", "Exotech", "", "Dynamo", "Marksman", 2, "Backer")); 
    champions.push_back(make_tuple("일라오이", "AminaSquad", "", "Bastion", "", 2, "Fronter")); 
    champions.push_back(make_tuple("다리우스", "Syndicate", "", "Bruiser", "", 2, "Fronter"));
    champions.push_back(make_tuple("라아스트", "DivineCorp", "", "Vanguard", "", 2, "Fronter"));
    champions.push_back(make_tuple("쉬바나", "Nitro", "", "Techie", "Bastion", 2, "Fronter"));
    champions.push_back(make_tuple("스카너", "Boombot", "", "Vanguard", "", 2, "Fronter")); 
    champions.push_back(make_tuple("나피리", "Exotech", "", "AMP", "", 2, "Fronter")); 

    champions.push_back(make_tuple("브라움", "Syndicate", "", "Vanguard", "", 3, "Fronter"));
    champions.push_back(make_tuple("자르반", "GoldenOx", "", "Vanguard", "Slayer", 3, "Fronter")); 
    champions.push_back(make_tuple("엘리스", "Nitro", "", "Dynamo", "", 3, "Backer")); 
    champions.push_back(make_tuple("유미", "AminaSquad", "", "AMP", "Strategist", 3, "Backer")); 
    champions.push_back(make_tuple("바루스", "Exotech", "", "Executioner", "", 3, "Backer")); 
    champions.push_back(make_tuple("피들스틱", "Boombot", "", "Techie", "", 3, "Fronter"));
    champions.push_back(make_tuple("모데카이저", "Exotech", "", "Techie", "Bruiser", 3, "Fronter")); 
    champions.push_back(make_tuple("갈리오", "Cyper", "", "Bastion", "", 3, "Fronter")); 
    champions.push_back(make_tuple("세나", "DivineCorp", "", "Slayer", "", 3, "Backer")); 
    champions.push_back(make_tuple("렝가", "StreetDemon", "", "Executioner", "", 3, "Fronter")); 
    champions.push_back(make_tuple("그라가스", "DivineCorp", "", "Bruiser", "", 3, "Fronter")); 
    champions.push_back(make_tuple("드레이븐", "Cyper", "", "Rapidfire", "", 3, "Backer"));
    champions.push_back(make_tuple("징크스", "StreetDemon", "", "Marksman", "", 3, "Backer"));

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
    cout << "ex) 2폭발봇, 엑소테크" << endl;
    cout << " => \"2폭발봇\" 입력후 enter" << endl;
    cout << " => \"1엑소테크\" 입력후 enter" << endl;
    cout << " => \"END\"입력후 enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "네트워크의신") godofNW += num;
        else if (traits == "동물특공대") aminaSquad += num;
        else if (traits == "사이버보스") cyberboss += num;
        else if (traits == "엑소테크") exotech += num;
        else if (traits == "황금황소") goldenOx += num;
        else if (traits == "니트로") nitro += num;
        else if (traits == "폭발봇") boombot += num;
        else if (traits == "범죄조직") syndicate += num;
        else if (traits == "사이퍼") cyper += num;
        else if (traits == "거리의악마") streetDemon += num;
        else if (traits == "신성기업") divineCorp += num;
        else if (traits == "영혼살해자") soulKiller += num;
        else if (traits == "군주") overload += num;
        else if (traits == "바이러스") virus += num;
  
        // classes
        else if (traits == "요새") bastion += num;
        else if (traits == "난동꾼") bruiser += num;
        else if (traits == "증폭") amp += num;
        else if (traits == "다이나모") dynamo += num;
        else if (traits == "속사포") rapidfire += num;
        else if (traits == "처형자") executioner += num;
        else if (traits == "사격수") marksman += num;  
        else if (traits == "선봉대") vanguard += num;
        else if (traits == "학살자") slayer += num;
        else if (traits == "기술광") techie += num;
        else if (traits == "책략가") strategist += num;
    }
    

}

// 선택이 완료된 조합의 시너지 점수를 계산하는 함수
int synerge_check(int index) {
    int synerge_count = 0;
    // 1 : 3
    // 2-3-4: 5 10 18
    // 2-4-6: 5 12 25
    // 2-4-6-8: 5 10 15 33
    // 3-4: 8 13
    // 3-5: 8 15
    // 3-5-7: 8 15 30
    // 3-5-7-9: 8 14 28 45
    // 3-5-7-10: 8 14 28 55
    // 3-6: 8 18
    // 3-6-8: 8 16 40
    // 3-6-9: 8 16 45


    // origin
    if (AminaSquad[index] >= 3 && AminaSquad[index] < 5) synerge_count += 1000;
    else if (AminaSquad[index] >= 5 && AminaSquad[index] < 7) synerge_count += 14;  
    else if (AminaSquad[index] >= 7 && AminaSquad[index] < 9) synerge_count += 28;  
    else if (AminaSquad[index] >= 10) synerge_count += 55;

    if (Cyberboss[index] >= 2 && Cyberboss[index] < 3) synerge_count += 1000;
    else if (Cyberboss[index] >= 3 && Cyberboss[index] < 4) synerge_count += 10;  
    else if (Cyberboss[index] >= 4) synerge_count += 18;

    if (Exotech[index] >= 3 && Exotech[index] < 5) synerge_count += 1000;
    else if (Exotech[index] >= 5 && Exotech[index] < 7) synerge_count += 14;  
    else if (Exotech[index] >= 7 && Exotech[index] < 9) synerge_count += 28;  
    else if (Exotech[index] >= 10) synerge_count += 55;

    if (GoldenOx[index] >= 2 && GoldenOx[index] < 4) synerge_count += 1000; 
    else if (GoldenOx[index] >= 4 && GoldenOx[index] < 6) synerge_count += 12; 
    else if (GoldenOx[index] >= 6) synerge_count += 25;
    
    if (Nitro[index] >= 3 && Nitro[index] < 4) synerge_count += 1000;
    else if (Nitro[index] >= 4) synerge_count += 13; 

    if (Boombot[index] >= 2 && Boombot[index] < 4) synerge_count += 1000;
    else if (Boombot[index] >= 4 && Boombot[index] < 4) synerge_count += 12;
    else if (Boombot[index] >= 6) synerge_count += 25;  

    if (Syndicate[index] >= 3 && Syndicate[index] < 5) synerge_count += 1000; 
    else if (Syndicate[index] >= 5 && Syndicate[index] < 7) synerge_count += 14; 
    else if (Syndicate[index] >= 7) synerge_count += 32;

    if (Cyper[index] >= 3 && Cyper[index] < 4) synerge_count += 1000;
    else if (Cyper[index] >= 4 && Cyper[index] < 5) synerge_count += 13;
    else if (Cyper[index] >= 5) synerge_count += 20;  

    if (StreetDemon[index] >= 3 && StreetDemon[index] < 5) synerge_count += 1000;
    else if (StreetDemon[index] >= 5 && StreetDemon[index] < 7) synerge_count += 14;  
    else if (StreetDemon[index] >= 7 && StreetDemon[index] < 9) synerge_count += 28;  
    else if (StreetDemon[index] >= 10) synerge_count += 55;

    if (DivineCorp[index] >= 1 && DivineCorp[index] < 2) synerge_count += 1000;
    else if (DivineCorp[index] >= 2 && DivineCorp[index] < 3) synerge_count += 5;
    else if (DivineCorp[index] >= 3 && DivineCorp[index] < 4) synerge_count += 8;
    else if (DivineCorp[index] >= 4 && DivineCorp[index] < 5) synerge_count += 12;
    else if (DivineCorp[index] >= 5 && DivineCorp[index] < 6) synerge_count += 17;
    else if (DivineCorp[index] >= 6 && DivineCorp[index] < 7) synerge_count += 22;
    else if (DivineCorp[index] >= 7) synerge_count += 28; 
    
    if (SoulKiller[index] == 1) synerge_count += 3;  
    if (Overload[index] == 1) synerge_count += 3; 
    if (Virus[index] == 1 ) synerge_count += 3;
    if (GodofNW[index] == 1) synerge_count += 3;


    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge_count += 1000;
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge_count += 10;
    else if (Bastion[index] >= 6) synerge_count += 25;

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 1000;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 12;
    else if (Bruiser[index] >= 6) synerge_count += 25;

    if (AMP[index] >= 2 && AMP[index] < 3) synerge_count += 1000;
    else if (AMP[index] >= 3 && AMP[index] < 4) synerge_count += 10;
    else if (AMP[index] >= 4 && AMP[index] < 5) synerge_count += 15;
    else if (AMP[index] >= 5) synerge_count += 20;

    if (Dynamo[index] >= 2 && Dynamo[index] < 3) synerge_count += 1000;
    else if (Dynamo[index] >= 3 && Dynamo[index] < 4) synerge_count += 10;
    else if (Dynamo[index] >= 4) synerge_count += 15;

    if (Rapidfire[index] >= 2 && Rapidfire[index] < 4) synerge_count += 1000;
    else if (Rapidfire[index] >= 4 && Rapidfire[index] < 6) synerge_count += 12;
    else if (Rapidfire[index] >= 6) synerge_count += 25; 

    if (Executioner[index] >= 2 && Executioner[index] < 3) synerge_count += 1000;
    else if (Executioner[index] >= 3 && Executioner[index] < 4) synerge_count += 10;
    else if (Executioner[index] >= 4 && Executioner[index] < 5) synerge_count += 15;
    else if (Executioner[index] >= 5) synerge_count += 20;

    if (Marksman[index] >= 2 && Marksman[index] < 4) synerge_count += 1000;
    else if (Marksman[index] >= 4 && Marksman[index] < 6) synerge_count += 12;
    else if (Marksman[index] >= 6) synerge_count += 25;  

    if (Vanguard[index] >= 2 && Vanguard[index] < 4) synerge_count += 1000;
    else if (Vanguard[index] >= 4 && Vanguard[index] < 6) synerge_count += 12;
    else if (Vanguard[index] >= 6) synerge_count += 25; 

    if (Slayer[index] >= 2 && Slayer[index] < 4) synerge_count += 1000;
    else if (Slayer[index] >= 4 && Slayer[index] < 6) synerge_count += 12;
    else if (Slayer[index] >= 6) synerge_count += 25; 

    if (Techie[index] >= 2 && Techie[index] < 4) synerge_count += 1000;
    else if (Techie[index] >= 4 && Techie[index] < 6) synerge_count += 10;
    else if (Techie[index] >= 6 && Techie[index] < 8) synerge_count += 15;
    else if (Techie[index] >= 8) synerge_count += 33;   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge_count += 1000;
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge_count += 10;
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge_count += 15;
    else if (Strategist[index] >= 5) synerge_count += 20; 

    // if (Fronter[index] - Backer[index] >= 3 && Fronter[index] - Backer[index] < 8) synerge_count += 10;
    // else if (Fronter[index] - Backer[index] >= 1 && Fronter[index] - Backer[index] + ANY[index] < 3) synerge_count += 5;
    // else if (Fronter[index] - Backer[index] < 1) synerge_count += 2;

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
    if (origin1 == "GodofNW") GodofNW[index]++;
    else if (origin1 == "AminaSquad") AminaSquad[index]++;
    else if (origin1 == "Cyberboss") Cyberboss[index]++;
    else if (origin1 == "Exotech") Exotech[index]++;
    else if (origin1 == "GoldenOx") GoldenOx[index]++;
    else if (origin1 == "Nitro") Nitro[index]++;
    else if (origin1 == "Boombot") Boombot[index]++;
    else if (origin1 == "Syndicate") Syndicate[index]++;
    else if (origin1 == "Cyper") Cyper[index]++;
    else if (origin1 == "StreetDemon") StreetDemon[index]++;
    else if (origin1 == "DivineCorp") DivineCorp[index]++;
    else if (origin1 == "Overload") Overload[index]++;
    else if (origin1 == "SoulKiller") SoulKiller[index]++;
    else if (origin1 == "Virus") Virus[index]++;

    // origin2
    if (origin2 == "GodofNW") GodofNW[index]++;
    else if (origin2 == "AminaSquad") AminaSquad[index]++;
    else if (origin2 == "Cyberboss") Cyberboss[index]++;
    else if (origin2 == "Exotech") Exotech[index]++;
    else if (origin2 == "GoldenOx") GoldenOx[index]++;
    else if (origin2 == "Nitro") Nitro[index]++;
    else if (origin2 == "Boombot") Boombot[index]++;
    else if (origin2 == "Syndicate") Syndicate[index]++;
    else if (origin2 == "Cyper") Cyper[index]++;
    else if (origin2 == "StreetDemon") StreetDemon[index]++;
    else if (origin2 == "DivineCorp") DivineCorp[index]++;
    else if (origin2 == "Overload") Overload[index]++;
    else if (origin2 == "SoulKiller") SoulKiller[index]++;
    else if (origin2 == "Virus") Virus[index]++;

    // classes1
    if (classes1 == "Bastion") Bastion[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "AMP") AMP[index]++;
    else if (classes1 == "Dynamo") Dynamo[index]++;
    else if (classes1 == "Rapidfire") Rapidfire[index]++;
    else if (classes1 == "Executioner") Executioner[index]++;
    else if (classes1 == "Marksman") Marksman[index]++;  
    else if (classes1 == "Vanguard") Vanguard[index]++;
    else if (classes1 == "Slayer") Slayer[index]++;
    else if (classes1 == "Techie") Techie[index]++;
    else if (classes1 == "Strategist") Strategist[index]++;

    // classes2, 특성이 2개 있는 챔피언들 처리
    if (classes2 == "Bastion") Bastion[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "AMP") AMP[index]++;
    else if (classes2 == "Dynamo") Dynamo[index]++;
    else if (classes2 == "Rapidfire") Rapidfire[index]++;
    else if (classes2 == "Executioner") Executioner[index]++;
    else if (classes2 == "Marksman") Marksman[index]++;  
    else if (classes2 == "Vanguard") Vanguard[index]++;
    else if (classes2 == "Slayer") Slayer[index]++;
    else if (classes2 == "Techie") Techie[index]++;
    else if (classes2 == "Strategist") Strategist[index]++;

    // 앞 뒷 처리
    if (BNF == "Fronter") Fronter[index]++;
    else if (BNF == "Backer") Backer[index]++;



}


int twostar_champion_cost(tuple <string, string, string, string, string, int, string> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    // origin
    if (AminaSquad[index] >= 3 && AminaSquad[index] < 5) synerge.append("3동물특공대 ");  
    else if (AminaSquad[index] >= 5 && AminaSquad[index] < 7) synerge.append("5동물특공대 ");  
    else if (AminaSquad[index] >= 7 && AminaSquad[index] < 9) synerge.append("7동물특공대 ");  
    else if (AminaSquad[index] >= 10) synerge.append("10동물특공대 ");
  
    if (Cyberboss[index] >= 2 && Cyberboss[index] < 3) synerge.append("2사이버보스 ");
    else if (Cyberboss[index] >= 3 && Cyberboss[index] < 4) synerge.append("3사이버보스 ");  
    else if (Cyberboss[index] >= 4) synerge.append("4사이버보스 ");

    if (Exotech[index] >= 3 && Exotech[index] < 5) synerge.append("3엑소테크 "); 
    else if (Exotech[index] >= 5 && Exotech[index] < 7) synerge.append("5엑소테크 "); 
    else if (Exotech[index] >= 7 && Exotech[index] < 10) synerge.append("7엑소테크 ");  
    else if (Exotech[index] >= 10) synerge.append("10엑소테크 ");

    if (GoldenOx[index] >= 2 && GoldenOx[index] < 4) synerge.append("2황금황소 "); 
    else if (GoldenOx[index] >= 4 && GoldenOx[index] < 6) synerge.append("4황금황소 "); 
    else if (GoldenOx[index] >= 6) synerge.append("6황금황소 ");
    
    if (Nitro[index] >= 3 && Nitro[index] < 4) synerge.append("3니트로 ");
    else if (Nitro[index] >= 4) synerge.append("4니트로 "); 

    if (Boombot[index] >= 2 && Boombot[index] < 4) synerge.append("2폭발봇 ");
    else if (Boombot[index] >= 4 && Boombot[index] < 4) synerge.append("4폭발봇 ");
    else if (Boombot[index] >= 6) synerge.append("6폭발봇 ");  

    if (Syndicate[index] >= 3 && Syndicate[index] < 5) synerge.append("3범죄조직 "); 
    else if (Syndicate[index] >= 5 && Syndicate[index] < 7) synerge.append("5범죄조직 "); 
    else if (Syndicate[index] >= 7) synerge.append("7범죄조직 ");

    if (Cyper[index] >= 2 && Cyper[index] < 3) synerge.append("2사이퍼 ");
    else if (Cyper[index] >= 3 && Cyper[index] < 4) synerge.append("3사이퍼 ");
    else if (Cyper[index] >= 4) synerge.append("4사이퍼 ");  

    if (StreetDemon[index] >= 3 && StreetDemon[index] < 6) synerge.append("3거리의악마 ");
    else if (StreetDemon[index] >= 5 && StreetDemon[index] < 7) synerge.append("5거리의악마 "); 
    else if (StreetDemon[index] >= 7 && StreetDemon[index] < 10) synerge.append("7거리의악마 "); 
    else if (StreetDemon[index] >= 10) synerge.append("10거리의악마 ");

    if (DivineCorp[index] >= 1 && DivineCorp[index] < 2) synerge.append("1신성기업 ");
    else if (DivineCorp[index] >= 2 && DivineCorp[index] < 3) synerge.append("2신성기업 ");
    else if (DivineCorp[index] >= 3 && DivineCorp[index] < 4) synerge.append("3신성기업 ");
    else if (DivineCorp[index] >= 4 && DivineCorp[index] < 5) synerge.append("4신성기업 ");
    else if (DivineCorp[index] >= 5 && DivineCorp[index] < 6) synerge.append("5신성기업 ");
    else if (DivineCorp[index] >= 6) synerge.append("6신성기업 "); 

    if (Overload[index] == 1) synerge.append("1군주 "); 
    if (Virus[index] == 1 ) synerge.append("1바이러스 ");
    if (SoulKiller[index] == 1) synerge.append("1영혼살해자 "); 
    if (GodofNW[index] == 1) synerge.append("1네트워크의신 ");


    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge.append("2요새 ");
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge.append("4요새 ");
    else if (Bastion[index] >= 6) synerge.append("6요새 ");

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2난동꾼 ");
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4난동꾼 ");
    else if (Bruiser[index] >= 6) synerge.append("6난동꾼 ");

    if (AMP[index] >= 2 && AMP[index] < 3) synerge.append("2증폭 ");
    else if (AMP[index] >= 3 && AMP[index] < 4) synerge.append("3증폭 ");
    else if (AMP[index] >= 4 && AMP[index] < 5) synerge.append("4증폭 ");
    else if (AMP[index] >= 5) synerge.append("5증폭 ");

    if (Dynamo[index] >= 2 && Dynamo[index] < 3) synerge.append("2다이나모 ");
    else if (Dynamo[index] >= 3 && Dynamo[index] < 4) synerge.append("3다이나모 ");
    else if (Dynamo[index] >= 4) synerge.append("4다이나모 ");

    if (Rapidfire[index] >= 2 && Rapidfire[index] < 4) synerge.append("2속사포 ");
    else if (Rapidfire[index] >= 4 && Rapidfire[index] < 6) synerge.append("4속사포 ");
    else if (Rapidfire[index] >= 6) synerge.append("6속사포 "); 

    if (Executioner[index] >= 2 && Executioner[index] < 3) synerge.append("2처형자 ");
    else if (Executioner[index] >= 3 && Executioner[index] < 4) synerge.append("3처형자 ");
    else if (Executioner[index] >= 4 && Executioner[index] < 5) synerge.append("4처형자 ");
    else if (Executioner[index] >= 5) synerge.append("5처형자 ");  

    if (Marksman[index] >= 2 && Marksman[index] < 4) synerge.append("2사격수 ");
    else if (Marksman[index] >= 4) synerge.append("4사격수 ");    

    if (Vanguard[index] >= 2 && Vanguard[index] < 4) synerge.append("2선봉대 ");
    else if (Vanguard[index] >= 4 && Vanguard[index] < 6) synerge.append("4선봉대 ");
    else if (Vanguard[index] >= 6) synerge.append("6선봉대 ");

    if (Slayer[index] >= 2 && Slayer[index] < 3) synerge.append("2학살자 ");
    else if (Slayer[index] >= 3 && Slayer[index] < 4) synerge.append("3학살자 ");
    else if (Slayer[index] >= 4 && Slayer[index] < 5) synerge.append("4학살자 ");
    else if (Slayer[index] >= 5 && Slayer[index] < 6) synerge.append("5학살자 ");
    else if (Slayer[index] >= 6) synerge.append("6학살자 ");

    if (Techie[index] >= 2 && Techie[index] < 4) synerge.append("2기술광 ");
    else if (Techie[index] >= 4 && Techie[index] < 6) synerge.append("4기술광 ");
    else if (Techie[index] >= 6 && Techie[index] < 8) synerge.append("6기술광 ");
    else if (Techie[index] >= 8) synerge.append("8기술광 ");   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge.append("2책략가 ");
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge.append("3책략가 ");
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge.append("4책략가 ");
    else if (Strategist[index] >= 5) synerge.append("5책략가 "); 

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

    return synerge;
}


vector <int> pick[61];

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
