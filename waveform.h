#pragma once
#include <cmath>

const double PI = 3.14159265358979;

enum waveform {def,bell,sawtooth,triangle,smoothtooth,piano,test};
char wavenote[] = { 'D','B','T','A','S','P','X' };
string wavename[] = { "def","bell","sawtooth","triangle","smoothtooth","piano","test" };
int wavelen = 7;

char w2c(waveform w) {
	return wavenote[w];
}

string w2s(waveform w) {
	return wavename[w];
}

double smin(double a, double b, double k) {
	return -log(exp(-k * a) + exp(-k * b)) / k;
}

double smax(double a, double b, double k) {
	return log(exp(k * a) + exp(k * b)) / k;
}

double deff(double phase) {
	return sin(phase);
}

double bellf(double phase) {
	return sin(phase) * pow(0.9, phase / 100);
}

double sawtoothf(double phase) {
	while (phase >= 0) phase -= 2 * PI;
	return (1 / PI) * phase - 1;
}

double smoothtoothf(double phase) {
	return smax(smin(3 * sin(phase), 1, 10), -1, 10);
}

double trianglef(double phase) {
	while (phase >= 0) phase -= 2 * PI;
	if (phase < PI / 2) return -2 / PI * phase;
	else if (PI / 2 <= phase && phase < 3 * PI / 2) return 2 / PI * phase;
	else return -2 / PI * phase + 4;
}

double pianof(double phase) {
	double x = 0.4 * 0.7 * sin(phase / 2) * exp(-0.001 * phase);
	x += 0.6 * 0.7 * sin(phase) * exp(-0.001 * phase);
	x += x * x * x;
	return x;
}

double testf(double phase) {
	return cos(phase);
}

double sound(waveform form, double phase) {
	if (form == 0) return deff(phase);
	else if (form == 1) return bellf(phase);
	else if (form == 2) return sawtoothf(phase);
	else if (form == 3) return trianglef(phase);
	else if (form == 4) return smoothtoothf(phase);
	else if (form == 5) return pianof(phase);
	else return testf(phase);
}