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


// ����� �Ϸ�� �� �ó����� �ʱ�ȭ ���ִ� �Լ�
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
    champions.push_back(make_tuple("�˸���Ÿ", "GoldenOx", "", "Bruiser", "", 1, "Fronter")); 
    champions.push_back(make_tuple("�����ڻ�", "StreetDemon", "", "Bruiser", "Slayer", 1, "Fronter")); 
    champions.push_back(make_tuple("�轺", "Exotech", "", "Bastion", "", 1, "Fronter")); 
    champions.push_back(make_tuple("�𸣰���", "DivineCorp", "", "Dynamo", "", 1, "Backer")); 
    champions.push_back(make_tuple("������", "AminaSquad", "", "Techie", "", 1, "Backer")); 
    champions.push_back(make_tuple("���̶�", "StreetDemon", "", "Techie", "", 1, "Backer")); 
    champions.push_back(make_tuple("�ڱ׸�", "Boombot", "", "Rapidfire", "", 1, "Backer"));
    champions.push_back(make_tuple("���Ϸ���", "AminaSquad", "", "Vanguard", "", 1, "Fronter"));
    champions.push_back(make_tuple("�ϴ޸�", "Nitro", "", "AMP", "", 1, "Fronter")); 
    champions.push_back(make_tuple("����", "Syndicate", "", "Slayer", "", 1, "Fronter")); 
    champions.push_back(make_tuple("Ų�巹��", "Nitro", "", "Marksman", "Rapidfire", 1, "Backer"));
    champions.push_back(make_tuple("�ǻ�", "Cyberboss", "", "Bastion", "", 1, "Fronter")); 
    champions.push_back(make_tuple("����", "Cyper", "", "Vanguard", "", 1, "Fronter")); 

    champions.push_back(make_tuple("���̰�", "Cyberboss", "", "Techie", "", 2, "Backer")); 
    champions.push_back(make_tuple("����", "AminaSquad", "", "Slayer", "", 2, "Backer")); 
    champions.push_back(make_tuple("Ʈ��", "Syndicate", "", "Rapidfire", "", 2, "Backer")); 
    champions.push_back(make_tuple("����", "StreetDemon", "", "Strategist", "", 2, "Fronter"));
    champions.push_back(make_tuple("�׷��̺���", "GoldenOx", "", "Executioner", "", 2, "Fronter")); 
    champions.push_back(make_tuple("�����", "Cyper", "", "Strategist", "", 2, "Backer")); 
    champions.push_back(make_tuple("��", "Exotech", "", "Dynamo", "Marksman", 2, "Backer")); 
    champions.push_back(make_tuple("�϶����", "AminaSquad", "", "Bastion", "", 2, "Fronter")); 
    champions.push_back(make_tuple("�ٸ��콺", "Syndicate", "", "Bruiser", "", 2, "Fronter"));
    champions.push_back(make_tuple("��ƽ�Ʈ", "DivineCorp", "", "Vanguard", "", 2, "Fronter"));
    champions.push_back(make_tuple("���ٳ�", "Nitro", "", "Techie", "Bastion", 2, "Fronter"));
    champions.push_back(make_tuple("��ī��", "Boombot", "", "Vanguard", "", 2, "Fronter")); 
    champions.push_back(make_tuple("���Ǹ�", "Exotech", "", "AMP", "", 2, "Fronter")); 

    champions.push_back(make_tuple("����", "Syndicate", "", "Vanguard", "", 3, "Fronter"));
    champions.push_back(make_tuple("�ڸ���", "GoldenOx", "", "Vanguard", "Slayer", 3, "Fronter")); 
    champions.push_back(make_tuple("������", "Nitro", "", "Dynamo", "", 3, "Backer")); 
    champions.push_back(make_tuple("����", "AminaSquad", "", "AMP", "Strategist", 3, "Backer")); 
    champions.push_back(make_tuple("�ٷ罺", "Exotech", "", "Executioner", "", 3, "Backer")); 
    champions.push_back(make_tuple("�ǵ齺ƽ", "Boombot", "", "Techie", "", 3, "Fronter"));
    champions.push_back(make_tuple("��ī����", "Exotech", "", "Techie", "Bruiser", 3, "Fronter")); 
    champions.push_back(make_tuple("������", "Cyper", "", "Bastion", "", 3, "Fronter")); 
    champions.push_back(make_tuple("����", "DivineCorp", "", "Slayer", "", 3, "Backer")); 
    champions.push_back(make_tuple("����", "StreetDemon", "", "Executioner", "", 3, "Fronter")); 
    champions.push_back(make_tuple("�׶󰡽�", "DivineCorp", "", "Bruiser", "", 3, "Fronter")); 
    champions.push_back(make_tuple("�巹�̺�", "Cyper", "", "Rapidfire", "", 3, "Backer"));
    champions.push_back(make_tuple("¡ũ��", "StreetDemon", "", "Marksman", "", 3, "Backer"));

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
    cout << "ex) 2���ߺ�, ������ũ" << endl;
    cout << " => \"2���ߺ�\" �Է��� enter" << endl;
    cout << " => \"1������ũ\" �Է��� enter" << endl;
    cout << " => \"END\"�Է��� enter" << endl;

    while(1) {
        string traitString, traits;
        int num;

        cin >> traitString;
        if (traitString == "END") break;


        num = stoi(traitString.substr(0,1));
        traits = traitString.substr(1);
        
        if (traits == "��Ʈ��ũ�ǽ�") godofNW += num;
        else if (traits == "����Ư����") aminaSquad += num;
        else if (traits == "���̹�����") cyberboss += num;
        else if (traits == "������ũ") exotech += num;
        else if (traits == "Ȳ��Ȳ��") goldenOx += num;
        else if (traits == "��Ʈ��") nitro += num;
        else if (traits == "���ߺ�") boombot += num;
        else if (traits == "��������") syndicate += num;
        else if (traits == "������") cyper += num;
        else if (traits == "�Ÿ��ǾǸ�") streetDemon += num;
        else if (traits == "�ż����") divineCorp += num;
        else if (traits == "��ȥ������") soulKiller += num;
        else if (traits == "����") overload += num;
        else if (traits == "���̷���") virus += num;
  
        // classes
        else if (traits == "���") bastion += num;
        else if (traits == "������") bruiser += num;
        else if (traits == "����") amp += num;
        else if (traits == "���̳���") dynamo += num;
        else if (traits == "�ӻ���") rapidfire += num;
        else if (traits == "ó����") executioner += num;
        else if (traits == "��ݼ�") marksman += num;  
        else if (traits == "������") vanguard += num;
        else if (traits == "�л���") slayer += num;
        else if (traits == "�����") techie += num;
        else if (traits == "å����") strategist += num;
    }
    

}

