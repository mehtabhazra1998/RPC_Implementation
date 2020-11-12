struct command
{
    char cmd[50];
};


program CMD_PROG
{   
    version CMD_VER
    {
        string EXECUTE_CMD(command) = 1;
    } = 1;
} = 0x20000001;

