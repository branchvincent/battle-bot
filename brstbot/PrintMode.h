#ifndef PRINTMODE_H
#define PRINTMODE_H

class PrintMode {
    
    public:
        void setPrintChar(char c);
        void print();
        static PrintMode p;
    private:
        char printChar;
        bool inAppendMode;
};

#endif
