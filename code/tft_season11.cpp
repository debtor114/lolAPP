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

// �Ϲ� è�Ǿ� ���հ� ���ù����� è�Ǿ� ����
vector < tuple <string, string, string, string, string, int, string> > champions;
vector < tuple <string, string, string, string, string, int, string> > selected_champions;

// ������ 4��, 6������, 7���̻� ȹ���� �� �ִ� è�Ǿ� ���յ�
vector< tuple <string, string, string, string, string, int, string> > level4_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level6_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level7_up_champions;

// ����� �� ��� ���� ������ è�Ǿ� ���յ�
vector< tuple <string, string, string, string, string, int, string> > user_select_champ;


int selected_size; // ������ è�Ǿ��� �� �� �����ߴ���

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



// ����� �Ϸ�� �� �ó����� �ʱ�ȭ ���ִ� �Լ�
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
    champions.push_back(make_tuple("�Ƹ�", "Fated", "", "Arcanist", "", 1, "")); 
    champions.push_back(make_tuple("�ʰ���", "Mythic", "", "Behemoth", "", 1, "")); 
    champions.push_back(make_tuple("����Ʋ��", "Ghostly", "", "Sniper", "", 1, "")); 
    champions.push_back(make_tuple("�ٸ��콺", "Umbral", "", "Duelist", "", 1, "")); 
    champions.push_back(make_tuple("�ں���", "Fortune", "", "Bruiser", "", 1, "")); 
    champions.push_back(make_tuple("����", "Storyweaver", "", "Warden", "", 1, "")); 
    champions.push_back(make_tuple("�轺", "Inkshadow", "", "Warden", "", 1, ""));
    champions.push_back(make_tuple("ī����", "Heavenly", "", "Reaper", "", 1, ""));
    champions.push_back(make_tuple("�ڱ׸�", "Mythic", "", "Invoker", "Sniper", 1, "")); 
    champions.push_back(make_tuple("������Ʈ", "Heavenly", "", "Behemoth", "", 1, "")); 
    champions.push_back(make_tuple("������", "Dryad", "", "Bruiser", "", 1, ""));
    champions.push_back(make_tuple("�ú�", "Storyweaver", "", "Trickshot", "", 1, "")); 
    champions.push_back(make_tuple("�߽���", "Fated", "", "Duelist", "", 1, "")); 

    champions.push_back(make_tuple("��Ʈ�Ͻ�", "Ghostly", "Inkshadow", "Bruiser", "", 2, "")); 
    champions.push_back(make_tuple("����", "Dryad", "", "Warden", "", 2, "")); 
    champions.push_back(make_tuple("�ܳ�", "Dragonlord", "", "Invoker", "", 2, "")); 
    champions.push_back(make_tuple("Ų�巹��", "Dryad", "Fated", "Reaper", "", 2, ""));
    champions.push_back(make_tuple("����", "Porcelain", "", "Arcanist", "", 2, "")); 
    champions.push_back(make_tuple("����", "Storyweaver", "", "Altruist", "Bruiser", 2, "")); 
    champions.push_back(make_tuple("����", "Inkshadow", "", "Sniper", "", 2, "")); 
    champions.push_back(make_tuple("��", "Ghostly", "", "Behemoth", "", 2, "")); 
    champions.push_back(make_tuple("Ƽ��", "Fortune", "", "Trickshot", "", 2, ""));
    champions.push_back(make_tuple("�丯", "Umbral", "", "Behemoth", "", 2, ""));
    champions.push_back(make_tuple("���̶�", "Storyweaver", "", "Sage", "", 2, ""));
    champions.push_back(make_tuple("����", "Heavenly", "Mythic", "Arcanist", "", 2, ""));
    champions.push_back(make_tuple("Ű�Ƴ�", "Heavenly", "", "Duelist", "", 2, ""));

    champions.push_back(make_tuple("�˷�", "Umbral", "", "Invoker", "", 3, ""));
    champions.push_back(make_tuple("�ƹ���", "Porcelain", "", "Warden", "", 3, "")); 
    champions.push_back(make_tuple("���縮����", "Fated", "", "Sniper", "", 3, "")); 
    champions.push_back(make_tuple("�ٵ�", "Mythic", "", "Trickshot", "", 3, "")); 
    champions.push_back(make_tuple("���ֳ̾�", "Dragonlord", "", "Sage", "", 3, "")); 
    champions.push_back(make_tuple("�϶����", "Ghostly", "", "Arcanist", "Warden", 3, ""));
    champions.push_back(make_tuple("�Ҷ�ī", "Heavenly", "", "Altruist", "", 3, "")); 
    champions.push_back(make_tuple("Ž��ġ", "Mythic", "", "Bruiser", "", 3, "")); 
    champions.push_back(make_tuple("������", "Fated", "", "Behemoth", "", 3, "")); 
    champions.push_back(make_tuple("Ʈ����Ÿ��", "Fortune", "", "Duelist", "", 3, "")); 
    champions.push_back(make_tuple("��������", "Inkshadow", "", "Duelist", "", 3, "")); 
    champions.push_back(make_tuple("���", "Umbral", "", "", "Reaper", 3, ""));
    champions.push_back(make_tuple("����", "Fortune", "Storyweaver", "Arcanist", "", 3, ""));

    champions.push_back(make_tuple("�ִ�", "Fortune", "", "Invoker", "", 4, "")); 
    champions.push_back(make_tuple("�ֽ�", "Porcelain", "", "Sniper", "", 4, "")); 
    champions.push_back(make_tuple("������", "Storyweaver", "", "Bruiser", "", 4, "")); 
    champions.push_back(make_tuple("ī�̻�", "Inkshadow", "", "Trickshot", "", 4, "")); 
    champions.push_back(make_tuple("����", "Ghostly", "", "Reaper", "", 4, ""));
    champions.push_back(make_tuple("����", "Dragonlord", "", "Duelist", "", 4, "")); 
    champions.push_back(make_tuple("������", "Mythic", "", "Invoker", "", 4, "")); 
    champions.push_back(make_tuple("�𸣰���", "Ghostly", "", "Sage", "", 4, "")); 
    champions.push_back(make_tuple("��ƿ����", "Mythic", "", "Warden", "", 4, "")); 
    champions.push_back(make_tuple("����", "Dryad", "", "Behemoth", "", 4, "")); 
    champions.push_back(make_tuple("���Ϸ���", "Umbral", "", "Bruiser", "", 4, "")); 
    champions.push_back(make_tuple("�ŵ��", "Fated", "", "Arcanist", "", 4, "")); 

    champions.push_back(make_tuple("������", "Dryad", "", "Invoker", "", 5, "")); 
    champions.push_back(make_tuple("�����", "Mythic", "", "Artist", "", 5, "")); 
    champions.push_back(make_tuple("�̷�����", "Storyweaver", "", "Duelist", "", 5, "")); 
    champions.push_back(make_tuple("������", "Porcelain", "", "Arcanist", "", 5, "")); 
    champions.push_back(make_tuple("��ĭ", "Dragonlord", "", "Altruist", "Lovers", 5, "")); 
    champions.push_back(make_tuple("��Ʈ", "Fated", "Umbral", "Warden", "", 5, "")); 
    champions.push_back(make_tuple("���", "Inkshadow", "", "Behemoth", "Spirit_walker", 5, "")); 
    champions.push_back(make_tuple("����", "Heavenly", "", "Great", "Sage", 5, "")); 
    champions.push_back(make_tuple("�ھ�", "Dragonlord", "", "Trickshot", "Lovers", 5, ""));
}



