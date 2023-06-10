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
vector < tuple <string, string, string, string, string, int> > user_select_champions;

// ����� �� ��� ���� ������ è�Ǿ� ���յ�
vector < tuple <string, string, string, string, string, int> > user_select_champ;


int selected_size; // ������ è�Ǿ��� �� �� �����ߴ���

// origin1
int Darkin[59];
int Demacia[59];
int Freljord[59];
int Ionia[59];
int Noxus[59];
int Piltover[59];
int Shadow_Isles[59];
int Shurima[59];
int Targon[59];
int Void[59];
int Wanderer[59];
int Yordle[59];
int Zaun[59];


// classes1
int Bastion[59];
int Bruiser[59];
int Challenger[59];
int Deadeye[59];
int Empress[59];
int Gunner[59];
int Invoker[59];
int Juggernaut[59];
int Multicaster[59];
int Redeemer[59];
int Rogue[59];
int Slayer[59];
int Sorcerer[59];
int Strategist[59];
int Technogenius[59];


// ����� �Ϸ�� �� �ó����� �ʱ�ȭ ���ִ� �Լ�
void init(int index) {
    Darkin[index] = 0;
    Demacia[index] = 0;
    Freljord[index] = 0;
    Ionia[index] = 0;
    Noxus[index] = 0;
    Piltover[index] = 0;
    Shadow_Isles[index] = 0;
    Shurima[index] = 0;
    Targon[index] = 0;
    Void[index] = 0;
    Wanderer[index] = 0;
    Yordle[index] = 0;
    Zaun[index] = 0;
    

    // classes
    Bastion[index] = 0;
    Bruiser[index] = 0;
    Deadeye[index] = 0;
    Challenger[index] = 0;
    Deadeye[index] = 0;
    Empress[index] = 0;
    Gunner[index] = 0;
    Invoker[index] = 0;
    Juggernaut[index] = 0;
    Multicaster[index] = 0;
    Redeemer[index] = 0;
    Rogue[index] = 0;
    Slayer[index] = 0;
    Sorcerer[index] = 0;
    Strategist[index] = 0;
    Technogenius[index] = 0;
}

