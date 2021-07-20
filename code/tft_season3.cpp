#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstdlib>

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
int max_value;

int celestial[52];
int cybernetic[52];
int mech_pilot[52];
int space_pirate[52];
int valkyrie[52];
int chronos[52];
int darkstar[52];
int rebel[52];
int starguardian[52];
int voidz[52];

int blademaster[52];
int brawler[52];
int demolitionist[52];
int mana_reaver[52];
int mercenary[52];
int protector[52];
int sorcerer[52];
int starship[52];
int blaster[52];
int inflitrator[52];
int mystic[52];
int sniper[52];
int vanguard[52];


void init(int index) {
    celestial[index] = 0;
    cybernetic[index] = 0;
    mech_pilot[index] = 0;
    space_pirate[index] = 0;
    valkyrie[index] = 0;
    chronos[index] = 0;
    darkstar[index] = 0;
    rebel[index] = 0;
    starguardian[index] = 0;
    voidz[index] = 0;

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
}

void champions_info() {
    champions.push_back(make_tuple("카직스", "voidz", "inflitrator", "", 1)); // Kha'Zix
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

    champions.push_back(make_tuple("애니", "mech_pilot", "sorcerer", "", 2)); // Annie
    champions.push_back(make_tuple("소나", "rebel", "mystic", "", 2)); // Sona
    champions.push_back(make_tuple("야스오", "rebel", "blademaster", "", 2)); // Yasuo
    champions.push_back(make_tuple("카이사", "valkyrie", "inflitrator", "", 2)); // Kai'sa
    champions.push_back(make_tuple("아리", "starguardian", "sorcerer", "", 2)); // Ahri
    champions.push_back(make_tuple("루시안", "cybernetic", "blaster", "", 2)); // Lucian
    champions.push_back(make_tuple("블리츠크랭크", "chronos", "brawler", "", 2)); // Blitzcrank
    champions.push_back(make_tuple("쉔", "chronos", "blademaster", "", 2)); // Shen
    champions.push_back(make_tuple("모데카이저", "darkstar", "vanguard", "", 2)); // Mordekaiser
    champions.push_back(make_tuple("다리우스", "space_pirate", "mana_reaver", "", 2)); // Darius
    champions.push_back(make_tuple("신짜오", "celestial", "protector", "", 2)); // Xin'Zhao
    champions.push_back(make_tuple("라칸", "celestial", "protector", "", 2)); // Rakan

    champions.push_back(make_tuple("럼블", "mech_pilot", "demolitionist", "", 3)); // Rumble
    champions.push_back(make_tuple("마스터이", "rebel", "blademaster", "", 3)); // Master Yi
    champions.push_back(make_tuple("신드라", "starguardian", "sorcerer", "", 3)); // Syndra
    champions.push_back(make_tuple("니코", "starguardian", "protector", "", 3)); // Neeko
    champions.push_back(make_tuple("바이", "cybernetic", "brawler", "", 3)); // Vi
    champions.push_back(make_tuple("이즈리얼", "chronos", "blaster", "", 3)); // Ezreal
    champions.push_back(make_tuple("럭스", "darkstar", "sorcerer", "", 3)); // Lux
    champions.push_back(make_tuple("카르마", "darkstar", "mystic", "", 3)); // Karma
    champions.push_back(make_tuple("샤코", "darkstar", "inflitrator", "", 3)); // Shaco
    champions.push_back(make_tuple("제이스", "space_pirate", "vanguard", "", 3)); // Jayce
    champions.push_back(make_tuple("애쉬", "celestial", "sniper", "", 3)); // Ashe
    champions.push_back(make_tuple("카사딘", "celestial", "mana_reaver", "", 3)); // Kassadin

    champions.push_back(make_tuple("벨코즈", "voidz", "sorcerer", "", 4)); // Vel'Koz
    champions.push_back(make_tuple("초가스", "voidz", "brawler", "", 4)); // Cho'Gat
    champions.push_back(make_tuple("피즈", "mech_pilot", "inflitrator", "", 4)); // Fizz
    champions.push_back(make_tuple("징크스", "rebel", "blaster", "", 4)); // Jinx
    champions.push_back(make_tuple("케일", "valkyrie", "blademaster", "", 4)); // Kayle
    champions.push_back(make_tuple("소라카", "starguardian", "mystic", "", 4)); // Soraka
    champions.push_back(make_tuple("이렐리아", "cybernetic", "blademaster", "mana_reaver", 4)); // Irelia
    champions.push_back(make_tuple("오공", "chronos", "vanguard", "", 4)); // Wukong
    champions.push_back(make_tuple("진", "darkstar", "sniper", "", 4)); // Jhin

    champions.push_back(make_tuple("아우솔", "rebel", "starship", "", 5)); // Aurelion Sol
    champions.push_back(make_tuple("미스포춘", "valkyrie", "blaster", "mercenary", 5)); // Miss Fortune
    champions.push_back(make_tuple("에코", "cybernetic", "inflitrator", "", 5)); // Ekko
    champions.push_back(make_tuple("쓰레쉬", "chronos", "mana_reaver", "", 5)); // Thresh
    champions.push_back(make_tuple("제라스", "darkstar", "sorcerer", "", 5)); // Xerath
    champions.push_back(make_tuple("갱플랭크", "space_pirate", "demolitionist", "mercenary", 5)); // Gangplank
    champions.push_back(make_tuple("룰루", "celestial", "mystic", "", 5)); // Lulu

}

