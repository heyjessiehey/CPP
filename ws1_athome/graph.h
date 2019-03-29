//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Jan 23 2018

#ifndef SICT_GRAPH_H_
#define SICT_GRAPH_H_

#define MAX_NO_OF_SAMPLES 20

namespace sict {
    void getSamples(int samples[], int noOfSamples);

    int findMax(int samples[], int noOfSamples);

    void printBar(int val, int max);

    void printGraph(int samples[], int noOfSamples);
}
#endif
