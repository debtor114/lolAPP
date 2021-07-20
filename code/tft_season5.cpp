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
vector < tuple <string, string, string, string, int> > champions;
vector < tuple <string, string, string, string, int> > selected_champions;

// 전설이 4렙, 6렙이하, 7렙이상 획득할 수 있는 챔피언 집합들
vector < tuple <string, string, string, string, int> > level4_down_champions;
vector < tuple <string, string, string, string, int> > level6_down_champions;
vector < tuple <string, string, string, string, int> > level7_up_champions;

// 경우의 수 계산 전에 선택한 챔피언 집합들
vector < tuple <string, string, string, string, int> > user_select_champ;


int selected_size; // 유저가 챔피언을 몇 개 선택했는지

// origin
int Abomination[58];
int Coven[58];
int Dawnbringer[58];
int Draconic[58];
int Dragonslayer[58];
int Eternal[58];
int Forgotten[58];
int Hellion[58];
int Ironclad[58];
int Nightbringer[58];
int Redeemed[58];
int Revenant[58];
int Verdant[58];


// classes
int Assassin[58];
int Brawler[58];
int Caretaker[58];
int Cavalier[58];
int Cruel[58];
int God_King[58];
int Invoker[58];
int Knight[58];
int Legionnaire[58];
int Mystic[58];
int Ranger[58];
int Renewer[58];
int Skirmisher[58];
int Spellweaver[58];


// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {
    Abomination[index] = 0;
    Coven[index] = 0;
    Dawnbringer[index] = 0;
    Draconic[index] = 0;
    Dragonslayer[index] = 0;
    Eternal[index] = 0;
    Forgotten[index] = 0;
    Hellion[index] = 0;
    Ironclad[index] = 0;
    Nightbringer[index] = 0;
    Redeemed[index] = 0;
    Revenant[index] = 0;
    Verdant[index] = 0;
    

    // classes
    Assassin[index] = 0;
    Brawler[index] = 0;
    Cavalier[index] = 0;
    Caretaker[index] = 0;
    Cavalier[index] = 0;
    Cruel[index] = 0;
    God_King[index] = 0;
    Invoker[index] = 0;
    Knight[index] = 0;
    Legionnaire[index] = 0;
    Mystic[index] = 0;
    Ranger[index] = 0;
    Renewer[index] = 0;
    Skirmisher[index] = 0;
    Spellweaver[index] = 0;
}

