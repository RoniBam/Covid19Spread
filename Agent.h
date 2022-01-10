//
// Created by Roni Bam on 14/02/2021.
//

#ifndef ASSIGNMENT1_AGENT_H
#define ASSIGNMENT1_AGENT_H

#endif //ASSIGNMENT1_AGENT_H
#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Tree.h"

class Agent{
public:
    Agent();

    virtual void act(Session& session)=0;
    virtual Agent * clone() const =0;
    virtual ~Agent();
};

class ContactTracer: public Agent{
public:
    ContactTracer();

    virtual void act(Session& session);
    virtual ContactTracer* clone() const ;
    virtual ~ContactTracer();
};


class Virus: public Agent{
public:
    Virus(int nodeInd);
    virtual void act(Session& session);
    Virus* clone() const;
    virtual ~Virus();

private:
    const int nodeInd;
};

#endif