/*
 * analisador_sintatico.h
 *
 *  Created on: 19 de abr de 2018
 *      Author: Joao
 */

#ifndef ANALISADOR_LEXICO_H_
#define ANALISADOR_LEXICO_H_
#define ERRO -1

#include<string>

class AnalisadorLexico{
private:
	static bool isLetra(char c){
		if((int(c) > 64  && int(c) < 91) || (int(c) > 96  && int(c) < 123))
			return true;
		return false;
	}

	static bool isNumero(char c){
		if(int(c) > 47  && int(c) < 58)
			return true;
		return false;
	}

	static bool isOperador(char c){
		if(c == '+' || c == '-' || c == '*' || c == ':')
			return true;
		return false;
	}

public:
	AnalisadorLexico(){}

	static bool is_estado_final(int estado){
		if(estado == 0 || estado == 15 || estado == 16 || estado == 17 || estado == 25)
			return true;
		return false;
	}

	static bool hasKeywords(std::string linha){
		if(linha.find("int ") == linha.npos &&
				linha.find("float ") == linha.npos &&
				linha.find("double ") == linha.npos &&
				linha.find("char ") == linha.npos &&
				linha.find("for ") == linha.npos &&
				linha.find("if ") == linha.npos &&
				linha.find("while ") == linha.npos)
					return false;
		return true;
	}

	static int analisar_linha(std::string linha){
			int estado = 0 /* iniciando o estado do automato com 0 */;
			unsigned int indexador = 0;
			while(indexador < linha.size()){
				if(linha.at(indexador) == '\r'){
					break;
				}
				switch(estado){
				case ERRO:
					indexador++;
					break;
				case 0:
					if(linha.at(indexador) == '/'){
						estado = 1;
					}else if(linha.at(indexador) == ' '){
						estado = 0;
					}else if(isLetra(linha.at(indexador))){
						estado = 4;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 1:
					if(linha.at(indexador) == '*'){
						estado = 2;
					}else if(linha.at(indexador) == '/'){
						estado = 25;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 2:
					if(linha.at(indexador) == '*'){
						estado = 3;
					}
					indexador++;
					break;
				case 3:
					if(linha.at(indexador) == '*'){
						estado = 3;
					}else if(linha.at(indexador) == '/'){
						estado = 0;
					}else{
						estado = 2;
					}
					indexador++;
					break;
				case 4:
					if(isLetra(linha.at(indexador)) || isNumero(linha.at(indexador))){
						estado = 4;
					}else if(linha.at(indexador) == '/'){
						estado = 5;
					}else if(linha.at(indexador) == ' '){
						estado = 9;
					}else if(linha.at(indexador) == '='){
						estado = 10;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 5:
					if(linha.at(indexador) == '*'){
						estado = 6;
					}else if(linha.at(indexador) == '/'){
						estado = 25;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 6:
					if(linha.at(indexador) == '*'){
						estado = 7;
					}else{
						estado = 6;
					}
					indexador++;
					break;
				case 7:
					if(linha.at(indexador) == '*'){
						estado = 7;
					}else if(linha.at(indexador) == '/'){
						estado = 8;
					}else{
						estado = 6;
					}
					indexador++;
					break;
				case 8:
					if(linha.at(indexador) == '/'){
						estado = 5;
					}else if(linha.at(indexador) == ' '){
						estado = 9;
					}else if(linha.at(indexador) == '='){
						estado = 10;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 9:
					if(linha.at(indexador) == ' '){
						estado = 9;
					}else if(linha.at(indexador) == '/'){
						estado = 5;
					}else if(linha.at(indexador) == '='){
						estado = 10;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 10:
					if(linha.at(indexador) == ' '){
						estado = 10;
					}else if(isLetra(linha.at(indexador))){
						estado = 15;
					}else if(isNumero(linha.at(indexador))){
						estado = 17;
					}else if(linha.at(indexador) == '/'){
						estado = 11;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 11:
					if(linha.at(indexador) == '*'){
						estado = 12;
					}else if(linha.at(indexador) == '/'){
						estado = 25;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 12:
					if(linha.at(indexador) == '*'){
						estado = 13;
					}else{
						estado = 12;
					}
					indexador++;
					break;
				case 13:
					if(linha.at(indexador) == '*'){
						estado = 13;
					}else if(linha.at(indexador) == '/'){
						estado = 14;
					}else{
						estado = 12;
					}
					indexador++;
					break;
				case 14:
					if(linha.at(indexador) == '/'){
						estado = 11;
					}else if(isLetra(linha.at(indexador))){
						estado = 15;
					}else if(linha.at(indexador) == ' '){
						estado = 10;
					}else if(isNumero(linha.at(indexador))){
						estado = 17;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 15:
					if(isLetra(linha.at(indexador)) || isNumero(linha.at(indexador))){
						estado = 15;
					}else if(linha.at(indexador) == ' '){
						estado = 16;
					}else if(linha.at(indexador) == '/'){
						estado = 24;
					}else if(isOperador(linha.at(indexador))){
						estado = 18;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 16:
					if(isOperador(linha.at(indexador))){
						estado = 18;
					}else if(linha.at(indexador) == ' '){
						estado = 16;
					}else if(linha.at(indexador) == '/'){
						estado = 24;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 17:
					if(isNumero(linha.at(indexador)) || isLetra(linha.at(indexador))){
						estado = 17;
					}else if(isOperador(linha.at(indexador))){
						estado = 18;
					}else if(linha.at(indexador) == ' '){
						estado = 16;
					}else if(linha.at(indexador) == '/'){
						estado = 24;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 18:
					if(linha.at(indexador) == '/'){
						estado = 21;
					}else if(linha.at(indexador) == ' '){
						estado = 10;
					}else if(isLetra(linha.at(indexador))){
						estado = 15;
					}else if(isNumero(linha.at(indexador))){
						estado = 17;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 19:
					if(linha.at(indexador) == '*'){
						estado = 20;
					}else{
						estado = 19;
					}
					indexador++;
					break;
				case 20:
					if(linha.at(indexador) == '*'){
						estado = 20;
					}else if(linha.at(indexador) == '/'){
						estado = 16;
					}else{
						estado = 19;
					}
					indexador++;
					break;
				case 21:
					if(linha.at(indexador) == '*'){
						estado = 22;
					}else if(linha.at(indexador) == '/'){
						estado = 25;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 22:
					if(linha.at(indexador) == '*'){
						estado = 23;
					}else{
						estado = 22;
					}
					indexador++;
					break;
				case 23:
					if(linha.at(indexador) == '*'){
						estado = 23;
					}else if(linha.at(indexador) == '/'){
						estado = 18;
					}else{
						estado = 22;
					}
					indexador++;
					break;
				case 24:
					if(linha.at(indexador) == '*'){
						estado = 19;
					}else if(linha.at(indexador) == '/'){
						estado = 25;
					}else{
						estado = ERRO;
					}
					indexador++;
					break;
				case 25:
					indexador++;
					break;
				};
			}
			return estado;
		}
};
#endif /* ANALISADOR_LEXICO_H_ */
