#include <stddef.h>
#include <stdio.h>

#include "RNResearchManager.h"

void rmStartLabsByIndexes(const char *technologyId, const int *labIndexes, const size_t labIndexesSize) {
	printf("Research commencing. [%s]", technologyId);

	if ((int)labIndexesSize > 0) {
		printf(" @ ");
		int i;
		for (i = 0; i < (int)labIndexesSize; i++) {
			printf("[%d]", labIndexes[i]);
		}
	}

	printf("\n");
}

void rmClearLabsByIndexes(const char *technologyId, const int *labIndexes, const size_t labIndexesSize) {
	printf("Research halted. [%s]", technologyId);

	if ((int)labIndexesSize > 0) {
		printf(" @ ");
		int i;
		for (i = 0; i < (int)labIndexesSize; i++) {
			printf("[%d]", labIndexes[i]);
		}
	}

	printf("\n");
}

void rmShowInfo(const char *technologyId) {
	printf("Research info: [%s]\n", technologyId);
}

void rmClose(void) {
	printf("Research Manager closed.\n");
}

const RNResearchManagerModule RNResearchManager = {
	.startLabsByIndexes = rmStartLabsByIndexes,
	.clearLabsByIndexes = rmClearLabsByIndexes,
	.showInfo = rmShowInfo,
	.close = rmClose,
};
