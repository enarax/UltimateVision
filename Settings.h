#ifndef _SETTINGS_H
#define _SETTINGS_H

#ifdef WEBCAM
//webcam
#define BLURSIZE 3
#define MINVALUE 35
#define MINHUE 80
#define MAXHUE 90
#define MINSATURATION 120
#define MAXSATURATION 255
#else
//robotcam - TBD
#define BLURSIZE 3
#define MINVALUE 64
#define MINHUE 160
#define MAXHUE 200
#define MINSATURATION 50
#define MAXSATURATION 100
#endif

#endif