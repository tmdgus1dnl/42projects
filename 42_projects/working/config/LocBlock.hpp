#ifndef LOCBLOCK_HPP
# define LOCBLOCK_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

#define GET 0
#define POST 1
#define DELETE 2

// location 블록 관련
class LocBlock
{
private:
	bool _autoindex; // on / off
	bool _method[3]; // 인덱스 순서는 GET, POST, DELETE 순서
	string _root;
	string _cgiPass; // CGI 로 넘기는것(pass)
	vector<string> _index; // index 파일 모음

	void _parseLine(vector<string>& tokens);
public:
	LocBlock();
	~LocBlock();

	void parseLocBlock(ifstream& file, const string& path);

	const bool& getAutoindex() const;
	const bool& getMethod(int method) const;
	const string& getRoot() const;
	const string& getCgipass() const;
	const vector<string>& getIndex() const;

	void print(string path) const; // 임시
};

#endif
