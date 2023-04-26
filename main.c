#include "main.h"

int main(int argc, char **argv, char **env)
{
        if (argc == 1)
	{
		shell_prompt(argv, env);
	}
        return (0);
}
