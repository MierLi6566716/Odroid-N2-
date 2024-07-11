#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <vectors>
#include <map>
#include <cstring>
#include <string>

#define N 256
#define LOG_LEVEL 0
#define DATATYPE float
#define MULTICORE 0

typedef struct _temperature {
	int cpu;
} Temperature;

struct arg_struct {
	DATATYPE* arg1;
	DATATYPE* arg2;
	DATATYPE* arg3;
	int arg4;
};

FILE *tm[_result;
int finish;
unsigned long long int START_TIME;
std::map<unsigned long long int, Temperature*> tempMap;

void print_temperature(Temperature* tmp) {
	printf("\nTemperature: %d", tmp->cpu);
}

unsigned long long int get_current_time() {
	struct timeval c_time;
	gettimeofday(&c_time, NULL);
	unsigned long long int current_time = (unsigned long long int)(c_time.tv_sec * 1000000 + c_time.tv_usec);
	return (unsigned long long int)(current_time - START_TIME);
}

int check_core_temperature() {
	char filename[1024];
	strcpy(filename, "/sys/class/thermal/thermal_zone0/temp");
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	char tmp[16];
	fgets(tmp, sizeof(tmp), fp);
	fclose(fp);
	return atoi(tmp);
}

void decrease_core_temp(int threshold) {

}

void* multiply(void* arguments) {
	struct arg_struct *args = (struct arg_struct *)arguments;
	DATATYPE *a = args->arg1;
	DATATYPE *b = args->arg2;
	DATATYPE *c = args->arg3;
	int core = args->arg4;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DATATYPE sum = 0;
			for (int k = 0; k < N; k++) {
				sum += a[i * N + k] * b[k * N + j];
			}
			c[i * N + j] = sum;
		}
	}
	pthread_exit(NULL);
}

void* temperature_monitor(void* args) {
	while (!finish) {
		unsigned long long int currentTime = get_current_time();
		Temperature* temp = new Temperature();
		temp->cpu = check_core_temperature();
		tempMap[currentTime] = temp;
		usleep(1000000); 

	}
	pthread_exit(NULL);
}

int main() {
	DATATYPE mat1_1[N*N], mat2_1[N*N], res_1[N*N];
	struct arg_struct *args_1;

	args_1 = (struct arg_struct *)malloc(sizeof(struct arg_struct));
	args_1->arg1 = (DATATYPE*)mat1_1;
	args_1->arg2 = (DATATYPE*)mat2_1;
	args_1->arg3 = (DATATYPE*)res_1;
	args_1->arg4 = 0;

	decrease_core_temp(58000);
	
	struct timeval c_time;
	gettimeofday(&c_time, NULL);
	START_TIME = (unsigned long long int)(c_time.tv_sec * 100000 + c_time.tv_usec)
	struct timeval c_time;
	gettimeofday(&c_time, NULL);
	

	struct timeval c_time;
	gettimeofday(&c_time, NULL);
	START_TIME = (unsigned long long int)(c_time.tv_sec * 1000000 + c_time.tv_usec);
	pthread_t thread_temperature_monitor, thread_core1;
	pthread_create(&thread_temperature_monitor, NULL, temperature_monitor, NULL)
	finish = 0;
	for (int k = 0; k < 10; k++) {
		unsigned long long int start = get_current_time();
		pthread_create(&thread_core1, NULL, multiply, args_1);
		pthread_join(thread_core1, NULL);
		printf("***Execution time: %llu ms.***\n", (get_current_time() - start) / 1000);
	}
	pthread_join(thread_temperature_monitor, NULL);

	for (auto const& entry : tempMap) {
		printf("Time: %llu, ", entry.first);
		print_temperature(entry.second);
	}

	fclose(tmp_result);
	printf("FINISHED!\n\n");
	return 0;
	}



	for (auto const& entry : tempMap) {
		printf("Time: %llu, ", entry.first);
		print_temperature(entry.second);
	}
	fclose(tmp_result);
	printf("FINISHED!\n\n");
	return 0;

	pthread_join(thread_temperature_monitor, NULL);



}


