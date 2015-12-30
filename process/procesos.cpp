
#include "procesos.h"
/* fork , exec a command and redirect output to a file ( or not )*/
int exec(string str,bool redirect,string ficheroRedirect)  {
    cout<< "[DEBUG] ejecutamos :  "+str<<endl;
    int fd;
    fpos_t pos;
    char  *args[64];    /* the command line argument */ 
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    if (trocearCadena(cstr, args)==0)return -1;/*   parse the line, if empty -1   */
    if (redirect){
      fflush(stdout);
      fgetpos(stdout, &pos);
      fd = dup(fileno(stdout));
      freopen(ficheroRedirect.c_str(), "w", stdout);
    }
    pid_t pid = fork();
    if (pid == 0){ //child  
  execvp(args[0],args);
        error("execvp failed "+str);
    }
    else if (pid > 0) {// parent process
        waitpid(pid, NULL, 0); // Wait for the child process to return.
        if (redirect){
          fflush(stdout);
          dup2(fd, fileno(stdout));
          close(fd);
          clearerr(stdout);
          fsetpos(stdout, &pos);  
  }
    }
    else{// fork failed
        printf("fork() failed!\n");
        return -1;
    }
    free(cstr);
    return 0;
}
/* ******************************************************* */
