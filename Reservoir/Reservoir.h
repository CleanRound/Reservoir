#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class Reservoir
{
private:

	int id;
	int code;
	char* Reservoir_Name = nullptr;
	double width;
	double length;
	double depth;
	char* Dop_Info = nullptr;
	char* Tip = nullptr;
	long double area;
	long double volume;

public:

	Reservoir();
	Reservoir(int _id, int _code, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info);

	Reservoir(const Reservoir& obj);

	void DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	long double SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	void AutoSearchArea(Reservoir* vodoem, const int countreservoir);

	void SearchAreaTip(Reservoir* vodoem, char const* charsearch, int const countreservoir);

	long double SearchVolume(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	bool CheckTip(Reservoir* vodoem, int const countreservoir, int _code1, int _code2, int* _idarray1, int* _idarray2);

	void Show_Tip();

	void Show_Reservoir();

	void Show_One_Reservoir();

	~Reservoir();


	int Getid();
	int Getcode();
	char* GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char* GetDop_Info();
	char* GetTip();
	long double Getarea();
	long double Getvolume();

	void Setid(int _id);
	void Setcode(int _code);
	void SetReservoir_Name(char* _Reservoir_Name);
	void Setwidth(double _width);
	void Setlength(double _length);
	void Setdepth(double _depth);
	void SetDop_Info(char* _Dop_Info);
	void SetTip(char* _Tip);
	void Setarea(long double _area);
	void Setvolume(long double _volume);

};

class Country
{
private:

	int cid;
	char* Country_Name = nullptr;
	Reservoir* Name = nullptr;

public:

	Country();
	Country(int _cid, const char* _name);

	Country(const Country& obj);

	void Show_Country();

	~Country();
};


void gotoxy(int, int);

void ChangeCursorStatus(bool);
void MenuFun1();
void MenuFun2();
void MenuFun3();
void MenuFun4();
void MenuFun5();
void MenuFun6();

void ExitOption();