void champions_info() {
    champions.push_back(make_tuple("아트록스", "Redeemed", "Legionnaire", "", 1)); 
    champions.push_back(make_tuple("그라가스", "Dawnbringer", "Cavalier", "", 1)); 
    champions.push_back(make_tuple("칼리스타", "Abomination", "Legionnaire", "", 1)); 
    champions.push_back(make_tuple("카직스", "Dawnbringer", "Assassin", "", 1)); 
    champions.push_back(make_tuple("클레드", "Hellion", "Cavalier", "", 1)); 
    champions.push_back(make_tuple("레오나", "Redeemed", "Knight", "", 1)); 
    champions.push_back(make_tuple("리산드라", "Coven", "Renewer", "", 1));
    champions.push_back(make_tuple("뽀삐", "Hellion", "Knight", "", 1));
    champions.push_back(make_tuple("우디르", "Draconic", "Skirmisher", "", 1)); 
    champions.push_back(make_tuple("베인", "Forgotten", "Ranger", "", 1)); 
    champions.push_back(make_tuple("블라디미르", "Nightbringer", "Renewer", "", 1));
    champions.push_back(make_tuple("워윅", "Forgotten", "Cavalier", "", 1));
    champions.push_back(make_tuple("직스", "Hellion", "Spellweaver", "", 1)); 

    champions.push_back(make_tuple("브랜드", "Abomination", "Spellweaver", "", 2)); 
    champions.push_back(make_tuple("헤카림", "Forgotten", "Cavalier", "", 2)); 
    champions.push_back(make_tuple("케넨", "Hellion", "Skirmisher", "", 2)); 
    champions.push_back(make_tuple("르블랑", "Coven", "Assassin", "", 2));
    champions.push_back(make_tuple("노틸러스", "Ironclad", "Knight", "", 2)); 
    champions.push_back(make_tuple("세주아니", "Nightbringer", "Cavalier", "", 2)); 
    champions.push_back(make_tuple("세트", "Draconic", "Cavalier", "", 2)); 
    champions.push_back(make_tuple("소라카", "Dawnbringer", "Renewer", "", 2)); 
    champions.push_back(make_tuple("신드라", "Redeemed", "Invoker", "", 2)); 
    champions.push_back(make_tuple("쓰레쉬", "Forgotten", "Knight", "", 2));
    champions.push_back(make_tuple("트런들", "God_King", "Skirmisher", "", 2));
    champions.push_back(make_tuple("바루스", "Redeemed", "Ranger", "", 2));
    champions.push_back(make_tuple("빅토르", "Forgotten", "Spellweaver", "", 2)); 

    champions.push_back(make_tuple("애쉬", "Verdant", "Draconic", "Ranger", 3));
    champions.push_back(make_tuple("카타리나", "Forgotten", "Assassin", "", 3)); 
    champions.push_back(make_tuple("리신", "Nightbringer", "Skirmisher", "", 3)); 
    champions.push_back(make_tuple("룰루", "Hellion", "Mystic", "", 3)); 
    champions.push_back(make_tuple("럭스", "Redeemed", "Mystic", "", 3)); 
    champions.push_back(make_tuple("모르가나", "Coven", "Nightbringer", "Mystic", 3));
    champions.push_back(make_tuple("니달리", "Dawnbringer", "Skirmisher", "", 3)); 
    champions.push_back(make_tuple("녹턴", "Revenant", "Assassin", "", 3)); 
    champions.push_back(make_tuple("누누", "Abomination", "Cavalier", "", 3)); 
    champions.push_back(make_tuple("판테온", "God_King", "Skirmisher", "", 3)); 
    champions.push_back(make_tuple("리븐", "Dawnbringer", "Legionnaire", "", 3)); 
    champions.push_back(make_tuple("야스오", "Nightbringer", "Legionnaire", "", 3));
    champions.push_back(make_tuple("자이라", "Draconic", "Spellweaver", "", 3));

    champions.push_back(make_tuple("아펠리오스", "Nightbringer", "Ranger", "", 4)); 
    champions.push_back(make_tuple("다이애나", "Nightbringer", "God_King", "Assassin", 4)); 
    champions.push_back(make_tuple("드레이븐", "Forgotten", "Legionnaire", "", 4)); 
    champions.push_back(make_tuple("아이번", "Revenant", "Invoker", "Renewer", 4)); 
    champions.push_back(make_tuple("잭스", "Ironclad", "Skirmisher", "", 4));
    champions.push_back(make_tuple("카르마", "Dawnbringer", "Invoker", "", 4)); 
    champions.push_back(make_tuple("모데카이저", "God_King", "Legionnaire", "", 4)); 
    champions.push_back(make_tuple("렐", "Redeemed", "Ironclad", "Cavalier", 4)); 
    champions.push_back(make_tuple("라이즈", "Abomination", "Forgotten", "Mystic", 4)); 
    champions.push_back(make_tuple("타릭", "Verdant", "Knight", "", 4)); 
    champions.push_back(make_tuple("벨코즈", "Redeemed", "Spellweaver", "", 4)); 

    champions.push_back(make_tuple("다리우스", "Nightbringer", "Knight", "God_King", 5)); 
    champions.push_back(make_tuple("가렌", "Dawnbringer", "Knight", "God_King", 5)); 
    champions.push_back(make_tuple("하이머딩거", "Draconic", "Caretaker", "Renewer", 5)); 
    champions.push_back(make_tuple("케일", "Redeemed", "Verdant", "Legionnaire", 5)); 
    champions.push_back(make_tuple("킨드레드", "Eternal", "Mystic", "Ranger", 5)); 
    champions.push_back(make_tuple("티모", "Hellion", "Cruel", "Invoker", 5)); 
    champions.push_back(make_tuple("비에고", "Forgotten", "Assassin", "Skirmisher", 5)); 
    champions.push_back(make_tuple("볼리베어", "Revenant", "Cavalier", "", 5)); 
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
            if (get<4>(champions[i]) < 4) level4_down_champions.push_back(champions[i]);
            if (get<4>(champions[i]) < 5) level6_down_champions.push_back(champions[i]);
            level7_up_champions.push_back(champions[i]);
        }
    }
}

