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
    champions.push_back(make_tuple("����", "battlecast", "inflitrator", "", 1)); // Nocturne
    champions.push_back(make_tuple("������Ʈ", "rebel", "brawler", "", 1)); // Malphight
    champions.push_back(make_tuple("����", "rebel", "demolitionist", "", 1)); // Ziggs
    champions.push_back(make_tuple("�ǻ�", "starguardian", "vanguard", "", 1)); // Poppy
    champions.push_back(make_tuple("����", "starguardian", "sorcerer", "", 1)); // Zoe
    champions.push_back(make_tuple("�ǿ���", "cybernetic", "blademaster", "", 1)); // Fiora
    champions.push_back(make_tuple("������", "cybernetic", "vanguard", "", 1)); // Leona
    champions.push_back(make_tuple("����Ʋ��", "chronos", "sniper", "", 1)); // Caitlyn
    champions.push_back(make_tuple("Ʈ��", "chronos", "sorcerer", "", 1)); // Twisted Fate
    champions.push_back(make_tuple("�׷��̺���", "space_pirate", "blaster", "", 1)); // Graves
    champions.push_back(make_tuple("�ھ�", "celestial", "blademaster", "", 1)); // Xayah
    champions.push_back(make_tuple("�ڸ���", "darkstar", "protector", "", 1)); // Jarvan
    champions.push_back(make_tuple("�϶����", "battlecast", "brawler", "", 1)); // illaoi

    champions.push_back(make_tuple("�ִ�", "mech_pilot", "sorcerer", "", 2)); // Annie
    champions.push_back(make_tuple("����", "rebel", "inflitrator", "", 2)); // Zed
    champions.push_back(make_tuple("�߽���", "rebel", "blademaster", "", 2)); // Yasuo
    champions.push_back(make_tuple("��ƿ����", "astro", "vanguard", "", 2)); // Nautilus
    champions.push_back(make_tuple("�Ƹ�", "starguardian", "sorcerer", "", 2)); // Ahri
    champions.push_back(make_tuple("��þ�", "cybernetic", "blaster", "", 2)); // Lucian
    champions.push_back(make_tuple("����ũ��ũ", "chronos", "brawler", "", 2)); // Blitzcrank
    champions.push_back(make_tuple("��", "chronos", "blademaster", "", 2)); // Shen
    champions.push_back(make_tuple("��ī����", "darkstar", "vanguard", "", 2)); // Mordekaiser
    champions.push_back(make_tuple("�ٸ��콺", "space_pirate", "mana_reaver", "", 2)); // Darius
    champions.push_back(make_tuple("��¥��", "celestial", "protector", "", 2)); // Xin'Zhao
    champions.push_back(make_tuple("��ĭ", "celestial", "protector", "", 2)); // Rakan
    champions.push_back(make_tuple("�ڱ׸�", "battlecast", "blaster", "", 2)); // Kog'maw

    champions.push_back(make_tuple("����", "mech_pilot", "demolitionist", "", 3)); // Rumble
    champions.push_back(make_tuple("��������", "rebel", "blademaster", "", 3)); // Master Yi
    champions.push_back(make_tuple("�ŵ��", "starguardian", "sorcerer", "", 3)); // Syndra
    champions.push_back(make_tuple("����", "starguardian", "protector", "", 3)); // Neeko
    champions.push_back(make_tuple("����", "cybernetic", "brawler", "", 3)); // Vi
    champions.push_back(make_tuple("�����", "chronos", "blaster", "", 3)); // Ezreal
    champions.push_back(make_tuple("ī�ÿ����", "battlecast", "mystic", "", 3)); // Cassiopeia
    champions.push_back(make_tuple("ī����", "darkstar", "mystic", "", 3)); // Karma
    champions.push_back(make_tuple("����", "darkstar", "inflitrator", "", 3)); // Shaco
    champions.push_back(make_tuple("���̽�", "space_pirate", "vanguard", "", 3)); // Jayce
    champions.push_back(make_tuple("�ֽ�", "celestial", "sniper", "", 3)); // Ashe
    champions.push_back(make_tuple("�ٵ�", "astro", "mystic", "", 3)); // Bard
    champions.push_back(make_tuple("����", "cybernetic", "sniper", "", 3)); // Vayne

    champions.push_back(make_tuple("���丣", "battlecast", "sorcerer", "", 4)); // Viktor
    champions.push_back(make_tuple("Ƽ��", "astro", "sniper", "", 4)); // Teemo
    champions.push_back(make_tuple("����", "mech_pilot", "inflitrator", "", 4)); // Fizz
    champions.push_back(make_tuple("¡ũ��", "rebel", "blaster", "", 4)); // Jinx
    champions.push_back(make_tuple("����", "chronos", "blademaster", "", 4)); // Riven
    champions.push_back(make_tuple("�Ҷ�ī", "starguardian", "mystic", "", 4)); // Soraka
    champions.push_back(make_tuple("�̷�����", "cybernetic", "blademaster", "mana_reaver", 4)); // Irelia
    champions.push_back(make_tuple("����", "chronos", "vanguard", "", 4)); // Wukong
    champions.push_back(make_tuple("��", "darkstar", "sniper", "", 4)); // Jhin
    champions.push_back(make_tuple("����", "astro", "brawler", "", 4)); // Gnar

    champions.push_back(make_tuple("�ƿ��", "rebel", "starship", "", 5)); // Aurelion Sol
    champions.push_back(make_tuple("�츣��", "battlecast", "protector", "", 5)); // Urgot
    champions.push_back(make_tuple("����", "cybernetic", "inflitrator", "", 5)); // Ekko
    champions.push_back(make_tuple("������", "chronos", "mana_reaver", "", 5)); // Thresh
    champions.push_back(make_tuple("����", "darkstar", "sorcerer", "", 5)); // Xerath
    champions.push_back(make_tuple("���÷�ũ", "space_pirate", "demolitionist", "mercenary", 5)); // Gangplank
    champions.push_back(make_tuple("���", "celestial", "mystic", "", 5)); // Lulu
    champions.push_back(make_tuple("�ܳ�", "starguardian", "paragon", "", 5)); // Janna


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
            cout << "������ è�Ǿ��� �������� �ʽ��ϴ�.\n��Ż�ڰ� �ִ��� Ȯ�����ּ���\n";
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

    if (celestial[index] >= 2 && celestial[index] < 4) synerge.append("2õ�� ");
    else if (celestial[index] >= 4 && celestial[index] < 6) synerge.append("4õ�� ");
    else if (celestial[index] >= 6) synerge.append("6õ�� ");

    if (cybernetic[index] >= 3 && (cybernetic[index] < 6)) synerge.append("3���̹���ƽ ");
    else if (cybernetic[index] >= 6 ) synerge.append("6���̹���ƽ ");

    if (mech_pilot[index] >= 3) synerge.append("3��ī���Ϸ� ");

    if (space_pirate[index] >= 2 && (space_pirate[index] < 4)) synerge.append("2�������� ");
    else if (space_pirate[index] >= 4) synerge.append("4�������� ");

    if (chronos[index] >= 2 && (chronos[index] < 4)) synerge.append("2�ð��� ");
    else if (chronos[index] >= 4 && (chronos[index] < 6)) synerge.append("4�ð��� ");
    else if (chronos[index] >= 6 && chronos[index] < 8) synerge.append("6�ð��� ");
    else if (chronos[index] >= 8) synerge.append("8�ð��� ");

    if (darkstar[index] >= 2 && (darkstar[index] < 4)) synerge.append("2�����Ǻ� ");
    else if (darkstar[index] >= 4 && (darkstar[index] < 6)) synerge.append("4�����Ǻ� ");
    else if (darkstar[index] >= 6 ) synerge.append("6�����Ǻ� ");

    if (rebel[index] >= 3 && (rebel[index] < 6)) synerge.append("3�ݱ� ");
    else if (rebel[index] >= 6 ) synerge.append("6�ݱ� ");

    if (starguardian[index] >= 3 && (starguardian[index] < 6)) synerge.append("3����ȣ�� ");
    else if (starguardian[index] >= 6 ) synerge.append("6����ȣ�� ");

    if (battlecast[index] >= 2 && (battlecast[index] < 4)) synerge.append("2������� ");
    else if (battlecast[index] >= 4 && (battlecast[index] < 6)) synerge.append("4������� ");
    else if (battlecast[index] >= 6 ) synerge.append("6������� ");

    if (astro[index] >= 3) synerge.append("3���ֺ���� ");

    if (blademaster[index] >= 3 && (blademaster[index] < 6)) synerge.append("3�˻� ");
    else if (blademaster[index] >= 6 ) synerge.append("6�˻� ");

    if (brawler[index] >= 2 && (brawler[index] < 4)) synerge.append("2�ο�� ");
    else if (brawler[index] >= 4) synerge.append("4�ο�� ");

    if (demolitionist[index] >= 2) synerge.append("2���ı� ");

    if (mana_reaver[index] >= 2) synerge.append("2������Ż�� ");

    if (mercenary[index] >= 1) synerge.append("1�뺴 ");

    if (protector[index] >= 2 && (protector[index] < 4)) synerge.append("2��ȣ�� ");
    else if (protector[index] >= 4 && (protector[index] < 6)) synerge.append("4��ȣ�� ");
    else if (protector[index] >= 6) synerge.append("6��ȣ�� ");

    if (sorcerer[index] >= 2 && (sorcerer[index] < 4)) synerge.append("2������ ");
    else if (sorcerer[index] >= 4 && (sorcerer[index] < 6)) synerge.append("4������ ");
    else if (sorcerer[index] >= 6 && sorcerer[index] < 8) synerge.append("6������ ");
    else if (sorcerer[index] >= 8) synerge.append("8������ ");

    if (starship[index] >= 1) synerge.append("1���ּ� ");

    if (blaster[index] >= 2 && (blaster[index] < 4)) synerge.append("2������ ");
    else if (blaster[index] >= 4) synerge.append("4������ ");

    if (inflitrator[index] >= 2 && (inflitrator[index] < 4)) synerge.append("2������ ");
    else if (inflitrator[index] >= 4 && (inflitrator[index] < 6)) synerge.append("4������ ");

    if (mystic[index] >= 2 && (mystic[index] < 4)) synerge.append("2�ź���� ");
    else if (mystic[index] >= 4) synerge.append("4�ź���� ");

    if (sniper[index] >= 2 && sniper[index] < 4) synerge.append("2���ݼ� ");
    else if (sniper[index] >= 4) synerge.append("4���ݼ� ");

    if (vanguard[index] >= 2 && (vanguard[index] < 4)) synerge.append("2������ ");
    else if (vanguard[index] >= 4 && vanguard[index] < 6) synerge.append("4������ ");
    else if (vanguard[index] >= 6 && vanguard[index] < 8) synerge.append("6������ ");

    if (paragon[index] >= 1) synerge.append("1�ε��� ");

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
            cout << "�������� è������ �� �����ϴ�. error(-1)" << "\n";
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
            cout << "�������� è������ �� �����ϴ�. error(-1)" << "\n";
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
            cout << "�������� è������ �� �����ϴ�. error(-1)" << "\n";
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
    cout << "�� ����: " << overall_combination.size() << "\n";
    cout << "�ְ� �ó��� ����: " << get<0>(overall_combination.top()) << "\n";
    cout << "LEVEL" << level << " ����" << "\n";

    int loop = stoi(argv[2]) < overall_combination.size() ? stoi(argv[2]) : overall_combination.size();

    for (int i = 0; i < loop; i++) {
        cout << "���� " << i+1 << "\n";
        cout << "  è�Ǿ�: " << get<2>(overall_combination.top()) << "\n";
        cout << "  �ó���: " << get<3>(overall_combination.top()) << "\n";
        cout << "  �ó��� ����: " << get<0>(overall_combination.top()) << "\n";
        cout << "  �ڽ�Ʈ: " << get<1>(overall_combination.top()) << "\n\n\n";
        overall_combination.pop();
    }
    return 0;

}