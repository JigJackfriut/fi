
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>


#include "httplib.h"

using namespace httplib;
using namespace std;
using json = nlohmann::json;

const int port = 5005;


int main() {
    httplib::Server svr;

  svr.Get(R"(/dynamicArt/getEmotionPercentages/)", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin", "*");


    
    json result;

 
        result = {{"Happiness", 50}, {"Sadness", 10}, {"Fear", 12}};
         
  
   res.set_content(result.dump(), "application/json");
});

svr.listen("0.0.0.0", port);
    return 0;
}
    

