#include <stdio.h>
#include <pthread.h>

void *prosesFibonacci(void *arg)
{
    int jumlah = 10;
    int angka1 = 0;
    int angka2 = 1;

    printf("Hasil Fibonacci %d angka:\n", jumlah);

    for (int i = 0; i < jumlah; i++)
    {
        printf("%d ", angka1);

        int hasil = angka1 + angka2;
        angka1 = angka2;
        angka2 = hasil;
    }

    printf("\n");

    return NULL;
}

int main()
{
    pthread_t threadFibo;

    printf("Memulai proses Fibonacci...\n");

    pthread_create(&threadFibo, NULL, prosesFibonacci, NULL);

    pthread_join(threadFibo, NULL);

    printf("Proses Fibonacci selesai.\n");

    return 0;
}