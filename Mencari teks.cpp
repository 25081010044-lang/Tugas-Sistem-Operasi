#include <stdio.h>
#include <pthread.h>

void *bacaData(void *arg) {
    FILE *file = fopen("data.txt", "r");
    char baris[100];

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return NULL;
    }

    printf("Data dari file:\n");

    while (fgets(baris, sizeof(baris), file)) {
        printf("%s", baris);
    }

    fclose(file);

    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, bacaData, NULL);
    pthread_join(thread, NULL);

    printf("Thread membaca file selesai.\n");

    return 0;
}