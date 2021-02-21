#ifndef COMMAND_H
#define COMMAND_H


class command
{
    public:
        char* Header();
        char* Settings();
        char* Options();
        char* FolderSync(char* device, char* poststring);
        char* Provision();
        char* Search();
        void Sync();

    protected:

    private:


};

#endif // COMMAND_H