// ������ �Ϸ�� ������ �ó��� ������ ����ϴ� �Լ�
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

// ������ �Ϸ�� ������ �ó����� ����ϴ� �Լ�
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

    // classes2, Ư���� 2�� �ִ� è�Ǿ�� ó��
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

    // �� �� ó��
    if (BNF == "Fronter") Fronter[index]++;
    else if (BNF == "Backer") Backer[index]++;



}


int twostar_champion_cost(tuple <string, string, string, string, string, int, string> &selected_champion) {
    return 3*get<5>(selected_champion);
}

// ������ �Ϸ�� ������ �ó����� ������ִ� �Լ�
string synerge_print(int index) {
    string synerge = "";

    // origin
    if (AminaSquad[index] >= 3 && AminaSquad[index] < 5) synerge.append("3����Ư���� ");  
    else if (AminaSquad[index] >= 5 && AminaSquad[index] < 7) synerge.append("5����Ư���� ");  
    else if (AminaSquad[index] >= 7 && AminaSquad[index] < 9) synerge.append("7����Ư���� ");  
    else if (AminaSquad[index] >= 10) synerge.append("10����Ư���� ");
  
    if (Cyberboss[index] >= 2 && Cyberboss[index] < 3) synerge.append("2���̹����� ");
    else if (Cyberboss[index] >= 3 && Cyberboss[index] < 4) synerge.append("3���̹����� ");  
    else if (Cyberboss[index] >= 4) synerge.append("4���̹����� ");

    if (Exotech[index] >= 3 && Exotech[index] < 5) synerge.append("3������ũ "); 
    else if (Exotech[index] >= 5 && Exotech[index] < 7) synerge.append("5������ũ "); 
    else if (Exotech[index] >= 7 && Exotech[index] < 10) synerge.append("7������ũ ");  
    else if (Exotech[index] >= 10) synerge.append("10������ũ ");

    if (GoldenOx[index] >= 2 && GoldenOx[index] < 4) synerge.append("2Ȳ��Ȳ�� "); 
    else if (GoldenOx[index] >= 4 && GoldenOx[index] < 6) synerge.append("4Ȳ��Ȳ�� "); 
    else if (GoldenOx[index] >= 6) synerge.append("6Ȳ��Ȳ�� ");
    
    if (Nitro[index] >= 3 && Nitro[index] < 4) synerge.append("3��Ʈ�� ");
    else if (Nitro[index] >= 4) synerge.append("4��Ʈ�� "); 

    if (Boombot[index] >= 2 && Boombot[index] < 4) synerge.append("2���ߺ� ");
    else if (Boombot[index] >= 4 && Boombot[index] < 4) synerge.append("4���ߺ� ");
    else if (Boombot[index] >= 6) synerge.append("6���ߺ� ");  

    if (Syndicate[index] >= 3 && Syndicate[index] < 5) synerge.append("3�������� "); 
    else if (Syndicate[index] >= 5 && Syndicate[index] < 7) synerge.append("5�������� "); 
    else if (Syndicate[index] >= 7) synerge.append("7�������� ");

    if (Cyper[index] >= 2 && Cyper[index] < 3) synerge.append("2������ ");
    else if (Cyper[index] >= 3 && Cyper[index] < 4) synerge.append("3������ ");
    else if (Cyper[index] >= 4) synerge.append("4������ ");  

    if (StreetDemon[index] >= 3 && StreetDemon[index] < 6) synerge.append("3�Ÿ��ǾǸ� ");
    else if (StreetDemon[index] >= 5 && StreetDemon[index] < 7) synerge.append("5�Ÿ��ǾǸ� "); 
    else if (StreetDemon[index] >= 7 && StreetDemon[index] < 10) synerge.append("7�Ÿ��ǾǸ� "); 
    else if (StreetDemon[index] >= 10) synerge.append("10�Ÿ��ǾǸ� ");

    if (DivineCorp[index] >= 1 && DivineCorp[index] < 2) synerge.append("1�ż���� ");
    else if (DivineCorp[index] >= 2 && DivineCorp[index] < 3) synerge.append("2�ż���� ");
    else if (DivineCorp[index] >= 3 && DivineCorp[index] < 4) synerge.append("3�ż���� ");
    else if (DivineCorp[index] >= 4 && DivineCorp[index] < 5) synerge.append("4�ż���� ");
    else if (DivineCorp[index] >= 5 && DivineCorp[index] < 6) synerge.append("5�ż���� ");
    else if (DivineCorp[index] >= 6) synerge.append("6�ż���� "); 

    if (Overload[index] == 1) synerge.append("1���� "); 
    if (Virus[index] == 1 ) synerge.append("1���̷��� ");
    if (SoulKiller[index] == 1) synerge.append("1��ȥ������ "); 
    if (GodofNW[index] == 1) synerge.append("1��Ʈ��ũ�ǽ� ");


    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge.append("2��� ");
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge.append("4��� ");
    else if (Bastion[index] >= 6) synerge.append("6��� ");

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2������ ");
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4������ ");
    else if (Bruiser[index] >= 6) synerge.append("6������ ");

    if (AMP[index] >= 2 && AMP[index] < 3) synerge.append("2���� ");
    else if (AMP[index] >= 3 && AMP[index] < 4) synerge.append("3���� ");
    else if (AMP[index] >= 4 && AMP[index] < 5) synerge.append("4���� ");
    else if (AMP[index] >= 5) synerge.append("5���� ");

    if (Dynamo[index] >= 2 && Dynamo[index] < 3) synerge.append("2���̳��� ");
    else if (Dynamo[index] >= 3 && Dynamo[index] < 4) synerge.append("3���̳��� ");
    else if (Dynamo[index] >= 4) synerge.append("4���̳��� ");

    if (Rapidfire[index] >= 2 && Rapidfire[index] < 4) synerge.append("2�ӻ��� ");
    else if (Rapidfire[index] >= 4 && Rapidfire[index] < 6) synerge.append("4�ӻ��� ");
    else if (Rapidfire[index] >= 6) synerge.append("6�ӻ��� "); 

    if (Executioner[index] >= 2 && Executioner[index] < 3) synerge.append("2ó���� ");
    else if (Executioner[index] >= 3 && Executioner[index] < 4) synerge.append("3ó���� ");
    else if (Executioner[index] >= 4 && Executioner[index] < 5) synerge.append("4ó���� ");
    else if (Executioner[index] >= 5) synerge.append("5ó���� ");  

    if (Marksman[index] >= 2 && Marksman[index] < 4) synerge.append("2��ݼ� ");
    else if (Marksman[index] >= 4) synerge.append("4��ݼ� ");    

    if (Vanguard[index] >= 2 && Vanguard[index] < 4) synerge.append("2������ ");
    else if (Vanguard[index] >= 4 && Vanguard[index] < 6) synerge.append("4������ ");
    else if (Vanguard[index] >= 6) synerge.append("6������ ");

    if (Slayer[index] >= 2 && Slayer[index] < 3) synerge.append("2�л��� ");
    else if (Slayer[index] >= 3 && Slayer[index] < 4) synerge.append("3�л��� ");
    else if (Slayer[index] >= 4 && Slayer[index] < 5) synerge.append("4�л��� ");
    else if (Slayer[index] >= 5 && Slayer[index] < 6) synerge.append("5�л��� ");
    else if (Slayer[index] >= 6) synerge.append("6�л��� ");

    if (Techie[index] >= 2 && Techie[index] < 4) synerge.append("2����� ");
    else if (Techie[index] >= 4 && Techie[index] < 6) synerge.append("4����� ");
    else if (Techie[index] >= 6 && Techie[index] < 8) synerge.append("6����� ");
    else if (Techie[index] >= 8) synerge.append("8����� ");   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge.append("2å���� ");
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge.append("3å���� ");
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge.append("4å���� ");
    else if (Strategist[index] >= 5) synerge.append("5å���� "); 

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
