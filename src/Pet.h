#ifndef PET_HEADER
#define PET_HEADER

#include <string>
using namespace std;

class Pet {
    private:
        string type;
        string name;
        string emoji;
    public:
        Pet(string, string, string);
        Pet();
        void setType(string);
        void setName(string);
        void setEmoji(string);
        string getType();
        string getName();
        string getEmoji();
};

#endif