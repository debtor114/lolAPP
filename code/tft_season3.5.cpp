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

vector < tuple <string, string, string, string, int> > champions;
vector < tuple <string, string, string, string, int> > level4_down_champions;
vector < tuple <string, string, string, string, int> > level6_down_champions;
vector < tuple <string, string, string, string, int> > level7_up_champions;
vector < tuple <string, string, string, string, int> > user_select_champ;

int selected_size;

int celestial[57];
int cybernetic[57];
int mech_pilot[57];
int space_pirate[57];
int chronos[57];
int darkstar[57];
int rebel[57];
int starguardian[57];
int astro[57];
int battlecast[57];


int blademaster[57];
int brawler[57];
int demolitionist[57];
int mana_reaver[57];
int mercenary[57];
int protector[57];
int sorcerer[57];
int starship[57];
int blaster[57];
int inflitrator[57];
int mystic[57];
int sniper[57];
int vanguard[57];
int paragon[57];


void init(int index) {
    celestial[index] = 0;
    cybernetic[index] = 0;
    mech_pilot[index] = 0;
    space_pirate[index] = 0;
    chronos[index] = 0;
    darkstar[index] = 0;
    rebel[index] = 0;
    starguardian[index] = 0;
    astro[index] = 0;
    battlecast[index] = 0;

    blademaster[index] = 0;
    brawler[index] = 0;
    demolitionist[index] = 0;
    mana_reaver[index] = 0;
    mercenary[index] = 0;
    protector[index] = 0;
    sorcerer[index] = 0;
    starship[index] = 0;
    blaster[index] = 0;
    inflitrator[index] = 0;
    mystic[index] = 0;
    sniper[index] = 0;
    vanguard[index] = 0;
    paragon[index] = 0;
}

