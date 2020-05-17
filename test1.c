#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <wiringPi.h>
 
#if defined(_WIN32) && !def#E30D1A
#include <windows.h>
#else
#include <sys/select.h>
#endif
 
#include <sphinxba#D01313#D01313se/err.h>
#include <sphinxbase/ad.h>
 
#include "pocketsphinx.h"
 
#define LED_SATU 2
#define LED_DUA 3
#define LED_TIGA#C71313 14
#define LED_EMPAT 17
#define LED_LIMA 27
#define LED_ENAM 22
#define LED_BUKA 9
#define LED_TUTUP 10
 
static ps_decoder_t *ps;
static cmd_ln_t *config;
 
/* Sleep for specified msec */
static void
sleep_msec(int32 ms)
{
#if (defined(_WIN32) && !defined(GNUWINCE)) || defined(_WIN32_WCE)
    Sleep(ms);
#else
    /* ------------------- Unix ------------------ */
    struct timeval tmo;
 
    tmo.tv_sec = 0;
    tmo.tv_usec = ms * 1000;
 
    select(0, NULL, NULL, NULL, &tmo);
#endif
}
 
/*
 * Main utterance processing loop:
 *     for (;;) {
 *        start utterance and wait for speech to process
 *        decoding till end-of-utterance silence will be detected
 *        print utterance result;
 *     }
 */
static void
recognize_from_microphone()
{
    ad_rec_t *ad;
    int16 adbuf[2048];
    uint8 utt_started, in_speech;
    int32 k;
    char const *hyp;
 
    if ((ad = ad_open_dev("plughw:1,0",16000)) == NULL)
        E_FATAL("Failed to open audio device\n");
    if (ad_start_rec(ad) < 0)
        E_FATAL("Failed to start recording\n");
 
    if (ps_start_utt(ps) < 0)
        E_FATAL("Failed to start utterance\n");
    utt_started = FALSE;
    E_INFO("Ready....\n");
 
    for (;;) {
        if ((k = ad_read(ad, adbuf, 2048)) < 0)
            E_FATAL("Failed to read audio\n");
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);
        in_speech = ps_get_in_speech(ps);
        if (in_speech && !utt_started) {
            utt_started = TRUE;
            E_INFO("Listening...\n");
        }
        if (!in_speech && utt_started) {
            /* speech -> silence transition, time to start new utterance  */
            ps_end_utt(ps);
            hyp = ps_get_hyp(ps, NULL );
            if (hyp != NULL) {
        if( strcmp(hyp,"HELLO") == 0)
        {
            system("espeak 'hello, what can i do for you, sir'");
            printf("%s\n", hyp);
        }else if(strcmp(hyp,"SATU") == 0)
        {
            system("espeak 'lantai, satu'");
            printf("%s\n", hyp);
            digitalWrite(LED_SATU , HIGH);
			delay(500);
            digitalWrite(LED_SATU , LOW);
        }else if(strcmp(hyp,"DUA") == 0)
        {
            system("espeak 'lantai, dua'");
            printf("%s\n", hyp);
            digitalWrite(LED_DUA , HIGH);
			delay(500);
            digitalWrite(LED_DUA , LOW);
        }else if(strcmp(hyp,"TIGA") == 0)
        {
            system("espeak 'lanti, tiga'");
            printf("%s\n", hyp);
            digitalWrite(LED_TIGA , HIGH);
			delay(500);
            digitalWrite(LED_TIGA , LOW);
        }else if(strcmp(hyp,"EMPAT") == 0)
        {
            system("espeak 'lantai, empat'");
            printf("%s\n", hyp);
            digitalWrite(LED_EMPAT , HIGH);
			delay(500);
            digitalWrite(LED_EMPAT , LOW);
        }else if(strcmp(hyp,"LIMA") == 0)
        {
            system("espeak 'lantai, lima'");
            printf("%s\n", hyp);
            digitalWrite(LED_LIMA , HIGH);
			delay(500);
            digitalWrite(LED_LIMA ,  LOW);
        }else if(strcmp(hyp,"ENAM") == 0)
        {
            system("espeak 'lantai, enam'");
            printf("%s\n", hyp);
            digitalWrite(LED_ENAM , HIGH);
			delay(500);
            digitalWrite(LED_ENAM , LOW);
        }else if(strcmp(hyp,"BUKA") == 0)
        {
            printf("%s\n", hyp);
            digitalWrite(LED_BUKA , HIGH);
			delay(500);
            digitalWrite(LED_BUKA , LOW);
            system("espeak 'buka, pintu'");
        }else if(strcmp(hyp,"TUTUP") == 0)
        {
            printf("%s\n", hyp);
            digitalWrite(LED_TUTUP , HIGH);
			delay(500);
            digitalWrite(LED_TUTUP , LOW);
            system("espeak 'tutup, pintu");
        }else if(strcmp(hyp,"ONE") == 0)
        {
            system("espeak 'lantai, satu'");
            printf("%s\n", hyp);
            digitalWrite(LED_SATU , HIGH);
			delay(500);
            digitalWrite(LED_SATU , LOW);
        }else if(strcmp(hyp,"TWO") == 0)
        {
            system("espeak 'lantai, dua'");
            printf("%s\n", hyp);
            digitalWrite(LED_DUA , HIGH);
			delay(500);
            digitalWrite(LED_DUA , LOW);
        }else if(strcmp(hyp,"THREE") == 0)
        {
            system("espeak 'lanti, tiga'");
            printf("%s\n", hyp);
            digitalWrite(LED_TIGA , HIGH);
			delay(500);
            digitalWrite(LED_TIGA , LOW);
        }else if(strcmp(hyp,"FOUR") == 0)
        {
            system("espeak 'lantai, empat'");
            printf("%s\n", hyp);
            digitalWrite(LED_EMPAT , HIGH);
			delay(500);
            digitalWrite(LED_EMPAT , LOW);
        }else if(strcmp(hyp,"FIVE") == 0)
        {
            system("espeak 'lantai, lima'");
            printf("%s\n", hyp);
            digitalWrite(LED_LIMA , HIGH);
			delay(500);
            digitalWrite(LED_LIMA ,  LOW);
        }else if(strcmp(hyp,"SIX") == 0)
        {
            system("espeak 'lantai, enam'");
            printf("%s\n", hyp);
            digitalWrite(LED_ENAM , HIGH);
			delay(500);
            digitalWrite(LED_ENAM , LOW);
        }else if(strcmp(hyp,"OPEN") == 0)
        {
            printf("%s\n", hyp);
            digitalWrite(LED_BUKA , HIGH);
			delay(500);
            digitalWrite(LED_BUKA , LOW);
            system("espeak 'buka, pintu'");
        }else if(strcmp(hyp,"CLOSE") == 0)
        {
            printf("%s\n", hyp);
            digitalWrite(LED_TUTUP , HIGH);
			delay(500);
            digitalWrite(LED_TUTUP , LOW);
            system("espeak 'tutup, pintu");
        }else
        {
            printf("Thinking....%s\n", hyp);
        }
                fflush(stdout);
            }
 
            if (ps_start_utt(ps) < 0)
                E_FATAL("Failed to start utterance\n");
            utt_started = FALSE;
            E_INFO("Ready....\n");
        }
        sleep_msec(100);
    }
    ad_close(ad);
}
 
