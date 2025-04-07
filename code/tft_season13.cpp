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

// ������ 4��, 6������, 7���̻� ȹ���� �� �ִ� è�Ǿ� ���յ�
vector< tuple <string, string, string, string, string, int, string> > level4_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level6_down_champions;
vector< tuple <string, string, string, string, string, int, string> > level7_up_champions;

// ����� �� ��� ���� ������ è�Ǿ� ���յ�
vector< tuple <string, string, string, string, string, int, string> > user_select_champ;


int selected_size; // ������ è�Ǿ��� �� �� �����ߴ���

// origin1
int Automata[60];
int Firelight[60];
int Rebel[60];
int Black_Rose[60];
int Experiment[60];
int Enforcer[60];
int Conqueror[60];
int Chem_Baron[60];
int Family[60];
int Scrap[60];
int Academy[60];
int Emissary[60];
int High_Roller[60];
int Junker_King[60];

// classes1
int Visionary[60];
int Pit_Fighter[60];
int Sorcerer[60];
int Watcher[60];
int Sniper[60];
int Artillerist[60];
int Bruiser[60];
int Form_Swapper[60];
int Dominator[60];
int Quickstriker[60];
int Ambusher[60];
int Sentinel[60];


// position

int Fronter[60];
int Backer[60];
int ANY[60];

// fix synerge
int automata;
int firelight;
int rebel;
int black_rose;
int experiment;
int enforcer;
int conqueror;
int chem_baron;
int family;
int scrap;
int academy;
int emissary;
int junker_king;
int high_roller;

int visionary;
int pit_fighter;
int sorcerer;
int watcher;
int sniper;
int artillerist;
int bruiser;
int form_swapper;
int dominator;
int quickstriker;
int ambusher;
int sentinel;

int fronter;
int backer;
int any;



// ����� �Ϸ�� �� �ó����� �ʱ�ȭ ���ִ� �Լ�
void init(int index) {

    // origins
    Firelight[index] = firelight;
    Enforcer[index] = enforcer;
    Rebel[index] = rebel;
    Experiment[index] = experiment;
    Conqueror[index] = conqueror;
    Chem_Baron[index] = chem_baron;
    Family[index] = family;
    Black_Rose[index] = black_rose;
    Automata[index] = automata;
    Academy[index] = academy;
    Scrap[index] = scrap;
    Emissary[index] = emissary;
    High_Roller[index] = high_roller;
    Junker_King[index] = junker_king;


    // classes
    Visionary[index] = visionary;
    Quickstriker[index] = quickstriker;
    Sentinel[index] = sentinel;
    Pit_Fighter[index] = pit_fighter;
    Watcher[index] = watcher;
    Sorcerer[index] = sorcerer;
    Artillerist[index] = artillerist;
    Dominator[index] = dominator;
    Ambusher[index] = ambusher;
    Sniper[index] = sniper;
    Form_Swapper[index] = form_swapper;
    Bruiser[index] = bruiser;

    Fronter[index] = fronter;
    Backer[index] = backer;
    ANY[index] = any;

}

