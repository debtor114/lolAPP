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
vector < tuple <string, string, string, string, string, int> > champions;
vector < tuple <string, string, string, string, string, int> > selected_champions;

// ������ 4��, 6������, 7���̻� ȹ���� �� �ִ� è�Ǿ� ���յ�
vector < tuple <string, string, string, string, string, int> > level4_down_champions;
vector < tuple <string, string, string, string, string, int> > level6_down_champions;
vector < tuple <string, string, string, string, string, int> > level7_up_champions;

// ����� �� ��� ���� ������ è�Ǿ� ���յ�
vector < tuple <string, string, string, string, string, int> > user_select_champ;


int selected_size; // ������ è�Ǿ��� �� �� �����ߴ���

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



// ����� �Ϸ�� �� �ó����� �ʱ�ȭ ���ִ� �Լ�
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
    champions.push_back(make_tuple("����", "Disco", "", "Dazzler", "", 1)); 
    champions.push_back(make_tuple("������", "KDA", "", "Sentinel", "Superfan", 1)); 
    champions.push_back(make_tuple("����", "Punk", "", "Mosher", "", 1)); 
    champions.push_back(make_tuple("�ִ�", "EMO", "", "Spellweaver", "", 1)); 
    champions.push_back(make_tuple("�߽���", "True_Damage", "", "Edgelord", "", 1)); 
    champions.push_back(make_tuple("�ö���", "Pentakill", "", "Bruiser", "", 1)); 
    champions.push_back(make_tuple("�̺�", "KDA", "", "CrowdDiver", "", 1)); 
    champions.push_back(make_tuple("¡ũ��", "Punk", "", "Rapidfire", "", 1));
    champions.push_back(make_tuple("�ɳ�", "True_Damage", "", "Sentinel", "Superfan", 1));
    champions.push_back(make_tuple("�ڸ�Ű", "_8Bits", "", "BigShot", "", 1)); 
    champions.push_back(make_tuple("ũ����", "Heartsteel", "", "Sentinel", "", 1)); 
    champions.push_back(make_tuple("Ÿ��", "Disco", "", "Guardian", "", 1));
    champions.push_back(make_tuple("Ž��ġ", "Country", "", "Bruiser", "", 1)); 

    champions.push_back(make_tuple("����", "_8Bits", "", "Sentinel", "", 2)); 
    champions.push_back(make_tuple("�׶󰡽�", "Disco", "", "Bruiser", "Spellweaver", 2)); 
    champions.push_back(make_tuple("����", "Pentakill", "", "Superfan", "Mosher", 2)); 
    champions.push_back(make_tuple("�ٵ�", "Jazz", "", "Dazzler", "", 2));
    champions.push_back(make_tuple("����", "True_Damage", "", "Rapidfire", "", 2)); 
    champions.push_back(make_tuple("������", "KDA", "", "Spellweaver", "", 2)); 
    champions.push_back(make_tuple("���縮����", "Heartsteel", "", "Rapidfire", "", 2)); 
    champions.push_back(make_tuple("�轺", "EDM", "", "Mosher", "", 2)); 
    champions.push_back(make_tuple("ī�̻�", "KDA", "", "BigShot", "", 2));
    champions.push_back(make_tuple("īŸ����", "Country", "", "CrowdDiver", "", 2));
    champions.push_back(make_tuple("����", "Pentakill", "", "Edgelord", "", 2));
    champions.push_back(make_tuple("Ʈ��ġ", "Punk", "", "Executioner", "", 2)); 
    champions.push_back(make_tuple("���׿�", "Punk", "", "Guardian", "", 2)); 

    champions.push_back(make_tuple("����", "KDA", "", "Guardian", "Superfan", 3));
    champions.push_back(make_tuple("����", "EDM", "", "Dazzler", "", 3)); 
    champions.push_back(make_tuple("���", "Hyperpop", "", "Spellweaver", "", 3)); 
    champions.push_back(make_tuple("����", "_8Bits", "", "Edgelord", "", 3)); 
    champions.push_back(make_tuple("��ī����", "Country", "", "Sentinel", "", 3)); 
    champions.push_back(make_tuple("�̽�����", "Jazz", "", "BigShot", "", 3));
    champions.push_back(make_tuple("����", "EMO", "", "Executioner", "", 3)); 
    champions.push_back(make_tuple("��̶�", "Country", "", "Executioner", "", 3)); 
    champions.push_back(make_tuple("��Ʈ", "Heartsteel", "", "Bruiser", "Mosher", 3)); 
    champions.push_back(make_tuple("�ƹ���", "EMO", "", "Guardian", "", 3)); 
    champions.push_back(make_tuple("����", "True_Damage", "", "Sentinel", "Spellweaver", 3)); 
    champions.push_back(make_tuple("���", "Heartsteel", "", "CrowdDiver", "Edgelord", 3));
    champions.push_back(make_tuple("�츣��", "Country", "", "Mosher", "", 3));

    champions.push_back(make_tuple("����ũ��ũ", "Disco", "", "Sentinel", "", 4)); 
    champions.push_back(make_tuple("�񿡰�", "Pentakill", "", "Edgelord", "", 4)); 
    champions.push_back(make_tuple("�ǻ�", "EMO", "", "Mosher", "", 4)); 
    champions.push_back(make_tuple("������", "Country", "", "Guardian", "", 4)); 
    champions.push_back(make_tuple("�Ƹ�", "KDA", "", "Spellweaver", "", 4));
    champions.push_back(make_tuple("��Į��T", "True_Damage", "", "Breakout", "Executioner", 4)); 
    champions.push_back(make_tuple("��Į��K", "KDA", "", "Breakout", "Executioner", 4)); 
    champions.push_back(make_tuple("�����", "Heartsteel", "", "BigShot", "", 4)); 
    champions.push_back(make_tuple("��ũ", "EDM", "", "Bruiser", "", 4)); 
    champions.push_back(make_tuple("����", "EDM", "", "CrowdDiver", "", 4)); 
    champions.push_back(make_tuple("ī����", "Pentakill", "", "Executioner", "", 4)); 
    champions.push_back(make_tuple("����Ʋ��", "_8Bits", "", "Rapidfire", "", 4)); 
    champions.push_back(make_tuple("Ʈ��", "Disco", "", "Dazzler", "", 4)); 

    champions.push_back(make_tuple("��þ�", "Jazz", "", "Rapidfire", "", 5)); 
    champions.push_back(make_tuple("�ҳ�", "Mixmaster", "", "Spellweaver", "", 5)); 
    champions.push_back(make_tuple("�丯", "Pentakill", "", "Guardian", "Mosher", 5)); 
    champions.push_back(make_tuple("�϶����", "ILLBEATS", "", "Bruiser", "", 5)); 
    champions.push_back(make_tuple("����", "Hyperpop", "", "Dazzler", "", 5)); 
    champions.push_back(make_tuple("��", "Maestro", "", "BigShot", "", 5)); 
    champions.push_back(make_tuple("����", "Heartsteel", "Wildcard", "Edgelord", "", 5)); 
    champions.push_back(make_tuple("Ű�Ƴ�", "True_Damage", "", "CrowdDiver", "", 5)); 
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
    cout << "ex) 2�ͽ�������, ����" << endl;
    cout << " => \"2�ͽ�������\" �Է��� enter" << endl;
    cout << " => \"1����\" �Է��� enter" << endl;
    cout << " => \"END\"�Է��� enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "�ͽ�������") mixmaster += num;
        else if (traits == "8��Ʈ") _8bits += num;
        else if (traits == "����") disco += num;
        else if (traits == "Heartsteel") heartsteel += num;
        else if (traits == "TrueDamage") true_Damage += num;
        else if (traits == "EDM") eDM += num;
        else if (traits == "�̸��ھ�") eMO += num;
        else if (traits == "��Ʈ��") country += num;
        else if (traits == "����") jazz += num;
        else if (traits == "��Ÿų") pentakill += num;
        else if (traits == "�Ϸ���Ʈ") iLLBEATS += num;
        else if (traits == "��ũ") punk += num;
        else if (traits == "��������") hyperpop += num;
        else if (traits == "KDA") kDA += num;
        else if (traits == "������Ʈ��") maestro += num;
        else if (traits == "���ϵ�ī��") wildcard += num;
  
        // classes
        else if (traits == "������") sentinel += num;
        else if (traits == "������") bruiser += num;
        else if (traits == "�ӻ���") rapidfire += num;
        else if (traits == "�Ź�") bigShot += num;
        else if (traits == "���") mosher += num;
        else if (traits == "ó����") executioner += num;
        else if (traits == "�����������̹�") crowdDiver += num;
        else if (traits == "��Ȥ����") dazzler += num;  
        else if (traits == "��ȣ��") guardian += num;
        else if (traits == "�̴ܾ�") edgelord += num;
        else if (traits == "�ֹ�����") spellweaver += num;
        else if (traits == "������") superfan += num;
        else if (traits == "����Ʈ") breakout += num;
    }
    

}