// 선택이 완료된 조합의 시너지 점수를 계산하는 함수
int synerge_check(int index) {
    int synerge_count = 0;

    // origin
    if (Abomination[index] >= 3 && Abomination[index] < 4) synerge_count += 15;
    else if (Abomination[index] >= 4 && Abomination[index] < 5) synerge_count += 20;  
    else if (Abomination[index] >= 5) synerge_count += 25;

    if (Coven[index] >= 3) synerge_count += 15;
  
    if (Dawnbringer[index] >= 2 && Dawnbringer[index] < 4) synerge_count += 10;
    else if (Dawnbringer[index] >= 4 && Dawnbringer[index] < 6) synerge_count += 20;  
    else if (Dawnbringer[index] >= 6 && Dawnbringer[index] < 8) synerge_count += 30;
    else if (Dawnbringer[index] >= 8) synerge_count += 40;

    if (Draconic[index] >= 3 && Draconic[index] < 5) synerge_count += 15; 
    else if (Draconic[index] >= 5) synerge_count += 25;

    if (Dragonslayer[index] >= 2 && Dragonslayer[index] < 4) synerge_count += 10;
    else if (Dragonslayer[index] >= 4) synerge_count += 20;
    
    if (Eternal[index] >= 1) synerge_count += 5;

    if (Forgotten[index] >= 3 && Forgotten[index] < 6) synerge_count += 15;
    else if (Forgotten[index] >= 6 && Forgotten[index] < 9) synerge_count += 30;
    else if (Forgotten[index] >= 9) synerge_count += 45;  

    if (Hellion[index] >= 3 && Hellion[index] < 5) synerge_count += 15; 
    else if (Hellion[index] >= 5 && Hellion[index] < 7) synerge_count += 25; 
    else if (Hellion[index] >= 7) synerge_count += 35;

    if (Ironclad[index] >= 2 && Ironclad[index] < 3) synerge_count += 10;
    else if (Ironclad[index] >= 3) synerge_count += 15;  

    if (Nightbringer[index] >= 2 && Nightbringer[index] < 4) synerge_count += 10;
    else if (Nightbringer[index] >= 4 && Nightbringer[index] < 6) synerge_count += 20;
    else if (Nightbringer[index] >= 6 && Nightbringer[index] < 8) synerge_count += 30;  
    else if (Nightbringer[index] >= 8) synerge_count += 40;

    if (Redeemed[index] >= 3 && Redeemed[index] < 6) synerge_count += 15;
    else if (Redeemed[index] >= 6 && Redeemed[index] < 9) synerge_count += 30;
    else if (Redeemed[index] >= 9) synerge_count += 45;

    if (Revenant[index] >= 2 && Revenant[index] < 3) synerge_count += 10;
    else if (Revenant[index] >= 3) synerge_count += 15;

    if (Verdant[index] >= 2 && Verdant[index] < 3) synerge_count += 10;
    else if (Verdant[index] >= 3) synerge_count += 15;


    // classes
    if (Assassin[index] >= 2 && Assassin[index] < 4) synerge_count += 10;
    else if (Assassin[index] >= 4 && Assassin[index] < 6) synerge_count += 20;
    else if (Assassin[index] >= 6) synerge_count += 30;

    if (Brawler[index] >= 2 && Brawler[index] < 4) synerge_count += 10;
    else if (Brawler[index] >= 4) synerge_count += 20;

    if (Caretaker[index] == 1) synerge_count += 5;

    if (Cavalier[index] >= 2 && Cavalier[index] < 3) synerge_count += 10;
    else if (Cavalier[index] >= 3 && Cavalier[index] < 4) synerge_count += 15;
    else if (Cavalier[index] >= 4) synerge_count += 20;

    if (Cruel[index] == 1 ) synerge_count += 5;

    if (God_King[index] == 1) synerge_count += 5;  

    if (Invoker[index] >= 2 && Invoker[index] < 4) synerge_count += 10;
    else if (Invoker[index] >= 4) synerge_count += 20; 

    if (Knight[index] >= 2 && Knight[index] < 4) synerge_count += 10;
    else if (Knight[index] >= 4 && Knight[index] < 6) synerge_count += 20;
    else if (Knight[index] >= 6) synerge_count += 30;  

    if (Legionnaire[index] >= 2 && Legionnaire[index] < 4) synerge_count += 10;
    else if (Legionnaire[index] >= 4 && Legionnaire[index] < 6) synerge_count += 20;
    else if (Legionnaire[index] >= 6 && Legionnaire[index] < 8) synerge_count += 30;
    else if (Legionnaire[index] >= 8) synerge_count += 40;  

    if (Mystic[index] >= 2 && Mystic[index] < 3) synerge_count += 10;
    else if (Mystic[index] >= 3 && Mystic[index] < 4) synerge_count += 15;
    else if (Mystic[index] >= 4) synerge_count += 20;  

    if (Ranger[index] >= 2 && Ranger[index] < 4) synerge_count += 10;
    else if (Ranger[index] >= 4) synerge_count += 20;

    if (Renewer[index] >= 2 && Renewer[index] < 4) synerge_count += 10;
    else if (Renewer[index] >= 4) synerge_count += 20;  

    if (Skirmisher[index] >= 3 && Skirmisher[index] < 6) synerge_count += 15;
    else if (Skirmisher[index] >= 6) synerge_count += 30;   

    if (Spellweaver[index] >= 2 && Spellweaver[index] < 4) synerge_count += 10;
    else if (Spellweaver[index] >= 4) synerge_count += 20;  

    return synerge_count;
}

