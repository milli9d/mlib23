/**
 * @brief Generic Test Bench to experiment and learn with components
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>

#include <unistd.h>
#include <signal.h>
#include <time.h>

#include <sys/time.h>

#include "time_str.hpp"
#include "colors.h"

void timer_callback(int signum) {
    printf(COLOR_HIGH_GREEN "INFO: " COLOR_RESET "Signal triggered at %s\n", time_str::get_time_str());
}

int main(int argc, char** argv) {
    printf("Signal test started at %s\n", time_str::get_time_str());

    signal(SIGALRM, timer_callback);

    struct itimerval timer;

    timer.it_value.tv_sec = 1u;
    timer.it_value.tv_usec = 0u;

    timer.it_interval.tv_sec = 1u;
    timer.it_interval.tv_usec = 0u;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (sleep(10u) != 0) {}

    return 0;
}