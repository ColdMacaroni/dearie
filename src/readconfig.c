#include <stdio.h>
#include <stdlib.h>
#include "readconfig.h"

config_t defaultConfig(void)
{
    char *entries_dir;

    // Try to get where to store the stuff
    char *home_dir = getenv("XDG_DATA_HOME");
    if (home_dir == NULL)
    {
        char *home_dir = getenv("HOME");
        if (home_dir == NULL)
        {
            fprintf(stderr, "There is no $XDG_DATA_HOME or $HOME environment variable");
            exit(EXIT_FAILURE);
        }
    }



    snprintf(entries_dir, BUFSIZ, "owo");

    config_t default_config = {
        .entries_dir = "",
        .twelve_hours = false,
        .template_str = "$(date)\n---"
    };

    return default_config;
}

config_t readConfig(char *config_path)
{
    

}
