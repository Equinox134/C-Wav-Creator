// Audio Maker.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <cstdio>
#include <cmath>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "winmm.lib")

#include "waveform.h"
#include "audio.h"

Track track = Track(2, 600, 3);

void SnowdinTownTrack() {
    vector<note> h = { d4s,c4,g3s };

    //bar 1
    track.Insert(1, 1.0 / 2, 1.0 / 2, d6s, bell);
    track.Insert(1, 1.0, 1.0 / 2, d5s, bell);
    track.Insert(1, 3.0 / 2, 1.0 / 2, g5s, bell);
    track.Insert(1, 2.0, 1.0 / 2, d5s, bell);
    track.Insert(1, 5.0 / 2, 1.0 / 2, 1.0, a5s, bell);
    track.Insert(1, 15.0 / 4, 1.0 / 4, g5s, bell);
    track.Insert(1, 4.0, 1.0 / 4, a5s, bell);

    track.Insert(1, 1.0 / 2, 1.0 / 2, c4s, bell);
    track.Insert(1, 1.0, 1.0 / 2, c5s, bell);
    track.Insert(1, 3.0 / 2, 1.0 / 2, g4s, bell);
    track.Insert(1, 2.0, 1.0 / 2, c5s, bell);
    track.Insert(1, 5.0 / 2, 1.0 / 2, 1.0, c4, bell);

    //bar 2
    track.Insert(2, 1.0 / 2, 1.0 / 2, c6, bell);
    track.Insert(2, 1.0, 1.0 / 2, g5s, bell);
    track.Insert(2, 3.0 / 2, 1.0 / 2, d5s, bell);
    track.Insert(2, 2.0, 1.0 / 2, 1.0, c5, bell);
    track.Insert(2, 3.0, 1.0 / 2, c5s, bell);
    track.Insert(2, 4.0, 1.0, d5s, bell);

    track.Insert(2, 1.0 / 2, 1.0 / 2, a3s, bell);
    track.Insert(2, 1.0, 1.0 / 2, g4s, bell);
    track.Insert(2, 3.0 / 2, 1.0 / 2, c5, bell);
    h = { d4s, c4, g3s };
    track.InsertH(2, 2.0, 1.0 / 2, 3.0 / 2, h, bell);
    h = { f4, c4s, a3s };
    track.InsertH(2, 4.0, 1.0, h, bell);

    //bar 3
    track.Insert(3, 1.0 / 2, 1.0 / 2, d6s, bell);
    track.Insert(3, 1.0, 1.0 / 2, d5s, bell);
    track.Insert(3, 3.0 / 2, 1.0 / 2, g5s, bell);
    track.Insert(3, 2.0, 1.0 / 2, d5s, bell);
    track.Insert(3, 5.0 / 2, 1.0 / 2, 1.0, a5s, bell);
    track.Insert(3, 15.0 / 4, 1.0 / 4, g5s, bell);
    track.Insert(3, 4.0, 1.0 / 4, a5s, bell);

    track.Insert(3, 1.0 / 2, 1.0 / 2, c4s, bell);
    track.Insert(3, 1.0, 1.0 / 2, c5s, bell);
    track.Insert(3, 3.0 / 2, 1.0 / 2, g4s, bell);
    track.Insert(3, 2.0, 1.0 / 2, c5s, bell);
    track.Insert(3, 5.0 / 2, 1.0 / 2, 1.0, c4, bell);

    //bar 4
    track.Insert(4, 1.0 / 2, 1.0 / 2, c6, bell);
    track.Insert(4, 1.0, 1.0 / 2, c6s, bell);
    track.Insert(4, 3.0 / 2, 1.0 / 2, c6, bell);
    track.Insert(4, 2.0, 1.0 / 2, 1.0, a5s, bell);
    track.Insert(4, 3.0, 1.0 / 2, c6, bell);
    track.Insert(4, 4.0, 1.0, g5s, bell);

    track.Insert(4, 1.0 / 2, 1.0 / 2, a3s, bell);
    track.Insert(4, 1.0, 1.0 / 2, g4s, bell);
    track.Insert(4, 3.0 / 2, 1.0 / 2, c5, bell);
    h = { a4s, g4, d4s };
    track.InsertH(4, 2.0, 1.0 / 2, 3.0 / 2, h, bell);
    h = { d5s, c5, g4s };
    track.InsertH(4, 4.0, 1.0, h, bell);

    //bar 5
    track.Insert(5, 1.0 / 2, 1.0 / 2, d6s, bell);
    track.Insert(5, 1.0, 1.0 / 2, d5s, bell);
    track.Insert(5, 3.0 / 2, 1.0 / 2, g5s, bell);
    track.Insert(5, 2.0, 1.0 / 2, d5s, bell);
    track.Insert(5, 5.0 / 2, 1.0 / 2, 1.0, a5s, bell);
    track.Insert(5, 15.0 / 4, 1.0 / 4, g5s, bell);
    track.Insert(5, 4.0, 1.0 / 4, a5s, bell);

    track.Insert(5, 1.0 / 2, 1.0 / 2, c4s, bell);
    track.Insert(5, 1.0, 1.0 / 2, c5s, bell);
    track.Insert(5, 3.0 / 2, 1.0 / 2, g4s, bell);
    track.Insert(5, 2.0, 1.0 / 2, c5s, bell);
    track.Insert(5, 5.0 / 2, 1.0 / 2, 1.0, c4, bell);

    //bar 6
    track.Insert(6, 1.0 / 2, 1.0 / 2, c6, bell);
    track.Insert(6, 1.0, 1.0 / 2, g5s, bell);
    track.Insert(6, 3.0 / 2, 1.0 / 2, d5s, bell);
    track.Insert(6, 2.0, 1.0 / 2, 1.0, c5, bell);
    track.Insert(6, 3.0, 1.0 / 2, c5s, bell);
    track.Insert(6, 4.0, 1.0, d5s, bell);

    track.Insert(6, 1.0 / 2, 1.0 / 2, a3s, bell);
    track.Insert(6, 1.0, 1.0 / 2, g4s, bell);
    track.Insert(6, 3.0 / 2, 1.0 / 2, c5, bell);
    h = { d4s, c4, g3s };
    track.InsertH(6, 2.0, 1.0 / 2, 3.0 / 2, h, bell);
    h = { f4, c4s, a3s };
    track.InsertH(6, 4.0, 1.0, h, bell);

    //bar 7
    track.Insert(7, 1.0 / 2, 1.0 / 2, d6s, bell);
    track.Insert(7, 1.0, 1.0 / 2, d5s, bell);
    track.Insert(7, 3.0 / 2, 1.0 / 2, g5s, bell);
    track.Insert(7, 2.0, 1.0 / 2, d5s, bell);
    track.Insert(7, 5.0 / 2, 1.0 / 2, 1.0, a5s, bell);
    track.Insert(7, 15.0 / 4, 1.0 / 4, g5s, bell);
    track.Insert(7, 4.0, 1.0 / 4, a5s, bell);

    track.Insert(7, 1.0 / 2, 1.0 / 2, c4s, bell);
    track.Insert(7, 1.0, 1.0 / 2, c5s, bell);
    track.Insert(7, 3.0 / 2, 1.0 / 2, g4s, bell);
    track.Insert(7, 2.0, 1.0 / 2, c5s, bell);
    track.Insert(7, 5.0 / 2, 1.0 / 2, 1.0, c4, bell);

    //bar 8
    track.Insert(8, 1.0 / 2, 1.0 / 2, c6, bell);
    track.Insert(8, 1.0, 1.0 / 2, c6s, bell);
    track.Insert(8, 3.0 / 2, 1.0 / 2, c6, bell);
    track.Insert(8, 2.0, 1.0 / 2, 5.0 / 2, a5s, bell);

    track.Insert(8, 1.0 / 2, 1.0 / 2, a3s, bell);
    track.Insert(8, 1.0, 1.0 / 2, g4s, bell);
    track.Insert(8, 3.0 / 2, 1.0 / 2, c5, bell);
    h = { a4s, g4, d4s };
    track.InsertH(8, 2.0, 1.0 / 2, 3.0 / 2, h, bell);
    h = { d5s, c5, g4s };
    track.InsertH(8, 4.0, 1.0, h, bell);
}

