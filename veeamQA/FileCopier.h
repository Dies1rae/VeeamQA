#pragma once
#include "tinyxml.h"

#include <string>
#include <vector>
#include <stdexcept>

class FileCopier {
public:
	FileCopier() = default;

	FileCopier(const std::string& xml) : xml_config_(xml) {
		this->xmlParse();
	}

	~FileCopier() = default;

	bool copierGoBrrrr();

private:
	void xmlParse();

	std::string xml_config_;
	std::vector<std::pair<std::string, std::string>> cp_base_;
};

