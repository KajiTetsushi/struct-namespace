#include <stdio.h>
#include "RNBuildManager.h"

void bmStartBatch(const char* shipType, const int batchSize) {
	printf("Construction commencing. [%s] x %d\n", shipType, batchSize);
}

void bmPauseBatch(const char* shipType) {
	printf("Construction paused. [%s]\n", shipType);
}

void bmResumeBatch(const char* shipType) {
	printf("Construction resumed. [%s]\n", shipType);
}

void bmCancelBatch(const char* shipType) {
	printf("Construction cancelled. [%s]\n", shipType);
}

void bmClose() {
	printf("Build Manager closed.\n");
}

const RNBuildManagerModule RNBuildManager = {
	.startBatch = bmStartBatch,
	.pauseBatch = bmPauseBatch,
	.resumeBatch = bmResumeBatch,
	.cancelBatch = bmCancelBatch,
	.close = bmClose,
};
