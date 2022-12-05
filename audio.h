#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#include "waveform.h"
#pragma comment(lib, "winmm.lib")

#define MAX 65536/8

typedef unsigned char byte;

struct WAV
{
	byte ChunkID[4];      //"RIFF"
	byte ChunkSize[4];    //*
	byte Format[4];       //"WAVE"
	byte Subchunk1ID[4];  //"fmt "
	byte Subchunk1Size[4];//*
	byte AudioFormat[2];  //*, 1:pcm(pulse code modulation)
	byte NumChannels[2];  //*
	byte SampleRate[4];   //*
	byte ByteRate[4];     //*
	byte BlockAlign[2];   //*
	byte BitsPerSample[2];//*
	byte Subchunk2ID[4];  //"data"
	byte Subchunk2Size[4];//*
};

struct WAVt
{
	byte ChunkID[4];    //"RIFF"
	int ChunkSize;      //*
	byte Format[4];     //"WAVE"
	byte Subchunk1ID[4];//"fmt "
	int Subchunk1Size;  //*
	short AudioFormat;  //*, 1:pcm(pulse code modulation)
	short NumChannels;  //*
	int SampleRate;     //*
	int ByteRate;       //*
	short BlockAlign;   //*
	short BitsPerSample;//*
	byte Subchunk2ID[4];//"data"
	int Subchunk2Size;  //*
};

//little endian write
void lew(byte* x, int t, int n)
{
	for (int i = 0; i < n; i++, t >>= 8)
		x[i] = t & 0xFF;
}

WAV writeheader(WAVt x)
{
	WAV t;
	for (int i = 0; i < 4; i++) t.ChunkID[i] = x.ChunkID[i];
	lew(t.ChunkSize, x.ChunkSize, 4);
	for (int i = 0; i < 4; i++) t.Format[i] = x.Format[i];
	for (int i = 0; i < 4; i++) t.Subchunk1ID[i] = x.Subchunk1ID[i];
	lew(t.Subchunk1Size, x.Subchunk1Size, 4);
	lew(t.AudioFormat, x.AudioFormat, 2);
	lew(t.NumChannels, x.NumChannels, 2);
	lew(t.SampleRate, x.SampleRate, 4);
	lew(t.ByteRate, x.ByteRate, 4);
	lew(t.BlockAlign, x.BlockAlign, 2);
	lew(t.BitsPerSample, x.BitsPerSample, 2);
	for (int i = 0; i < 4; i++) t.Subchunk2ID[i] = x.Subchunk2ID[i];
	lew(t.Subchunk2Size, x.Subchunk2Size, 4);
	return t;
}

enum note {
	c1, c1s, d1, d1s, e1, f1, f1s, g1, g1s, a1, a1s, b1,
	c2, c2s, d2, d2s, e2, f2, f2s, g2, g2s, a2, a2s, b2,
	c3, c3s, d3, d3s, e3, f3, f3s, g3, g3s, a3, a3s, b3,
	c4, c4s, d4, d4s, e4, f4, f4s, g4, g4s, a4, a4s, b4,
	c5, c5s, d5, d5s, e5, f5, f5s, g5, g5s, a5, a5s, b5,
	c6, c6s, d6, d6s, e6, f6, f6s, g6, g6s, a6, a6s, b6,
	c7, c7s, d7, d7s, e7, f7, f7s, g7, g7s, a7, a7s, b7,
	c8, c8s, d8, d8s, e8, f8, f8s, g8, g8s, a8, a8s, b8
};
double freq[] = {
	32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74,
	65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47,
	130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94,
	261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88,
	523.25, 554.37, 587.33, 622.25, 659.26, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77,
	1046.5, 1108.7, 1174.7, 1244.5, 1318.5, 1396.9, 1480.0, 1568.0, 1661.2, 1760.0, 1864.7, 1975.5,
	2093.0, 2217.5, 2349.3, 2489.0, 2637.0, 2793.8, 2960.0, 3136.0, 3322.4, 3520.0, 3729.3, 3951.1,
	4186.0, 4434.9, 4698.6, 4978.0, 5274.0, 5587.7, 5919.9, 6271.9, 6644.9, 7040.0, 7458.6, 7902.1
};

