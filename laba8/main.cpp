#include<windows.h>
#include<iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    //������������ ������ ���� � �����
    cout << "������� ���� � �����: ";
    char adr[80];
    cin >> adr;   //d:\\AFILE\\*

    //�������� ������ ������ � ��������� �����
    WIN32_FIND_DATAA FindFileData;
    HANDLE hf;
    hf=FindFirstFileA(adr, &FindFileData);  // ��������� ����

    string s[10]; //������ � ���������� ������ � �����
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



    return 0;
}
