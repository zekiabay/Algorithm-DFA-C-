// AlgoProj.cpp : Defines the entry point for the console application.
//We are searching for "zekize" string.
#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace	std;
enum STATE { S, q0, q1, q2, q3, q4, q5 };
enum STATE state = S;
enum STATE Start(char c) {
	if (c == 'z')
		state = q0;
	else
		state = S;
	return state;
}
enum STATE z(char c) {
	if (c == 'z') 
		state = q0;
	else if (c == 'e') 
		state = q1;
	else 
		state = S;
	return state;
}
enum STATE Ze(char c) {
	if (c == 'k')
		state = q2;
	else
		state = S;
	return state;
}
enum STATE Zek(char c) {
	if (c == 'i')
		state = q3;
	else
		state = S;
	return state;

}
enum STATE Zeki(char c) {
	if (c == 'z')
		state = q4;
	else
		state = S;
	return state;
}
enum STATE Zekiz(char c) {
	if (c == 'e')
		state = q5;
	else if (c == 'z')
		state = q0;
	else
		state = S;
	return state;
}

int main()
{
	int count = 0;
	ifstream myReadFile;
	myReadFile.open("C:/Users/Zeki/Desktop/example.txt");
	char c;
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> c;
			if (state == S) {
				state = Start(c);
			}
			else if (state == q0) {
				state = z(c);
			}
			else if (state == q1) {
				state = Ze(c);
			}
			else if (state == q2) {
				state = Zek(c);
			}
			else if (state == q3) {
				state = Zeki(c);
			}
			else if (state == q4) {
				state = Zekiz(c);
			}
			else if (state == q5) {
				cout << "String found."<<endl;
				myReadFile.close();		
				return 0;
			}		
		}
	}
	cout << "String not found."<<endl;
	return 0;
}