void champions_info() {
    champions.push_back(make_tuple("녹턴", "battlecast", "inflitrator", "", 1)); // Nocturne
    champions.push_back(make_tuple("말파이트", "rebel", "brawler", "", 1)); // Malphight
    champions.push_back(make_tuple("직스", "rebel", "demolitionist", "", 1)); // Ziggs
    champions.push_back(make_tuple("뽀삐", "starguardian", "vanguard", "", 1)); // Poppy
    champions.push_back(make_tuple("조이", "starguardian", "sorcerer", "", 1)); // Zoe
    champions.push_back(make_tuple("피오라", "cybernetic", "blademaster", "", 1)); // Fiora
    champions.push_back(make_tuple("레오나", "cybernetic", "vanguard", "", 1)); // Leona
    champions.push_back(make_tuple("케이틀린", "chronos", "sniper", "", 1)); // Caitlyn
    champions.push_back(make_tuple("트페", "chronos", "sorcerer", "", 1)); // Twisted Fate
    champions.push_back(make_tuple("그레이브즈", "space_pirate", "blaster", "", 1)); // Graves
    champions.push_back(make_tuple("자야", "celestial", "blademaster", "", 1)); // Xayah
    champions.push_back(make_tuple("자르반", "darkstar", "protector", "", 1)); // Jarvan
    champions.push_back(make_tuple("일라오이", "battlecast", "brawler", "", 1)); // illaoi

    champions.push_back(make_tuple("애니", "mech_pilot", "sorcerer", "", 2)); // Annie
    champions.push_back(make_tuple("제드", "rebel", "inflitrator", "", 2)); // Zed
    champions.push_back(make_tuple("야스오", "rebel", "blademaster", "", 2)); // Yasuo
    champions.push_back(make_tuple("노틸러스", "astro", "vanguard", "", 2)); // Nautilus
    champions.push_back(make_tuple("아리", "starguardian", "sorcerer", "", 2)); // Ahri
    champions.push_back(make_tuple("루시안", "cybernetic", "blaster", "", 2)); // Lucian
    champions.push_back(make_tuple("블리츠크랭크", "chronos", "brawler", "", 2)); // Blitzcrank
    champions.push_back(make_tuple("쉔", "chronos", "blademaster", "", 2)); // Shen
    champions.push_back(make_tuple("모데카이저", "darkstar", "vanguard", "", 2)); // Mordekaiser
    champions.push_back(make_tuple("다리우스", "space_pirate", "mana_reaver", "", 2)); // Darius
    champions.push_back(make_tuple("신짜오", "celestial", "protector", "", 2)); // Xin'Zhao
    champions.push_back(make_tuple("라칸", "celestial", "protector", "", 2)); // Rakan
    champions.push_back(make_tuple("코그모", "battlecast", "blaster", "", 2)); // Kog'maw

    champions.push_back(make_tuple("럼블", "mech_pilot", "demolitionist", "", 3)); // Rumble
    champions.push_back(make_tuple("마스터이", "rebel", "blademaster", "", 3)); // Master Yi
    champions.push_back(make_tuple("신드라", "starguardian", "sorcerer", "", 3)); // Syndra
    champions.push_back(make_tuple("니코", "starguardian", "protector", "", 3)); // Neeko
    champions.push_back(make_tuple("바이", "cybernetic", "brawler", "", 3)); // Vi
    champions.push_back(make_tuple("이즈리얼", "chronos", "blaster", "", 3)); // Ezreal
    champions.push_back(make_tuple("카시오페아", "battlecast", "mystic", "", 3)); // Cassiopeia
    champions.push_back(make_tuple("카르마", "darkstar", "mystic", "", 3)); // Karma
    champions.push_back(make_tuple("샤코", "darkstar", "inflitrator", "", 3)); // Shaco
    champions.push_back(make_tuple("제이스", "space_pirate", "vanguard", "", 3)); // Jayce
    champions.push_back(make_tuple("애쉬", "celestial", "sniper", "", 3)); // Ashe
    champions.push_back(make_tuple("바드", "astro", "mystic", "", 3)); // Bard
    champions.push_back(make_tuple("베인", "cybernetic", "sniper", "", 3)); // Vayne

    champions.push_back(make_tuple("빅토르", "battlecast", "sorcerer", "", 4)); // Viktor
    champions.push_back(make_tuple("티모", "astro", "sniper", "", 4)); // Teemo
    champions.push_back(make_tuple("피즈", "mech_pilot", "inflitrator", "", 4)); // Fizz
    champions.push_back(make_tuple("징크스", "rebel", "blaster", "", 4)); // Jinx
    champions.push_back(make_tuple("리븐", "chronos", "blademaster", "", 4)); // Riven
    champions.push_back(make_tuple("소라카", "starguardian", "mystic", "", 4)); // Soraka
    champions.push_back(make_tuple("이렐리아", "cybernetic", "blademaster", "mana_reaver", 4)); // Irelia
    champions.push_back(make_tuple("오공", "chronos", "vanguard", "", 4)); // Wukong
    champions.push_back(make_tuple("진", "darkstar", "sniper", "", 4)); // Jhin
    champions.push_back(make_tuple("나르", "astro", "brawler", "", 4)); // Gnar

    champions.push_back(make_tuple("아우솔", "rebel", "starship", "", 5)); // Aurelion Sol
    champions.push_back(make_tuple("우르곳", "battlecast", "protector", "", 5)); // Urgot
    champions.push_back(make_tuple("에코", "cybernetic", "inflitrator", "", 5)); // Ekko
    champions.push_back(make_tuple("쓰레쉬", "chronos", "mana_reaver", "", 5)); // Thresh
    champions.push_back(make_tuple("제라스", "darkstar", "sorcerer", "", 5)); // Xerath
    champions.push_back(make_tuple("갱플랭크", "space_pirate", "demolitionist", "mercenary", 5)); // Gangplank
    champions.push_back(make_tuple("룰루", "celestial", "mystic", "", 5)); // Lulu
    champions.push_back(make_tuple("잔나", "starguardian", "paragon", "", 5)); // Janna


}

