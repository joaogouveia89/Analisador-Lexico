/*
 * analisador_sintatico.h
 *
 *  Created on: 19 de abr de 2018
 *      Author: Joao
 */

#ifndef ANALISADOR_LEXICO_H_
#define ANALISADOR_LEXICO_H_

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
		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '>' || c == '<' || c == '(' || c == ')' || c == '{' || c == '}')
			return true;
		return false;
	}

public:
	AnalisadorLexico(){}

	static bool is_estado_final(int estado){
		if(estado == 0 || estado == 4 || estado == 7 || estado == 11)
			return true;
		return false;
	}

	static int analisar_linha(std::string linha){
			int estado = 0 /* iniciando o estado do automato com 0 */;
			unsigned int indexador = 0;
			while(indexador < linha.size()){
				if(linha.at(indexador) == '\r'){
					break;
				}
				switch(estado){
				case 0:
					while(indexador < linha.size() && linha.at(indexador) == ' '){
						indexador++;
					}
					if(indexador < linha.size()){
						if(linha.at(indexador) == '/'){
							indexador++;
							estado = 1;
						}else if(isLetra(linha.at(indexador)) == true){
							estado = 6;
							indexador++;
						}
						else{
							estado = 5;
						}
					}
					break;
				case 1:
					if(linha.at(indexador) == '*'){
						indexador++;
						estado = 2;
					}else if(linha.at(indexador) == '/'){
						indexador++;
						estado = 4;
					}
					break;
				case 2:
					while(indexador < linha.size() && linha.at(indexador) == ' '){
						indexador++;
					}
					if(indexador < linha.size()){
						if(linha.at(indexador) == '*'){
							indexador++;
							estado = 3;
						}else{
							indexador++;
							estado = 2;
						}
					}

					break;
				case 3:
					if(linha.at(indexador) == '/'){
						estado = 0;
						indexador++;
					}else if(linha.at(indexador) == '*'){
						estado = 3;
						indexador++;
					}else{
						indexador++;
						estado = 2;
					}
					break;
				case 4:
					indexador++;
					break;
				case 5:
					indexador++;
					break;
				case 6:
					while(indexador < linha.size() && (linha.at(indexador) == ' ')){
						indexador++;
					}

					if(indexador < linha.size()){
						if(isNumero(linha.at(indexador)) || isLetra(linha.at(indexador))){
							estado = 7;
						}else if(linha.at(indexador) == '/'){
							estado = 1;
						}else if(isOperador(linha.at(indexador))){
							estado = 8;
						}
						indexador++;
					}

					break;
				case 7:
					while(indexador < linha.size() && (linha.at(indexador) == ' ' || isNumero(linha.at(indexador)))){
						indexador++;
					}
					if(indexador < linha.size()){
						if(linha.at(indexador) == '+' || linha.at(indexador) == '-' || linha.at(indexador) == '*'){
							indexador++;
							estado = 6;
						}else if(linha.at(indexador) == '/'){
							indexador++;
							estado = 10;
						}else{
							indexador++;
							estado = 7;
						}
					}
					break;
				case 8:
					if(indexador >= linha.size()){
						estado = 8;
					}
					else if(linha.at(indexador) == ' '){
						indexador++;
						estado = 6;
					}else if(linha.at(indexador) == '/'){
						indexador++;
						estado = 1;
					}else if(isOperador(linha.at(indexador))){
						indexador++;
						estado = 9;
					}else if(isNumero(linha.at(indexador)) || isLetra(linha.at(indexador))){
						estado = 7;
						indexador++;
					}
					break;
				case 9:
					if(isLetra(linha.at(indexador)) || isNumero(linha.at(indexador))){
						indexador++;
						estado = 7;
					}else{
						indexador++;
						estado = 5;
					}
					break;
				case 10:
					if(linha.at(indexador) == ' '){
						indexador++;
					}else if(isLetra(linha.at(indexador)) || isNumero(linha.at(indexador))){
						indexador++;
						estado = 11;
					}else if(linha.at(indexador) == '/'){
						indexador++;
						estado = 4;
					}else if(linha.at(indexador) == '*'){
						indexador++;
						estado = 2;
					}else{
						indexador++;
						estado = 5;
					}
					break;
				case 11:
					if(linha.at(indexador) == ' '){
						indexador++;
					}else if(linha.at(indexador) == '/'){
						estado = 1;
						indexador++;
					}else if(isOperador(linha.at(indexador))){
						estado = 6;
						indexador++;
					}
					break;

				};
			}
			return estado;
		}
};

#endif /* ANALISADOR_LEXICO_H_ */
