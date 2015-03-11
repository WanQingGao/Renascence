#include "test/GPTest.h"
#include "core/GPProducer.h"
#include "core/GPFunctionDataBase.h"
#include "core/GPFactory.h"
#include "head.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <utils/debug.h>
using namespace std;
class GPSearchIOTest:public GPTest
{
    public:
        virtual void run()
        {
            /*Single*/
            GPFunctionDataBase* base = GPFactory::createDataBase("func.xml", NULL);
            AUTOCLEAN(base);
            {
                GPProducer* sys = GPFactory::createProducer(base);
                GPProducer& gen = *sys;
                AUTOCLEAN(sys);
                const IStatusType* ist = base->vQueryType(string("TrFilterMatrix"));
                vector<const IStatusType*> out;
                out.push_back(ist);
                vector<const IStatusType*> inp;
                IGPAutoDefFunction* f = gen.vCreateFunction(out, inp);
                GPContents GPinp;
                auto _output = f->run(&GPinp);
                GPASSERT(_output->size()==1);
                ist->vSave(_output->get(0), cout);
                cout <<endl;
                _output->clear();
                delete _output;
                f->decRef();
                /*Multi*/
                vector<IGPAutoDefFunction*> f_mul = gen.vCreateAllFunction(out, inp);
                GPASSERT(!f_mul.empty());
                cout <<"Multi function's size = "<< f_mul.size() << endl;
                for (int i=0; i<f_mul.size(); ++i)
                {
                    ostringstream fileName;
                    fileName << "output/GPSearchIOTest"<<i<<".xml";
                    ofstream output(fileName.str().c_str());
                    f = f_mul[i];
                    auto _output2 = f->run(&GPinp);
                    GPASSERT(_output2->size()==1);
                    ist->vSave(_output2->get(0), cout);
                    cout << endl;
                    _output2->clear();
                    delete _output2;
                    f->save(output);
                    f->decRef();
                    output.close();
                }
            }
        }
        GPSearchIOTest(){}
        virtual ~GPSearchIOTest(){}
};

static GPTestRegister<GPSearchIOTest> a("GPSearchIOTest");
