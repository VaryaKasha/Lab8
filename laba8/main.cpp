#include<windows.h>
#include<iostream>

#include<string>
#include<fstream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    //???????????? ?????? ???? ? ?????
    cout << "??????? ???? ? ?????: ";
    char adr[80];
    cin >> adr;   //d:\\AFILE\\* (??? ????)

    //???????? ?????? ?????? ? ????????? ?????
    WIN32_FIND_DATAA FindFileData;
    HANDLE hf;

   // hf=FindFirstFileA("c:\\test\\test2\\*", &FindFileData);
   // hf=FindFirstFileA("d:\\AFILE\\*", &FindFileData);

    hf=FindFirstFileA(adr, &FindFileData);  // ????????? ????

    string s[10]; //?????? ? ?????????? ?????? ? ?????
    int i=0;
    if (hf!=INVALID_HANDLE_VALUE){
        do{
            s[i] = FindFileData.cFileName;
            i++;
        }
        while (FindNextFileA(hf,&FindFileData)!=0);
        FindClose(hf);
    }
    cout << s[2] << endl << s[3] << endl;
    // 11:13 30.05.2016
    string str1 = adr;
    str1.erase(str1.length()-1, 1);
    string str2;
    for(int i = 0; i < 2; i++)
    {
        str2 = str1 + s[2+i]; // put k faylam + nazvaniye faylov s massiva
     // cout << str2 << endl;
        ifstream fin(str2, ios_base::in);
    //  fin.seekg(0, ios::beg);
        if(!fin.is_open())
        {
            cout << "\nFile don't open";
            return 0;
        }
        string str_for_audio; // stroka dlya zapisi
     // string str_for_audio2;
        getline(fin, str_for_audio);
     // getline(fin, str_for_audio2);
     // str_for_audio.insert(str_for_audio.length(), str_for_audio2, 0, str_for_audio2.length());

        fin.close();
        str_for_audio.erase(str_for_audio.find("TIT2")+22, str_for_audio.length());  // obrezayem po poslednemu tegu, inache zapihivaet ves fayl v stroku
    //  str_for_audio.push_back('$');
    //  cout << str_for_audio.length();
    //  cout << endl << "Pervaya stroka: "<< str_for_audio << endl;
        string album = str_for_audio.substr(21, 4);   // nahodim po simvolam i vivodim
        cout << "Albom: " << album << endl;
        string nazvaniye = str_for_audio.substr(67, 11);
        cout << "Nazvaniye: " << nazvaniye << endl;
        string ispolnitel = str_for_audio.substr(50, 7);
        cout << "Ispolnitel: " << ispolnitel << endl;
        string god = str_for_audio.substr(36, 4);
        cout << "God: " << god << endl;
    }
    //
    /*string str1;
    ifstream fin;
    fin.open(s[3]);
    fin >> str1;
    cout << str1;

    fin.close();*/


    return 0;
}
