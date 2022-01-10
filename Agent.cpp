//
// Created by Roni Bam on 14/02/2021.
//


#include "Agent.h"
#include <iostream>
class Graph;

Agent::Agent() = default;


Agent :: ~Agent() = default;

ContactTracer::ContactTracer() = default;

void ContactTracer::act(Session &session) {
    int infected = session.dequeueInfected();
    if (infected >= 0) {
        Tree *tree = session.getGraph()->BFS(infected, session);
        int toDisconnect = tree->traceTree();
        for (int i = 0; i < session.getGraph()->getMatrix().size(); ++i) {
            if (session.getGraph()->getMatrix()[toDisconnect][i] == 1) {
                session.getGraph()->removeEdge(toDisconnect, i);
            }
        }
        delete tree;
    }
}



ContactTracer * ContactTracer::clone() const {
    return new ContactTracer(*this)  ;
}

ContactTracer::~ContactTracer() = default;

Virus::Virus(int nodeInd) : nodeInd(nodeInd) {}

Virus::~Virus() = default;

void Virus::act(Session &session) {
    if (!session.getGraph()->isInfected(nodeInd)){
        session.enqueueInfected(nodeInd);
        session.getGraph()->infectNode(nodeInd);
    }
    for (int i = 0; i < session.getGraph()->getMatrix().size(); ++i) {
        if (session.getGraph()->getMatrix()[nodeInd][i]==1 && (!session.getGraph()->isCarrier(i))) {
            session.addAgent(Virus (i));
            session.getGraph()->spreadVirus(i);
            break;
        }
    }
}

Virus* Virus::clone() const  {
    return new Virus(*this);
}