string nota[] = {
	"c1", "c1#", "d1", "d1#", "e1", "f1", "f1#", "g1", "g1#", "a1", "a1#", "b1",
	"c2", "c2#", "d2", "d2#", "e2", "f2", "f2#", "g2", "g2#", "a2", "a2#", "b2",
	"c3", "c3#", "d3", "d3#", "e3", "f3", "f3#", "g3", "g3#", "a3", "a3#", "b3",
	"c4", "c4#", "d4", "d4#", "e4", "f4", "f4#", "g4", "g4#", "a4", "a4#", "b4",
	"c5", "c5#", "d5", "d5#", "e5", "f5", "f5#", "g5", "g5#", "a5", "a5#", "b5",
	"c6", "c6#", "d6", "d6#", "e6", "f6", "f6#", "g6", "g6#", "a6", "a6#", "b6",
	"c7", "c7#", "d7", "d7#", "e7", "f7", "f7#", "g7", "g7#", "a7", "a7#", "b7",
	"c8", "c8#", "d8", "d8#", "e8", "f8", "f8#", "g8", "g8#", "a8", "a8#", "b8"
};

string nota2[] = {
	"c1", "c1s", "d1", "d1s", "e1", "f1", "f1s", "g1", "g1s", "a1", "a1s", "b1",
	"c2", "c2s", "d2", "d2s", "e2", "f2", "f2s", "g2", "g2s", "a2", "a2s", "b2",
	"c3", "c3s", "d3", "d3s", "e3", "f3", "f3s", "g3", "g3s", "a3", "a3s", "b3",
	"c4", "c4s", "d4", "d4s", "e4", "f4", "f4s", "g4", "g4s", "a4", "a4s", "b4",
	"c5", "c5s", "d5", "d5s", "e5", "f5", "f5s", "g5", "g5s", "a5", "a5s", "b5",
	"c6", "c6s", "d6", "d6s", "e6", "f6", "f6s", "g6", "g6s", "a6", "a6s", "b6",
	"c7", "c7s", "d7", "d7s", "e7", "f7", "f7s", "g7", "g7s", "a7", "a7s", "b7",
	"c8", "c8s", "d8", "d8s", "e8", "f8", "f8s", "g8", "g8s", "a8", "a8s", "b8"
};

string n2s(note n) {
	return nota[n];
}

note s2n(string s) {
	for (int i = c1; i <= b8; i++) {
		if (nota[i] == s||nota2[i] == s) {
			return (note)i;
		}
	}
	return c1;
}

struct Note {
	int barn;
	double start;
	double len;
	double playlen;
	int n;
	int w;
	double vol;
	int channel;

	bool operator < (const Note& O) const {
		if (barn != O.barn) return barn < O.barn;
		if (start != O.start) return start < O.start;
		if (len != O.len) return len < O.len;
		if (n != O.n) return n < O.n;
		if (vol != O.vol) return vol < O.vol;
		if (w != O.w) return w < O.w;
		return channel < O.channel;
	}
};

class Audio {
public:
	int pcm[44100 * 30][4] = {},nb, duration;
	int startDelay = 1;
	Audio(int o, int k = 1) {
		startDelay = k;
		duration = 1000 * startDelay;
		one = o;
		setHeader();
	}

	void SetOne(int o) {
		one = o;
		setHeader();
	}

	void SetDuration(int d) {
		duration = d+1000 * startDelay;
		setHeader();
	}

