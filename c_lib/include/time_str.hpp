#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>

#include <unistd.h>
#include <signal.h>
#include <time.h>

class time_str {
  private:
  public:
    static char _buffer[26u];

    time_str() {}

    ~time_str() {
        free(_buffer);
    }

    static char* get_time_str() {
        time_t now = time(NULL);
        strftime(time_str::_buffer, 26, "%Y-%m-%d %H:%M:%S", localtime(&now));
        return time_str::_buffer;
    }
};

char time_str::_buffer[26u] = "";