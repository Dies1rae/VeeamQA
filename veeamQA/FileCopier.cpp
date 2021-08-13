#include "FileCopier.h"

#include <fstream>

void FileCopier::xmlParse() {
	TiXmlDocument xml_balse(this->xml_config_.c_str());
	if (xml_balse.LoadFile()) {
		TiXmlElement *element = xml_balse.FirstChildElement("config")->FirstChildElement("file");
		if (element == NULL) {
			throw std::runtime_error("Wrong xml format");
		}
		while (element != NULL) {
			std::string src = element->Attribute("source_path");
			if (src[src.size() - 1] != '\\') {
				src += '\\';
			}
			src += element->Attribute("file_name");
			std::string dst = element->Attribute("destination_path");
			if (dst[dst.size() - 1] != '\\') {
				dst += '\\';
			}
			dst += element->Attribute("file_name");
			this->cp_base_.push_back({std::move(src), std::move(dst)});
			element = element->NextSiblingElement("file");
		}
	} else {
		throw std::runtime_error("Could not open file");
	}
}

bool FileCopier::copierGoBrrrr() {
	for (const auto& [src_, dst_] : this->cp_base_) {
		std::ifstream src(src_, std::ios::binary);
		std::ofstream dst(dst_, std::ios::binary);
		if (!src.good()) {
			throw std::runtime_error("Could not open file " + src_);
		}
		dst << src.rdbuf();
		src.close();
		dst.close();
		if (dst.bad()) {
			throw std::runtime_error("Could not write to file " + dst_);
		}
	}
}