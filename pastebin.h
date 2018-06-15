#include <iostream>
#include <curl/curl.h>
#include <string>
#include <sstream>

const std::string api_user_key = "f17fc3504c7ec92ea94c7f13491c9a88";
const std::string api_dev_key = "37211b17059dcd5f9c59b83348cd7d9d";

CURLcode post_code(std::string filename, std::string expire_time, std::string code);
