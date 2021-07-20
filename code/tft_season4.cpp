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
int cultist[58];
int divine[58];
int dusk[58];
int elderwood[58];
int enlightened[58];
int exile[58];
int fortune[58];
int moonlight[58];
int ninja[58];
int spirit[58];
int theboss[58];
int tormented[58];
int warload[58];

// classes
int adept[58];
int assassin[58];
int brawler[58];
int duelist[58];
int emperor[58];
int hunter[58];
int dazzler[58];
int keeper[58];
int mage[58];
int mystic[58];
int shade[58];
int sharpshooter[58];
int vanguard[58];


// 계산이 완료된 후 시너지를 초기화 해주는 함수
void init(int index) {
    cultist[index] = 0;
    divine[index] = 0;
    dusk[index] = 0;
    elderwood[index] = 0;
    enlightened[index] = 0;
    exile[index] = 0;
    fortune[index] = 0;
    moonlight[index] = 0;
    ninja[index] = 0;
    spirit[index] = 0;
    theboss[index] = 0;
    tormented[index] = 0;
    warload[index] = 0;

    // classes
    adept[index] = 0;
    assassin[index] = 0;
    brawler[index] = 0;
    duelist[index] = 0;
    dazzler[index] = 0;
    emperor[index] = 0;
    hunter[index] = 0;
    keeper[index] = 0;
    mage[index] = 0;
    mystic[index] = 0;
    shade[index] = 0;
    sharpshooter[index] = 0;
    vanguard[index] = 0;
}

void champions_info() {
    champions.push_back(make_tuple("트페", "cultist", "mage", "", 1)); 
    champions.push_back(make_tuple("엘리스", "cultist", "keeper", "", 1)); 
    champions.push_back(make_tuple("오공", "divine", "vanguard", "", 1)); 
    champions.push_back(make_tuple("베인", "dusk", "sharpshooter", "", 1)); 
    champions.push_back(make_tuple("마오카이", "elderwood", "brawler", "", 1)); 
    champions.push_back(make_tuple("피오라", "enlightened", "duelist", "", 1)); 
    champions.push_back(make_tuple("나미", "enlightened", "mage", "", 1));
    champions.push_back(make_tuple("야스오", "exile", "duelist", "", 1));
    champions.push_back(make_tuple("탐켄치", "fortune", "brawler", "", 1)); 
    champions.push_back(make_tuple("리산드라", "moonlight", "dazzler", "", 1)); 
    champions.push_back(make_tuple("다이애나", "moonlight", "assassin", "", 1));
    champions.push_back(make_tuple("가렌", "warload", "vanguard", "", 1));
    champions.push_back(make_tuple("니달리", "warload", "sharpshooter", "", 1)); 

    champions.push_back(make_tuple("파이크", "cultist", "assassin", "", 2)); 
    champions.push_back(make_tuple("잭스", "divine", "duelist", "", 2)); 
    champions.push_back(make_tuple("쓰레쉬", "dusk", "vanguard", "", 2)); 
    champions.push_back(make_tuple("헤카림", "elderwood", "vanguard", "", 2));
    champions.push_back(make_tuple("룰루", "elderwood", "mage", "", 2)); 
    champions.push_back(make_tuple("잔나", "enlightened", "mystic", "", 2)); 
    champions.push_back(make_tuple("애니", "fortune", "mage", "", 2)); 
    champions.push_back(make_tuple("아펠리오스", "moonlight", "hunter", "", 2)); 
    champions.push_back(make_tuple("사일러스", "moonlight", "brawler", "", 2)); 
    champions.push_back(make_tuple("제드", "ninja", "shade", "", 2));
    champions.push_back(make_tuple("티모", "spirit", "sharpshooter", "", 2));
    champions.push_back(make_tuple("자르반", "warload", "keeper", "", 2));
    champions.push_back(make_tuple("바이", "warload", "brawler", "", 2)); 

    champions.push_back(make_tuple("이블린", "cultist", "shade", "", 3));
    champions.push_back(make_tuple("칼리스타", "cultist", "duelist", "", 3)); 
    champions.push_back(make_tuple("이렐리아", "divine", "adept", "enlightened", 3)); 
    champions.push_back(make_tuple("럭스", "divine", "dazzler", "", 3)); 
    champions.push_back(make_tuple("누누", "elderwood", "brawler", "", 3)); 
    champions.push_back(make_tuple("베이가", "elderwood", "mage", "", 3)); 
    champions.push_back(make_tuple("징크스", "fortune", "sharpshooter", "", 3));
    champions.push_back(make_tuple("카타리나", "fortune", "assassin", "warload", 3)); 
    champions.push_back(make_tuple("아칼리", "ninja", "assassin", "", 3)); 
    champions.push_back(make_tuple("케넨", "ninja", "keeper", "", 3)); 
    champions.push_back(make_tuple("킨드레드", "spirit", "hunter", "", 3)); 
    champions.push_back(make_tuple("유미", "spirit", "mystic", "", 3)); 
    champions.push_back(make_tuple("신짜오", "warload", "duelist", "", 3)); 

    champions.push_back(make_tuple("아트록스", "cultist", "vanguard", "", 4)); 
    champions.push_back(make_tuple("진", "cultist", "sharpshooter", "", 4)); 
    champions.push_back(make_tuple("워윅", "divine", "brawler", "hunter", 4)); 
    champions.push_back(make_tuple("카시오페아", "dusk", "mystic", "", 4)); 
    champions.push_back(make_tuple("리븐", "dusk", "keeper", "", 4));
    champions.push_back(make_tuple("애쉬", "elderwood", "hunter", "", 4)); 
    champions.push_back(make_tuple("모르가나", "enlightened", "dazzler", "", 4)); 
    champions.push_back(make_tuple("탈론", "enlightened", "assassin", "", 4)); 
    champions.push_back(make_tuple("세주아니", "fortune", "vanguard", "", 4)); 
    champions.push_back(make_tuple("쉔", "ninja", "adept", "mystic", 4)); 
    champions.push_back(make_tuple("아리", "spirit", "mage", "", 4)); 

    champions.push_back(make_tuple("질리언", "cultist", "mystic", "", 5)); 
    champions.push_back(make_tuple("리신", "divine", "duelist", "", 5)); 
    champions.push_back(make_tuple("릴리아", "dusk", "mage", "", 5)); 
    champions.push_back(make_tuple("이즈리얼", "elderwood", "dazzler", "", 5)); 
    champions.push_back(make_tuple("요네", "exile", "adept", "", 5)); 
    champions.push_back(make_tuple("세트", "theboss", "brawler", "", 5)); 
    champions.push_back(make_tuple("케인", "tormented", "shade", "", 5)); 
    champions.push_back(make_tuple("아지르", "warload", "emperor", "keeper", 5)); 
}