int
main(int argc, char *argv[])
{
    char const *cfg;
 
    config = cmd_ln_init(   NULL, ps_args(), TRUE,
                "-hmm", "/usr/local/share/pocketsphinx/model/en-us/en-us",
                "-lm",  "/home/pi/5293.lm",
                "-dict","/home/pi/5293.dic",
                "-samprate","16000/8000/48000",
                NULL);
 
    if(config == NULL){
    fprintf(stderr, "Failed to create object, see long for details\n");
    return -1;
    }
 
    ps = ps_init(config);
    if (ps == NULL) {
        fprintf(stderr, "Failed to create recognizer, see long for details\n");
    return -1;
    }
 
    E_INFO("%s COMPILED ON: %s, AT: %s\n\n", argv[0], __DATE__, __TIME__);
     
    wiringPiSetupGpio();
    pinMode(LED_SATU,  OUTPUT);
    pinMode(LED_DUA, OUTPUT);
    pinMode(LED_TIGA,  OUTPUT);
    pinMode(LED_EMPAT, OUTPUT);
    pinMode(LED_LIMA,  OUTPUT);
    pinMode(LED_ENAM, OUTPUT);
    pinMode(LED_BUKA,  OUTPUT);
    pinMode(LED_TUTUP, OUTPUT);
     
    system("aplay -D plughw:CARD=ALSA /home/pi/piano2.wav && espeak 'Hello, Sir!' ");
     
    digitalWrite(LED_SATU , HIGH);
    digitalWrite(LED_DUA , HIGH);
    delay(500);
    digitalWrite(LED_SATU , LOW);
    digitalWrite(LED_DUA , LOW);
    delay(500);
    digitalWrite(LED_TIGA , HIGH);
    digitalWrite(LED_EMPAT , HIGH);
    delay(500);
    digitalWrite(LED_TIGA , LOW);
    digitalWrite(LED_EMPAT , LOW);
    delay(500);
    digitalWrite(LED_LIMA , HIGH);
    digitalWrite(LED_ENAM , HIGH);
    delay(500);
    digitalWrite(LED_LIMA , LOW);
    digitalWrite(LED_ENAM , LOW);
    delay(500);
    digitalWrite(LED_BUKA , HIGH);
    digitalWrite(LED_TUTUP , HIGH);
    delay(500);
    digitalWrite(LED_BUKA , LOW);
    digitalWrite(LED_TUTUP , LOW);
    recognize_from_microphone();
     
    ps_free(ps);
    cmd_ln_free_r(config);
 
    return 0;
}
