#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd;
  struct stat fs;
  void *payload;

  fd = open(argv[1], O_RDONLY);
  assert(fd != -1);

  assert(fstat(fd, &fs) != -1);

  payload = mmap(0, fs.st_size, PROT_READ | PROT_EXEC, MAP_SHARED, fd, 0);
  assert(payload != MAP_FAILED);

  (*(void (*)(void))payload)();

  assert(munmap(payload, fs.st_size) != -1);
  assert(close(fd) != -1);

  return EXIT_SUCCESS;
}