waveform cw = piano;
int bn = 1;

void command() {
    string cmd;
    cin >> cmd;
    if (cmd == "setb") {
        cin >> bn;
        cout << "Changed bar\n\n";
    }
    else if (cmd == "insert") {
        string n;
        double st, len, plt;
        cin >> st >> len >> plt >> n;

        if(plt<0) track.Insert(bn, st, len, s2n(n), cw);
        else track.Insert(bn, st, len, plt, s2n(n), cw);
        cout << "Track added\n\n";
    }
    else if (cmd == "remove") {
        string n;
        double st, len, plt;
        cin >> st >> len >> plt >> n;

        if (plt < 0) track.Remove(bn, st, len, s2n(n), cw);
        else track.Remove(bn, st, len, plt, s2n(n), cw);
        cout << "Track removed\n\n";
    }
    else if (cmd == "inserth") {
        int num;
        double st, len, plt;
        vector<note> ns;
        cin >> st >> len >> plt >> num;
        for (int i = 0; i < num; i++) {
            string s; cin >> s;
            ns.push_back(s2n(s));
        }

        if(plt<0) track.InsertH(bn, st, len, ns, cw);
        else track.InsertH(bn, st, len, plt, ns, cw);
        cout << "Harmonic added\n\n";
    }
    else if (cmd == "removeh") {
        int num;
        double st, len, plt;
        vector<note> ns;
        cin >> st >> len >> plt >> num;
        for (int i = 0; i < num; i++) {
            string s; cin >> s;
            ns.push_back(s2n(s));
        }

        if (plt < 0) track.RemoveH(bn, st, len, ns, cw);
        else track.RemoveH(bn, st, len, plt, ns, cw);
        cout << "Harmonic removed\n\n";
    }
    else if (cmd == "insertp") {
        int ch;
        string n;
        double st, len, plt, vol;
        cin >> st >> len >> plt >> n >> vol >> ch;

        track.Insert(bn, st, len, plt, s2n(n), cw, vol, ch);
        cout << "Track added\n\n";
    }
    else if (cmd == "change") {
        cout << "\n";
        for (int i = 0; i < wavelen; i++) {
            cout << i << ": " << w2s((waveform)i) << "\n";
        }
        int x; cin >> x;
        if (x >= wavelen) return;
        cw = (waveform)x;
        cout << "Sound changed\n\n";
    }
    else if (cmd == "draw") {
        int x; cin >> x;
        if (x >= track.barNum) return;
        track.DrawBar(x);
    }
    else if (cmd == "save") {
        string s; cin >> s;
        track.Save(s);
        cout << "Track saved\n\n";
    }
    else if (cmd == "export") {
        string s; cin >> s;
        track.Export(s);
        cout << "Track exported\n\n";
    }
    else if (cmd == "import") {
        string s; cin >> s;
        track.Import(s);
        cout << "Track imported\n\n";
    }
    else if (cmd == "print") {
        cout << bn << " " << w2s(cw) << " " << track.barNum - 2 << "\n\n";
    }
    else if (cmd == "add") {
        int x; cin >> x;
        track.BarNum(track.barNum - 2 + x);
        cout << "Bar number changed\n\n";
    }
    else if (cmd == "set") {
        int x; cin >> x;
        track.BarNum(x);
        cout << "Bar number changed\n\n";
    }
    else if (cmd == "play") {
        int x; cin >> x;
        if (x >= track.barNum) return;
        cout << "playing...\n\n";
        if (x > 0) track.PlayBar(x);
        else track.PlayFull();
    }
    else if (cmd == "cp") {
        int x, y; cin >> x >> y;
        track.CopyPaste(x, y);
        cout << "Copy Pasted\n\n";
    }
    else if (cmd == "x"||cmd=="exit") {
        exit(0);
    }
}

int main()
{
    while (1) {
        cout << ">> ";
        command();
    }
    
    printf("done\n");
}