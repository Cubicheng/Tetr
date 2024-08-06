#include "music.h"
#include "graphics.h"

# pragma comment(lib,"Winmm.lib")

bool mus::on_warning;

void mus::init(){
	on_warning = false;
	mciSendString(_T("open resource/bgm.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("open resource/hit.mp3 alias hit"), NULL, 0, NULL);
	mciSendString(_T("open resource/floor.mp3 alias floor"), NULL, 0, NULL);
	mciSendString(_T("open resource/harddrop.mp3 alias harddrop"), NULL, 0, NULL);
	mciSendString(_T("open resource/hold.mp3 alias hold"), NULL, 0, NULL);
	mciSendString(_T("open resource/clearline.mp3 alias clearline"), NULL, 0, NULL);
	mciSendString(_T("open resource/warning.mp3 alias warning"), NULL, 0, NULL);
	mciSendString(_T("setaudio bgm volume to 600"), NULL, 0, NULL);
	mciSendString(_T("setaudio clearline volume to 500"), NULL, 0, NULL);

}

void mus::hit(){
	mciSendString(_T("play hit from 0"), NULL, 0, NULL);
}

void mus::bgm() {
	mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);
}

void mus::floor() {
	//mciSendString(_T("play floor from 0"), NULL, 0, NULL);
}

void mus::clearline() {
	mciSendString(_T("play clearline from 0"), NULL, 0, NULL);
}

void mus::hold() {
	mciSendString(_T("play hold from 0"), NULL, 0, NULL);
}

void mus::harddrop() {
	mciSendString(_T("play harddrop from 0"), NULL, 0, NULL);
}

void mus::warning_start(){
	if (on_warning) return;
	mciSendString(_T("play warning repeat from 0"), NULL, 0, NULL);
	on_warning = true;
}

void mus::warning_end(){
	mciSendString(_T("pause warning"), NULL, 0, NULL);
	on_warning = false;
}


