#ifndef READCONFIG
#define READCONFIG
#include <stdbool.h>
typedef struct config
{
    char *entries_dir;
    bool twelve_hours;
    char *template_str;
} config_t;

config_t defaultConfig(void);
config_t readConfig(char *config_path);

#endif
