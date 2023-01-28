#ifndef COMMAND_H
#define COMMAND_H


class command
{
    public:
       unsigned char* Header();
       unsigned  char* Settings();
       unsigned char* Options();
       unsigned  char* FolderSync(char* device,  char* poststring);
       unsigned char* Provision();
       unsigned char* Search(char* device, unsigned char* poststring);
       unsigned  char* Sync(char* device,  unsigned char* poststring);
       unsigned char* Sendmail();

    protected:

    private:


};

#endif // COMMAND_H
