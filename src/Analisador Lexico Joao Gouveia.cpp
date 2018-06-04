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

#include "analisador_lexico.h"
#include "file_validation.h"

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
		if(AnalisadorLexico::is_estado_final(estado)){
			if(AnalisadorLexico::hasKeywords(line)){
				std::cout<<"Linha "<<numeroLinha<<" tem palavras chave!"<<std::endl;
			}else{
				std::cout<<"Linha "<<numeroLinha<<" ok!"<<std::endl;
			}
		}else{
			std::cout<<"Problemas na linha "<< numeroLinha<<std::endl;
		}
		std::cout<<"	parou no estado = " << estado << std::endl;
		numeroLinha++;
	}
	std::cout<<"Fim da analise lexica!"<<std::endl;
}
