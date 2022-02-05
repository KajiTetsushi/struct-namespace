#include <stddef.h>

#include "buildManager/RNBuildManager.h"
#include "researchManager/RNResearchManager.h"

int main() {
	char *p1MissileCorvette = "P1MissileCorvette";
	int noOfP1MissileCorvette = 5;
	RNBuildManager.startBatch(p1MissileCorvette, 5);
	RNBuildManager.pauseBatch(p1MissileCorvette);
	RNBuildManager.resumeBatch(p1MissileCorvette);
	RNBuildManager.cancelBatch(p1MissileCorvette);
	RNBuildManager.close();

	char *guidedMissiles = "GuidedMissiles";
	int guidedMissilesLabIndexes[3] = {0, 2, 4};
	size_t guidedMissilesLabIndexesSize = sizeof(guidedMissilesLabIndexes) / sizeof(guidedMissilesLabIndexes[0]);
	RNResearchManager.startLabsByIndexes(guidedMissiles, guidedMissilesLabIndexes, guidedMissilesLabIndexesSize);
	RNResearchManager.clearLabsByIndexes(guidedMissiles, guidedMissilesLabIndexes, guidedMissilesLabIndexesSize);
	RNResearchManager.showInfo(guidedMissiles);
	RNResearchManager.close();

	return 0;
}
