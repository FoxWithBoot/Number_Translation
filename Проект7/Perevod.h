#pragma once
#ifndef Perevod_h
#define Perevod_h
#include <string>
using namespace std;

class Chislo {
private:
	int under;
	string chis;
public:
	Chislo() {}
	Chislo(int under, string chis) { //конструктор
		this->chis = chis;
		this->under = under;
	}
	string getChis() { //возвращает число
		return chis;
	}
	int getUnd() { //возвращает основание системы
		return under;
	}
private:
	Chislo SisToDec(Chislo a) { //переводит из другой системы в 10ную систему
		int n, c;
		n = a.chis.length();
		c = Kod(a.chis[0]);
		for (int i = 1; i < n; i++) {
			c = Kod(a.chis[i]) + c*a.under;
		}
		a.chis = to_string(c);
		a.under = 10;
		return a;
	}
	Chislo DecToSis(Chislo a, int und) { //переводит из 10ной системы в другую
		int n, c, t;
		string s;
		n = a.chis.length();
		c = Kod(a.chis[0]);
		for (int i = 1; i < n; i++) {
			c = Kod(a.chis[i]) + c*a.under;
		}

		for (int i = 0; c != 0; i++) {
			t = c%und;
			s.insert(0, 1, ReKod(t));
			c = c / und;
		}
		a.under = und;
		a.chis = s;
		return a;
	}
public:
	Chislo SisToSis(Chislo a, int und) { //переводит из одной системы в другую
		a = DecToSis(SisToDec(a), und);
		return a;
	}
	Chislo& operator = (const Chislo &a) { //перегрузка оператора =
		this->chis = a.chis;
		this->under = a.under;
		return *this;
	}
private:
	int Kod(char c) { //возвращает код по его символу с учетом 10ной системы
		if (((int)c < 58) && ((int)c > 47)) return ((int)c - 48);
		if (((int)c < 71) && ((int)c > 64)) return ((int)c - 55);
	}
	char ReKod(int n) { //возвращает символ по его коду с учетом 10ной системы
		if ((n < 10) && (n >-1)) return (char)(n + 48);
		if ((n < 16) && (n > 9)) return (char)(n + 55);
	}
};
#endif