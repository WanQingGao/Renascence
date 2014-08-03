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
#include "core/GPProducerFactory.h"
#include "system/xmlGenerateSystem.h"

GPProducer* GPProducerFactory::create()
{
    return new xmlGenerateSystem;
}
GPProducer* GPProducerFactory::create(const char* file, IFunctionTable* t)
{
    xmlGenerateSystem* g = new xmlGenerateSystem;
    g->addXml(file, t);
    return g;
}