// ������ �Ϸ�� ������ �ó��� ������ ����ϴ� �Լ�
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

// ������ �Ϸ�� ������ �ó����� ����ϴ� �Լ�
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


    // classes2, Ư���� 2�� �ִ� è�Ǿ�� ó��
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

// ������ �Ϸ�� ������ �ó����� ������ִ� �Լ�
string synerge_print(int index) {
    string synerge = "";

    if (_8Bits[index] >= 2 && _8Bits[index] < 4) synerge.append("2 8��Ʈ ");
    else if (_8Bits[index] >= 4 && _8Bits[index] < 6) synerge.append("4 8��Ʈ ");
    else if (_8Bits[index] >= 6) synerge.append("6 8��Ʈ ");

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
    
    if (Disco[index] >= 3 && Disco[index] < 4) synerge.append("3���� ");
    else if (Disco[index] >= 4 && Disco[index] < 5) synerge.append("4���� ");
    else if (Disco[index] >= 5 && Disco[index] < 6) synerge.append("5���� ");
    else if (Disco[index] >= 6) synerge.append("6���� ");

    if (Maestro[index] == 1) synerge.append("1������Ʈ�� ");
    if (Mixmaster[index] == 1) synerge.append("1�ͽ������� ");
    if (Wildcard[index] == 1) synerge.append("1���ϵ�ī�� ");
  
    if (EMO[index] >= 2 && EMO[index] < 4) synerge.append("2�̸��ھ� ");
    else if (EMO[index] >= 4 && EMO[index] < 6) synerge.append("4�̸��ھ� ");
    else if (EMO[index] >= 6) synerge.append("6�̸��ھ� ");  

    if (ILLBEATS[index] == 1) synerge.append("1�Ϸ���Ʈ ");
    
    if (Jazz[index] >= 2 && Jazz[index] < 3) synerge.append("2���� ");
    else if (Jazz[index] >= 3 && Jazz[index] < 4) synerge.append("3���� ");
    else if (Jazz[index] >= 4) synerge.append("4���� ");

    if (Country[index] >= 3 && Country[index] < 5) synerge.append("3��Ʈ�� ");
    else if (Country[index] >= 5 && Country[index] < 7) synerge.append("5��Ʈ�� ");
    else if (Country[index] >= 7) synerge.append("7��Ʈ�� ");

    if (Punk[index] >= 2 && Punk[index] < 4) synerge.append("2��ũ ");
    else if (Punk[index] >= 4 && Punk[index] < 6) synerge.append("4��ũ ");
    else if (Punk[index] >= 6) synerge.append("6��ũ ");

    if (Pentakill[index] >= 3 && Pentakill[index] < 5) synerge.append("3��Ÿų ");
    else if (Pentakill[index] >= 5 && Pentakill[index] < 7) synerge.append("5��Ÿų "); 
    else if (Pentakill[index] >= 7 && Pentakill[index] < 10) synerge.append("7��Ÿų ");
    else if (Pentakill[index] >= 10) synerge.append("10��Ÿų ");

    if (Hyperpop[index] >= 1 && Hyperpop[index] < 2) synerge.append("1�������� ");
    else if (Hyperpop[index] >= 2 && Hyperpop[index] < 3) synerge.append("2�������� ");
    else if (Hyperpop[index] >= 3 && Hyperpop[index] < 4) synerge.append("3�������� ");
    else if (Hyperpop[index] >= 4) synerge.append("4�������� ");


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
    if (Sentinel[index] >= 2 && Sentinel[index] < 4) synerge.append("2������ ");
    else if (Sentinel[index] >= 4 && Sentinel[index] < 6) synerge.append("4������ ");
    else if (Sentinel[index] >= 6 && Sentinel[index] < 8) synerge.append("6������ ");
    else if (Sentinel[index] >= 8) synerge.append("8������ ");

    if (BigShot[index] >= 2 && BigShot[index] < 4) synerge.append("2�Ź� ");
    else if (BigShot[index] >= 4 && BigShot[index] < 6) synerge.append("4�Ź� ");
    else if (BigShot[index] >= 6) synerge.append("6�Ź� ");

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2�ο�� ");
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4�ο�� ");
    else if (Bruiser[index] >= 6) synerge.append("6�ο�� ");

    if (Breakout[index] == 1) synerge.append("1����Ʈ ");

    if (Rapidfire[index] >= 2 && Rapidfire[index] < 4) synerge.append("2�ӻ��� ");
    else if (Rapidfire[index] >= 4 && Rapidfire[index] < 6) synerge.append("4�ӻ��� ");
    else if (Rapidfire[index] >= 6) synerge.append("6�ӻ��� ");

    if (Guardian[index] >= 2 && Guardian[index] < 4) synerge.append("2��ȣ�� ");
    else if (Guardian[index] >= 4 && Guardian[index] < 6) synerge.append("4��ȣ�� ");
    else if (Guardian[index] >= 6) synerge.append("6��ȣ�� ");

    if (CrowdDiver[index] >= 2 && CrowdDiver[index] < 4) synerge.append("2�����������̹� ");
    else if (CrowdDiver[index] >= 4 && CrowdDiver[index] < 6) synerge.append("4�����������̹� ");
    else if (CrowdDiver[index] >= 6) synerge.append("6�����������̹� ");

    if (Superfan[index] >= 3 && Superfan[index] < 4) synerge.append("3������ ");
    else if (Superfan[index] >= 4 && Superfan[index] < 5) synerge.append("4������ ");
    else if (Superfan[index] >= 5) synerge.append("5������ ");

    if (Edgelord[index] >= 3 && Edgelord[index] < 5) synerge.append("3�̴ܾ� ");
    else if (Edgelord[index] >= 5 && Edgelord[index] < 7) synerge.append("5�̴ܾ� ");
    else if (Edgelord[index] >= 7) synerge.append("7�̴ܾ� ");

    if (Spellweaver[index] >= 3 && Spellweaver[index] < 5) synerge.append("3�ֹ����� ");
    else if (Spellweaver[index] >= 5 && Spellweaver[index] < 7) synerge.append("5�ֹ����� ");
    else if (Spellweaver[index] >= 7 && Spellweaver[index] < 10) synerge.append("7�ֹ����� ");
    else if (Spellweaver[index] >= 10)  synerge.append("10�ֹ����� "); 

    if (Executioner[index] >= 2 && Executioner[index] < 3)  synerge.append("2ó���� ");
    else if (Executioner[index] >= 4 && Executioner[index] < 6)  synerge.append("4ó���� ");
    else if (Executioner[index] >= 6)  synerge.append("6ó���� ");

    if (Mosher[index] >= 2 && Mosher[index] < 4) synerge.append("2��� ");
    else if (Mosher[index] >= 4 && Mosher[index] < 6) synerge.append("4��� ");
    else if (Mosher[index] >= 6) synerge.append("6��� ");

    if (Dazzler[index] >= 2 && Dazzler[index] < 4) synerge.append("2��Ȥ���� ");
    else if (Dazzler[index] >= 4 && Dazzler[index] < 6) synerge.append("4��Ȥ���� ");
    else if (Dazzler[index] >= 6) synerge.append("6��Ȥ���� ");


    return synerge;
}


vector <int> pick[59];

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
