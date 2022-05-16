#include "types.h"
#include "stat.h"
#include "user.h"

int BASE, LIMIT;

void run(int d) {
	if (BASE == LIMIT) {
		exit();
    }

	BASE++;
	int tid = thread_creator((void *) &run, 0);
	int stat = thread_join(tid);
	printf(1, "[ID] %d => [%s] %d\n", thread_id(), (stat == 0) ? "Success" : "Failed", stat);
}

int main(int argc, char const *argv[]) {
	if (argc < 3) {
		printf(1, "Please pass BASE and LIMIT values as argument\n");
		exit();
	}

	BASE = atoi(argv[1]);
	LIMIT = atoi(argv[2]);

	int tid = thread_creator((void *) &run, 0);
	thread_join(tid);

	return 0;
}