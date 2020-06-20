#include <stdio.h>
#include "requests.h"
#include "json.h"

int main(int argc, const char **argv)
{
	json_char* json;
	json_value* value;
    req_t req;                     /* declare struct used to store data */
    int ret = requests_init(&req); /* setup */
    if (ret) {
        return 1;
    }
    printf("hi");
    requests_get(&req, "https://covidtracking.com/api/states"); /* submit GET request */
    printf("Request URL: %s\n", req.url);
    printf("Response Code: %lu\n", req.code);
    printf("Response Body:\n%s", req.text);

    json = (json_char*)req.txt;

    requests_close(&req); /* clean up */
    return 0;
}