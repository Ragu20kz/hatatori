#include "PlayTime.h"
#include <assert.h>
#include "config.h"

namespace {
	static const int TIME_AGAIN = 59; //ŽžŠÔ§ŒÀ
	static const int IMAGE_SIZE = 64; //”‚ÌƒTƒCƒY
	static const int SPACE_SIZE = 32; //ŠÔŠu
	static const int DIGIT = 10;      //Œ…
}

PlayTime::PlayTime(){
	time = 10;
	timeFrame = 0;
	imageNumber = LoadGraph("data\\textures\\num07.png");
	assert(imageNumber >= 0);
	imageTime = LoadGraph("data\\textures\\time.png");
	assert(imageTime >= 0);
	activeTime = true;
}

PlayTime::~PlayTime(){
	if (imageNumber > 0) {
		DeleteGraph(imageNumber);
	}
	if (imageTime > 0) {
		DeleteGraph(imageTime);
	}
}

void PlayTime::Update(){
	if (activeTime)
		timeFrame--;

	if (timeFrame < 0) {
		time--;
		timeFrame = TIME_AGAIN;
	}
}

void PlayTime::Draw(){
	if (activeTime) {
		DrawRectGraph(0, 0, 0, 0, 107, 60, imageTime, true, false);
		int dig = 0;
		int copy = time;
		do {
			DrawRectGraph(30 - (SPACE_SIZE * dig), 35,
				(copy % DIGIT) * IMAGE_SIZE, 0, IMAGE_SIZE, IMAGE_SIZE, imageNumber, true, false);
			copy = copy / DIGIT;
			dig++;
		} while (copy > 0);
	}

}

bool PlayTime::SetActiveTime(bool active){
	activeTime = active;
	return false;
}

bool PlayTime::IsTimeUp()
{
	return (time == 0);
}

