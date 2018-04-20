/*
 * file_validation.h
 *
 *  Created on: 19 de abr de 2018
 *      Author: Joao
 */

#ifndef FILE_VALIDATION_H_
#define FILE_VALIDATION_H_

#include <regex>
bool checarArgumentos(int argc, char* argv[]){
	std::regex rx("^(.*)\\.txt$");
	if(argc != 2 || !std::regex_match(argv[1], rx))
		return false;

	return true;
}

#endif /* FILE_VALIDATION_H_ */