void makingChampionList(int argc, char** argv) {
    if (argc >= 4) {
        for (int i = 3; i < argc; i++) {
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

int synerge_check(int index) {
    int synerge_count = 0;

    if (celestial[index] >= 2 && celestial[index] < 4) synerge_count += 10;
    else if (celestial[index] >= 4 && celestial[index] < 6) synerge_count += 21;
    else if (celestial[index] >= 6) synerge_count += 32;

    if (cybernetic[index] >= 3 && cybernetic[index] < 6) synerge_count += 15;
    else if (cybernetic[index] >= 6) synerge_count += 32;  

    if (mech_pilot[index] >= 3) synerge_count += 15;  

    if (space_pirate[index] >= 2 && space_pirate[index] < 4) synerge_count += 10;
    if (space_pirate[index] >= 4) synerge_count += 21;

    if (chronos[index] >= 2 && chronos[index] < 4) synerge_count += 10;
    else if (chronos[index] >= 4 && chronos[index] < 6) synerge_count += 21;
    else if (chronos[index] >= 6 && chronos[index] < 8) synerge_count += 32;
    else if (chronos[index] >= 8) synerge_count += 43;

    if (darkstar[index] >= 2 && darkstar[index] < 4) synerge_count += 10;
    else if (darkstar[index] >= 4 && darkstar[index] < 6) synerge_count += 21;
    else if (darkstar[index] >= 6) synerge_count += 32;

    if (rebel[index] >= 3 && rebel[index] < 6) synerge_count += 15;
    else if (rebel[index] >= 6) synerge_count += 32;  

    if (starguardian[index] >= 3 && starguardian[index] < 6) synerge_count += 15;
    else if (starguardian[index] >= 6) synerge_count += 32;  

    if (astro[index] >= 3) synerge_count += 15;  

    if (battlecast[index] >= 2 && battlecast[index] < 4) synerge_count += 10;
    else if (battlecast[index] >= 4 && battlecast[index] < 6) synerge_count += 21;
    else if (battlecast[index] >= 6) synerge_count += 32;


    if (blademaster[index] >= 3 && blademaster[index] < 6) synerge_count += 15;
    else if (blademaster[index] >= 6) synerge_count += 32; 

    if (brawler[index] >= 2 && brawler[index] < 4) synerge_count += 10;
    else if (brawler[index] >= 4) synerge_count += 21; 

    if (demolitionist[index] >= 2) synerge_count += 10;

    if (mana_reaver[index] >= 2) synerge_count += 10;

    if (mercenary[index] >= 1) synerge_count += 5;

    if (protector[index] >= 2 && protector[index] < 4) synerge_count += 10;
    else if (protector[index] >= 4) synerge_count += 21;

    if (sorcerer[index] >= 2 && sorcerer[index] < 4) synerge_count += 10;
    else if (sorcerer[index] >= 4 && sorcerer[index] < 6) synerge_count += 21;
    else if (sorcerer[index] >= 6 && sorcerer[index] < 8) synerge_count += 32;
    else if (sorcerer[index] >= 8) synerge_count += 43;

    if (starship[index] >= 1) synerge_count += 5;

    if (blaster[index] >= 2 && blaster[index] < 4) synerge_count += 10;
    else if (blaster[index] >= 4) synerge_count += 21;

    if (inflitrator[index] >= 2 && inflitrator[index] < 4) synerge_count += 10;
    else if (inflitrator[index] >= 4) synerge_count += 21;

    if (mystic[index] >= 2 && mystic[index] < 4) synerge_count += 10;
    else if (mystic[index] >= 4) synerge_count += 21;

    if (sniper[index] >= 2 && sniper[index] < 4 ) synerge_count += 10;
    else if (sniper[index] >= 4) synerge_count += 21;

    if (vanguard[index] >= 2 && vanguard[index] < 4) synerge_count += 10;
    else if (vanguard[index] >= 4 && vanguard[index] < 6) synerge_count += 21;
    else if (vanguard[index] >= 6 ) synerge_count += 32;

    if (paragon[index] >= 1) synerge_count += 5;

    return synerge_count;
}


void synerge_add(tuple <string, string, string, string, int> &champion, int index) {
    string tribe = get<1>(champion);
    string character = get<2>(champion);
    string additional = get<3>(champion);

    if (tribe == "celestial") celestial[index]++;
    else if (tribe == "cybernetic") cybernetic[index]++;
    else if (tribe == "mech_pilot") mech_pilot[index]++;
    else if (tribe == "space_pirate") space_pirate[index]++;
    else if (tribe == "chronos") chronos[index]++;
    else if (tribe == "darkstar") darkstar[index]++;
    else if (tribe == "rebel") rebel[index]++;
    else if (tribe == "starguardian") starguardian[index]++;
    else if (tribe == "battlecast") battlecast[index]++;
    else if (tribe == "astro") astro[index]++;

    if (character == "blademaster") blademaster[index]++;
    else if (character == "brawler") brawler[index]++;
    else if (character == "demolitionist") demolitionist[index]++;
    else if (character == "mana_reaver") mana_reaver[index]++;  
    else if (character == "protector") protector[index]++;
    else if (character == "sorcerer") sorcerer[index]++;
    else if (character == "blaster") blaster[index]++;
    else if (character == "inflitrator") inflitrator[index]++;
    else if (character == "mystic") mystic[index]++;
    else if (character == "sniper") sniper[index]++;
    else if (character == "vanguard") vanguard[index]++;
    else if (character == "starship") starship[index]++;
    else if (character == "paragon") paragon[index]++;

    if (additional == "mercenary") mercenary[index]++;
    else if (additional == "mana_reaver") mana_reaver[index]++;
}


int synerge_cost(tuple <string, string, string, string, int> &selected_champion) {
    return get<4>(selected_champion);
}


string synerge_print(int index) {
    string synerge = "";

    if (celestial[index] >= 2 && celestial[index] < 4) synerge.append("2천상 ");
    else if (celestial[index] >= 4 && celestial[index] < 6) synerge.append("4천상 ");
    else if (celestial[index] >= 6) synerge.append("6천상 ");

    if (cybernetic[index] >= 3 && (cybernetic[index] < 6)) synerge.append("3사이버네틱 ");
    else if (cybernetic[index] >= 6 ) synerge.append("6사이버네틱 ");

    if (mech_pilot[index] >= 3) synerge.append("3메카파일럿 ");

    if (space_pirate[index] >= 2 && (space_pirate[index] < 4)) synerge.append("2우주해적 ");
    else if (space_pirate[index] >= 4) synerge.append("4우주해적 ");

    if (chronos[index] >= 2 && (chronos[index] < 4)) synerge.append("2시공간 ");
    else if (chronos[index] >= 4 && (chronos[index] < 6)) synerge.append("4시공간 ");
    else if (chronos[index] >= 6 && chronos[index] < 8) synerge.append("6시공간 ");
    else if (chronos[index] >= 8) synerge.append("8시공간 ");

    if (darkstar[index] >= 2 && (darkstar[index] < 4)) synerge.append("2암흑의별 ");
    else if (darkstar[index] >= 4 && (darkstar[index] < 6)) synerge.append("4암흑의별 ");
    else if (darkstar[index] >= 6 ) synerge.append("6암흑의별 ");

    if (rebel[index] >= 3 && (rebel[index] < 6)) synerge.append("3반군 ");
    else if (rebel[index] >= 6 ) synerge.append("6반군 ");

    if (starguardian[index] >= 3 && (starguardian[index] < 6)) synerge.append("3별수호자 ");
    else if (starguardian[index] >= 6 ) synerge.append("6별수호자 ");

    if (battlecast[index] >= 2 && (battlecast[index] < 4)) synerge.append("2전투기계 ");
    else if (battlecast[index] >= 4 && (battlecast[index] < 6)) synerge.append("4전투기계 ");
    else if (battlecast[index] >= 6 ) synerge.append("6전투기계 ");

    if (astro[index] >= 3) synerge.append("3우주비행사 ");

    if (blademaster[index] >= 3 && (blademaster[index] < 6)) synerge.append("3검사 ");
    else if (blademaster[index] >= 6 ) synerge.append("6검사 ");

    if (brawler[index] >= 2 && (brawler[index] < 4)) synerge.append("2싸움꾼 ");
    else if (brawler[index] >= 4) synerge.append("4싸움꾼 ");

    if (demolitionist[index] >= 2) synerge.append("2폭파광 ");

    if (mana_reaver[index] >= 2) synerge.append("2마나약탈자 ");

    if (mercenary[index] >= 1) synerge.append("1용병 ");

    if (protector[index] >= 2 && (protector[index] < 4)) synerge.append("2수호자 ");
    else if (protector[index] >= 4 && (protector[index] < 6)) synerge.append("4수호자 ");
    else if (protector[index] >= 6) synerge.append("6수호자 ");

    if (sorcerer[index] >= 2 && (sorcerer[index] < 4)) synerge.append("2마법사 ");
    else if (sorcerer[index] >= 4 && (sorcerer[index] < 6)) synerge.append("4마법사 ");
    else if (sorcerer[index] >= 6 && sorcerer[index] < 8) synerge.append("6마법사 ");
    else if (sorcerer[index] >= 8) synerge.append("8마법사 ");

    if (starship[index] >= 1) synerge.append("1우주선 ");

    if (blaster[index] >= 2 && (blaster[index] < 4)) synerge.append("2총잡이 ");
    else if (blaster[index] >= 4) synerge.append("4총잡이 ");

    if (inflitrator[index] >= 2 && (inflitrator[index] < 4)) synerge.append("2잠입자 ");
    else if (inflitrator[index] >= 4 && (inflitrator[index] < 6)) synerge.append("4잠입자 ");

    if (mystic[index] >= 2 && (mystic[index] < 4)) synerge.append("2신비술사 ");
    else if (mystic[index] >= 4) synerge.append("4신비술사 ");

    if (sniper[index] >= 2 && sniper[index] < 4) synerge.append("2저격수 ");
    else if (sniper[index] >= 4) synerge.append("4저격수 ");

    if (vanguard[index] >= 2 && (vanguard[index] < 4)) synerge.append("2선봉대 ");
    else if (vanguard[index] >= 4 && vanguard[index] < 6) synerge.append("4선봉대 ");
    else if (vanguard[index] >= 6 && vanguard[index] < 8) synerge.append("6선봉대 ");

    if (paragon[index] >= 1) synerge.append("1인도자 ");

    return synerge;
}


vector <int> pick[57];
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
    time_t start, middle, end;
    double result;
    ios::sync_with_stdio(false);

    level = stoi(argv[1]);
    start = time(NULL);
    
    // champ vector creation
    champions_info();
    makingChampionList(argc, argv);

    vector <thread> threads;

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