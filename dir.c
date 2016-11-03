#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  DIR * a = opendir(".");
  struct dirent *ent = readdir(a);
  struct stat buff;
  int tot = 0;

  while (ent){
    if (ent->d_type & DT_DIR){
      printf("%s (directory)\n", ent->d_name);
    }
    else{
      stat(ent->d_name, &buff);
      tot += buff.st_size;
      printf("%s\n", ent->d_name);
    }
    ent = readdir(a);
  }

  closedir(a);
  printf("total size: %d\n", tot);
}