void champions_info() {
    champions.push_back(make_tuple("ī�ÿ����", "Noxus", "Shurima", "Invoker", "", 1)); 
    champions.push_back(make_tuple("�ʰ���", "Void", "", "Bruiser", "", 1)); 
    champions.push_back(make_tuple("�̷�����", "Ionia", "", "Challenger", "", 1)); 
    champions.push_back(make_tuple("��", "Ionia", "", "Deadeye", "", 1)); 
    champions.push_back(make_tuple("����", "Demacia", "", "Slayer", "", 1)); 
    champions.push_back(make_tuple("������", "Void", "", "Sorcerer", "", 1)); 
    champions.push_back(make_tuple("����ī��", "Shadow_Isles", "", "Bastion", "", 1));
    champions.push_back(make_tuple("�ǻ�", "Demacia", "Yordle", "Bastion", "", 1));
    champions.push_back(make_tuple("�����Ƴ�", "Piltover", "", "Sorcerer", "", 1)); 
    champions.push_back(make_tuple("������", "Shurima", "", "Bruiser", "", 1)); 
    champions.push_back(make_tuple("����̸�", "Void", "Slayer", "", "", 1));
    champions.push_back(make_tuple("��̶�", "Noxus", "", "Challenger", "", 1));
    champions.push_back(make_tuple("Ʈ����Ÿ��", "Yordle", "", "Gunner", "", 1)); 
    champions.push_back(make_tuple("�񿡰�", "Shadow_Isles", "", "Rogue", "", 1)); 

    champions.push_back(make_tuple("�ֽ�", "Freljord", "", "Deadeye", "", 2)); 
    champions.push_back(make_tuple("������", "Demacia", "", "Invoker", "", 2)); 
    champions.push_back(make_tuple("¡ũ��", "Zaun", "", "Gunner", "", 2)); 
    champions.push_back(make_tuple("ī���", "Void", "", "Bastion", "", 2));
    champions.push_back(make_tuple("Ŭ����", "Noxus", "Yordle", "Slayer", "", 2)); 
    champions.push_back(make_tuple("�Ҷ�ī", "Targon", "", "Invoker", "", 2)); 
    champions.push_back(make_tuple("��Ʈ", "Ionia", "", "Juggernaut", "", 2)); 
    champions.push_back(make_tuple("������", "Noxus", "", "Sorcerer", "Strategist", 2)); 
    champions.push_back(make_tuple("Ż����", "Shurima", "", "Multicaster", "", 2));
    champions.push_back(make_tuple("Ƽ��", "Yordle", "", "Bruiser", "Strategist", 2));
    champions.push_back(make_tuple("����", "Piltover", "", "Bruiser", "", 2));
    champions.push_back(make_tuple("����", "Zaun", "", "Challenger", "Juggernaut", 2)); 
    champions.push_back(make_tuple("����", "Ionia", "", "Rogue", "Slayer", 2)); 

    champions.push_back(make_tuple("��ũ��", "Shurima", "", "Deadeye", "", 3));
    champions.push_back(make_tuple("�ٸ��콺", "Noxus", "", "Juggernaut", "", 3)); 
    champions.push_back(make_tuple("����", "Piltover", "Zaun", "Rogue", "", 3)); 
    champions.push_back(make_tuple("����", "Demacia", "", "Juggernaut", "", 3)); 
    champions.push_back(make_tuple("���̽�", "Piltover", "", "Gunner", "", 3)); 
    champions.push_back(make_tuple("Į����Ÿ", "Shadow_Isles", "", "Challenger", "", 3));
    champions.push_back(make_tuple("ī����", "Ionia", "", "Invoker", "", 3)); 
    champions.push_back(make_tuple("īŸ����", "Noxus", "", "Rogue", "", 3)); 
    champions.push_back(make_tuple("������", "Freljord", "", "Invoker", "", 3)); 
    champions.push_back(make_tuple("������", "Void", "", "Bruiser", "", 3)); 
    champions.push_back(make_tuple("�ҳ�", "Demacia", "", "Multicaster", "", 3)); 
    champions.push_back(make_tuple("Ÿ��", "Targon", "", "Bastion", "Sorcerer", 3));
    champions.push_back(make_tuple("������", "Void", "", "Multicaster", "Sorcerer", 3));

    champions.push_back(make_tuple("���縮����", "Targon", "", "Deadeye", "", 4)); 
    champions.push_back(make_tuple("������", "Shurima", "", "Strategist", "", 4)); 
    champions.push_back(make_tuple("����", "Shadow_Isles", "", "Slayer", "", 4)); 
    champions.push_back(make_tuple("�ڸ���", "Demacia", "", "Strategist", "", 4)); 
    champions.push_back(make_tuple("ī�̻�", "Void", "", "Challenger", "", 4));
    champions.push_back(make_tuple("����", "Demacia", "", "Sorcerer", "", 4)); 
    champions.push_back(make_tuple("������", "Shurima", "", "Juggernaut", "", 4)); 
    champions.push_back(make_tuple("���־ƴ�", "Freljord", "", "Bruiser", "", 4)); 
    champions.push_back(make_tuple("��", "Ionia", "", "Bastion", "Invoker", 4)); 
    champions.push_back(make_tuple("�츣��", "Zaun", "", "Deadeye", "", 4)); 
    champions.push_back(make_tuple("�߽���", "Ionia", "", "Challenger", "", 4)); 
    champions.push_back(make_tuple("����", "Zaun", "", "Gunner", "", 4)); 

    champions.push_back(make_tuple("��Ʈ�Ͻ�", "Darkin", "", "Juggernaut", "Slayer", 5)); 
    champions.push_back(make_tuple("�Ƹ�", "Ionia", "", "Sorcerer", "", 5)); 
    champions.push_back(make_tuple("���̸ӵ���", "Piltover", "Yordle", "Technogenius", "", 5)); 
    champions.push_back(make_tuple("ũ����", "Shurima", "", "Bastion", "", 5)); 
    champions.push_back(make_tuple("������", "Wanderer", "", "Invoker", "", 5)); 
    champions.push_back(make_tuple("����", "Shadow_Isles", "", "Gunner", "Redeemer", 5)); 
    champions.push_back(make_tuple("���̿�", "Noxus", "", "Bruiser", "", 5)); 
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

    // �־��� è�Ǿ� �ӿ����� ����� ã��ʹٸ�
    if (user_select_champ.size() > stoi(argv[1])) {
        for (int i = 0; i < user_select_champ.size(); i++) {  
            user_select_champions.push_back(user_select_champ[i]);
        }
    }

    else {
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
}

// ������ �Ϸ�� ������ �ó��� ������ ����ϴ� �Լ�
int synerge_check(int index) {
    int synerge_count = 0;
    // 1 : 5
    // 2-3-4: 5 10 18
    // 2-4-6: 5 12 25
    // 2-4-6-8: 5 10 15 33
    // 3-5: 8 15
    // 3-5-7: 8 15 30
    // 3-5-7-9: 8 14 22 45
    // 3-6: 8 18
    // 3-6-8: 8 16 40
    // 3-6-9: 8 16 45


    // origin
    if (Demacia[index] >= 3 && Demacia[index] < 5) synerge_count += 8;
    else if (Demacia[index] >= 5 && Demacia[index] < 7) synerge_count += 14;  
    else if (Demacia[index] >= 7 && Demacia[index] < 9) synerge_count += 22;  
    else if (Demacia[index] >= 9) synerge_count += 45;

    if (Darkin[index] == 1) synerge_count += 5;
  
    if (Freljord[index] >= 2 && Freljord[index] < 3) synerge_count += 5;
    else if (Freljord[index] >= 3 && Freljord[index] < 4) synerge_count += 10;  
    else if (Freljord[index] >= 4) synerge_count += 18;

    if (Ionia[index] >= 3 && Ionia[index] < 6) synerge_count += 8; 
    else if (Ionia[index] >= 6 && Ionia[index] < 9) synerge_count += 16; 
    else if (Ionia[index] >= 9) synerge_count += 45;

    if (Noxus[index] >= 3 && Noxus[index] < 6) synerge_count += 8; 
    else if (Noxus[index] >= 6 && Noxus[index] < 9) synerge_count += 16; 
    else if (Noxus[index] >= 9) synerge_count += 45;
    
    if (Piltover[index] >= 3 && Piltover[index] < 6) synerge_count += 8;
    else if (Piltover[index] >= 6) synerge_count += 18; 

    if (Shadow_Isles[index] >= 2 && Shadow_Isles[index] < 4) synerge_count += 5;
    else if (Shadow_Isles[index] >= 4 && Shadow_Isles[index] < 4) synerge_count += 12;
    else if (Shadow_Isles[index] >= 6) synerge_count += 25;  

    if (Shurima[index] >= 3 && Shurima[index] < 5) synerge_count += 8; 
    else if (Shurima[index] >= 5 && Shurima[index] < 7) synerge_count += 14; 
    else if (Shurima[index] >= 7 && Shurima[index] < 9) synerge_count += 22; 
    else if (Shurima[index] >= 9) synerge_count += 45;

    if (Targon[index] >= 2 && Targon[index] < 3) synerge_count += 5;
    else if (Targon[index] >= 3 && Targon[index] < 4) synerge_count += 10;
    else if (Targon[index] >= 4) synerge_count += 10;  

    if (Void[index] >= 3 && Void[index] < 6) synerge_count += 8;
    else if (Void[index] >= 6 && Void[index] < 8) synerge_count += 16; 
    else if (Void[index] >= 8) synerge_count += 40;

    if (Wanderer[index] == 1) synerge_count += 5;

    if (Yordle[index] >= 3 && Yordle[index] < 5) synerge_count += 8;
    else if (Yordle[index] >= 5) synerge_count += 15;

    if (Zaun[index] >= 2 && Zaun[index] < 4) synerge_count += 5;
    else if (Zaun[index] >= 4 && Zaun[index] < 6) synerge_count += 12;
    else if (Zaun[index] >= 6) synerge_count += 25;



    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge_count += 5;
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge_count += 10;
    else if (Bastion[index] >= 6 && Bastion[index] < 8) synerge_count += 15;
    else if (Bastion[index] >= 8) synerge_count += 33;

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge_count += 5;
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge_count += 12;
    else if (Bruiser[index] >= 6) synerge_count += 25;

    if (Challenger[index] >= 2 && Challenger[index] < 4) synerge_count += 5;
    else if (Challenger[index] >= 4 && Challenger[index] < 6) synerge_count += 10;
    else if (Challenger[index] >= 6 && Challenger[index] < 8) synerge_count += 15;
    else if (Challenger[index] >= 8) synerge_count += 33;

    if (Deadeye[index] >= 2 && Deadeye[index] < 4) synerge_count += 5;
    else if (Deadeye[index] >= 4 && Deadeye[index] < 6) synerge_count += 12;
    else if (Deadeye[index] >= 6) synerge_count += 25;

    if (Empress[index] == 1 ) synerge_count += 5;

    if (Gunner[index] >= 2 && Gunner[index] < 4) synerge_count += 5;
    else if (Gunner[index] >= 4 && Gunner[index] < 6) synerge_count += 12;
    else if (Gunner[index] >= 6) synerge_count += 25; 

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge_count += 5;
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge_count += 12;
    else if (Invoker[index] >= 6) synerge_count += 25; 

    if (Juggernaut[index] >= 2 && Juggernaut[index] < 4) synerge_count += 5;
    else if (Juggernaut[index] >= 4 && Juggernaut[index] < 6) synerge_count += 12;
    else if (Juggernaut[index] >= 6) synerge_count += 25;  

    if (Multicaster[index] >= 2 && Multicaster[index] < 4) synerge_count += 5;
    else if (Multicaster[index] >= 4) synerge_count += 12;  

    if (Redeemer[index] == 1) synerge_count += 5;  

    if (Rogue[index] >= 2 && Rogue[index] < 4) synerge_count += 10;
    else if (Rogue[index] >= 4) synerge_count += 20;

    if (Slayer[index] >= 2 && Slayer[index] < 3) synerge_count += 5;
    else if (Slayer[index] >= 3 && Slayer[index] < 4) synerge_count += 10;
    else if (Slayer[index] >= 4 && Slayer[index] < 5) synerge_count += 15;
    else if (Slayer[index] >= 5 && Slayer[index] < 6) synerge_count += 25;
    else if (Slayer[index] >= 6) synerge_count += 30;

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge_count += 5;
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge_count += 10;
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge_count += 15;
    else if (Sorcerer[index] >= 8) synerge_count += 33;   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge_count += 5;
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge_count += 10;
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge_count += 15;
    else if (Strategist[index] >= 5) synerge_count += 27; 

    if (Technogenius[index] == 1) synerge_count += 5; 

    return synerge_count;
}

// ������ �Ϸ�� ������ �ó����� ����ϴ� �Լ�
void synerge_add(tuple <string, string, string, string, string, int> &champion, int index) {
    string origin1 = get<1>(champion);
    string origin2 = get<2>(champion);
    string classes1 = get<3>(champion);
    string classes2 = get<4>(champion);

    // origin1
    if (origin1 == "Darkin") Darkin[index]++;
    else if (origin1 == "Demacia") Demacia[index]++;
    else if (origin1 == "Freljord") Freljord[index]++;
    else if (origin1 == "Ionia") Ionia[index]++;
    else if (origin1 == "Noxus") Noxus[index]++;
    else if (origin1 == "Shadow_Isles") Shadow_Isles[index]++;
    else if (origin1 == "Shurima") Shurima[index]++;
    else if (origin1 == "Piltover") Piltover[index]++;
    else if (origin1 == "Targon") Targon[index]++;
    else if (origin1 == "Yordle") Yordle[index]++;
    else if (origin1 == "Wanderer") Wanderer[index]++;
    else if (origin1 == "Zaun") Zaun[index]++;
    else if (origin1 == "Void") Void[index]++;
    else if (origin1 == "Bastion") Bastion[index]++;
    else if (origin1 == "Bruiser") Bruiser[index]++;
    else if (origin1 == "Deadeye") Deadeye[index]++;
    else if (origin1 == "Multicaster") Multicaster[index]++;  
    else if (origin1 == "Slayer") Slayer[index]++;
    else if (origin1 == "Challenger") Challenger[index]++;
    else if (origin1 == "Invoker") Invoker[index]++;
    else if (origin1 == "Gunner") Gunner[index]++;
    else if (origin1 == "Juggernaut") Juggernaut[index]++;
    else if (origin1 == "Rogue") Rogue[index]++;
    else if (origin1 == "Redeemer") Redeemer[index]++;
    else if (origin1 == "Empress") Empress[index]++;
    else if (origin1 == "Sorcerer") Sorcerer[index]++;
    else if (origin1 == "Strategist") Strategist[index]++;

    // origin2
    if (origin2 == "Darkin") Darkin[index]++;
    else if (origin2 == "Demacia") Demacia[index]++;
    else if (origin2 == "Freljord") Freljord[index]++;
    else if (origin2 == "Ionia") Ionia[index]++;
    else if (origin2 == "Noxus") Noxus[index]++;
    else if (origin2 == "Shadow_Isles") Shadow_Isles[index]++;
    else if (origin2 == "Shurima") Shurima[index]++;
    else if (origin2 == "Piltover") Piltover[index]++;
    else if (origin2 == "Targon") Targon[index]++;
    else if (origin2 == "Yordle") Yordle[index]++;
    else if (origin2 == "Wanderer") Wanderer[index]++;
    else if (origin2 == "Zaun") Zaun[index]++;
    else if (origin2 == "Void") Void[index]++;
    else if (origin2 == "Bastion") Bastion[index]++;
    else if (origin2 == "Bruiser") Bruiser[index]++;
    else if (origin2 == "Deadeye") Deadeye[index]++;
    else if (origin2 == "Multicaster") Multicaster[index]++;  
    else if (origin2 == "Slayer") Slayer[index]++;
    else if (origin2 == "Challenger") Challenger[index]++;
    else if (origin2 == "Invoker") Invoker[index]++;
    else if (origin2 == "Gunner") Gunner[index]++;
    else if (origin2 == "Juggernaut") Juggernaut[index]++;
    else if (origin2 == "Rogue") Rogue[index]++;
    else if (origin2 == "Redeemer") Redeemer[index]++;
    else if (origin2 == "Empress") Empress[index]++;
    else if (origin2 == "Sorcerer") Sorcerer[index]++;
    else if (origin2 == "Strategist") Strategist[index]++;

    // classes1
    if (classes1 == "Bastion") Bastion[index]++;
    else if (classes1 == "Bruiser") Bruiser[index]++;
    else if (classes1 == "Deadeye") Deadeye[index]++;
    else if (classes1 == "Multicaster") Multicaster[index]++;  
    else if (classes1 == "Slayer") Slayer[index]++;
    else if (classes1 == "Challenger") Challenger[index]++;
    else if (classes1 == "Invoker") Invoker[index]++;
    else if (classes1 == "Gunner") Gunner[index]++;
    else if (classes1 == "Juggernaut") Juggernaut[index]++;
    else if (classes1 == "Rogue") Rogue[index]++;
    else if (classes1 == "Redeemer") Redeemer[index]++;
    else if (classes1 == "Empress") Empress[index]++;
    else if (classes1 == "Sorcerer") Sorcerer[index]++;
    else if (classes1 == "Strategist") Strategist[index]++;
    else if (classes1 == "Darkin") Darkin[index]++;
    else if (classes1 == "Demacia") Demacia[index]++;
    else if (classes1 == "Freljord") Freljord[index]++;
    else if (classes1 == "Ionia") Ionia[index]++;
    else if (classes1 == "Noxus") Noxus[index]++;
    else if (classes1 == "Shadow_Isles") Shadow_Isles[index]++;
    else if (classes1 == "Shurima") Shurima[index]++;
    else if (classes1 == "Piltover") Piltover[index]++;
    else if (classes1 == "Targon") Targon[index]++;
    else if (classes1 == "Yordle") Yordle[index]++;
    else if (classes1 == "Wanderer") Wanderer[index]++;
    else if (classes1 == "Zaun") Zaun[index]++;
    else if (classes1 == "Void") Void[index]++;
    else if (classes1 == "Technogenius") Technogenius[index]++;

    // classes2, Ư���� 2�� �ִ� è�Ǿ�� ó��
    if (classes2 == "Bastion") Bastion[index]++;
    else if (classes2 == "Bruiser") Bruiser[index]++;
    else if (classes2 == "Deadeye") Deadeye[index]++;
    else if (classes2 == "Multicaster") Multicaster[index]++;  
    else if (classes2 == "Slayer") Slayer[index]++;
    else if (classes2 == "Challenger") Challenger[index]++;
    else if (classes2 == "Invoker") Invoker[index]++;
    else if (classes2 == "Gunner") Gunner[index]++;
    else if (classes2 == "Juggernaut") Juggernaut[index]++;
    else if (classes2 == "Rogue") Rogue[index]++;
    else if (classes2 == "Redeemer") Redeemer[index]++;
    else if (classes2 == "Empress") Empress[index]++;
    else if (classes2 == "Sorcerer") Sorcerer[index]++;
    else if (classes2 == "Strategist") Strategist[index]++;
    else if (classes2 == "Darkin") Darkin[index]++;
    else if (classes2 == "Demacia") Demacia[index]++;
    else if (classes2 == "Freljord") Freljord[index]++;
    else if (classes2 == "Ionia") Ionia[index]++;
    else if (classes2 == "Noxus") Noxus[index]++;
    else if (classes2 == "Shadow_Isles") Shadow_Isles[index]++;
    else if (classes2 == "Shurima") Shurima[index]++;
    else if (classes2 == "Piltover") Piltover[index]++;
    else if (classes2 == "Targon") Targon[index]++;
    else if (classes2 == "Yordle") Yordle[index]++;
    else if (classes2 == "Wanderer") Wanderer[index]++;
    else if (classes2 == "Zaun") Zaun[index]++;
    else if (classes2 == "Void") Void[index]++;
    else if (classes2 == "Technogenius") Technogenius[index]++;

}


int synerge_cost(tuple <string, string, string, string, string, int> &selected_champion) {
    return get<5>(selected_champion);
}

// ������ �Ϸ�� ������ �ó����� ������ִ� �Լ�
string synerge_print(int index) {
    string synerge = "";

    // origin
    if (Demacia[index] >= 3 && Demacia[index] < 5) synerge.append("3�����þ� ");  
    else if (Demacia[index] >= 5 && Demacia[index] < 7) synerge.append("5�����þ� ");  
    else if (Demacia[index] >= 7 && Demacia[index] < 9) synerge.append("7�����þ� ");  
    else if (Demacia[index] >= 9) synerge.append("9�����þ� ");

    if (Darkin[index] == 1) synerge.append("1�ٸ�Ų ");
  
    if (Freljord[index] >= 2 && Freljord[index] < 3) synerge.append("2������� ");
    else if (Freljord[index] >= 3 && Freljord[index] < 4) synerge.append("3������� ");  
    else if (Freljord[index] >= 4) synerge.append("4������� ");

    if (Ionia[index] >= 3 && Ionia[index] < 6) synerge.append("3���̿��Ͼ� "); 
    else if (Ionia[index] >= 6 && Ionia[index] < 9) synerge.append("6���̿��Ͼ� "); 
    else if (Ionia[index] >= 9) synerge.append("9���̿��Ͼ� ");

    if (Noxus[index] >= 3 && Noxus[index] < 6) synerge.append("3�켭�� "); 
    else if (Noxus[index] >= 6 && Noxus[index] < 9) synerge.append("6�켭�� "); 
    else if (Noxus[index] >= 9) synerge.append("9�켭�� ");
    
    if (Piltover[index] >= 3 && Piltover[index] < 6) synerge.append("3��Ʈ���� ");
    else if (Piltover[index] >= 6) synerge.append("6��Ʈ���� "); 

    if (Shadow_Isles[index] >= 2 && Shadow_Isles[index] < 4) synerge.append("2�׸��ڱ��� ");
    else if (Shadow_Isles[index] >= 4 && Shadow_Isles[index] < 4) synerge.append("4�׸��ڱ��� ");
    else if (Shadow_Isles[index] >= 6) synerge.append("6�׸��ڱ��� ");  

    if (Shurima[index] >= 3 && Shurima[index] < 5) synerge.append("3������ "); 
    else if (Shurima[index] >= 5 && Shurima[index] < 7) synerge.append("5������ "); 
    else if (Shurima[index] >= 7 && Shurima[index] < 9) synerge.append("7������ "); 
    else if (Shurima[index] >= 9) synerge.append("9������ ");

    if (Targon[index] >= 2 && Targon[index] < 3) synerge.append("2Ÿ�� ");
    else if (Targon[index] >= 3 && Targon[index] < 4) synerge.append("3Ÿ�� ");
    else if (Targon[index] >= 4) synerge.append("4Ÿ�� ");  

    if (Void[index] >= 3 && Void[index] < 6) synerge.append("3���� ");
    else if (Void[index] >= 6 && Void[index] < 8) synerge.append("6���� "); 
    else if (Void[index] >= 8) synerge.append("8���� ");

    if (Wanderer[index] == 1) synerge.append("1����� ");

    if (Yordle[index] >= 3 && Yordle[index] < 5) synerge.append("3��� ");
    else if (Yordle[index] >= 5) synerge.append("5��� ");

    if (Zaun[index] >= 2 && Zaun[index] < 4) synerge.append("2�ڿ� ");
    else if (Zaun[index] >= 4 && Zaun[index] < 6) synerge.append("4�ڿ� ");
    else if (Zaun[index] >= 6) synerge.append("6�ڿ� ");



    // classes
    if (Bastion[index] >= 2 && Bastion[index] < 4) synerge.append("2��� ");
    else if (Bastion[index] >= 4 && Bastion[index] < 6) synerge.append("4��� ");
    else if (Bastion[index] >= 6 && Bastion[index] < 8) synerge.append("6��� ");
    else if (Bastion[index] >= 8) synerge.append("8��� ");

    if (Bruiser[index] >= 2 && Bruiser[index] < 4) synerge.append("2������ ");
    else if (Bruiser[index] >= 4 && Bruiser[index] < 6) synerge.append("4������ ");
    else if (Bruiser[index] >= 6) synerge.append("6������ ");

    if (Challenger[index] >= 2 && Challenger[index] < 4) synerge.append("2������ ");
    else if (Challenger[index] >= 4 && Challenger[index] < 6) synerge.append("4������ ");
    else if (Challenger[index] >= 6 && Challenger[index] < 8) synerge.append("6������ ");
    else if (Challenger[index] >= 8) synerge.append("8������ ");

    if (Deadeye[index] >= 2 && Deadeye[index] < 4) synerge.append("2��߹��� ");
    else if (Deadeye[index] >= 4 && Deadeye[index] < 6) synerge.append("4��߹��� ");
    else if (Deadeye[index] >= 6) synerge.append("6��߹��� ");

    if (Empress[index] == 1 ) synerge.append("1���� ");

    if (Gunner[index] >= 2 && Gunner[index] < 4) synerge.append("2��� ");
    else if (Gunner[index] >= 4 && Gunner[index] < 6) synerge.append("4��� ");
    else if (Gunner[index] >= 6) synerge.append("6��� "); 

    if (Invoker[index] >= 2 && Invoker[index] < 3) synerge.append("2����� ");
    else if (Invoker[index] >= 4 && Invoker[index] < 6) synerge.append("4����� ");
    else if (Invoker[index] >= 6) synerge.append("6����� "); 

    if (Juggernaut[index] >= 2 && Juggernaut[index] < 4) synerge.append("2������ ");
    else if (Juggernaut[index] >= 4 && Juggernaut[index] < 6) synerge.append("4������ ");
    else if (Juggernaut[index] >= 6) synerge.append("6������ ");  

    if (Multicaster[index] >= 2 && Multicaster[index] < 4) synerge.append("2���⸶���� ");
    else if (Multicaster[index] >= 4) synerge.append("4���⸶���� ");  

    if (Redeemer[index] == 1) synerge.append("1������ ");  

    if (Rogue[index] >= 2 && Rogue[index] < 4) synerge.append("2���Ѵ� ");
    else if (Rogue[index] >= 4) synerge.append("4���Ѵ� ");

    if (Slayer[index] >= 2 && Slayer[index] < 3) synerge.append("2�л��� ");
    else if (Slayer[index] >= 3 && Slayer[index] < 4) synerge.append("3�л��� ");
    else if (Slayer[index] >= 4 && Slayer[index] < 5) synerge.append("4�л��� ");
    else if (Slayer[index] >= 5 && Slayer[index] < 6) synerge.append("5�л��� ");
    else if (Slayer[index] >= 6) synerge.append("6�л��� ");

    if (Sorcerer[index] >= 2 && Sorcerer[index] < 4) synerge.append("2������ ");
    else if (Sorcerer[index] >= 4 && Sorcerer[index] < 6) synerge.append("4������ ");
    else if (Sorcerer[index] >= 6 && Sorcerer[index] < 8) synerge.append("6������ ");
    else if (Sorcerer[index] >= 8) synerge.append("8������ ");   

    if (Strategist[index] >= 2 && Strategist[index] < 3) synerge.append("2å���� ");
    else if (Strategist[index] >= 3 && Strategist[index] < 4) synerge.append("3å���� ");
    else if (Strategist[index] >= 4 && Strategist[index] < 5) synerge.append("4å���� ");
    else if (Strategist[index] >= 5) synerge.append("5å���� "); 

    if (Technogenius[index] == 1) synerge.append("1�߸��Ǵ밡 "); 

    return synerge;
}


vector <int> pick[59];

// pq�� minHeap�� ����ؼ� Ž��, ����, ���Ŀ� log(N)�� �ð����⵵�� ���´�, ���� ������ �ʿ� X
priority_queue < tuple <int, int, string, string > > overall_combination;
int level;

// mutex
recursive_mutex m;

void combination_custom (int index, int thread_index) {
    string selected_champ;
    int cost = 0;
    if(pick[thread_index].size() == level) { 
        for(int i = 0; i < pick[thread_index].size(); i++) {
            synerge_add(user_select_champions[pick[thread_index][i]], thread_index); 
            cost += synerge_cost(user_select_champions[pick[thread_index][i]]);
            selected_champ.append(get<0>(user_select_champions[pick[thread_index][i]])); 
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

    for(int i = index; i < user_select_champions.size(); i++) {
        pick[thread_index].push_back(i);
        combination_custom(i+1, thread_index);
        pick[thread_index].pop_back();
        if (pick[thread_index].size() == 0) return;
        
    }
}

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

    if (selected_size > level) {
        for (int i = 0; i <= user_select_champions.size()-level; i++) {
            threads.push_back(thread(combination_custom, i, i));
        }

        for (int i = 0; i < threads.size(); i++) {
            if (threads[i].joinable()) threads[i].join();
        }
    }

    else {

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
