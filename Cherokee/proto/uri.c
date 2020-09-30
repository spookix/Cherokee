#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

const char* path = "/home/flay/.profile";

int main() {
    struct stat buff;
    if (stat(path, &buff) == -1)
        return 1;
    if ((buff.st_mode & S_IFMT) == S_IFDIR) {
        printf("%s is a directory", path);
    } else if ((buff.st_mode & S_IFMT) == S_IFREG) {
        printf("%s is a file", path);
    } else {
        printf("%s is a unsupported file", path);
        return 1;
    }
    return 0;
}