// �ʹݺο� �־��� è�Ǿ� ���յ��� ������ִ� �Լ�
void makingChampionList(int argc, char** argv) {
    if (argc >= 4) {
        for (int i = 3; i < argc; i++) {
            // ������ ������ �Ϲ� è�Ǿ�
            for (int j = 0; j < champions.size(); j++) {
                if(argv[i] == get<0>(champions[j])) {
                    user_select_champ.push_back(champions[j]);
                }
            }
   
        }
        if (user_select_champ.size() < argc - 3) {
            cout << "������ è�Ǿ��� �������� �ʽ��ϴ�.\n��Ż�ڰ� �ִ��� Ȯ�����ּ���\n";
            for (int i = 3; i < argc; i++) {
                cout << argv[i] << " ";
                //cout << get<0>(user_select_champ[j]) << " ";
            }
            exit(0);
        }
    }

    selected_size = user_select_champ.size();

    // ������ ������ è�Ǿ�(user_select_champ)�� ���õ� è�Ǿ� ����(level4_down_champions.. etc..)�� �ߺ� ���ԵǴ� �� ����
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
    cout << "����ü�� Ư���� ���� ���� ���� �ó����� �����մϴ�." << endl;
    cout << "Ư���� �Ѱ� �� �������ּ���" << endl;
    cout << "ex) 2���ڱ�, ��Ÿ��" << endl;
    cout << " => \"2���ڱ�\" �Է��� enter" << endl;
    cout << " => \"1��Ÿ��\" �Է��� enter" << endl;
    cout << " => \"END\"�Է��� enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "���ڱ�") porcelain += num;
        else if (traits == "�뱺��") dragonlord += num;
        else if (traits == "�ʿ�") fated += num;
        else if (traits == "��ȭ") mythic += num;
        else if (traits == "���") fortune += num;
        else if (traits == "������") dryad += num;
        else if (traits == "ȥ��") ghostly += num;
        else if (traits == "õ��") heavenly += num;
        else if (traits == "�Ա׸���") inkshadow += num;
        else if (traits == "�Ͽ�") umbral += num;
        else if (traits == "�̾߱��") stroyweaver += num;
        else if (traits == "����") exalted += num;

        // classes
        else if (traits == "����������") arcanist += num;
        else if (traits == "������") bruiser += num;
        else if (traits == "������") duelist += num;
        else if (traits == "�Ŵ뱫��") behemoth += num;
        else if (traits == "����") lover += num;
        else if (traits == "���ݼ�") sniper += num;
        else if (traits == "�����") invoker += num;
        else if (traits == "�ļ���") warden += num;
        else if (traits == "���ֲ�") trickshot += num;  
        else if (traits == "ȣ��") great += num;
        else if (traits == "���") reaper += num;
        else if (traits == "��Ÿ��") altruist += num;
        else if (traits == "�����ּ���") spirit_Walker += num;
        else if (traits == "����") sage += num;
        else if (traits == "������") artist += num;
    }
    

}


