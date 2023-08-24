#include <sys/eventfd.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int fd;
uint64_t buffer;

void threadFunc(void) {
    int t;
    while (1) {
        t = read(fd, &buffer, sizeof(buffer));
        if (sizeof(buffer) < 8) {
            printf("buffer error\n");
        }
        printf("t = %11u buffer = %11u\n", t, buffer);
        if (t == 8) {
            printf("Wake up successfully\n");
        }
    }
}

int main() {
    uint64_t buf = 1;
    int ret;
    pthread_t tid;
    if ((fd = eventfd(0, 0)) == -1) {
        printf("Creation failed\n");
    }
    if (pthread_create(&tid, NULL, threadFunc, NULL) < 0) {
        printf("Thread creation failed\n");
    }
    while (1) {
        ret = write(fd, &buf, sizeof(buf));
        ret = write(fd, &buf, sizeof(buf));
        ret = write(fd, &buf, sizeof(buf));
        if (ret != 8) {
            printf("write error\n");
        }
      sleep(2);
    }
    return 0;
}
