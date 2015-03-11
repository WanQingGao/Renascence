/******************************************************************
   Copyright 2014, Jiang Xiao-tang

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
#include "FilePath.h"
#include "core/GPFactory.h"
#include "core/GPProducer.h"
#include "core/GPFunctionDataBase.h"
#include <fstream>
#include "utils/AutoClean.h"
#include <utils/debug.h>
#include "core/xmlGPDataLoader.h"
using namespace std;

int main(int argc, char** argv)
{
    /*Prepare Runtime*/
    GPASSERT(argc>=2);
    FilePath::setEnvPath(argv[1]);
	GPFunctionDataBase* base = GPFactory::createDataBase(NULL, NULL);
    ifstream is;
    bool res = FilePath::open(FilePath::RUNTIME, is);
    GPASSERT(true == res);
	base->loadXml(is);
	AUTOCLEAN(base);
	{
		GPProducer* sys = GPFactory::createProducer(base);
		/*Load Standard function*/
		res = FilePath::open(FilePath::STANDARD, is);
		GPASSERT(true == res);
		IGPAutoDefFunction* function = sys->vCreateFunctionFromIS(is);
		AutoClean __clean_funtion(function);
		is.close();
		/*Find all input and output file*/
		vector<string> inputFiles;
		vector<string> outputFiles;
		res = (FilePath::open(FilePath::INPUT, is));
		GPASSERT(true == res);
		string temp;
		while (is >> temp)
		{
			inputFiles.push_back(temp);
		}
		is.close();
		res = (FilePath::open(FilePath::OUTPUT, is));
		GPASSERT(true == res);
		while (is >> temp)
		{
			outputFiles.push_back(temp);
		}
		is.close();
		res = (inputFiles.size() == outputFiles.size());
		GPASSERT(true == res);
		/*TODO Load Compare function*/
		/*Start to compare*/
		int n = inputFiles.size();
		ofstream result_os(FilePath::file(FilePath::RESULT).c_str());
		for (int i=0; i<n; ++i)
		{
			xmlGPDataLoader lin(*base);
			xmlGPDataLoader lout(*base);
			lin.loadFile(inputFiles[i].c_str());
			lout.loadFile(outputFiles[i].c_str());
			GPData* inp = lin.get();
			GPData* out = lout.get();
			GPContents* gp_inp = inp->expand();
			GPContents* gp_out = function->run(gp_inp);
			double res = out->compare(*gp_out);
			result_os <<res <<"\n";
			gp_out->clear();
            delete gp_out;
		}
		result_os.close();
	}

    return 1;
}