void champions_info() {
    champions.push_back(make_tuple("�ƹ���", "Automata", "", "Watcher", "", 1, "Fronter")); 
    champions.push_back(make_tuple("�Ŀ��", "Family", "Scrap", "Ambusher", "", 1, "Backer")); 
    champions.push_back(make_tuple("�ٸ��콺", "Conqueror", "", "Watcher", "", 1, "Fronter")); 
    champions.push_back(make_tuple("�巹�̺�", "Conqueror", "", "Pit_Fighter", "", 1, "Backer")); 
    champions.push_back(make_tuple("����", "Enforcer", "", "Bruiser", "", 1, "Fronter")); 
    champions.push_back(make_tuple("�̷�����", "Rebel", "", "Sentinel", "", 1, "Fronter")); 
    champions.push_back(make_tuple("����", "Academy", "", "Sorcerer", "", 1, "Backer"));
    champions.push_back(make_tuple("�𸣰���", "Black_Rose", "", "Visionary", "", 1, "Backer"));
    champions.push_back(make_tuple("���̿÷�", "Family", "", "Pit_Fighter", "", 1, "Fronter")); 
    champions.push_back(make_tuple("�޵�", "Enforcer", "", "Sniper", "", 1, "Backer")); 
    champions.push_back(make_tuple("������", "Chem_Baron", "", "Sentinel", "", 1, "Fronter"));
    champions.push_back(make_tuple("Ʈ����", "Scrap", "", "Bruiser", "", 1, "Fronter")); 
    champions.push_back(make_tuple("����", "Rebel", "", "Visionary", "", 1, "Backer")); 
    champions.push_back(make_tuple("���̶�", "Experiment", "", "Sorcerer", "", 1, "Backer")); 

    champions.push_back(make_tuple("��Į��", "Rebel", "", "Quickstriker", "", 2, "Fronter")); 
    champions.push_back(make_tuple("ī��", "Enforcer", "", "Ambusher", "", 2, "Fronter")); 
    champions.push_back(make_tuple("������", "Academy", "", "Sentinel", "", 2, "Fronter")); 
    champions.push_back(make_tuple("����", "Automata", "", "Quickstriker", "", 2, "Fronter"));
    champions.push_back(make_tuple("����", "Family", "", "Watcher", "", 2, "Fronter")); 
    champions.push_back(make_tuple("��", "Conqueror", "", "Sentinel", "Visionary", 2, "Fronter")); 
    champions.push_back(make_tuple("��Ʈ", "Rebel", "", "Bruiser", "", 2, "Fronter")); 
    champions.push_back(make_tuple("Ʈ����Ÿ��", "Emissary", "", "Artillerist", "", 2, "Backer")); 
    champions.push_back(make_tuple("�츣��", "Experiment", "", "Artillerist", "Pit_Fighter", 2, "Fronter"));
    champions.push_back(make_tuple("����̸�", "Black_Rose", "", "Watcher", "Sorcerer", 2, "Fronter"));
    champions.push_back(make_tuple("����", "Firelight", "", "Sniper", "", 2, "Backer"));
    champions.push_back(make_tuple("����", "Scrap", "", "Dominator", "", 2, "Backer"));
    champions.push_back(make_tuple("����Ÿ", "Chem_Baron", "", "Visionary", "", 2, "Backer"));


    champions.push_back(make_tuple("�θ���", "Enforcer", "", "Sentinel", "", 3, "Fronter"));
    champions.push_back(make_tuple("����ũ��ũ", "Automata", "", "Dominator", "", 3, "Fronter")); 
    champions.push_back(make_tuple("ī�ÿ����", "Black_Rose", "", "Dominator", "", 3, "Backer")); 
    champions.push_back(make_tuple("����", "Chem_Baron", "", "Bruiser", "", 3, "Fronter")); 
    champions.push_back(make_tuple("�����", "Academy", "Rebel", "Artillerist", "", 3, "Backer")); 
    champions.push_back(make_tuple("��ī", "Firelight", "", "Watcher", "", 3, "Fronter"));
    champions.push_back(make_tuple("���÷�ũ", "Scrap", "", "Pit_Fighter", "Form_Swapper", 3, "ANY")); 
    champions.push_back(make_tuple("����ġ", "Chem_Baron", "", "Ambusher", "", 3, "Fronter")); 
    champions.push_back(make_tuple("�ڱ׸�", "Automata", "", "Sniper", "", 3, "Backer")); 
    champions.push_back(make_tuple("����", "Emissary", "", "Sorcerer", "", 3, "Backer")); 
    champions.push_back(make_tuple("����", "Experiment", "", "Bruiser", "Visionary", 3, "Fronter")); 
    champions.push_back(make_tuple("������", "Conqueror", "", "Sorcerer", "Form_Swapper", 3, "ANY"));
    champions.push_back(make_tuple("Ʈ��", "Enforcer", "", "Quickstriker", "", 3, "Backer"));

    champions.push_back(make_tuple("�Ϻ���", "Conqueror", "Emissary", "Quickstriker", "", 4, "Fronter")); 
    champions.push_back(make_tuple("�ڸ�Ű", "Scrap", "", "Artillerist", "", 4, "Backer")); 
    champions.push_back(make_tuple("����", "Experiment", "", "Dominator", "", 4, "Fronter")); 
    champions.push_back(make_tuple("����", "Firelight", "Scrap", "Ambusher", "", 4, "Fronter")); 
    champions.push_back(make_tuple("����", "Emissary", "", "Watcher", "", 4, "Fronter"));
    champions.push_back(make_tuple("������", "Black_Rose", "", "Bruiser", "Form_Swapper", 4, "ANY")); 
    champions.push_back(make_tuple("���̸ӵ���", "Academy", "", "Visionary", "", 4, "Backer")); 
    champions.push_back(make_tuple("�϶����", "Rebel", "", "Sentinel", "", 4, "Fronter")); 
    champions.push_back(make_tuple("����", "Chem_Baron", "", "Dominator", "", 4, "Backer")); 
    champions.push_back(make_tuple("Ʈ��ġ", "Experiment", "", "Sniper", "", 4, "Backer")); 
    champions.push_back(make_tuple("����", "Enforcer", "", "Pit_Fighter", "", 4, "Fronter")); 
    champions.push_back(make_tuple("����", "Rebel", "", "Sorcerer", "", 4, "Backer")); 

    champions.push_back(make_tuple("����Ʋ��", "Enforcer", "", "Sniper", "", 5, "Backer")); 
    champions.push_back(make_tuple("���̽�", "Academy", "", "Form_Swapper", "", 5, "ANY")); 
    champions.push_back(make_tuple("¡ũ��", "Rebel", "", "Ambusher", "", 5, "Backer")); 
    champions.push_back(make_tuple("�����", "Black_Rose", "", "Sorcerer", "", 5, "Backer")); 
    champions.push_back(make_tuple("����ī", "Chem_Baron", "High_Roller", "Pit_Fighter", "", 5, "Fronter")); 
    champions.push_back(make_tuple("������", "Automata", "", "Visionary", "", 5, "Backer")); 
    champions.push_back(make_tuple("��ī����", "Conqueror", "", "Dominator", "", 5, "Fronter")); 
    champions.push_back(make_tuple("����", "Junker_Kings", "Scrap", "Sentinel", "", 5, "Fronter")); 
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
    cout << "�߰� �ó����� �����մϴ�." << endl;
    cout << "Ư���� �Ѱ� �� �������ּ���" << endl;
    cout << "ex) 2������, 1������" << endl;
    cout << " => \"2������\" �Է��� enter" << endl;
    cout << " => \"1������\" �Է��� enter" << endl;
    cout << " => \"END\"�Է��� enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "�ڵ����") automata += num;
        else if (traits == "��ȭ��") firelight += num;
        else if (traits == "�ݱ�") rebel += num;
        else if (traits == "������̴�") black_rose += num;
        else if (traits == "����ü") experiment += num;
        else if (traits == "������") enforcer += num;
        else if (traits == "������") conqueror += num;
        else if (traits == "ȭ������") chem_baron += num;
        else if (traits == "����") family += num;
        else if (traits == "����") scrap += num;
        else if (traits == "��ī����") academy += num;
        else if (traits == "����") emissary += num;
        else if (traits == "���ǿ�") junker_king += num;
        else if (traits == "���ڲ�") high_roller += num;

        // classes
        else if (traits == "������") visionary += num;
        else if (traits == "����") pit_fighter += num;
        else if (traits == "������") sorcerer += num;
        else if (traits == "�ֽ���") watcher += num;
        else if (traits == "���ݼ�") sniper += num;
        else if (traits == "����") artillerist += num;
        else if (traits == "������") bruiser += num;
        else if (traits == "������ȯ��") form_swapper += num;  
        else if (traits == "������") dominator += num;
        else if (traits == "�⵿Ÿ�ݴ�") quickstriker += num;
        else if (traits == "�ź���") ambusher += num;
        else if (traits == "������") sentinel += num;

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
    if (Automata[index] >= 2 && Automata[index] < 4) synerge_count += 5;
    else if (Automata[index] >= 4 && Automata[index] < 6) synerge_count += 10;  
    else if (Automata[index] >= 6) synerge_count += 15;

    if (Firelight[index] >= 2 && Firelight[index] < 3) synerge_count += 5;
    else if (Firelight[index] >= 3 && Firelight[index] < 4) synerge_count += 10;  
    else if (Firelight[index] >= 4) synerge_count += 15;  

    if (Rebel[index] >= 3 && Rebel[index] < 5) synerge_count += 8; 
    else if (Rebel[index] >= 5 && Rebel[index] < 7) synerge_count += 15; 
    else if (Rebel[index] >= 7 && Rebel[index] < 10) synerge_count += 30; 
    else if (Rebel[index] >= 10) synerge_count += 45;

    if (Black_Rose[index] >= 3 && Black_Rose[index] < 4) synerge_count += 7; 
    else if (Black_Rose[index] >= 4 && Black_Rose[index] < 5) synerge_count += 12; 
    else if (Black_Rose[index] >= 5 && Black_Rose[index] < 7) synerge_count += 15; 
    else if (Black_Rose[index] >= 7) synerge_count += 30; 

    if (Experiment[index] >= 3 && Experiment[index] < 5) synerge_count += 8; 
    else if (Experiment[index] >= 5 && Experiment[index] < 7) synerge_count += 15; 
    else if (Experiment[index] >= 7) synerge_count += 30;
    
    if (Enforcer[index] >= 2 && Enforcer[index] < 4) synerge_count += 5;
    else if (Enforcer[index] >= 4 && Enforcer[index] < 6) synerge_count += 10;
    else if (Enforcer[index] >= 6 && Enforcer[index] < 8) synerge_count += 15;
    else if (Enforcer[index] >= 8 && Enforcer[index] < 10) synerge_count += 31;
    else if (Enforcer[index] >= 10) synerge_count += 42;  

    if (Conqueror[index] >= 2 && Conqueror[index] < 4) synerge_count += 5; 
    else if (Conqueror[index] >= 4 && Conqueror[index] < 6) synerge_count += 10; 
    else if (Conqueror[index] >= 6 && Conqueror[index] < 8) synerge_count += 15; 
    else if (Conqueror[index] >= 9) synerge_count += 38;

    if (Chem_Baron[index] >= 3 && Chem_Baron[index] < 4) synerge_count += 9;
    else if (Chem_Baron[index] >= 4 && Chem_Baron[index] < 5) synerge_count += 14;
    else if (Chem_Baron[index] >= 5 && Chem_Baron[index] < 6) synerge_count += 20;
    else if (Chem_Baron[index] >= 6 && Chem_Baron[index] < 7) synerge_count += 26;
    else if (Chem_Baron[index] >= 7) synerge_count += 33;  

    if (Family[index] >= 3 && Family[index] < 4) synerge_count += 7;
    else if (Family[index] >= 4 && Family[index] < 5) synerge_count += 13; 
    else if (Family[index] >= 5) synerge_count += 16;

    if (Scrap[index] >= 2 && Scrap[index] < 4) synerge_count += 5; 
    else if (Scrap[index] >= 4 && Scrap[index] < 6) synerge_count += 12; 
    else if (Scrap[index] >= 6 && Scrap[index] < 8) synerge_count += 25; 
    else if (Scrap[index] >= 9) synerge_count += 38;

    if (Academy[index] >= 3 && Academy[index] < 4) synerge_count += 8; 
    else if (Academy[index] >= 4 && Academy[index] < 5) synerge_count += 13; 
    else if (Academy[index] >= 5 && Academy[index] < 6) synerge_count += 18; 
    else if (Academy[index] >= 6) synerge_count += 25;

    if (Emissary[index] >= 1 && Emissary[index] < 2) synerge_count += 8; 
    else if (Emissary[index] >= 2 && Emissary[index] < 4) synerge_count -= 3;
    else if (Emissary[index] >= 4) synerge_count += 15;

    if (High_Roller[index] == 1) synerge_count += 2;  
    if (Junker_King[index] == 1 ) synerge_count += 2;

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

    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge_count += 5;
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge_count += 12;
    else if (Sentinel[index] >= 6) synerge_count += 25;

    if (Visionary[index] >= 2 && Visionary[index] < 4) synerge_count += 5;
    else if (Visionary[index] >= 4 && Visionary[index] < 6) synerge_count += 10;
    else if (Visionary[index] >= 6 && Visionary[index] < 8) synerge_count += 15;
    else if (Visionary[index] >= 8) synerge_count += 31;

    if (Pit_Fighter[index] >= 2 && Pit_Fighter[index] < 4) synerge_count += 5;
    else if (Pit_Fighter[index] >= 4 && Pit_Fighter[index] < 6) synerge_count += 10;
    else if (Pit_Fighter[index] >= 6 && Pit_Fighter[index] < 8) synerge_count += 15;
    else if (Pit_Fighter[index] >= 8) synerge_count += 33;

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge_count += 5;
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge_count += 10;
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge_count += 15;
    else if (Sorcerer[index] >= 8) synerge_count += 32;

    if (Watcher[index] >= 2 && Watcher[index] < 4) synerge_count += 5;
    else if (Watcher[index] >= 4 && Watcher[index] < 6) synerge_count += 12;
    else if (Watcher[index] >= 6) synerge_count += 25;

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge_count += 5;
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge_count += 12;
    else if (Sniper[index] >= 6) synerge_count += 25; 

    if (Artillerist[index] >= 2 && Artillerist[index] < 3) synerge_count += 5;
    else if (Artillerist[index] >= 4 && Artillerist[index] < 6) synerge_count += 12;
    else if (Artillerist[index] >= 6) synerge_count += 25; 

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 5;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 12;
    else if (Bruiser[index] >= 6) synerge_count += 25;  

    if (Form_Swapper[index] >= 2 && Form_Swapper[index] < 4) synerge_count += 5;
    else if (Form_Swapper[index] >= 4) synerge_count += 12;  

    if (Dominator[index] >= 2 && Dominator[index] < 4) synerge_count += 5;
    else if (Dominator[index] >= 4 && Dominator[index] < 6) synerge_count += 12;
    else if (Dominator[index] >= 6) synerge_count += 25; 

    if (Quickstriker[index] >= 2 && Quickstriker[index] < 3) synerge_count += 5;
    else if (Quickstriker[index] >= 3 && Quickstriker[index] < 4) synerge_count += 10;
    else if (Quickstriker[index] >= 4) synerge_count += 18;

    if (Ambusher[index] >= 2 && Ambusher[index] < 3) synerge_count += 5;
    else if (Ambusher[index] >= 3 && Ambusher[index] < 4) synerge_count += 10;
    else if (Ambusher[index] >= 4 && Ambusher[index] < 5) synerge_count += 15;
    else if (Ambusher[index] >= 5) synerge_count += 22; 


    // if (Fronter[index] - Backer[index] + ANY[index] >= 3 && Fronter[index] - Backer[index] + ANY[index] < 8) synerge_count += 10;
    // else if (Fronter[index] - Backer[index] + ANY[index] >= 1 && Fronter[index] - Backer[index] + ANY[index] < 3) synerge_count += 5;
    // else if (Fronter[index] - Backer[index] + ANY[index] < 1) synerge_count += 2;


    return synerge_count;
}

