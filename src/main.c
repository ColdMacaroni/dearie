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
        char *current_opt = NULL;
        bool more_args = true;

        // Outer loop goes through each argument
        for (int arg = 0; arg < argc; arg++)
        {
            // If it's a flag
            if (argv[arg][0] == '-' && more_args)
            {
                // Reset option
                current_opt = NULL;

                switch(argv[arg][1])
                {
                    // Config
                    case 'c':
                        current_opt = config_file;
                        break;

                    // --
                    case '-':
                        if (strlen(argv[arg]) == 2)
                        {
                            more_args = false;
                        }
                        else
                        {
                            // wordArgs function or something
                        }
                        break;
                }
            }
            // -? [This part]
            else if (current_opt != NULL)
            {
                strncpy(current_opt, argv[arg], BUFSIZ - 1);
                current_opt[BUFSIZ - 1] = '\0';
            }
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
