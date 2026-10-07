#include <stdio.h>
#include <pthread.h>

void*hitungfaktorial(void * arg){
	int angka = 9;
	int hasil = 1;
	
	for (int i = 1; i <= angka; i++) {
        hasil *= i;
}
   
   printf("hasil %d = %d\n", angka, hasil);
   
   return NULL;
   
}

int main () {
	pthread_t thread;
	pthread_create(&thread, NULL, hitungfaktorial, NULL);
	pthread_join(thread, NULL);
	
	printf("Thread faktorial selesai.\n");
	
	return 0 ;
}