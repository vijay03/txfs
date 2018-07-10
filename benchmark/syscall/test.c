#include "shared.h"

int main(void) {
  int f0, f1, f2;
  int ret=-1;
  DEFINE_FILES;

  syscall(324);

#if 1
#if 0
  f0 = open(file0, O_CREAT | O_WRONLY | O_APPEND, 0644);
  write(f0, "0000000\n", 8);
#endif
  sync();

  ret = syscall(322);
  if (ret < 0) printf("Error: sys_txbegin().\n");
  printf("Current process ID : %d\n", getpid());
  //f0 = open(file0, O_CREAT | O_WRONLY | O_APPEND, 0644);
  f1 = open(file1, O_CREAT | O_WRONLY | O_APPEND, 0644);
//  f1 = open(file1, O_CREAT | O_WRONLY, 0644);
  //f2 = open(file2, O_CREAT | O_WRONLY | O_APPEND, 0644);
  write(f1, "1111111\n", 8);
//  lseek(f1, 16, SEEK_SET);
//  write(f1, "3333333\n", 8);
  //ret = syscall(326);
  ret = syscall(323);
  if (ret < 0) printf("Error: sys_txend().\n");
  sync();

#if 0
  f2 = open(file2, O_CREAT | O_WRONLY | O_APPEND, 0644);
  write(f2, "2222222\n", 8);
  sync();
#endif

  write(f1, "2222222\n", 8);
sync();
  close(f1);
#endif

  syscall(325);

#if 0
  f1 = open(file1, O_CREAT | O_WRONLY | O_APPEND, 0644);
//  f1 = open(file1, O_CREAT | O_WRONLY, 0644);
//  lseek(f1, 20, SEEK_SET);
  write(f1, "3333333\n", 8);
  close(f1);
#endif

  sync();
}