void makingChampionList(int argc, char** argv) {
    if (argc >= 4) {
        for (int i = 3; i < argc; i++) {
            for (int j = 0; j < 52; j++) {
                if(argv[i] == get<0>(champions[j])) {
                    user_select_champ.push_back(champions[j]);
                }
            }   
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
    else if (celestial[index] >= 6) synerge_count += 33;

    if (cybernetic[index] >= 3 && cybernetic[index] < 6) synerge_count += 15;
    else if (cybernetic[index] >= 6) synerge_count += 33;  

    if (mech_pilot[index] >= 3) synerge_count += 15;  

    if (space_pirate[index] >= 2 && space_pirate[index] < 4) synerge_count += 10;
    if (space_pirate[index] >= 4) synerge_count += 21;

    if (valkyrie[index] >= 2) synerge_count += 10;  

    if (chronos[index] >= 2 && chronos[index] < 4) synerge_count += 10;
    else if (chronos[index] >= 4 && chronos[index] < 6) synerge_count += 21;
    else if (chronos[index] >= 6) synerge_count += 33;

    if (darkstar[index] >= 3 && darkstar[index] < 6) synerge_count += 15;
    else if (darkstar[index] >= 6) synerge_count += 33;  

    if (rebel[index] >= 3 && rebel[index] < 6) synerge_count += 15;
    else if (rebel[index] >= 6) synerge_count += 33;  

    if (starguardian[index] >= 3 && starguardian[index] < 6) synerge_count += 15;
    else if (starguardian[index] >= 6) synerge_count += 33;  

    if (voidz[index] >= 3) synerge_count += 15;

    if (blademaster[index] >= 3 && blademaster[index] < 6) synerge_count += 15;
    else if (blademaster[index] >= 6) synerge_count += 33; 

    if (brawler[index] >= 2 && brawler[index] < 4) synerge_count += 10;
    else if (brawler[index] >= 4) synerge_count += 21; 

    if (demolitionist[index] >= 2) synerge_count += 10;

    if (mana_reaver[index] >= 2) synerge_count += 10;

    if (mercenary[index] >= 1) synerge_count += 5;

    if (protector[index] >= 2 && protector[index] < 4) synerge_count += 10;
    else if (protector[index] >= 4) synerge_count += 21;

    if (sorcerer[index] >= 2 && sorcerer[index] < 4) synerge_count += 10;
    else if (sorcerer[index] >= 4 && sorcerer[index] < 6) synerge_count += 21;
    else if (sorcerer[index] >= 6 && sorcerer[index] < 8) synerge_count += 33;
    else if (sorcerer[index] >= 8) synerge_count += 44;

    if (starship[index] >= 1) synerge_count += 5;

    if (blaster[index] >= 2 && blaster[index] < 4) synerge_count += 10;
    else if (blaster[index] >= 4) synerge_count += 21;

    if (inflitrator[index] >= 2 && inflitrator[index] < 4) synerge_count += 10;
    else if (inflitrator[index] >= 4) synerge_count += 21;

    if (mystic[index] >= 2 && mystic[index] < 4) synerge_count += 10;
    else if (mystic[index] >= 4) synerge_count += 21;

    if (sniper[index] >= 2) synerge_count += 10;

    if (vanguard[index] >= 2 && vanguard[index] < 4) synerge_count += 10;
    else if (vanguard[index] >= 4) synerge_count += 21;

    return synerge_count;
}


void synerge_add(tuple <string, string, string, string, int> &champion, int index) {

    if (get<1>(champion) == "celestial") celestial[index]++;
    else if (get<1>(champion) == "cybernetic") cybernetic[index]++;
    else if (get<1>(champion) == "mech_pilot") mech_pilot[index]++;
    else if (get<1>(champion) == "space_pirate") space_pirate[index]++;
    else if (get<1>(champion) == "valkyrie") valkyrie[index]++;
    else if (get<1>(champion) == "chronos") chronos[index]++;
    else if (get<1>(champion) == "darkstar") darkstar[index]++;
    else if (get<1>(champion) == "rebel") rebel[index]++;
    else if (get<1>(champion) == "starguardian") starguardian[index]++;
    else if (get<1>(champion) == "voidz") voidz[index]++;

    if (get<2>(champion) == "blademaster") blademaster[index]++;
    else if (get<2>(champion) == "brawler") brawler[index]++;
    else if (get<2>(champion) == "demolitionist") demolitionist[index]++;
    else if (get<2>(champion) == "mana_reaver") mana_reaver[index]++;  
    else if (get<2>(champion) == "protector") protector[index]++;
    else if (get<2>(champion) == "sorcerer") sorcerer[index]++;
    else if (get<2>(champion) == "blaster") blaster[index]++;
    else if (get<2>(champion) == "inflitrator") inflitrator[index]++;
    else if (get<2>(champion) == "mystic") mystic[index]++;
    else if (get<2>(champion) == "sniper") sniper[index]++;
    else if (get<2>(champion) == "vanguard") vanguard[index]++;
    else if (get<2>(champion) == "starship") starship[index]++;

    if (get<3>(champion) == "mercenary") mercenary[index]++;
    else if (get<3>(champion) == "mana_reaver") mana_reaver[index]++;
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

    if (valkyrie[index] >= 2) synerge.append("2발키리 ");

    if (chronos[index] >= 2 && (chronos[index] < 4)) synerge.append("2시공간 ");
    else if (chronos[index] >= 4 && (chronos[index] < 6)) synerge.append("4시공간 ");
    else if (chronos[index] >= 6) synerge.append("6시공간 ");

    if (darkstar[index] >= 3 && (darkstar[index] < 6)) synerge.append("3암흑의별 ");
    else if (darkstar[index] >= 6 ) synerge.append("6암흑의별 ");

    if (rebel[index] >= 3 && (rebel[index] < 6)) synerge.append("3반군 ");
    else if (rebel[index] >= 6 ) synerge.append("6반군 ");

    if (starguardian[index] >= 3 && (starguardian[index] < 6)) synerge.append("3별수호자 ");
    else if (starguardian[index] >= 6 ) synerge.append("6별수호자 ");

    if (voidz[index] >= 3) synerge.append("3공허 ");

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

    if (sniper[index] >= 2) synerge.append("2저격수 ");

    if (vanguard[index] >= 2 && (vanguard[index] < 4)) synerge.append("2선봉대 ");
    else if (vanguard[index] >= 4) synerge.append("4선봉대 ");

    return synerge;
}


vector <int> pick[52];
vector < tuple <int, string, string > > overall_combination;
int level;

// mutex
recursive_mutex m;

void combination_level4_down(int index, int thread_index) {
    string selected_champ;
    if(pick[thread_index].size() == level - selected_size) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(level4_down_champions[pick[thread_index][i]], thread_index); 
            selected_champ.append(get<0>(level4_down_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            selected_champ.append(get<0>(user_select_champ[i]));
            selected_champ.append(" ");
        }  

        int synerge_value = synerge_check(thread_index);
        if (synerge_value > max_value) 
            max_value = synerge_value;

        string synerge = "";
        synerge = synerge_print(thread_index);
    
        // critical section
        m.lock();
        if (synerge.length() != 0)
            overall_combination.push_back(make_tuple(synerge_value, selected_champ, synerge));
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
    if(pick[thread_index].size() == level - selected_size) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(level6_down_champions[pick[thread_index][i]], thread_index); 
            selected_champ.append(get<0>(level6_down_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            selected_champ.append(get<0>(user_select_champ[i]));
            selected_champ.append(" ");
        }  
    
        int synerge_value = synerge_check(thread_index);
        if (synerge_value > max_value) 
            max_value = synerge_value;

        string synerge = "";
        synerge = synerge_print(thread_index);
    
        // critical section
        m.lock();
        if (synerge.length() != 0)
            overall_combination.push_back(make_tuple(synerge_value, selected_champ, synerge));
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
    if(pick[thread_index].size() == level - selected_size) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(level7_up_champions[pick[thread_index][i]], thread_index); 
            selected_champ.append(get<0>(level7_up_champions[pick[thread_index][i]])); 
            selected_champ.append(" ");
        }

       for(int i = 0; i < selected_size; i++) {
            synerge_add(user_select_champ[i], thread_index);
            selected_champ.append(get<0>(user_select_champ[i]));
            selected_champ.append(" ");
        }  

        int synerge_value = synerge_check(thread_index);
        if (synerge_value > max_value) 
            max_value = synerge_value;

        string synerge = "";
        synerge = synerge_print(thread_index);
    
        // critical section
        m.lock();
        if (synerge.length() != 0)
            overall_combination.push_back(make_tuple(synerge_value, selected_champ, synerge));
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


// radix
int n;
void countSort(int exp) { 
    vector <tuple <int, string, string>> output(n);
    vector <int> count(10, 0); 

	for (int i = 0; i < n; i++) 
		count[ (get<0>(overall_combination[i])/exp)%10 ]++; 

    // 오름차순, 내림차순 정렬은 여기서 조작한다.
	for (int i = 9; i > 0; i--) 
		count[i-1] += count[i]; 

	for (int i = n - 1; i >= 0; i--) { 
		output[count[ (get<0>(overall_combination[i])/exp)%10 ] - 1] = overall_combination[i]; 
		count[ (get<0>(overall_combination[i])/exp)%10 ]--; 
	} 
	overall_combination = output;
} 


void radixsort() {  
    int m = max_value;
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(exp); 
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

    middle = time(NULL);
    cout << "calculation time: " << (double)(middle - start) << "\n";

    // sorting
    n = overall_combination.size();
    radixsort();
    // sort(overall_combination.begin(), overall_combination.end(), greater<tuple<int, string, string>>());

    end = time(NULL);
    result = (double)(end - middle);


    // print
    cout << "sorting time: " << result << "\n";
    cout << "총 갯수: " << overall_combination.size() << "\n";
    cout << "최고 시너지 점수: " << get<0>(overall_combination[0]) << "\n";
    cout << "LEVEL" << level << " 조합" << "\n";

    int loop = stoi(argv[2]) < overall_combination.size() ? stoi(argv[2]) : overall_combination.size();

    for (int i = 0; i < loop; i++) {
        cout << "조합 " << i+1 << "\n";
        cout << "  챔피언: " << get<1>(overall_combination[i]) << "\n";
        cout << "  시너지: " << get<2>(overall_combination[i]) << "\n\n\n";
    }
    return 0;

}