#ifndef RUNNER_H 
#define RUNNER_H

class RunAbstract {
private:
    /******* attributes ******/

public:
    /****** constructor ******/
    RunAbstract() {}

    /****** fundemental functions *****/
    virtual void run()= 0;
};

#endif