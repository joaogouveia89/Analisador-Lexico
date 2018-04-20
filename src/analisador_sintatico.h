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
public:
	AnalisadorLexico(){}
	static bool analisar_linha(std::string linha){
		return true;
	}
};

#endif /* ANALISADOR_SINTATICO_H_ */
