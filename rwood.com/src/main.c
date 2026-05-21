#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool EnhMode = true;
bool MMX = false;
bool SMPCHK = true;
bool PAE = false;
bool PAECHK = true;
bool SMP = false;
bool Safe = false;
bool flog = false;

bool ShowUsage = false;

int main(int argc, char const *argv[])
{
    int i;
    // First we gotta check the arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "/?") == 0) {
            ShowUsage = true;
        }
        if (strcmp(argv[i], "/flog") == 0) {
            flog = true;
        }
        if (strcmp(argv[i], "/safe") == 0) {
            Safe = true;
        }
        if (strcmp(argv[i], "/SMP") == 0) {
            SMP = true;
        }
        if (strcmp(argv[i], "/PAE") == 0) {
            PAE = true;
        }
        if (strcmp(argv[i], "/MMX") == 0) {
            MMX = true;
        }
        if (strcmp(argv[i], "/noPAE") == 0) {
            PAE = false;
            PAECHK = false;
        }
        if (strcmp(argv[i], "/noSMP") == 0) {
            SMP = false;
            SMPCHK = false;
        }
        if (strcmp(argv[i], "/3") == 0) {
            EnhMode = true;
        }
    }

    // Display help
    if (ShowUsage) {
        printf("USAGE: RWOOD.COM [options]\n");
        printf("   /3        Force running in 386 Enhanced Mode\n");
        printf("   /MMX      Force running in Pentium(R) MMX Enhanced Mode\n\n\n\n");
        printf("   /PAE      Force using PAE. Requires HIMEMSX\n");
        printf("   /noPAE    Force-disable PAE\n");
        printf("   /SMP      Force using SMP. Requires a multi-core CPU or multiple CPUs\n");
        printf("   /noSMP    Force-disable SMP\n\n\n\n");
        printf("   /safe     Run in safe mode, no third-party drivers, only standard RollingWOOD ones\n");
        printf("   /flog     Log to the file C:\\RLNGWOOD\\SYSTEM\\BOOT.LOG\n");
        return 0;
    }

    return 0;
}
