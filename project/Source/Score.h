#pragma once
#include <list>

struct SCORE_INFO {
	int playerNun;
	int score;

	SCORE_INFO(): playerNun(-1), score(0){}
};

class Score {
public:
	static Score* GetInstance() {
		static Score* inst = nullptr;
		if (inst == nullptr) {
			inst = new Score();
		}
		return inst;
	}

	void Reset();

	const std::list<SCORE_INFO>& GetList() { return scoreList; }

	void AddScore(const SCORE_INFO& _info);
private:
	Score();
	~Score();

	std::list<SCORE_INFO> scoreList;
};