// ������ �Ϸ�� ������ �ó����� ����ϴ� �Լ�
void synerge_add(tuple <string, string, string, string, string, int, string> &champion, int index) {
    string origin1 = get<1>(champion);
    string origin2 = get<2>(champion);
    string classes1 = get<3>(champion);
    string classes2 = get<4>(champion);
    string BNF = get<6>(champion);

    // origin1
    if (origin1 == "Automata") Automata[index]++;
    else if (origin1 == "Firelight") Firelight[index]++;
    else if (origin1 == "Rebel") Rebel[index]++;
    else if (origin1 == "Black_Rose") Black_Rose[index]++;
    else if (origin1 == "Experiment") Experiment[index]++;
    else if (origin1 == "Enforcer") Enforcer[index]++;
    else if (origin1 == "Conqueror") Conqueror[index]++;
    else if (origin1 == "Chem_Baron") Chem_Baron[index]++;
    else if (origin1 == "Family") Family[index]++;
    else if (origin1 == "Scrap") Scrap[index]++;
    else if (origin1 == "Academy") Academy[index]++;
    else if (origin1 == "Junker_King") Junker_King[index]++;
    else if (origin1 == "Emissary") Emissary[index]++; 
    else if (origin1 == "High_Roller") High_Roller[index]++;

    // origin2
    if (origin2 == "Automata") Automata[index]++;
    else if (origin2 == "Firelight") Firelight[index]++;
    else if (origin2 == "Rebel") Rebel[index]++;
    else if (origin2 == "Black_Rose") Black_Rose[index]++;
    else if (origin2 == "Experiment") Experiment[index]++;
    else if (origin2 == "Enforcer") Enforcer[index]++;
    else if (origin2 == "Conqueror") Conqueror[index]++;
    else if (origin2 == "Chem_Baron") Chem_Baron[index]++;
    else if (origin2 == "Family") Family[index]++;
    else if (origin2 == "Scrap") Scrap[index]++;
    else if (origin2 == "Academy") Academy[index]++;
    else if (origin2 == "Junker_King") Junker_King[index]++;
    else if (origin2 == "Emissary") Emissary[index]++;
    else if (origin2 == "High_Roller") High_Roller[index]++;

    // classes1
    if (classes1 == "Visionary") Visionary[index]++;
    else if (classes1 == "Sorcerer") Sorcerer[index]++;
    else if (classes1 == "Watcher") Watcher[index]++;
    else if (classes1 == "Sniper") Sniper[index]++;
    else if (classes1 == "Artillerist") Artillerist[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "Form_Swapper") Form_Swapper[index]++;  
    else if (classes1 == "Dominator") Dominator[index]++;
    else if (classes1 == "Quickstriker") Quickstriker[index]++;
    else if (classes1 == "Ambusher") Ambusher[index]++;
    else if (classes1 == "Sentinel") Sentinel[index]++;
    else if (classes1 == "Pit_Fighter") Pit_Fighter[index]++;


    // classes2, Ư���� 2�� �ִ� è�Ǿ�� ó��
    if (classes2 == "Visionary") Visionary[index]++;
    else if (classes2 == "Sorcerer") Sorcerer[index]++;
    else if (classes2 == "Watcher") Watcher[index]++;
    else if (classes2 == "Sniper") Sniper[index]++;
    else if (classes2 == "Artillerist") Artillerist[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "Form_Swapper") Form_Swapper[index]++;  
    else if (classes2 == "Dominator") Dominator[index]++;
    else if (classes2 == "Quickstriker") Quickstriker[index]++;
    else if (classes2 == "Ambusher") Ambusher[index]++;
    else if (classes2 == "Sentinel") Sentinel[index]++;
    else if (classes2 == "Pit_Fighter") Pit_Fighter[index]++;

    // �� �� ó��
    if (BNF == "Fronter") Fronter[index]++;
    else if (BNF == "Backer") Backer[index]++;
    else if (BNF == "ANY") ANY[index]++;
}