	void Insert(int start, int end, note n, waveform w = def, double vol = MAX, int channel = -1) {
		int s = s2s(start), e = s2s(end);
		double freqrps = 2 * freq[n] * PI / headt.SampleRate;

		double phase = 0;
		for (int i = s; i <= e; i++) {
			if (channel == -1) {
				for (int j = 0; j < ch; j++) {
					pcm[i][j] += int(vol * sound(w, phase));
				}
			}
			else if(0 <= channel && channel < ch) {
				pcm[i][channel] += int(vol * sound(w, phase));
			}
			phase += freqrps;
		}

		if (end >= duration-1000 * startDelay) {
			duration = end + 1000 * startDelay;
			setHeader();
		}
	}

	void InsertL(int start, int len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		Insert(start, start + len - 1, n, w, vol, channel);
	}

	void InsertL2(int start, double len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		int l = int(one * len);
		Insert(start, start + l - 1, n, w, vol, channel);
	}

	void Remove(int start, int end, note n, waveform w = def, double vol = MAX, int channel = -1) {
		if (start >= duration - 1000 * startDelay || end >= duration - 1000 * startDelay) return;
		int s = s2s(start), e = s2s(end);
		double freqrps = 2 * freq[n] * PI / headt.SampleRate;

		double phase = 0;
		for (int i = s; i <= e; i++) {
			if (channel == -1) {
				for (int j = 0; j < ch; j++) {
					pcm[i][j] -= int(vol * sound(w, phase));
				}
			}
			else if (0 <= channel && channel < ch) {
				pcm[i][channel] -= int(vol * sound(w, phase));
			}
			phase += freqrps;
		}
	}

	void RemoveL(int start, int len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		Remove(start, start + len - 1, n, w, vol, channel);
	}

	void RemoveL2(int start, double len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		int l = int(one * len);
		Remove(start, start + l - 1, n, w, vol, channel);
	}

	void Write(int start, int end, note n, waveform w = def, double vol = MAX, int channel = -1) {
		int s = s2s(start), e = s2s(end), t = 0;
		double freqrps = 2 * freq[n] * PI / headt.SampleRate;

		for (int i = 0; i < s; i++) {
			if (channel == -1) {
				for (int j = 0; j < ch; j++) {
					tmp[t][j] = pcm[i][j];
				}
			}
			else if (0 <= channel && channel < ch) {
				tmp[t][channel] = pcm[i][channel];
			}
			t++;
		}

		double phase = 0;
		for (int i = s; i <= e; i++) {
			if (channel == -1) {
				for (int j = 0; j < ch; j++) {
					tmp[t][j] = int(vol * sound(w, phase));
				}
			}
			else if (0 <= channel && channel < ch) {
				tmp[t][channel] = int(vol * sound(w, phase));
			}
			phase += freqrps;
			t++;
		}

		for (int i = s; i < nb; i++) {
			if (channel == -1) {
				for (int j = 0; j < ch; j++) {
					tmp[t][j] = pcm[i][j];
				}
			}
			else if (0 <= channel && channel < ch) {
				tmp[t][channel] = pcm[i][channel];
			}
			t++;
		}

		duration += end - start + 1;
		setHeader();

		swap(pcm, tmp);
	}

	void WriteL(int start, int len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		Write(start, start + len - 1, n, w, vol, channel);
	}

	void Cut(int start, int end) {
		int s = s2s(start), e = s2s(end), t = 0;
		for (int i = 0; i < nb; i++) {
			if (s <= i && i <= e) {
				continue;
			}
			for (int j = 0; j < ch; j++) {
				tmp[t][j] = pcm[i][j];
			}
			t++;
		}

		duration -= end - start + 1;
		setHeader();

		swap(pcm, tmp);
	}

	void CutL(int start, int len) {
		Cut(start, start + len - 1);
	}