void selected_champions_info() {
    // cost 1
    selected_champions.push_back(make_tuple("트페(광신도)", "cultistx2", "mage", "", 1)); 
    selected_champions.push_back(make_tuple("트페(요술사)", "cultist", "magex2", "", 1)); 
    
    selected_champions.push_back(make_tuple("엘리스(광신도)", "cultistx2", "keeper", "", 1)); 
    selected_champions.push_back(make_tuple("엘리스(귀감)", "cultist", "keeperx2", "", 1)); 

    selected_champions.push_back(make_tuple("오공(신성)", "divinex2", "vanguard", "", 1)); 
    selected_champions.push_back(make_tuple("오공(선봉대)", "divine", "vanguardx2", "", 1)); 

    selected_champions.push_back(make_tuple("베인(황혼)", "duskx2", "sharpshooter", "", 1)); 
    selected_champions.push_back(make_tuple("베인(명사수)", "dusk", "sharpshooterx2", "", 1)); 

    selected_champions.push_back(make_tuple("마오카이(나무정령)", "elderwoodx2", "brawler", "", 1)); 
    selected_champions.push_back(make_tuple("마오카이(싸움꾼)", "elderwood", "brawlerx2", "", 1)); 

    selected_champions.push_back(make_tuple("피오라(선지자)", "enlightenedx2", "duelist", "", 1)); 
    selected_champions.push_back(make_tuple("피오라(결투가)", "enlightened", "duelistx2", "", 1)); 

    selected_champions.push_back(make_tuple("나미(선지자)", "enlightenedx2", "mage", "", 1));
    selected_champions.push_back(make_tuple("나미(요술사)", "enlightened", "magex2", "", 1));

    selected_champions.push_back(make_tuple("야스오(추방자)", "exilex2", "duelist", "", 1));
    selected_champions.push_back(make_tuple("야스오(결투가)", "exile", "duelistx2", "", 1));

    selected_champions.push_back(make_tuple("탐켄치(행운)", "fortunex2", "brawler", "", 1)); 
    selected_champions.push_back(make_tuple("탐켄치(싸움꾼)", "fortune", "brawlerx2", "", 1)); 

    selected_champions.push_back(make_tuple("리산드라(달빛)", "moonlightx2", "dazzler", "", 1)); 
    selected_champions.push_back(make_tuple("리산드라(현혹술사)", "moonlight", "dazzlerx2", "", 1)); 

    selected_champions.push_back(make_tuple("다이애나(달빛)", "moonlightx2", "assassin", "", 1));
    selected_champions.push_back(make_tuple("다이애나(암살자)", "moonlight", "assassinx2", "", 1));

    selected_champions.push_back(make_tuple("가렌(대장군)", "warloadx2", "vanguard", "", 1));
    selected_champions.push_back(make_tuple("가렌(선봉대)", "warload", "vanguardx2", "", 1));

    selected_champions.push_back(make_tuple("니달리(대장군)", "warloadx2", "sharpshooter", "", 1)); 
    selected_champions.push_back(make_tuple("니달리(명사수)", "warload", "sharpshooterx2", "", 1)); 

    // cost 2
    selected_champions.push_back(make_tuple("파이크(광신도)", "cultistx2", "assassin", "", 2)); 
    selected_champions.push_back(make_tuple("파이크(암살자)", "cultist", "assassinx2", "", 2)); 

    selected_champions.push_back(make_tuple("잭스(신성)", "divinex2", "duelist", "", 2)); 
    selected_champions.push_back(make_tuple("잭스(결투가)", "divine", "duelistx2", "", 2)); 

    selected_champions.push_back(make_tuple("쓰레쉬(황혼)", "duskx2", "vanguard", "", 2)); 
    selected_champions.push_back(make_tuple("쓰레쉬(선봉대)", "dusk", "vanguardx2", "", 2)); 

    selected_champions.push_back(make_tuple("헤카림(나무정령)", "elderwoodx2", "vanguard", "", 2));
    selected_champions.push_back(make_tuple("헤카림(선봉대)", "elderwood", "vanguardx2", "", 2));
    
    selected_champions.push_back(make_tuple("룰루(나무정령)", "elderwoodx2", "mage", "", 2)); 
    selected_champions.push_back(make_tuple("룰루(요술사)", "elderwood", "magex2", "", 2)); 

    selected_champions.push_back(make_tuple("잔나(선지자)", "enlightenedx2", "mystic", "", 2)); 
    selected_champions.push_back(make_tuple("잔나(신비술사)", "enlightened", "mysticx2", "", 2)); 

    selected_champions.push_back(make_tuple("애니(행운)", "fortunex2", "mage", "", 2)); 
    selected_champions.push_back(make_tuple("애니(요술사)", "fortune", "magex2", "", 2)); 

    selected_champions.push_back(make_tuple("아펠리오스(달빛)", "moonlightx2", "hunter", "", 2)); 
    selected_champions.push_back(make_tuple("아펠리오스(사냥꾼)", "moonlight", "hunterx2", "", 2)); 

    selected_champions.push_back(make_tuple("사일러스(달빛)", "moonlightx2", "brawler", "", 2)); 
    selected_champions.push_back(make_tuple("사일러스(싸움꾼)", "moonlight", "brawlerx2", "", 2)); 

    selected_champions.push_back(make_tuple("제드(닌자)", "ninjax2", "shade", "", 2));
    selected_champions.push_back(make_tuple("제드(그림자)", "ninja", "shadex2", "", 2));

    selected_champions.push_back(make_tuple("티모(영혼)", "spiritx2", "sharpshooter", "", 2));
    selected_champions.push_back(make_tuple("티모(명사수)", "spirit", "sharpshooterx2", "", 2));

    selected_champions.push_back(make_tuple("자르반(대장군)", "warloadx2", "keeper", "", 2));
    selected_champions.push_back(make_tuple("자르반(귀감)", "warload", "keeperx2", "", 2));

    selected_champions.push_back(make_tuple("바이(대장군)", "warloadx2", "brawler", "", 2)); 
    selected_champions.push_back(make_tuple("바이(싸움꾼)", "warload", "brawlerx2", "", 2)); 

    // cost 3
    selected_champions.push_back(make_tuple("이블린(광신도)", "cultistx2", "shade", "", 3));
    selected_champions.push_back(make_tuple("이블린(그림자)", "cultist", "shadex2", "", 3));

    selected_champions.push_back(make_tuple("칼리스타(광신도)", "cultistx2", "duelist", "", 3)); 
    selected_champions.push_back(make_tuple("칼리스타(결투가)", "cultist", "duelistx2", "", 3)); 

    selected_champions.push_back(make_tuple("이렐리아(신성)", "divinex2", "adept", "enlightened", 3)); 
    selected_champions.push_back(make_tuple("이렐리아(조율자)", "divine", "adeptx2", "enlightened", 3)); 
    selected_champions.push_back(make_tuple("이렐리아(선지자)", "divine", "adept", "enlightenedx2", 3)); 

    selected_champions.push_back(make_tuple("럭스(신성)", "divinex2", "dazzler", "", 3)); 
    selected_champions.push_back(make_tuple("럭스(현혹술사)", "divine", "dazzlerx2", "", 3)); 

    selected_champions.push_back(make_tuple("누누(나무정령)", "elderwoodx2", "brawler", "", 3)); 
    selected_champions.push_back(make_tuple("누누(싸움꾼)", "elderwood", "brawlerx2", "", 3)); 

    selected_champions.push_back(make_tuple("베이가(나무정령)", "elderwoodx2", "mage", "", 3)); 
    selected_champions.push_back(make_tuple("베이가(요술사)", "elderwood", "magex2", "", 3)); 

    selected_champions.push_back(make_tuple("징크스(행운)", "fortunex2", "sharpshooter", "", 3));
    selected_champions.push_back(make_tuple("징크스(명사수)", "fortune", "sharpshooterx2", "", 3));

    selected_champions.push_back(make_tuple("카타리나(행운)", "fortunex2", "assassin", "warload", 3)); 
    selected_champions.push_back(make_tuple("카타리나(암살자)", "fortune", "assassinx2", "warload", 3)); 
    selected_champions.push_back(make_tuple("카타리나(대장군)", "fortune", "assassin", "warloadx2", 3)); 

    selected_champions.push_back(make_tuple("아칼리(닌자)", "ninjax2", "assassin", "", 3)); 
    selected_champions.push_back(make_tuple("아칼리(암살자)", "ninja", "assassinx2", "", 3)); 

    selected_champions.push_back(make_tuple("케넨(닌자)", "ninjax2", "keeper", "", 3)); 
    selected_champions.push_back(make_tuple("케넨(귀감)", "ninja", "keeperx2", "", 3)); 

    selected_champions.push_back(make_tuple("킨드레드(영혼)", "spiritx2", "hunter", "", 3)); 
    selected_champions.push_back(make_tuple("킨드레드(사냥꾼)", "spirit", "hunterx2", "", 3)); 

    selected_champions.push_back(make_tuple("유미(영혼)", "spiritx2", "mystic", "", 3)); 
    selected_champions.push_back(make_tuple("유미(신비술사)", "spirit", "mysticx2", "", 3)); 

    selected_champions.push_back(make_tuple("신짜오(대장군)", "warloadx2", "duelist", "", 3)); 
    selected_champions.push_back(make_tuple("신짜오(결투가)", "warload", "duelistx2", "", 3)); 

    // cost 4
    selected_champions.push_back(make_tuple("아트록스(광신도)", "cultistx2", "vanguard", "", 4)); 
    selected_champions.push_back(make_tuple("아트록스(선봉대)", "cultist", "vanguardx2", "", 4)); 

    selected_champions.push_back(make_tuple("진(광신도)", "cultistx2", "sharpshooter", "", 4)); 
    selected_champions.push_back(make_tuple("진(명사수)", "cultist", "sharpshooterx2", "", 4)); 

    selected_champions.push_back(make_tuple("워윅(신성)", "divinex2", "brawler", "hunter", 4)); 
    selected_champions.push_back(make_tuple("워윅(싸움꾼)", "divine", "brawlerx2", "hunter", 4)); 
    selected_champions.push_back(make_tuple("워윅(사냥꾼)", "divine", "brawler", "hunterx2", 4)); 

    selected_champions.push_back(make_tuple("카시오페아(황혼)", "duskx2", "mystic", "", 4)); 
    selected_champions.push_back(make_tuple("카시오페아(신비술사)", "dusk", "mysticx2", "", 4)); 

    selected_champions.push_back(make_tuple("리븐(황혼)", "duskx2", "keeper", "", 4));
    selected_champions.push_back(make_tuple("리븐(귀감)", "dusk", "keepex2r", "", 4));

    selected_champions.push_back(make_tuple("애쉬(나무정령)", "elderwoodx2", "hunter", "", 4));
    selected_champions.push_back(make_tuple("애쉬(사냥꾼)", "elderwood", "hunterx2", "", 4)); 
    
    selected_champions.push_back(make_tuple("모르가나(선지자)", "enlightenedx2", "dazzler", "", 4)); 
    selected_champions.push_back(make_tuple("모르가나(현혹술사)", "enlightened", "dazzlerx2", "", 4)); 

    selected_champions.push_back(make_tuple("탈론(선지자)", "enlightenedx2", "assassin", "", 4)); 
    selected_champions.push_back(make_tuple("탈론(암살자)", "enlightened", "assassinx2", "", 4)); 

    selected_champions.push_back(make_tuple("세주아니(행운)", "fortunex2", "vanguard", "", 4)); 
    selected_champions.push_back(make_tuple("세주아니(선봉대)", "fortune", "vanguardx2", "", 4)); 

    selected_champions.push_back(make_tuple("쉔(닌자)", "ninjax2", "adept", "mystic", 4)); 
    selected_champions.push_back(make_tuple("쉔(조율자)", "ninja", "adeptx2", "mystic", 4)); 
    selected_champions.push_back(make_tuple("쉔(신비술사)", "ninja", "adept", "mysticx2", 4)); 

    selected_champions.push_back(make_tuple("아리(영혼)", "spiritx2", "mage", "", 4)); 
    selected_champions.push_back(make_tuple("아리(요술사)", "spirit", "magex2", "", 4)); 

    // cost 5
    selected_champions.push_back(make_tuple("질리언(광신도)", "cultistx2", "mystic", "", 5)); 
    selected_champions.push_back(make_tuple("질리언(신비술사)", "cultist", "mysticx2", "", 5)); 

    selected_champions.push_back(make_tuple("리신(신성)", "divinex2", "duelist", "", 5)); 
    selected_champions.push_back(make_tuple("리신(결투가)", "divine", "duelistx2", "", 5)); 

    selected_champions.push_back(make_tuple("릴리아(황혼)", "duskx2", "mage", "", 5)); 
    selected_champions.push_back(make_tuple("릴리아(요술사)", "dusk", "magex2", "", 5)); 

    selected_champions.push_back(make_tuple("이즈리얼(나무정령)", "elderwoodx2", "dazzler", "", 5)); 
    selected_champions.push_back(make_tuple("이즈리얼(현혹술사)", "elderwood", "dazzlerx2", "", 5)); 

    selected_champions.push_back(make_tuple("요네(추방자)", "exilex2", "adept", "", 5)); 
    selected_champions.push_back(make_tuple("요네(조율자)", "exile", "adeptx2", "", 5)); 

    selected_champions.push_back(make_tuple("세트(우두머리)", "thebossx2", "brawler", "", 5)); 
    selected_champions.push_back(make_tuple("세트(싸움꾼)", "theboss", "brawlerx2", "", 5)); 

    selected_champions.push_back(make_tuple("케인(번뇌)", "tormentedx2", "shade", "", 5)); 
    selected_champions.push_back(make_tuple("케인(그림자)", "tormented", "shadex2", "", 5)); 

    selected_champions.push_back(make_tuple("아지르(대장군)", "warloadx2", "emperor", "keeper", 5)); 
    selected_champions.push_back(make_tuple("아지르(귀감)", "warload", "emperor", "keeperx2", 5)); 
}


