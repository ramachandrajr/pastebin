#include "pastebin.h"

int main()
{
    CURLcode res = post_code("myfile.cpp", "1D", "something heare");

    if (res != CURLE_OK)
        std::cout << "Failed: " << curl_easy_strerror(res) << "\n";

    return 0;
}