	void Export(string name) {
		//printf("%d %d\n", headt.Subchunk2Size, headt.ChunkSize);

		fopen_s(&file, name.c_str(), "wb");
		head = writeheader(headt);
		fwrite(&head, sizeof(head), 1, file);

		int t = 0;
		for (int i = 0; i < nb; i++) {
			if (i < s2s(1000)&&startDelay) {
				lew(buffer, 0, sz);
				fwrite(buffer, sz, 1, file);
				continue;
			}
			for (int j = 0; j < ch; j++) {
				lew(buffer, pcm[t][j], sz);
				fwrite(buffer, sz, 1, file);
			}
			t++;
		}
		fclose(file);
	}

private:
	int tmp[44100 * 30][4] = {};
	int one;

	WAV head;
	WAVt headt = {
		//*:little endian
		'R','I','F','F', //byte ChunkID[4];//"RIFF"
		0,               //ChunkSize;      //*
		'W','A','V','E', //Format[4];      //"WAVE"
		'f','m','t',' ', //Subchunk1ID[4]; //"fmt "
		16,              //Subchunk1Size;  //*
		1,               //AudioFormat;    //*, 1:pcm(pulse code modulation)
		2,               //NumChannels;    //*, 1:mono, 2:stereo
		44100,           //SampleRate;     //*
		176400,          //ByteRate;       //*
		4,               //BlockAlign;     //*
		16,              //BitsPerSample;  //*
		'd','a','t','a', //Subchunk2ID[4]; //"data"
		0                //Subchunk2Size;  //*
	};
	byte buffer[4];
	int ch, sz;
	bool play = false;
	FILE* file;

	void setHeader() {
		headt.Subchunk2Size = (int)(headt.ByteRate * (duration / 1000.0));
		headt.ChunkSize = headt.Subchunk2Size + 36;

		nb = (headt.Subchunk2Size) / headt.BlockAlign;
		ch = headt.NumChannels;
		sz = headt.BlockAlign / ch;
	}

	int s2s(int msec) {
		return int(headt.SampleRate * msec/1000.0);
	}
};

Audio audiotmp = Audio(500, 0);
Audio audiotmp2 = Audio(500, 0);

class Track {
public:
	int barNum;

	Track(int bn, int nd, int noten) {
		barNum = bn+2;
		one = nd;
		noteNum = noten;

		audiotmp.startDelay = 0;
		audiotmp.SetOne(nd);
		audiotmp.SetDuration(one * noteNum);

		for (int i = 0; i < 102; i++) {
			bars.push_back(audiotmp);
		}

		setHeader();
		setNotes();
	}

	void BarNum(int bn) {
		audiotmp.startDelay = 0;
		audiotmp.SetOne(barDuration);
		audiotmp.SetDuration(one * noteNum);

		int nbarNum = bn+2;
		if (nbarNum < barNum) {
			for (int i = 0; i < barNum - nbarNum; i++) {
				bars.pop_back();
			}
			bars[nbarNum - 1] = audiotmp;
		}
		else {
			for (int i = 0; i < nbarNum - barNum; i++) {
				bars.push_back(audiotmp);
			}
		}
		barNum = nbarNum;
		setHeader();
	}

	void noteDuration(int bd) {
		one = bd;
		setHeader();
	}

	void NoteNum(int nn) {
		noteNum = nn;
		setHeader();
	}

	void Insert(int barn, double start, double len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		bars[barn].InsertL(int(one * max(start-len,0)), int(one * len), n, w, vol, channel);
		notes[barn].insert({barn,start,len,-1,n,w,vol,channel});
	}

	void Insert(int barn, double start, double len, double playlen, note n, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		bars[barn].InsertL(int(one * max(start - len, 0)), int(playlen * one), n, w, vol, channel);
		notes[barn].insert({barn,start,len,playlen,n,w,vol,channel});
	}

	void InsertH(int barn, double start, double len, vector<note> ns, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		int s = ns.size();
		for (int i = 0; i < s; i++) {
			Insert(barn, start, len, ns[i], w, vol, channel);
			notes[barn].insert({barn,start,len,-1,ns[i],w,vol,channel});
		}
	}

