#include "test/GPTest.h"
#include "core/GPProducer.h"
#include "core/GPProducerFactory.h"
#include "utils/AutoClean.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
using namespace std;
class GPSearchIOTest:public GPTest
{
    public:
        virtual void run()
        {
            /*Single*/
            GPProducer* sys = GPProducerFactory::create("func.xml", NULL);
            AUTOCLEAN(sys);
            GPProducer& gen = *sys;
            int outId = gen.queryType(string("TrFilterMatrix"));
            const IStatusType& ist = gen.queryType(outId);
            vector<int> out;
            out.push_back(outId);
            vector<int> inp;
            IGPAutoDefFunction* f = gen.vCreateFunction(out, inp);
            vector<void*> GPinp;
            GP_Output GPout = f->run(GPinp);
            vector<void*> _output;
            GP_Output_collect(_output, GPout);
            assert(_output.size()==1);
            ist.print(cout, _output[0]);
            cout <<endl;
            GP_Output_clear(GPout);
            f->decRef();
            /*Multi*/
            vector<IGPAutoDefFunction*> f_mul = gen.vCreateAllFunction(out, inp);
            assert(!f_mul.empty());
            cout <<"Multi function's size = "<< f_mul.size() << endl;
            for (int i=0; i<f_mul.size(); ++i)
            {
                ostringstream fileName;
                fileName << "output/GPSearchIOTest"<<i<<".xml";
                ofstream output(fileName.str().c_str());
                f = f_mul[i];
                GPout = f->run(GPinp);
                vector<void*> _output2;
                GP_Output_collect(_output2, GPout);
                assert(_output2.size()==1);
                ist.print(cout, _output2[0]);
                cout << endl;
                GP_Output_clear(GPout);
                f->save(output);
                f->decRef();
                output.close();
            }
        }
        GPSearchIOTest(){}
        virtual ~GPSearchIOTest(){}
};

static GPTestRegister<GPSearchIOTest> a("GPSearchIOTest");
