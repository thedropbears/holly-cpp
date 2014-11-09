#ifndef FINDTARGET
#define FINDTARGET

class FindTarget: public Command {
    public:
        
    private:
        const int directions[] = {0, 22, -22, 45, -45};
        int cmd_no = 0;
        void Execute();
        bool isFinished();
        void
};

#endif