	void InsertH(int barn, double start, double len, double playlen, vector<note> ns, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		int s = ns.size();
		for (int i = 0; i < s; i++) {
			Insert(barn, start, len, playlen, ns[i], w, vol, channel);
			notes[barn].insert({barn,start,len,playlen,ns[i],w,vol,channel});
		}
	}

	void Remove(int barn, double start, double len, note n, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		bars[barn].RemoveL(int(one * max(start - len, 0)), int(one * len), n, w, vol, channel);
		notes[barn].erase({barn,start,len,-1,n,w,vol,channel});
	}

	void Remove(int barn, double start, double len, double playlen, note n, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		bars[barn].RemoveL(int(one * max(start - len, 0)), int(playlen * one), n, w, vol, channel);
		notes[barn].erase({barn,start,len,playlen,n,w,vol,channel});
	}

	void RemoveH(int barn, double start, double len, vector<note> ns, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		int s = ns.size();
		for (int i = 0; i < s; i++) {
			Remove(barn, start, len, ns[i], w, vol, channel);
			notes[barn].erase({barn,start,len,-1,ns[i],w,vol,channel});
		}
	}

	void RemoveH(int barn, double start, double len, double playlen, vector<note> ns, waveform w = def, double vol = MAX, int channel = -1) {
		if (barn >= barNum) return;
		int s = ns.size();
		for (int i = 0; i < s; i++) {
			Remove(barn, start, len, playlen, ns[i], w, vol, channel);
			notes[barn].erase({barn,start,len,playlen,ns[i],w,vol,channel});
		}
	}

	void CopyPaste(int barn, int to) {
		if (barn == to) return;
		copy = notes[barn];
		for (auto i = copy.begin(); i != copy.end(); i++) {
			Note n = *i;
			if (n.playlen < 0) Insert(to, n.start, n.len, (note)n.n, (waveform)n.w, n.vol, n.channel);
			else Insert(to, n.start, n.len, n.playlen, (note)n.n, (waveform)n.w, n.vol, n.channel);
		}
	}

	void PlayBar(int barn) {
		if (barn >= barNum) return;
		bars[barn].Export("tmp\\tmp.wav");
		PlaySound(TEXT("tmp\\tmp.wav"), NULL, SND_FILENAME);
	}

	void PlayFull() {
		Export("tmp\\tmp.wav", false);
		PlaySound(TEXT("tmp\\tmp.wav"), NULL, SND_FILENAME);
	}

