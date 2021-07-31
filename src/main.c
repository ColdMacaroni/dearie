#include <stdio.h>
#include "readconfig.h"

int
main(int argc, char **argv)
{
    config_t config = readConfig(NULL);
    printf("Entries dir: %s\n12hr format: %s\nTemplate: %s\n",
            config.entries_dir,
            (config.twelve_hours) ? "true" : "false",
            config.template_str);
}
