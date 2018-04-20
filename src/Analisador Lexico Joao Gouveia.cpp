//=====================================================================================================
// Name        : Analisador.cpp
// Author      : João Lucas Gouveia
// Version     :
// Copyright   : Free usage
// Description : Trabalho para a matéria de compiladores na Fumec ministrada pelo professor João Paulo
//=====================================================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "file_validation.h"
#include "analisador_sintatico.h"

int main(int argc, char* argv[]) {

	std::string line;
	int numeroLinha = 1;

	// checando argumentos(argv)
	if(!checarArgumentos(argc, argv)){
		std::cout<<"Entrada invalida! Compilacao abortada! Entre com um nome de arquivo no formato nome.txt"<<std::endl;
		return 0;
	}

	std::ifstream fonte(argv[1], std::ifstream::binary);

	if(!fonte){
		std::cout<<"Arquivo nao encontrado!"<<std::endl;
		return 0;
	}

	while (std::getline(fonte, line)){
		if(!analisar_linha(line)){
			std::cout<<"Erro na linha " << numeroLinha << std::endl;
		}
		numeroLinha++;
	}
	std::cout<<"Fim da analise lexica!"<<std::endl;
}
