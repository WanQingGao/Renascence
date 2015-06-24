#include "test/GPTest.h"

#include "core/GPFunctionDataBase.h"
#include "core/GPProducer.h"
#include "core/GPFactory.h"
#include "core/BasicComposeFunction.h"
#include <fstream>
#include <string>
#include <iostream>
#include "head.h"

using namespace std;

class GPloadXmlTreeTest2:public GPTest
{
    public:
        virtual void run()
        {
            GPFunctionDataBase* base = GPFactory::createDataBase("func.xml", NULL);
            AUTOCLEAN(base);
            {
                GPProducer* gen = GPFactory::createProducer(base);
                AUTOCLEAN(gen);
                {
                    ifstream f("result.xml");
                    IGPAutoDefFunction* gp = gen->vCreateFunctionFromIS(f);
                    AUTOCLEAN(gp);
                    f.close();
                    ofstream file;
                    file.open("output/GPloadXmlTreeTest.xml");
                    gp->vSave(file);
                    file.close();
                    IGPAutoDefFunction* gp2 = gp->vCopy();
                    AUTOCLEAN(gp2);
                    file.open("output/GPloadXmlTreeTest_copy.xml");
                    gp2->vSave(file);
                    file.close();
                    file.open("output/GPloadXmlTreeTest_mutate.xml");
                    gp2->vMutate();
                    gp2->vSave(file);
                    file.close();
                }
            }
        }
        GPloadXmlTreeTest2(){}
        virtual ~GPloadXmlTreeTest2(){}
};

static GPTestRegister<GPloadXmlTreeTest2> a("GPloadXmlTreeTest");
