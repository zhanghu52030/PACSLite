#include "base/json_helper.h"

#include <fstream>
#include <memory>
#include <sstream>

namespace base {

void JsonToString(const Json::Value& json, std::string* str) {
  Json::StreamWriterBuilder builder;
  *str = Json::writeString(builder, json);
}

bool StringToJson(const std::string& str, Json::Value* json,
                  std::string* error_msg) {
  Json::CharReaderBuilder builder;
  std::stringstream stream(str);
  return Json::parseFromStream(builder, stream, json, error_msg);
}

bool LoadJsonFromFile(const std::wstring& file_path, Json::Value* json,
                      std::string* error_msg) {
  std::ifstream ifs(file_path);
  if (ifs.fail()) {
    return false;
  }

  Json::CharReaderBuilder builder;
  return Json::parseFromStream(builder, ifs, json, error_msg);
}

bool SaveJsonToFile(const std::wstring& file_path, const Json::Value& json) {
  std::ofstream ofs(file_path);
  if (ofs.fail()) {
    return false;
  }

  Json::StreamWriterBuilder builder;
  builder["indentation"] = "  ";
  std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  writer->write(json, &ofs);

  ofs.close();

  return true;
}

}  // namespace base
