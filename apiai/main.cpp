#include <iostream>
#include <string>
#include <map>
#include <sstream>

#include <future>
#include <thread>

#include <curl/curl.h>
#include <cJSON.h>

#include "AI.h"

#include "query/TextQueryRequest.h"
#include "Exception.h"

#include "JSON/JSONException.h"

using namespace std;

using namespace ai::query::request;

int main(int argc, char *argv[]) {

    ai::AI::global_init();

    auto credentials = ai::Credentials("ff98c090685f484caaffada53cdce7b3", "4c91a8e5-275f-4bf0-8f94-befa78ef92cd ");

    auto request = std::shared_ptr<TextQueryRequest>(new TextQueryRequest(QueryText::One("Hello"), "en", credentials, Parameters("sessionId")));

    auto response = request->perform();

//    ai::query::QueryRequest request("HelloManyContexts", "en", credentials);

//    auto response = request.perform();

////    std::cout << "identifier: " << response.result.getFulfillment()->getSpeech() << std::endl;

//    std::cout << response << std::endl;

    ai::AI::global_clean();

    return 0;
}