	void DrawBar(int barn, bool all = false, note mn = g1, note mx = g6) {
		if (barn >= barNum) return;
		set<Note> ns = notes[barn];
		int low = g7s, high = c1;
		for (auto i = ns.begin(); i != ns.end(); i++) {
			low = min(low, (*i).n);
			high = max(high, (*i).n);
		}
		if (all) {
			low = mn;
			high = mx;
		}

		int sheet[84][128] = {};
		for (auto i = ns.begin(); i != ns.end(); i++) {
			int n = (*i).n;
			int len = (int)(16 * (*i).len);
			if ((*i).playlen != -1) len = (int)(16 * (*i).playlen);
			int start = (int)(16 * ((*i).start - (*i).len));
			int w = (*i).w;
			for (int j = start; j < start + len; j++) {
				sheet[n][j] = w+1;
			}
		}

		cout << "\n";
		cout << "Bar Number: " << barn << "\n\n";
		for (int i = high; i >= low; i--) {
			string s = n2s((note)i);
			if (s.length() == 2) cout << s << "  ";
			else cout << s << " ";
			for (int j = 0; j < noteNum * 16; j++) {
				if (sheet[i][j]) cout << w2c((waveform)(sheet[i][j] - 1));
				else cout << "-";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	void Save(string name) {
		string nn = "save\\";
		nn += name;
		
		int num = 0;
		for (int i = 0; i < barNum; i++) {
			set<Note> s = notes[i];
			for (auto j = s.begin(); j != s.end(); j++) {
				num++;
			}
		}

		ofstream sfile(nn);
		if (sfile.is_open()) {
			sfile << barNum-2 << "\n";
			sfile << num << "\n";
			for (int i = 0; i < barNum; i++) {
				set<Note> s = notes[i];
				for (auto j = s.begin(); j != s.end(); j++) {
					Note n = *j;
					sfile << n.barn << " " << n.start << " " << n.len << " ";
					sfile << n.playlen << " " << n.n << " " << n.w << " " << n.vol << " " << n.channel << "\n";
				}
			}
			sfile.close();
		}
	}

	void Import(string name) {
		setBars();
		setNotes();

		string nn = "save\\";
		nn += name;

		ifstream sfile(nn);
		if (sfile.is_open()) {
			int k;
			sfile >> k;
			BarNum(k);
			int num;
			sfile >> num;
			for (int i = 0; i < num; i++) {
				int bn, no, wa, ch;
				double st, ln, plt, vol;
				sfile >> bn >> st >> ln >> plt >> no >> wa >> vol >> ch;
				if(plt<0) Insert(bn, st, ln, (note)no, (waveform)wa, vol, ch);
				else Insert(bn, st, ln, plt, (note)no, (waveform)wa, vol, ch);
			}
			sfile.close();
		}
	}

	void Export(string name, bool f = true) {
		//printf("%d %d\n", headt.Subchunk2Size, headt.ChunkSize);

		string nn = "";
		if (f) nn = "sound\\";
		nn += name;

		fopen_s(&file, nn.c_str(), "wb");
		head = writeheader(headt);
		fwrite(&head, sizeof(head), 1, file);

		int t = 0;
		for (int i = 0; i < barNum; i++) {
			for (int j = 0; j < bars[i].nb; j++) {
				for (int k = 0; k < ch; k++) {
					pcm[t][k] = bars[i].pcm[j][k];
					lew(buffer, pcm[t][k], sz);
					fwrite(buffer, sz, 1, file);
				}
				t++;
			}
		}
		fclose(file);
	}

private:
	vector<Audio> bars;
	set<Note> notes[100];
	set<Note> copy;

	int barDuration, one, noteNum;

	int pcm[44100 * 1000][4];
	WAV head;
	WAVt headt = {
		//*:little endian
		'R','I','F','F', //byte ChunkID[4];//"RIFF"
		0,               //ChunkSize;      //*
		'W','A','V','E', //Format[4];      //"WAVE"
		'f','m','t',' ', //Subchunk1ID[4]; //"fmt "
		16,              //Subchunk1Size;  //*
		1,               //AudioFormat;    //*, 1:pcm(pulse code modulation)
		2,               //NumChannels;    //*, 1:mono, 2:stereo
		44100,           //SampleRate;     //*
		176400,          //ByteRate;       //*
		4,               //BlockAlign;     //*
		16,              //BitsPerSample;  //*
		'd','a','t','a', //Subchunk2ID[4]; //"data"
		0                //Subchunk2Size;  //*
	};
	byte buffer[4];
	int duration, nb, ch, sz;
	FILE* file;

	void setNotes() {
		for (int i = 0; i < barNum; i++) {
			notes[i].clear();
		}
	}

	void setBars() {
		bars.clear();

		audiotmp.startDelay = 0;
		audiotmp.SetOne(barDuration);
		audiotmp.SetDuration(one * noteNum);

		for (int i = 0; i < 102; i++) {
			bars.push_back(audiotmp);
		}
	}

	void setHeader() {
		barDuration = one * noteNum;
		duration = barNum * barDuration;

		headt.Subchunk2Size = (int)(headt.ByteRate * (duration / 1000.0));
		headt.ChunkSize = headt.Subchunk2Size + 36;

		nb = (headt.Subchunk2Size) / headt.BlockAlign;
		ch = headt.NumChannels;
		sz = headt.BlockAlign / ch;
	}

	int s2s(int msec) {
		return int(headt.SampleRate * msec / 1000.0);
	}
};
