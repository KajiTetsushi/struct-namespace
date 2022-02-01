#ifndef RNBuildManager_h
#define RNBuildManager_h

typedef struct RNBuildManagerModule {
	/**
	 * @brief Commences a build batch job.
	 * @param shipType The identifier of the ship type to batch.
	 * @param batchSize The quantity of the ship type to build in one batch job.
	 */
	void (*startBatch)(const char *shipType, const int batchSize);
	/**
	 * @brief Suspends a build batch job.
	 * @param shipType The identifier of the ship type to batch.
	 */
	void (*pauseBatch)(const char *shipType);
	/**
	 * @brief Continues a build batch job.
	 * @param shipType The identifier of the ship type to batch.
	 */
	void (*resumeBatch)(const char *shipType);
	/**
	 * @brief Terminates a build batch jon.
	 * @param shipType The identifier of the ship type to batch.
	 */
	void (*cancelBatch)(const char *shipType);
	/**
	 * @brief Exits the Build Manager.
	 */
	void (*close)(void);
} RNBuildManagerModule;

extern const RNBuildManagerModule RNBuildManager;

#endif /* RNBuildManager.h */