// 선택이 완료된 조합의 시너지를 계산하는 함수
void synerge_add(tuple <string, string, string, string, int> &champion, int index) {
    string origin = get<1>(champion);
    string classes = get<2>(champion);
    string additional = get<3>(champion);

    // origin
    if (origin == "Abomination") Abomination[index]++;
    else if (origin == "Coven") Coven[index]++;
    else if (origin == "Dawnbringer") Dawnbringer[index]++;
    else if (origin == "Draconic") Draconic[index]++;
    else if (origin == "Dragonslayer") Dragonslayer[index]++;
    else if (origin == "Forgotten") Forgotten[index]++;
    else if (origin == "Hellion") Hellion[index]++;
    else if (origin == "Eternal") Eternal[index]++;
    else if (origin == "Ironclad") Ironclad[index]++;
    else if (origin == "Revenant") Revenant[index]++;
    else if (origin == "Redeemed") Redeemed[index]++;
    else if (origin == "Verdant") Verdant[index]++;
    else if (origin == "Nightbringer") Nightbringer[index]++;
    else if (origin == "Assassin") Assassin[index]++;
    else if (origin == "Brawler") Brawler[index]++;
    else if (origin == "Cavalier") Cavalier[index]++;
    else if (origin == "Legionnaire") Legionnaire[index]++;  
    else if (origin == "Renewer") Renewer[index]++;
    else if (origin == "Caretaker") Caretaker[index]++;
    else if (origin == "Invoker") Invoker[index]++;
    else if (origin == "God_King") God_King[index]++;
    else if (origin == "Knight") Knight[index]++;
    else if (origin == "Ranger") Ranger[index]++;
    else if (origin == "Mystic") Mystic[index]++;
    else if (origin == "Cruel") Cruel[index]++;
    else if (origin == "Skirmisher") Skirmisher[index]++;
    else if (origin == "Spellweaver") Spellweaver[index]++;

    // class
    if (classes == "Assassin") Assassin[index]++;
    else if (classes == "Brawler") Brawler[index]++;
    else if (classes == "Cavalier") Cavalier[index]++;
    else if (classes == "Legionnaire") Legionnaire[index]++;  
    else if (classes == "Renewer") Renewer[index]++;
    else if (classes == "Caretaker") Caretaker[index]++;
    else if (classes == "Invoker") Invoker[index]++;
    else if (classes == "God_King") God_King[index]++;
    else if (classes == "Knight") Knight[index]++;
    else if (classes == "Ranger") Ranger[index]++;
    else if (classes == "Mystic") Mystic[index]++;
    else if (classes == "Cruel") Cruel[index]++;
    else if (classes == "Skirmisher") Skirmisher[index]++;
    else if (classes == "Spellweaver") Spellweaver[index]++;
    else if (classes == "Abomination") Abomination[index]++;
    else if (classes == "Coven") Coven[index]++;
    else if (classes == "Dawnbringer") Dawnbringer[index]++;
    else if (classes == "Draconic") Draconic[index]++;
    else if (classes == "Dragonslayer") Dragonslayer[index]++;
    else if (classes == "Forgotten") Forgotten[index]++;
    else if (classes == "Hellion") Hellion[index]++;
    else if (classes == "Eternal") Eternal[index]++;
    else if (classes == "Ironclad") Ironclad[index]++;
    else if (classes == "Revenant") Revenant[index]++;
    else if (classes == "Redeemed") Redeemed[index]++;
    else if (classes == "Verdant") Verdant[index]++;
    else if (classes == "Nightbringer") Nightbringer[index]++;

    // additional, 특성이 3개 있는 챔피언들 처리
    if (additional == "Assassin") Assassin[index]++;
    else if (additional == "Brawler") Brawler[index]++;
    else if (additional == "Cavalier") Cavalier[index]++;
    else if (additional == "Legionnaire") Legionnaire[index]++;  
    else if (additional == "Renewer") Renewer[index]++;
    else if (additional == "Caretaker") Caretaker[index]++;
    else if (additional == "Invoker") Invoker[index]++;
    else if (additional == "God_King") God_King[index]++;
    else if (additional == "Knight") Knight[index]++;
    else if (additional == "Ranger") Ranger[index]++;
    else if (additional == "Mystic") Mystic[index]++;
    else if (additional == "Cruel") Cruel[index]++;
    else if (additional == "Skirmisher") Skirmisher[index]++;
    else if (additional == "Spellweaver") Spellweaver[index]++;

}