// 선택받은자 챔피언과 일반 챔피언 중복을 제거하기 위한 함수
// ex) "진"과 "진(광신도)"가 하나의 조합에 들어가있어 3광신도가 활성화되는 에러를 방지하기 위함
string deduplication (string selected_champ) {
    string delimiter = "(";

    int pos = 0;
    string token;
    while ((pos = selected_champ.find(delimiter)) != string::npos) {
        token = selected_champ.substr(0, pos);
        selected_champ.erase(0, pos + delimiter.length());
    }

    return token;
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

            // 유저가 선택한 선택받은 자 챔피언
            for (int j = 0; j < selected_champions.size(); j++) {
                if(argv[i] == get<0>(selected_champions[j])) {
                    user_select_champ.push_back(selected_champions[j]);
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
            if (get<0>(champions[i]) == get<0>(user_select_champ[j]) ||  get<0>(champions[i]) == deduplication(get<0>(user_select_champ[j]))) {
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
    if (cultist[index] >= 3 && cultist[index] < 6) synerge_count += 15;
    else if (cultist[index] >= 6 && cultist[index] < 9) synerge_count += 32;  
    else if (cultist[index] >= 9) synerge_count += 85;

    if (divine[index] >= 2 && divine[index] < 4) synerge_count += 7;
    else if (divine[index] >= 4 && divine[index] < 6) synerge_count += 21;
    else if (divine[index] >= 6 && divine[index] < 8) synerge_count += 32;
    else if (divine[index] >= 8) synerge_count += 43;    

    if (dusk[index] >= 2 && dusk[index] < 4) synerge_count += 7;
    else if (dusk[index] >= 4 && dusk[index] < 6) synerge_count += 21;
    else if (dusk[index] >= 6) synerge_count += 32;

    if (elderwood[index] >= 3 && elderwood[index] < 6) synerge_count += 15;
    else if (elderwood[index] >= 6 && elderwood[index] < 9) synerge_count += 32;  
    else if (elderwood[index] >= 9) synerge_count += 60;

    if (enlightened[index] >= 2 && enlightened[index] < 4) synerge_count += 7;
    else if (enlightened[index] >= 4 && enlightened[index] < 6) synerge_count += 21;
    else if (enlightened[index] >= 6) synerge_count += 32;
    
    if (exile[index] >= 1 && exile[index] < 2) synerge_count += 3;
    else if (exile[index] >= 2) synerge_count += 11;  

    if (fortune[index] >= 3 && fortune[index] > 6) synerge_count += 15;  
    else if (fortune[index] >= 6) synerge_count += 32;

    if (moonlight[index] >= 3 && moonlight[index] < 5) synerge_count += 15;  
    else if (moonlight[index] >= 5) synerge_count += 25;

    if (ninja[index] == 1) synerge_count += 9;
    else if (ninja[index] == 4) synerge_count += 24;  

    if (theboss[index] == 1) synerge_count += 15;

    if (tormented[index] == 1) synerge_count += 1;

    if (spirit[index] >= 2 && spirit[index] < 4) synerge_count += 7;
    else if (spirit[index] >= 4) synerge_count += 24;

    if (warload[index] >= 3 && warload[index] < 6) synerge_count += 15;
    else if (warload[index] >= 6 && warload[index] < 9) synerge_count += 32;  
    else if (warload[index] >= 9) synerge_count += 60;


    // classes
    if (adept[index] >= 2 && adept[index] < 3) synerge_count += 12;
    else if (adept[index] >= 3 && adept[index] < 4) synerge_count += 18;  
    else if (adept[index] >= 4) synerge_count += 30;

    if (assassin[index] >= 2 && assassin[index] < 4) synerge_count += 7;
    else if (assassin[index] >= 4 && assassin[index] < 6) synerge_count += 21;
    else if (assassin[index] >= 6) synerge_count += 52;

    if (brawler[index] >= 2 && brawler[index] < 4) synerge_count += 7;
    else if (brawler[index] >= 4 && brawler[index] < 6) synerge_count += 21;
    else if (brawler[index] >= 6 && brawler[index] < 8) synerge_count += 32;
    else if (brawler[index] >= 8) synerge_count += 64;

    if (dazzler[index] >= 2 && dazzler[index] < 4) synerge_count += 7;
    else if (dazzler[index] >= 4) synerge_count += 21;   

    // 수정할것
    if (duelist[index] >= 2 && duelist[index] < 4) synerge_count += 7;
    else if (duelist[index] >= 4 && duelist[index] < 6) synerge_count += 21;
    else if (duelist[index] >= 6 && duelist[index] < 8) synerge_count += 32;
    else if (duelist[index] >= 8) synerge_count += 43;  

    if (emperor[index] == 1) synerge_count += 7;

    if (hunter[index] >= 2 && hunter[index] < 3) synerge_count += 8;
    else if (hunter[index] >= 3 && hunter[index] < 4) synerge_count += 18;
    else if (hunter[index] >= 4 && hunter[index] < 5) synerge_count += 28;
    else if (hunter[index] >= 5) synerge_count += 40;  

    // 수정할것
    if (keeper[index] >= 2 && keeper[index] < 4) synerge_count += 8;
    else if (keeper[index] >= 4 && keeper[index] < 6) synerge_count += 21;
    else if (keeper[index] >= 6) synerge_count += 32;

    if (mage[index] >= 3 && mage[index] < 6) synerge_count += 15;
    else if (mage[index] >= 6 && mage[index] < 9) synerge_count += 45;  
    else if (mage[index] >= 9) synerge_count += 60;

    // 수정할것
    if (mystic[index] >= 2 && mystic[index] < 4) synerge_count += 8;
    else if (mystic[index] >= 4 && mystic[index] < 6) synerge_count += 25;
    else if (mystic[index] >= 6) synerge_count += 32;  
     

    if (shade[index] >= 2 && shade[index] < 3) synerge_count += 8;
    else if (shade[index] >= 3 && shade[index] < 4) synerge_count += 24;  
    else if (shade[index] >= 4) synerge_count += 48;   

    if (sharpshooter[index] >= 2 && sharpshooter[index] < 4) synerge_count += 7;
    else if (sharpshooter[index] >= 4 && sharpshooter[index] < 6) synerge_count += 21;
    else if (sharpshooter[index] >= 6) synerge_count += 62;   

    // 수정할것
    if (vanguard[index] >= 2 && vanguard[index] < 4) synerge_count += 7;
    else if (vanguard[index] >= 4 && vanguard[index] < 6) synerge_count += 21;
    else if (vanguard[index] >= 6 && vanguard[index] < 8) synerge_count += 32;
    else if (vanguard[index] >= 8) synerge_count += 60;  
 

    return synerge_count;
}

// 선택이 완료된 조합의 시너지를 계산하는 함수
void synerge_add(tuple <string, string, string, string, int> &champion, int index) {
    string origin = get<1>(champion);
    string classes = get<2>(champion);
    string additional = get<3>(champion);

    if (origin == "cultist") cultist[index]++;
    else if (origin == "divine") divine[index]++;
    else if (origin == "dusk") dusk[index]++;
    else if (origin == "elderwood") elderwood[index]++;
    else if (origin == "enlightened") enlightened[index]++;
    else if (origin == "exile") exile[index]++;
    else if (origin == "fortune") fortune[index]++;
    else if (origin == "moonlight") moonlight[index]++;
    else if (origin == "ninja") ninja[index]++;
    else if (origin == "spirit") spirit[index]++;
    else if (origin == "theboss") theboss[index]++;
    else if (origin == "tormented") tormented[index]++;
    else if (origin == "warload") warload[index]++;

    if (classes == "adept") adept[index]++;
    else if (classes == "assassin") assassin[index]++;
    else if (classes == "brawler") brawler[index]++;
    else if (classes == "dazzler") dazzler[index]++;  
    else if (classes == "duelist") duelist[index]++;
    else if (classes == "emperor") emperor[index]++;
    else if (classes == "hunter") hunter[index]++;
    else if (classes == "keeper") keeper[index]++;
    else if (classes == "mage") mage[index]++;
    else if (classes == "mystic") mystic[index]++;
    else if (classes == "shade") shade[index]++;
    else if (classes == "sharpshooter") sharpshooter[index]++;
    else if (classes == "vanguard") vanguard[index]++;

    if (additional == "cultist") cultist[index]++;
    else if (additional == "divine") divine[index]++;
    else if (additional == "dusk") dusk[index]++;
    else if (additional == "elderwood") elderwood[index]++;
    else if (additional == "enlightened") enlightened[index]++;
    else if (additional == "exile") exile[index]++;
    else if (additional == "fortune") fortune[index]++;
    else if (additional == "moonlight") moonlight[index]++;
    else if (additional == "ninja") ninja[index]++;
    else if (additional == "spirit") spirit[index]++;
    else if (additional == "theboss") theboss[index]++;
    else if (additional == "tormented") tormented[index]++;
    else if (additional == "warload") warload[index]++;
    else if (additional == "adept") adept[index]++;
    else if (additional == "assassin") assassin[index]++;
    else if (additional == "brawler") brawler[index]++;
    else if (additional == "dazzler") dazzler[index]++;  
    else if (additional == "duelist") duelist[index]++;
    else if (additional == "emperor") emperor[index]++;
    else if (additional == "hunter") hunter[index]++;
    else if (additional == "keeper") keeper[index]++;
    else if (additional == "mage") mage[index]++;
    else if (additional == "mystic") mystic[index]++;
    else if (additional == "shade") shade[index]++;
    else if (additional == "sharpshooter") sharpshooter[index]++;
    else if (additional == "vanguard") vanguard[index]++;

    // selected champions x2
    if (origin == "cultistx2") cultist[index] += 2;
    else if (origin == "divinex2") divine[index] += 2;
    else if (origin == "duskx2") dusk[index] += 2;
    else if (origin == "elderwoodx2") elderwood[index] += 2;
    else if (origin == "enlightenedx2") enlightened[index] += 2;
    else if (origin == "exilex2") exile[index] += 2;
    else if (origin == "fortunex2") fortune[index] += 2;
    else if (origin == "moonlightx2") moonlight[index] += 2;
    else if (origin == "ninjax2") ninja[index] += 2;
    else if (origin == "spiritx2") spirit[index] += 2;
    else if (origin == "thebossx2") theboss[index] += 2;
    else if (origin == "tormentedx2") tormented[index] += 2;
    else if (origin == "warloadx2") warload[index] += 2;

    if (classes == "adeptx2") adept[index] += 2;
    else if (classes == "assassinx2") assassin[index] += 2;
    else if (classes == "brawlerx2") brawler[index] += 2;
    else if (classes == "dazzlerx2") dazzler[index] += 2;  
    else if (classes == "duelistx2") duelist[index] += 2;
    else if (classes == "emperorx2") emperor[index] += 2;
    else if (classes == "hunterx2") hunter[index] += 2;
    else if (classes == "keeperx2") keeper[index] += 2;
    else if (classes == "magex2") mage[index] += 2;
    else if (classes == "mysticx2") mystic[index] += 2;
    else if (classes == "shadex2") shade[index] += 2;
    else if (classes == "sharpshooterx2") sharpshooter[index] += 2;
    else if (classes == "vanguardx2") vanguard[index] += 2;

    if (additional == "cultistx2") cultist[index] += 2;
    else if (additional == "divinex2") divine[index] += 2;
    else if (additional == "duskx2") dusk[index] += 2;
    else if (additional == "elderwoodx2") elderwood[index] += 2;
    else if (additional == "enlightenedx2") enlightened[index] += 2;
    else if (additional == "exilex2") exile[index] += 2;
    else if (additional == "fortunex2") fortune[index] += 2;
    else if (additional == "moonlightx2") moonlight[index] += 2;
    else if (additional == "ninjax2") ninja[index] += 2;
    else if (additional == "spiritx2") spirit[index] += 2;
    else if (additional == "thebossx2") theboss[index] += 2;
    else if (additional == "tormentedx2") tormented[index] += 2;
    else if (additional == "warloadx2") warload[index] += 2;
    else if (additional == "adeptx2") adept[index] += 2;
    else if (additional == "assassinx2") assassin[index] += 2;
    else if (additional == "brawlerx2") brawler[index] += 2;
    else if (additional == "dazzlerx2") dazzler[index] += 2;  
    else if (additional == "duelistx2") duelist[index] += 2;
    else if (additional == "emperorx2") emperor[index] += 2;
    else if (additional == "hunterx2") hunter[index] += 2;
    else if (additional == "keeperx2") keeper[index] += 2;
    else if (additional == "magex2") mage[index] += 2;
    else if (additional == "mysticx2") mystic[index] += 2;
    else if (additional == "shadex2") shade[index] += 2;
    else if (additional == "sharpshooterx2") sharpshooter[index] += 2;
    else if (additional == "vanguardx2") vanguard[index] += 2;
}


int synerge_cost(tuple <string, string, string, string, int> &selected_champion) {
    return get<4>(selected_champion);
}

// 선택이 완료된 조합의 시너지를 출력해주는 함수
string synerge_print(int index) {
    string synerge = "";

    // origin
    if (cultist[index] >= 3 && cultist[index] < 6) synerge.append("3광신도 ");
    else if (cultist[index] >= 6 && cultist[index] < 9) synerge.append("6광신도 ");
    else if (cultist[index] >= 9) synerge.append("9광신도 ");

    if (divine[index] >= 2 && divine[index] < 4) synerge.append("2신성 ");
    else if (divine[index] >= 4 && divine[index] < 6) synerge.append("4신성 ");
    else if (divine[index] >= 6 && divine[index] < 8) synerge.append("6신성 ");
    else if (divine[index] >= 8) synerge.append("8신성 ");

    if (dusk[index] >= 2 && dusk[index] < 4) synerge.append("2황혼 ");
    else if (dusk[index] >= 4 && dusk[index] < 6) synerge.append("4황혼 ");
    else if (dusk[index] >= 6) synerge.append("6황혼 ");

    if (elderwood[index] >= 3 && elderwood[index] < 6) synerge.append("3나무정령 ");
    else if (elderwood[index] >= 6 && elderwood[index] < 9) synerge.append("6나무정령 ");
    else if (elderwood[index] >= 9) synerge.append("9나무정령 ");

    if (enlightened[index] >= 2 && enlightened[index] < 4) synerge.append("2선지자 ");
    else if (enlightened[index] >= 4 && enlightened[index] < 6) synerge.append("4선지자 ");
    else if (enlightened[index] >= 6) synerge.append("6선지자 ");

    if (spirit[index] >= 2 && spirit[index] < 4) synerge.append("2영혼 ");
    else if (spirit[index] >= 4 && spirit[index] < 6) synerge.append("4영혼 ");
    else if (spirit[index] >= 6) synerge.append("6영혼 ");
    
    
    if (exile[index] >= 1 && exile[index] < 2) synerge.append("1추방자 ");
    else if (exile[index] >= 2) synerge.append("2추방자 ");

    if (fortune[index] >= 3 && fortune[index] > 6)  synerge.append("3행운 ");
    else if (fortune[index] >= 6)  synerge.append("6행운 ");

    if (moonlight[index] >= 3) synerge.append("3달빛 ");   

    if (ninja[index] == 1) synerge.append("1닌자 ");  
    else if (ninja[index] == 4) synerge.append("4닌자 ");  

    if (theboss[index] == 1) synerge.append("1우두머리 ");  

    if (tormented[index] == 1) synerge.append("1번뇌 ");  

    if (warload[index] >= 3 && warload[index] < 6) synerge.append("3대장군 ");  
    else if (warload[index] >= 6 && warload[index] < 9) synerge.append("6대장군 ");   
    else if (warload[index] >= 9) synerge.append("9대장군 ");   


    // classes
    if (adept[index] >= 2 && adept[index] < 3) synerge.append("2조율자 ");  
    else if (adept[index] >= 3 && adept[index] < 4) synerge.append("3조율자 ");
    else if (adept[index] >= 4) synerge.append("4조율자 ");

    if (assassin[index] >= 2 && assassin[index] < 4) synerge.append("2암살자 ");
    else if (assassin[index] >= 4 && assassin[index] < 6) synerge.append("4암살자 ");
    else if (assassin[index] >= 6) synerge.append("6암살자 ");

    if (brawler[index] >= 2 && brawler[index] < 4) synerge.append("2싸움꾼 ");
    else if (brawler[index] >= 4 && brawler[index] < 6) synerge.append("4싸움꾼 ");
    else if (brawler[index] >= 6 && brawler[index] < 8) synerge.append("6싸움꾼 ");
    else if (brawler[index] >= 8) synerge.append("8싸움꾼 ");

    if (dazzler[index] >= 2 && dazzler[index] < 4) synerge.append("2현혹술사 ");
    else if (dazzler[index] >= 4) synerge.append("4현혹술사 ");  

    if (duelist[index] >= 2 && duelist[index] < 4) synerge.append("2결투가 ");
    else if (duelist[index] >= 4 && duelist[index] < 6) synerge.append("4결투가 ");
    else if (duelist[index] >= 6 && duelist[index] < 8) synerge.append("6결투가 ");
    else if (duelist[index] >= 8) synerge.append("8결투가 ");

    if (emperor[index] == 1) synerge.append("1황제 ");

    if (hunter[index] >= 2 && hunter[index] < 3) synerge.append("2사냥꾼 ");
    else if (hunter[index] >= 3 && hunter[index] < 4) synerge.append("3사냥꾼 ");
    else if (hunter[index] >= 4 && hunter[index] < 5) synerge.append("4사냥꾼 ");
    else if (hunter[index] >= 5) synerge.append("5사냥꾼 ");

    if (keeper[index] >= 2 && keeper[index] < 4) synerge.append("2귀감 ");
    else if (keeper[index] >= 4 && keeper[index] < 6) synerge.append("4귀감 ");
    else if (keeper[index] >= 6) synerge.append("6귀감 ");

    if (mage[index] >= 3 && mage[index] < 6) synerge.append("3요술사 ");
    else if (mage[index] >= 6 && mage[index] < 9) synerge.append("6요술사 ");
    else if (mage[index] >= 9) synerge.append("9요술사 ");

    if (mystic[index] >= 2 && mystic[index] < 4) synerge.append("2신비술사 ");
    else if (mystic[index] >= 4 && mystic[index] < 6) synerge.append("4신비술사 ");
    else if (mystic[index] >= 6) synerge.append("6신비술사 ");

    if (shade[index] >= 2 && shade[index] < 3) synerge.append("2그림자 ");
    else if (shade[index] >= 3 && shade[index] < 4) synerge.append("3그림자 "); 
    else if (shade[index] >= 4) synerge.append("4그림자 ");  

    if (sharpshooter[index] >= 2 && sharpshooter[index] < 4) synerge.append("2명사수 ");
    else if (sharpshooter[index] >= 4 && sharpshooter[index] < 6) synerge.append("4명사수 ");
    else if (sharpshooter[index] >= 6) synerge.append("6명사수 ");  

    if (vanguard[index] >= 2 && vanguard[index] < 4) synerge.append("2선봉대 ");
    else if (vanguard[index] >= 4 && vanguard[index] < 6) synerge.append("4선봉대 ");
    else if (vanguard[index] >= 6) synerge.append("6선봉대 ");
 
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
    selected_champions_info();
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