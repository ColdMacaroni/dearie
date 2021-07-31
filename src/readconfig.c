#include <stdio.h>
#include <stdlib.h>

#include "readconfig.h"
#include "program_info.h"

config_t defaultConfig(void)
{
    char entries_dir[BUFSIZ];
    char entries_path[] = PRGRM_NAME"/entries";

    // Try to get where to store the stuff
    char *home_dir = getenv("XDG_DATA_HOME");

    // If XDG_DATA_HOME doesnt exist
    if (home_dir == NULL)
    {
        char *home_dir = getenv("HOME");

        // If there is no HOME for some reason
        if (home_dir == NULL)
        {
            fprintf(stderr, "There is no $XDG_DATA_HOME or $HOME environment variable. You should probably do something about that.");
            exit(EXIT_FAILURE);
        }
        // FOR HOME
        snprintf(entries_dir, BUFSIZ,
                 "%s/Documents/%s", home_dir, entries_path);
    }
    else
    {
        // FOR XDG DATA DIR
        snprintf(entries_dir, BUFSIZ, "%s/%s", home_dir, entries_path);
    }

    config_t default_config = {
        .entries_dir = entries_dir,
        .twelve_hours = false,
        .template_str = "$(date)\n---"
    };

    return default_config;
}

config_t readConfig(char *config_path)
{
    // Load default config
    config_t config = defaultConfig();

    return config;
}