int synerge_cost(tuple <string, string, string, string, int> &selected_champion) {
    return get<4>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    // origin
    if (Abomination[index] >= 3 && Abomination[index] < 4) synerge.append("3괴생명체 ");
    else if (Abomination[index] >= 4 && Abomination[index] < 5) synerge.append("4괴생명체 ");
    else if (Abomination[index] >= 5) synerge.append("5괴생명체 ");

    if (Coven[index] >= 3) synerge.append("3악의여단 ");
  
    if (Dawnbringer[index] >= 2 && Dawnbringer[index] < 4) synerge.append("2빛의인도자 ");
    else if (Dawnbringer[index] >= 4 && Dawnbringer[index] < 6) synerge.append("4빛의인도자 "); 
    else if (Dawnbringer[index] >= 6 && Dawnbringer[index] < 8) synerge.append("6빛의인도자 ");
    else if (Dawnbringer[index] >= 8) synerge.append("8빛의인도자 ");

    if (Draconic[index] >= 3 && Draconic[index] < 5) synerge.append("3용족 ");
    else if (Draconic[index] >= 5) synerge.append("5용족 ");

    if (Dragonslayer[index] >= 2 && Dragonslayer[index] < 4) synerge.append("2용사냥꾼 ");
    else if (Dragonslayer[index] >= 4) synerge.append("4용사냥꾼 ");
    
    if (Eternal[index] >= 1) synerge.append("1영겁 ");

    if (Forgotten[index] >= 3 && Forgotten[index] < 6) synerge.append("3망각 ");
    else if (Forgotten[index] >= 6 && Forgotten[index] < 9) synerge.append("6망각 ");
    else if (Forgotten[index] >= 9) synerge.append("9망각 ");

    if (Hellion[index] >= 3 && Hellion[index] < 5) synerge.append("3악동 ");
    else if (Hellion[index] >= 5 && Hellion[index] < 7) synerge.append("5악동 ");
    else if (Hellion[index] >= 7) synerge.append("7악동 ");

    if (Ironclad[index] >= 2 && Ironclad[index] < 3) synerge.append("2철갑 ");
    else if (Ironclad[index] >= 3) synerge.append("3철갑 ");  

    if (Nightbringer[index] >= 2 && Nightbringer[index] < 4) synerge.append("2어둠의인도자 ");
    else if (Nightbringer[index] >= 4 && Nightbringer[index] < 6) synerge.append("4어둠의인도자 ");
    else if (Nightbringer[index] >= 6 && Nightbringer[index] < 8) synerge.append("6어둠의인도자 ");
    else if (Nightbringer[index] >= 8) synerge.append("8어둠의인도자 ");

    if (Redeemed[index] >= 3 && Redeemed[index] < 6) synerge.append("3구원받은자 ");
    else if (Redeemed[index] >= 6 && Redeemed[index] < 9) synerge.append("6구원받은자 ");
    else if (Redeemed[index] >= 9) synerge.append("9구원받은자 ");

    if (Revenant[index] >= 2 && Revenant[index] < 3) synerge.append("2망령 ");
    else if (Revenant[index] >= 3) synerge.append("3망령 ");

    if (Verdant[index] >= 2 && Verdant[index] < 3) synerge.append("2신록 ");
    else if (Verdant[index] >= 3) synerge.append("3신록 ");


    // classes
    if (Assassin[index] >= 2 && Assassin[index] < 4) synerge.append("2암살자 ");
    else if (Assassin[index] >= 4 && Assassin[index] < 6) synerge.append("4암살자 ");
    else if (Assassin[index] >= 6) synerge.append("6암살자 ");

    if (Brawler[index] >= 2 && Brawler[index] < 4) synerge.append("2싸움꾼 ");
    else if (Brawler[index] >= 4) synerge.append("4싸움꾼 ");

    if (Caretaker[index] == 1) synerge.append("1용사육사 ");

    if (Cavalier[index] >= 2 && Cavalier[index] < 3) synerge.append("2기병대 ");
    else if (Cavalier[index] >= 3 && Cavalier[index] < 4) synerge.append("3기병대 ");
    else if (Cavalier[index] >= 4) synerge.append("4기병대 ");

    if (Cruel[index] == 1 ) synerge.append("1극악무도 ");

    if (God_King[index] == 1) synerge.append("1신왕 ");

    if (Invoker[index] >= 2 && Invoker[index] < 4) synerge.append("2기원자 ");
    else if (Invoker[index] >= 4) synerge.append("4기원자 ");

    if (Knight[index] >= 2 && Knight[index] < 4) synerge.append("2기사 ");
    else if (Knight[index] >= 4 && Knight[index] < 6) synerge.append("4기사 ");
    else if (Knight[index] >= 6) synerge.append("6기사 ");

    if (Legionnaire[index] >= 2 && Legionnaire[index] < 4) synerge.append("2군단 ");
    else if (Legionnaire[index] >= 4 && Legionnaire[index] < 6) synerge.append("4군단 ");
    else if (Legionnaire[index] >= 6 && Legionnaire[index] < 8) synerge.append("6군단 ");
    else if (Legionnaire[index] >= 8) synerge.append("8군단 ");

    if (Mystic[index] >= 2 && Mystic[index] < 3) synerge.append("2신비술사 ");
    else if (Mystic[index] >= 3 && Mystic[index] < 4) synerge.append("3신비술사 ");
    else if (Mystic[index] >= 4) synerge.append("4신비술사 "); 

    if (Ranger[index] >= 2 && Ranger[index] < 4) synerge.append("2정찰대 ");
    else if (Ranger[index] >= 4) synerge.append("4정찰대 ");

    if (Renewer[index] >= 2 && Renewer[index] < 4) synerge.append("2재생술사 ");
    else if (Renewer[index] >= 4) synerge.append("4재생술사 ");

    if (Skirmisher[index] >= 3 && Skirmisher[index] < 6) synerge.append("3척후병 ");
    else if (Skirmisher[index] >= 6) synerge.append("6척후병 "); 

    if (Spellweaver[index] >= 2 && Spellweaver[index] < 4) synerge.append("2주문술사 ");
    else if (Spellweaver[index] >= 4) synerge.append("4주문술사 "); 
 
    return synerge;
}


vector <int> pick[58];

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
            cost += synerge_cost(level4_down_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(level4_down_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            cost += synerge_cost(user_select_champ[i]);
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
            cost += synerge_cost(level6_down_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(level6_down_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            cost += synerge_cost(user_select_champ[i]);
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
            cost += synerge_cost(level7_up_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(level7_up_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            cost += synerge_cost(user_select_champ[i]);
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
    start = time(NULL);

    // champ vector creation
    champions_info();
    makingChampionList(argc, argv);

    vector <thread> threads;

    cout << "Processing... " << endl;

    // level check
    if (level <= 4) {
        if (selected_size > level) {
            cout << "레벨보다 챔프수가 더 많습니다. error(-1)" << "\n";
            exit(-1);
        }
        else if (selected_size == level) combination_level4_down(0, 0);
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
        if (selected_size > level) {
            cout << "레벨보다 챔프수가 더 많습니다. error(-1)" << "\n";
            exit(-1);
        }
        else if (selected_size == level) combination_level6_down(0, 0);
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
        if (selected_size > level) {
            cout << "레벨보다 챔프수가 더 많습니다. error(-1)" << "\n";
            exit(-1);
        }
        else if (selected_size == level) combination_level7_up(0, 0);
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
