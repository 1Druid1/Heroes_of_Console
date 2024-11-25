#ifndef STYLE_H
#define STYLE_H
#include <iostream>
using namespace std;

//Функция рисования линии в обозначении определенного символа
//shift-отступ(число символов в отступе), если не нужен то 0
//symbol-символ, которым будет нарисована линия
//length-длина линии(число символов)
 void drawline(int shift, char symbol, int length){
 	if(shift>0){
 	char* identation;
 	identation=new char[shift];
 	for(int i=0; i<shift; i++){
 		identation[i]=' ';
 		cout<<identation[i];
 	} delete []identation;
 	}
 	char* line;
 	line=new char[length];
 	for(int i=0; i<length; i++){
 		line[i]=symbol;
 		cout<<line[i];
 	} delete []line;
 }
 #endif
