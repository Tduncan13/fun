#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

bool byrIsValid(std::string s){
	if(!std::regex_match(s, std::regex("[0-9]{4}"))) return false;
	if(std::stoi(s) < 1920 || std::stoi(s) > 2002) return false;

	return true;
}

bool iyrIsValid(std::string s){
	if(!std::regex_match(s, std::regex("[0-9]{4}"))) return false;
	if(std::stoi(s) < 2010 || std::stoi(s) > 2020) return false;

	return true;
}

bool eyrIsValid(std::string s){
	if(!std::regex_match(s, std::regex("[0-9]{4}"))) return false;
	if(std::stoi(s) < 2020 || std::stoi(s) > 2030) return false;

	return true;
}

bool hgtIsValid(std::string s){
	if(!std::regex_match(s, std::regex("[0-9]+(in|cm)"))) return false;
	if(s.find("cm") != std::string::npos){
		int h = std::stoi(s.substr(0, s.length() - 2));
		if(h < 150 || h > 193) return false;
	}
	else if(s.find("in") != std::string::npos){
		int h = std::stoi(s.substr(0, s.length() - 2));
		if(h < 59 || h > 76) return false;
	}

	return true;
}

bool hclIsValid(std::string s){
	if(!std::regex_match(s, std::regex("#([0-9+]|[a-f]+)+"))) return false;

	return true;
}

bool eclIsValid(std::string s){
	if(s == "amb") return true;
	else if(s == "blu") return true;
	else if(s == "brn") return true;
	else if(s == "gry") return true;
	else if(s == "grn") return true;
	else if(s == "hzl") return true;
	else if(s == "oth") return true;

	return false;
}

bool pidIsValid(std::string s){
	if(!std::regex_match(s, std::regex("[0-9+]{9}"))) return false;
	
	return true;
}

bool isValid(std::unordered_map<std::string, std::string> *p){
	
	int count = 0;
	std::string birth_year = "byr";
	std::string issued_year = "iyr";
	std::string exp_year = "eyr";
	std::string height = "hgt";
	std::string hair_color = "hcl";
	std::string eye_color = "ecl";
	std::string pid = "pid";

	// Check that birth year is four digits and between 1920 and 2002	
	if(p->find(birth_year) != p->end())
		if(byrIsValid(p->at(birth_year))) count++;

	// Check issued year is four digits and between 2010 and 2020
	if(p->find(issued_year)	!= p->end()) 
		if(iyrIsValid(p->at(issued_year))) count++;

	// Check expiration year is four digits and between 2020 and 2030
	if(p->find(exp_year) != p->end())
		if(eyrIsValid(p->at(exp_year))) count++;

	// Check height is a number followed by either in or cm. 
	// if cm, must be between 150 and 193
	// if in, must be between 59 and 76
	if(p->find(height) != p->end()) 
		if(hgtIsValid(p->at(height))) count++;

	// Check hair color is a # followed by six characters 0-9 or a-f
	if(p->find(hair_color) != p->end())
		if(hclIsValid(p->at(hair_color))) count++;

	// Check eye color is either: amb, blu, brn, gry, grn, hzl, oth
	if(p->find(eye_color)	!= p->end()) 
		if(eclIsValid(p->at(eye_color))) count++;

	// Check pid is nine-digit number, including leading zeros
	if(p->find(pid)	!= p->end())
		if(pidIsValid(p->at(pid)))	count++;

	return (count == 7) ? true : false;
}

std::unordered_map<std::string, std::string> *createPassport(std::vector<std::string> record){
	std::unordered_map<std::string, std::string> *p = new std::unordered_map<std::string, std::string>();
	std::string s;

	// Break passenger info into vector
	for(std::string line : record){
		s += line + " ";
	}
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::copy(vstrings.begin(), vstrings.end(), vstrings.begin());

	// Break Vector into key value pairs
	size_t pos = 0;
	std::string delimeter = ":";

	for(std::string kv : vstrings){
		while((pos = kv.find(delimeter)) != std::string::npos){
			std::string key = kv.substr(0, pos);
			kv.erase(0, pos + delimeter.length());
			std::string value = kv;
			p->insert({key, value});
		}
	}

	return p;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::string line;
	std::vector<std::string> record;
	std::unordered_map<std::string, std::string> *passport;
	int count = 0;

	while(std::getline(infile, line)){
		
		if(line == ""){
			passport = createPassport(record);
			count += isValid(passport) ? 1 : 0;
			record.clear();
			continue;
		}
		record.push_back(line);
	}

	passport = createPassport(record);
	count += isValid(passport) ? 1 : 0;

	std::cout << count << std::endl;
}