void addExaltedChamp() {
    cout << "���� è�Ǿ��� �߰��մϴ�." << endl;
    cout << "è�Ǿ��� �Ѱ� �� �������ּ���" << endl;
    cout << "ex) ����, �ʰ���, ���, " << endl;
    cout << " => \"����\" �Է��� enter" << endl;
    cout << " => \"�ʰ���\" �Է��� enter" << endl;
    cout << " => ���� �Է� �� \"END\" enter" << endl;

    while(1) {
        string champ;
        cin >> champ;
        if (champ == "END") break;

        for (int i = 0; i < 60; i++) {
            if (get<0>(champions[i]) == champ) {
                get<6>(champions[i]) = "Exalted";
                // cout << "���ε�ϿϷ� : " << get<0>(champions[i]) << endl;
            }
        }
    }
}

// ������ �Ϸ�� ������ �ó��� ������ ����ϴ� �Լ�
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

// ������ �Ϸ�� ������ �ó����� ����ϴ� �Լ�
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


    // classes2, Ư���� 2�� �ִ� è�Ǿ�� ó��
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

    // ���� ó��
    if (origin3 == "Exalted") Exalted[index]++;

}


int twostar_champion_cost(tuple <string, string, string, string, string, int, string> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// ������ �Ϸ�� ������ �ó����� ������ִ� �Լ�
string synerge_print(int index) {
    string synerge = "";

    if (Porcelain[index] >= 2 && Porcelain[index] < 4) synerge.append("2���ڱ� ");
    else if (Porcelain[index] >= 4 && Porcelain[index] < 6) synerge.append("4���ڱ� ");   
    else if (Porcelain[index] >= 6) synerge.append("6���ڱ� "); 

    if (Dragonlord[index] >= 2 && Dragonlord[index] < 3) synerge.append("2�뱺�� "); 
    else if (Dragonlord[index] >= 3 && Dragonlord[index] < 4) synerge.append("3�뱺�� ");   
    else if (Dragonlord[index] >= 4 && Dragonlord[index] < 5) synerge.append("4�뱺�� ");   
    else if (Dragonlord[index] >= 5) synerge.append("5�뱺�� "); 

    if (Fated[index] >= 3 && Fated[index] < 5) synerge.append("3�ʿ� ");  
    else if (Fated[index] >= 5 && Fated[index] < 7) synerge.append("5�ʿ� ");  
    else if (Fated[index] >= 7 && Fated[index] < 10) synerge.append("7�ʿ� ");  
    else if (Fated[index] >= 10) synerge.append("10�ʿ� "); 

    if (Mythic[index] >= 3 && Mythic[index] < 5) synerge.append("3��ȭ ");  
    else if (Mythic[index] >= 5 && Mythic[index] < 7) synerge.append("5��ȭ ");  
    else if (Mythic[index] >= 7 && Mythic[index] < 10) synerge.append("7��ȭ ");  
    else if (Mythic[index] >= 10) synerge.append("10��ȭ "); 

     if (Fortune[index] >= 3 && Fortune[index] < 5) synerge.append("3��� ");  
    else if (Fortune[index] >= 5 && Fortune[index] < 7) synerge.append("5��� ");  
    else if (Fortune[index] >= 7) synerge.append("7��� "); 
    
    if (Dryad[index] >= 2 && Dryad[index] < 4) synerge.append("2������ "); 
    else if (Dryad[index] >= 4 && Dryad[index] < 4) synerge.append("4������ "); 
    else if (Dryad[index] >= 6) synerge.append("6������ ");   

    if (Ghostly[index] >= 2 && Ghostly[index] < 4) synerge.append("2ȥ�� ");  
    else if (Ghostly[index] >= 4 && Ghostly[index] < 6) synerge.append("4ȥ�� ");  
    else if (Ghostly[index] >= 6 && Ghostly[index] < 8) synerge.append("6ȥ�� ");  
    else if (Ghostly[index] >= 8) synerge.append("8ȥ�� "); 

    if (Heavenly[index] >= 2 && Heavenly[index] < 3) synerge.append("2õ�� "); 
    else if (Heavenly[index] >= 3 && Heavenly[index] < 4) synerge.append("3õ�� "); 
    else if (Heavenly[index] >= 4 && Heavenly[index] < 5) synerge.append("4õ�� "); 
    else if (Heavenly[index] >= 5 && Heavenly[index] < 6) synerge.append("5õ�� "); 
    else if (Heavenly[index] >= 6 && Heavenly[index] < 7) synerge.append("6õ�� "); 
    else if (Heavenly[index] >= 7) synerge.append("7õ�� ");   

    if (Inkshadow[index] >= 3 && Inkshadow[index] < 5) synerge.append("3�Ա׸��� "); 
    else if (Inkshadow[index] >= 5 && Inkshadow[index] < 7) synerge.append("5�Ա׸��� ");  
    else if (Inkshadow[index] >= 7) synerge.append("7�Ա׸��� "); 

    if (Umbral[index] >= 2 && Umbral[index] < 4) synerge.append("2�Ͽ� ");  
    else if (Umbral[index] >= 4 && Umbral[index] < 6) synerge.append("4�Ͽ� ");  
    else if (Umbral[index] >= 6 && Umbral[index] < 8) synerge.append("6�Ͽ� ");  
    else if (Umbral[index] >= 9) synerge.append("9�Ͽ� "); 

    if (Storyweaver[index] >= 3 && Storyweaver[index] < 5) synerge.append("3�̾߱�� ");  
    else if (Storyweaver[index] >= 5 && Storyweaver[index] < 7) synerge.append("5�̾߱�� ");  
    else if (Storyweaver[index] >= 7 && Storyweaver[index] < 10) synerge.append("7�̾߱�� ");  
    else if (Storyweaver[index] >= 10) synerge.append("10�̾߱�� "); 

    if (Exalted[index] >= 3 && Exalted[index] < 5) synerge.append("3���� ");  
    else if (Exalted[index] >= 5) synerge.append("5���� "); 


    // classes
    if (Great[index] == 1) synerge.append("1ȣ�� ");   
    if (Lover[index] == 1 ) synerge.append("1���� "); 
    if (Artist[index] == 1) synerge.append("1������ ");  
    if (Spirit_Walker[index] == 1) synerge.append("1�����ּ��� "); 

    if (Arcanist[index] >= 2 && Arcanist[index] < 4) synerge.append("2���������� "); 
    else if (Arcanist[index] >= 4 && Arcanist[index] < 6) synerge.append("4���������� "); 
    else if (Arcanist[index] >= 6 && Arcanist[index] < 8) synerge.append("6���������� "); 
    else if (Arcanist[index] >= 8) synerge.append("8���������� "); 

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2������ "); 
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4������ "); 
    else if (Bruiser[index] >= 6 && Bruiser[index] < 8) synerge.append("6������ "); 
    else if (Bruiser[index] >= 8) synerge.append("8������ "); 

    if (Duelist[index] >= 2 && Duelist[index] < 4) synerge.append("2������ "); 
    else if (Duelist[index] >= 4 && Duelist[index] < 6) synerge.append("4������ "); 
    else if (Duelist[index] >= 6 && Duelist[index] < 8) synerge.append("6������ "); 
    else if (Duelist[index] >= 8) synerge.append("8������ "); 

    if (Behemoth[index] >= 2 && Behemoth[index] < 4) synerge.append("2�Ŵ뱫�� "); 
    else if (Behemoth[index] >= 4 && Behemoth[index] < 6) synerge.append("4�Ŵ뱫�� "); 
    else if (Behemoth[index] >= 6) synerge.append("6�Ŵ뱫�� "); 

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge.append("2���ݼ� "); 
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge.append("4���ݼ� "); 
    else if (Sniper[index] >= 6) synerge.append("6���ݼ� ");  

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge.append("2����� "); 
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge.append("4����� "); 
    else if (Invoker[index] >= 6) synerge.append("6����� ");  

    if (Warden[index] >= 2 && Warden[index] < 4) synerge.append("2�ļ��� "); 
    else if (Warden[index] >= 4 && Warden[index] < 6) synerge.append("4�ļ��� "); 
    else if (Warden[index] >= 6) synerge.append("6�ļ��� ");   

    if (Trickshot[index] >= 2 && Trickshot[index] < 4) synerge.append("2���ֲ� "); 
    else if (Trickshot[index] >= 4) synerge.append("4���ֲ� ");   

    if (Reaper[index] >= 2 && Reaper[index] < 4) synerge.append("2��� "); 
    else if (Reaper[index] >= 4) synerge.append("4��� "); 

    if (Altruist[index] >= 2 && Altruist[index] < 3) synerge.append("2��Ÿ�� "); 
    else if (Altruist[index] >= 3 && Altruist[index] < 4) synerge.append("3��Ÿ�� "); 
    else if (Altruist[index] >= 4) synerge.append("4��Ÿ�� "); 

    if (Sage[index] >= 2 && Sage[index] < 3) synerge.append("2���� "); 
    else if (Sage[index] >= 3 && Sage[index] < 4) synerge.append("3���� "); 
    else if (Sage[index] >= 4 && Sage[index] < 5) synerge.append("4���� "); 
    else if (Sage[index] >= 5) synerge.append("5���� ");  

    return synerge;
}


vector <int> pick[60];

// pq�� minHeap�� ����ؼ� Ž��, ����, ���Ŀ� log(N)�� �ð����⵵�� ���´�, ���� ������ �ʿ� X
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
