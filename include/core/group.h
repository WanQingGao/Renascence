/******************************************************************
   Copyright 2013, Jiang Xiao-tang

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
******************************************************************/
#ifndef EVOLUTION_GROUP
#define EVOLUTION_GROUP
#include <vector>
#include <iostream>
#include <fstream>
#include "genetic_operator.h"
using namespace std;

#define DEFAULT_FIT_EVOLUTION_GROUP "cache/fit.txt"
#define DEFAULT_OUTPUT_EVOLUTION_GROUP "output/result.txt"
#define PART_EVOLU 4

//Evolution group for general.
/*
class individual
{
private:
public:
    double fit_comput();
    inline double get_fit();
    void mutate();
    void print_f(ostream& output);
    void print();//可选
    static void data_input();//Load data
    static void destroy();//Free data
};
*/
template <class individual>
class evolution_group
{
private:
    vector<individual*> group; 
    individual* best;
    group_select<individual> sel;//The type of group_select operator
    mutation<individual> var;//The type of vary operator
    cross<individual> cro;//The type of crossover operator
public:
    evolution_group(const int scale=20,const int _s=0,const int _v=0,const int _c=0);
    ~evolution_group();
    inline individual* get_best(){return best;}
    bool best_decide();
    bool evolution_s();
    bool evolution(int genr=2000, const char* fit=DEFAULT_FIT_EVOLUTION_GROUP);
    inline void fit_record(ofstream& file){file<<best->get_fit()<<endl;}
    inline void output(const char* file=DEFAULT_OUTPUT_EVOLUTION_GROUP)
    {
        ofstream f;
        f.open(file);
        best->print_f(f);
        f<<endl<<best->get_fit();
        f.close();
    }
};
#include "group.tem"
#endif