int twostar_champion_cost(tuple <string, string, string, string, string, int, string> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// ������ �Ϸ�� ������ �ó����� ������ִ� �Լ�
string synerge_print(int index) {
    string synerge = "";

    if (Automata[index] >= 2 && Automata[index] < 4) synerge.append("2�ڵ���� ");
    else if (Automata[index] >= 4 && Automata[index] < 6) synerge.append("4�ڵ���� ");   
    else if (Automata[index] >= 6) synerge.append("6�ڵ���� "); 

    if (Firelight[index] >= 3 && Firelight[index] < 4) synerge.append("3��ȭ�� ");   
    else if (Firelight[index] >= 4 && Firelight[index] < 5) synerge.append("4��ȭ�� ");   
    else if (Firelight[index] >= 5) synerge.append("5��ȭ�� "); 

    if (Rebel[index] >= 3 && Rebel[index] < 5) synerge.append("3�ݱ� ");  
    else if (Rebel[index] >= 5 && Rebel[index] < 7) synerge.append("5�ݱ� ");  
    else if (Rebel[index] >= 7 && Rebel[index] < 10) synerge.append("7�ݱ� ");  
    else if (Rebel[index] >= 10) synerge.append("10�ݱ� "); 

    if (Black_Rose[index] >= 3 && Black_Rose[index] < 5) synerge.append("3������̴� ");  
    else if (Black_Rose[index] >= 5 && Black_Rose[index] < 7) synerge.append("5������̴� ");  
    else if (Black_Rose[index] >= 7 && Black_Rose[index] < 10) synerge.append("7������̴� ");  
    else if (Black_Rose[index] >= 10) synerge.append("10������̴� "); 

     if (Experiment[index] >= 3 && Experiment[index] < 5) synerge.append("3����ü ");  
    else if (Experiment[index] >= 5 && Experiment[index] < 7) synerge.append("5����ü ");  
    else if (Experiment[index] >= 7) synerge.append("7����ü "); 
    
    if (Enforcer[index] >= 2 && Enforcer[index] < 4) synerge.append("2������ "); 
    else if (Enforcer[index] >= 4 && Enforcer[index] < 4) synerge.append("4������ "); 
    else if (Enforcer[index] >= 6 && Enforcer[index] < 8) synerge.append("6������ "); 
    else if (Enforcer[index] >= 8 && Enforcer[index] < 10) synerge.append("8������ "); 
    else if (Enforcer[index] >= 10) synerge.append("10������ ");   

    if (Conqueror[index] >= 2 && Conqueror[index] < 4) synerge.append("2������ ");  
    else if (Conqueror[index] >= 4 && Conqueror[index] < 6) synerge.append("4������ ");  
    else if (Conqueror[index] >= 6 && Conqueror[index] < 8) synerge.append("6������ ");  
    else if (Conqueror[index] >= 9) synerge.append("9������ "); 

    if (Chem_Baron[index] >= 2 && Chem_Baron[index] < 3) synerge.append("2ȭ������ "); 
    else if (Chem_Baron[index] >= 3 && Chem_Baron[index] < 4) synerge.append("3ȭ������ "); 
    else if (Chem_Baron[index] >= 4 && Chem_Baron[index] < 5) synerge.append("4ȭ������ "); 
    else if (Chem_Baron[index] >= 5 && Chem_Baron[index] < 6) synerge.append("5ȭ������ "); 
    else if (Chem_Baron[index] >= 6 && Chem_Baron[index] < 7) synerge.append("6ȭ������ "); 
    else if (Chem_Baron[index] >= 7) synerge.append("7ȭ������ ");   

    if (Family[index] >= 2 && Family[index] < 3) synerge.append("2���� "); 
    else if (Family[index] >= 3 && Family[index] < 4) synerge.append("3���� ");  
    else if (Family[index] >= 4) synerge.append("4���� "); 

    if (Scrap[index] >= 2 && Scrap[index] < 4) synerge.append("2���� ");  
    else if (Scrap[index] >= 4 && Scrap[index] < 6) synerge.append("4���� ");  
    else if (Scrap[index] >= 6 && Scrap[index] < 8) synerge.append("6���� ");  
    else if (Scrap[index] >= 9) synerge.append("9���� "); 

    if (Academy[index] >= 3 && Academy[index] < 4) synerge.append("3��ī���� ");  
    else if (Academy[index] >= 4 && Academy[index] < 5) synerge.append("4��ī���� ");  
    else if (Academy[index] >= 5 && Academy[index] < 6) synerge.append("5��ī���� ");  
    else if (Academy[index] >= 6) synerge.append("6��ī���� "); 

    if (Emissary[index] >= 1 && Emissary[index] < 2) synerge.append("1���� ");  
    else if (Emissary[index] >= 2 && Emissary[index] < 3) synerge.append(" ");  
    else if (Emissary[index] >= 4) synerge.append("4���� "); 

    if (High_Roller[index] == 1) synerge.append("1���ڲ� ");   
    if (Junker_King[index] == 1 ) synerge.append("1���ǿ� "); 

    // classes  
    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge.append("2������ "); 
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge.append("4������ "); 
    else if (Sentinel[index] >= 6) synerge.append("6������ "); 

    if (Visionary[index] >= 2 && Visionary[index] < 4) synerge.append("2������ "); 
    else if (Visionary[index] >= 4 && Visionary[index] < 6) synerge.append("4������ "); 
    else if (Visionary[index] >= 6 && Visionary[index] < 8) synerge.append("6������ "); 
    else if (Visionary[index] >= 8) synerge.append("8������ "); 

    if (Pit_Fighter[index] >= 2 && Pit_Fighter[index] < 4) synerge.append("2���� "); 
    else if (Pit_Fighter[index] >= 4 && Pit_Fighter[index] < 6) synerge.append("4���� "); 
    else if (Pit_Fighter[index] >= 6 && Pit_Fighter[index] < 8) synerge.append("6���� "); 
    else if (Pit_Fighter[index] >= 8) synerge.append("8���� "); 

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge.append("2������ "); 
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge.append("4������ "); 
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge.append("6������ "); 
    else if (Sorcerer[index] >= 8) synerge.append("8������ "); 

    if (Watcher[index] >= 2 && Watcher[index] < 4) synerge.append("2�ֽ��� "); 
    else if (Watcher[index] >= 4 && Watcher[index] < 6) synerge.append("4�ֽ��� "); 
    else if (Watcher[index] >= 6) synerge.append("6�ֽ��� "); 

    if (Sniper[index] >= 2 && Sniper[index] < 4) synerge.append("2���ݼ� "); 
    else if (Sniper[index] >= 4 && Sniper[index] < 6) synerge.append("4���ݼ� "); 
    else if (Sniper[index] >= 6) synerge.append("6���ݼ� ");  

    if (Artillerist[index] >= 2 && Artillerist[index] < 3) synerge.append("2���� "); 
    else if (Artillerist[index] >= 4 && Artillerist[index] < 6) synerge.append("4���� "); 
    else if (Artillerist[index] >= 6) synerge.append("6���� ");  

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2������ "); 
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4������ "); 
    else if (Bruiser[index] >= 6) synerge.append("6������ ");   

    if (Form_Swapper[index] >= 2 && Form_Swapper[index] < 4) synerge.append("2������ȯ�� "); 
    else if (Form_Swapper[index] >= 4) synerge.append("4������ȯ�� ");   

    if (Dominator[index] >= 2 && Dominator[index] < 4) synerge.append("2������ "); 
    else if (Dominator[index] >= 4 && Dominator[index] < 6) synerge.append("4������ ");
    else if (Dominator[index] >= 6) synerge.append("6������ "); 

    if (Quickstriker[index] >= 2 && Quickstriker[index] < 3) synerge.append("2�⵿Ÿ�ݴ� "); 
    else if (Quickstriker[index] >= 3 && Quickstriker[index] < 4) synerge.append("3�⵿Ÿ�ݴ� "); 
    else if (Quickstriker[index] >= 4) synerge.append("4�⵿Ÿ�ݴ� "); 

    if (Ambusher[index] >= 2 && Ambusher[index] < 3) synerge.append("2�ź��� "); 
    else if (Ambusher[index] >= 3 && Ambusher[index] < 4) synerge.append("3�ź��� "); 
    else if (Ambusher[index] >= 4 && Ambusher[index] < 5) synerge.append("4�ź��� "); 
    else if (Ambusher[index] >= 5) synerge.append("5�ź��� ");  

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

    if (ANY[index] >= 1 && ANY[index] < 2)  synerge.append("/1");   
    else if (ANY[index] >= 2 && ANY[index] < 3) synerge.append("/2"); 
    else if (ANY[index] >= 3 && ANY[index] < 4) synerge.append("/3"); 
    else if (ANY[index] >= 4 && ANY[index] < 5) synerge.append("/4"); 
    else if (ANY[index] >= 5 && ANY[index] < 6) synerge.append("/5"); 
    else if (ANY[index] >= 6 && ANY[index] < 7) synerge.append("/6"); 
    else if (ANY[index] >= 7 && ANY[index] < 8) synerge.append("/7"); 
    else if (ANY[index] >= 8 && ANY[index] < 9) synerge.append("/8"); 
    else if (ANY[index] >= 9 && ANY[index] < 10) synerge.append("/9"); 
    else if (ANY[index] >= 10) synerge.append("/10"); 

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
