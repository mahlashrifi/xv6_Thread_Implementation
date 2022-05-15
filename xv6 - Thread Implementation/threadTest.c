#include "types.h"
#include "stat.h"
#include "user.h"

int BASE, LIMIT;
int count = 0;

void run(int d) {
	if (BASE == LIMIT) {
		return;
    }
    printf(1, "%d - CHKPNT #1\n", count);
	BASE++;
	int tid = thread_creator((void *) &run, 0);
    printf(1, "%d - CHKPNT #2\n", count);
	int stat = thread_join(tid);
    printf(1, "%d - CHKPNT #3\n", count);
	printf(1, "[ID] %d => [%s] %d\n", thread_id(), (stat == 0) ? "Success" : "Failed", stat);
    printf(1, "%d - CHKPNT #4\n", count++);
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