//=====================================================================================================
// Name        : Analisador.cpp
// Author      : Jo�o Lucas Gouveia
// Version     :
// Copyright   : Free usage
// Description : Trabalho para a mat�ria de compiladores na Fumec ministrada pelo professor Jo�o Paulo
//=====================================================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "file_validation.h"
#include "analisador_sintatico.h"

int main(int argc, char* argv[]) {

	std::string line;
	int numeroLinha = 1;
	int estado;

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
		estado = AnalisadorLexico::analisar_linha(line);
		if(estado != 30){
			std::cout<<"Erro no estado " << estado << std::endl;
		}
		numeroLinha++;
	}
	std::cout<<"Fim da analise lexica!"<<std::endl;
}
