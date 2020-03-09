
#ifndef STATS_H_
#define STATS_H_

class Stats {
public:
	Stats();
	virtual ~Stats();

	int numHits;
	int numMisses;
	int totalShots;
	double hitMissRatio;

};

#endif /* STATS_H_ */
