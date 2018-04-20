/*
 * analisador_sintatico.h
 *
 *  Created on: 19 de abr de 2018
 *      Author: Joao
 */

#ifndef ANALISADOR_SINTATICO_H_
#define ANALISADOR_SINTATICO_H_

#include<string>

class AnalisadorLexico{
private:
	const std::string op = "+-*:";
	const std::string num = "0123456789";
	const std::string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	AnalisadorLexico(){}
	static int analisar_linha(std::string linha){
		int estado = 0 /* iniciando o estado do automato com 0 */;
		int indexador = 0;
		while(estado != 30){
			switch(estado){
			case 0:
				while(linha.at(indexador) == ' '){
					indexador++;
				}
				if(linha.at(indexador) == '/'){
					indexador++;
					estado = 1;
				}
				break;
			case 1:
				if(linha.at(indexador) == '*'){
					indexador++;
					estado = 2;
				}else{
					return estado;
				}
				break;
			case 2:
				while(linha.at(indexador) != '*'){
					indexador++;
				}
				if(linha.at(indexador) == '*'){
					indexador++;
					estado = 3;
				}else{
					return 2;
				}
				break;
			case 3:
				while(linha.at(indexador) == '*'){
					indexador++;
				}
				if((linha.at(indexador) != '*') && (linha.at(indexador) != '/')){
					indexador++;
					estado = 2;
				}else if((linha.at(indexador) == '/')){
					indexador++;
					estado = 0;
				}else{
					return 3;
				}
				break;
			}
		};
		return estado;
	}
};

#endif /* ANALISADOR_SINTATICO_H_ */
