#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "readconfig.h"
#include "program_info.h"

int
main(int argc, char **argv)
{
    // Set the default config file
    char config_file[BUFSIZ];
    sprintf(config_file, "%s/.config/"PRGRM_NAME"/config", getenv("HOME"));

    // Go through arguments and stuff
    {
        char *current_arg;
        for (int arg = 0; arg < argc; arg++)
        {
            if (argv[arg][0] == '-');
        }
    }

    config_t config = readConfig(config_file);
    printf("Config file: %s\n"
           "Entries dir: %s\n"
           "12hr format: %s\n"
           "Template: %s\n",
            config_file,
            config.entries_dir,
            (config.twelve_hours) ? "true" : "false",
            config.template_str);
}
