#ifndef RNResearchManager_h
#define RNResearchManager_h

typedef struct RNResearchManagerModule {
	/**
	 * @brief Commences a research task.
	 * @param technologyId The identifier of the technology to unlock.
	 * @param labIndexes The indexes to the labs used to conduct the research.
	 * @param labIndexesSize The size of the list of indexes of labs to affect.
	 */
	void (*startLabsByIndexes)(const char *technologyId, const int *labIndexes, const size_t labIndexesSize);
	/**
	 * @brief Terminates a research task.
	 * @param technologyId The identifier of the technology to unlock.
	 * @param labIndexes The indexes to the labs used to conduct the research.
	 * @param labIndexesSize The size of the list of indexes of labs to affect.
	 */
	void (*clearLabsByIndexes)(const char *technologyId, const int *labIndexes, const size_t labIndexesSize);
	/**
	 * @brief Displays a technology information.
	 * @param technologyId The identifier of the technology
	 */
	void (*showInfo)(const char *technologyId);
	/**
	 * @brief Exits the Research Manager.
	 */
	void (*close)(void);
} RNResearchManagerModule;

extern const RNResearchManagerModule RNResearchManager;

#endif /* RNResearchManager.h */
