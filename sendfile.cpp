#include "pastebin.h"

using namespace std;

CURLcode post_code(string filename, string expire_time, string code)
{
    CURL *curl;
    CURLcode res;
    stringstream payload;

    payload << "api_option=paste" 
        << "&api_user_key=" << api_user_key
        << "&api_paste_expire=" << "1D" 
        << "&api_paste_format=" << "cpp"
        << "&api_paste_name=" << filename
        << "&api_dev_key=" << api_dev_key
        << "&api_paste_code=" << code;

    string post_fields = payload.str();

    //'api_option=paste&api_user_key='.$api_user_key.'&api_paste_private='.$api_paste_private.'&api_paste_name='.$api_paste_name.'&api_paste_expire_date='.$api_paste_expire_date.'&api_paste_format='.$api_paste_format.'&api_dev_key='.$api_dev_key.'&api_paste_code='.$api_paste_code

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://pastebin.com/api/api_post.php");
        curl_easy_setopt(
            curl, 
            CURLOPT_POSTFIELDS, 
            post_fields.c_str()
        );

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return res;
}
