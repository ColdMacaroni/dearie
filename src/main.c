#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "readconfig.h"

int
main(int argc, char **argv)
{
    char config_path[BUFSIZ];
    sprintf(config_path, "%s/.config/PGM_NAME/")

    // Go through arguments and stuff
    {
        char *current_arg;
        for (int arg = 0; arv < argc; arg++)
        {
            if (argv[arg][0] == '-')
        }
    }

    config_t config = readConfig(config_path);
    printf("Entries dir: %s\n12hr format: %s\nTemplate: %s\n",
            config.entries_dir,
            (config.twelve_hours) ? "true" : "false",
            config.template_str);
}
