#include "Score.h"

Score::Score()
{
	scoreList.clear();
}

Score::~Score()
{
}

void Score::Reset()
{
	scoreList.clear();
}

void Score::AddScore(const SCORE_INFO& _info)
{
	scoreList.emplace_back(_info);
}
