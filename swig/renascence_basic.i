%module RenascenceBasic
%{
#include "user/GPAPI.h"
%}
enum
{
    GP_PRODUCER_TREE=0,
    GP_PRODUCER_STREAM=2
};

/*Set basic path of lib
 * The lib will be loaded  from basic_path/
 * For Example, set basic_path as /a/b/c/
 * Then will load liba,so from /a/b/c/liba.so
 * */
void GP_Set_Lib_Path(const char* basic_path);

/*Set Basic path for File Stream, Affect the API GP_Stream_Create and GP_WStream_Create
 * Same as GP_Set_Lib_Path
 * */
void GP_Set_Stream_Path(const char* basic_path);

/*Create Read Stream for file, using rb mode. The Real file is basic_path + filename*/
GPStream* GP_Stream_Create(const char* filename);
/*Destroy the stream created by GP_Stream_Create, must not be used to destroy other Stream*/
void GP_Stream_Destroy(GPStream* s);


/*Create Write Stream for file, using wb mode. The Real file is basic_path + filename*/
GPWStream* GP_WStream_Create(const char* filename);
/*Destroy the stream created by GP_WStream_Create, must not be used to destroy other Stream*/
void GP_WStream_Destroy(GPWStream* s);

/* Load Contents by IStatusType's vLoad method, Cona GPContents
 * producer: the FunctionProducer
 * inputs: the list of Stream, must assume that all input are not NULL
 * typeNames: the list of types
 * n: select number, must be equal to types
 * For Example:
 *      GPContents* c = GP_Contents_Load(producer, inputs, "TrBmp TrBmp", 2);
 */
GPContents* GP_Contents_Load(AGPProducer* producer, GPStream** inputs, const char* typeNames, int n);

/*Return the number of contents*/
int GP_Contents_Size(GPContents* contents);


/*Return the content in the n pos*/
void* GP_Contents_Get(GPContents* contents, int n);

/*Return the double value of GP, must assert that the type is double*/
double GP_Contents_GetDouble(GPContents* contents, int n);

/*Set the double value of GP, must assert that the type is double*/
void GP_Contents_SetDouble(GPContents* contents, double value, int n);

/*Create a double value*/
GPContents* GP_Contents_CreateDouble(double value);

/*Create a string value*/
GPContents* GP_Contents_CreateString(const char* value);


/* Write Contents to appointed stream
 * content: the contents to be write, must not be null
 * outputs: the array of output stream, must not be null, all stream in this list should not be null, too
 * n: the pos of content, must be the range [0, size)
 * Example:
 *      int n = GP_Contents_Size(contents);
 *      for (int i=0; i<n; ++i)
 *      {
 *          char text[20];
 *          sprintf(text, "test%d.txt", i);
 *          outputStream = GP_WStream_Create(text);
 *          GP_Contents_Save(contents, outputStream, i);
 *          GP_WStream_Destroy(outputStream);
 *      }
 */
void GP_Contents_Save(GPContents* content, GPWStream* outputs, int n);

/*Destroy the contents in GPContents and itself
 * content: The memory to be freed
 */
void GP_Contents_Destroy(GPContents* content);


/* Create a collector, used to merge contents, the collector is also needed to be free by GP_Contents_Destroy, the collector doesn't own its content*/
GPContents* GP_Contents_CreateCollector();

/*Select the nth content in B, and add to Collector's end. User should not destroy B before collector is destroyed*/
/* Collector: The Dst Container, Must be come from GP_Contents_CreateCollector
 * B: The Src
 * n: The pos of content in B, n should be >=0, and n < B->size
 * Example:
 *      GPContents* col = GP_Contents_CreateCollector();
 *      GPContents* B = GP_Contents_Load(producer, inputsB, "TrBmp", 1);
 *      GPContents* A = GP_Contents_Load(producer, inputsA, "TrBmp TrBmp", 2);
 *      GP_Contents_Collect(col, A, 0);
 *      GP_Contents_Collect(col, A, 1);
 *      GP_Contents_Collect(col, B, 0);
 *      //Do Something by col
 *      GP_Contents_Destroy(col);
 *      GP_Contents_Destroy(A);
 *      GP_Contents_Destroy(B);
 */
void GP_Contents_Collect(GPContents* Collector, GPContents* B, int n);




/*Create AGPProducer by function table, meta file and type
 * metaStream:
 * table: obtain the method to get function, can be NULL, then GP will create table by the path decribed by meta file
 * n: the number of stream and tables
 * type: ALL:-1, TREE:0, GRAPIC:1, STREAM:2
 */
AGPProducer* GP_Producer_Create(GPStream** metaStream, IFunctionTable** table, int n, int type);

/*Destroy the AGPProducer, before using this API, Make sure that all function created by p is destroyed*/
void GP_Producer_Destroy(AGPProducer* p);


typedef struct GPOptimizorInfo
{
    /*The Max Tree Depth For all ADF Function
     * For Example:
     * If The nMaxADFDepth is set as 1, then ADF(x0, x1) can only be f(x0, x1), can't be f(g(x0), x1)
     */
    int nMaxADFDepth;
    
    /*Determine which method for optimization. Make different sense for structure and parameter*/
    int nOptimizeType;
    
    /*The Function to Determine whether the Auto-Generate-Function is good, the larger the better*/
    double(*pFitComputeFunction)(IGPAutoDefFunction* adf, void* pMeta);
    void* pMeta;
    
    /*The max time for pFitComputeFunction to call in optimization*/
    int nMaxRunTimes;
    
    /*If reached this value, the train of ADF will stop, if the value is zero, means run nMaxRunTimes*/
    double fTargetBestValue;
    
    /*When trainning, it will write in pBestInfo for recording, can be NULL if no need*/
    /*The info will be: formula, parameters, type and fitness*/
    GPWStream* pBestInfo;
    /*Output Value, Filled by evolution*/
    double fOutputBest;
#ifdef __cplusplus
    GPOptimizorInfo();
    GPOptimizorInfo(const GPOptimizorInfo& info);
    ~GPOptimizorInfo();
#endif
    
}GPOptimizorInfo;

/*Create a IGPAutoDefFunction by inputTypes and outputTypes, the types must be divided by space*/
/*For example: IGPAutoDefFunction* f = GP_Create_Function_ByType(p, "SkBitmap SkPaint", "SkStream", false)*/
/*
 * p: the AGPProducer created by GP_Producer_Create
 * outputTypes: the name of all output types
 * inputTypes: all the input types obtained for the IGPAutoDefFunction, not orderred, if set "", GP will not care about the input
 */
IGPAutoDefFunction* GP_Function_Create_ByType(const AGPProducer* p, const char* outputTypes, const char* inputTypes, GPOptimizorInfo* pInfo);

/*Create GP by formula like this: f(g(a, b), c)
 * p: the AGPProducer created by GP_Producer_Create
 * formula: the string of formula
 * inputType: the string of all types
 * pInfo：The Optimization info, only valid where formula contains ADF
 * Example: auto adf = GP_Function_Create_ByFormula(p, "f(x0, g(x1))", "Matrix Matrix", NULL);
 */
IGPAutoDefFunction* GP_Function_Create_ByFormula(const AGPProducer* p, const char* formula, const char* inputType, GPOptimizorInfo* pInfo);

/*The Inputs should be generate from stream by IStatusType inorder by the inputTypes return from GP_Function_Get_Inputs*/
GPContents* GP_Function_Run(IGPAutoDefFunction* f, GPContents* input);
/*Free the memory of function*/
void GP_Function_Destroy(IGPAutoDefFunction* f);

/*Load f from input stream, which mainly come from a xmlfile*/
IGPAutoDefFunction* GP_Function_Create_ByStream(const AGPProducer* p, GPStream* xmlFile);

/*Save f to output, use xml format*/
void GP_Function_Save(IGPAutoDefFunction* f, GPWStream* output);


/*Optimize IGPAutoDefFunction by adjust its parameters*/
/*REMIND: the f's parameters will be changed after this api*/
/*If fit_fun is not random, this api make sure that fit_fun(f) will at least not decrease*/
/*
 f: The IGPAutoDefFunction to be Optimize
 pInfo: obtain function to determine f's fit, nMaxRunTimes is the maxTimes to run IGPAutoDefFunction in these api, will affect the algorithm of PSO. The nMaxADFDepth make no sense
 pInfo.nOptimizeType: 0 (use PSO, will compute maxTimes), 1(Use random golden divide Optimization, fast but not very accuracy)
 
 example:
 {
 struct GPOptimizorInfo info;
 info.nMaxRunTimes = 1000;
 info.pFitComputeFunction = f;
 info.pMeta = meta;
 GP_Function_Optimize(f, &info);
 }
 */
void GP_Function_Optimize(IGPAutoDefFunction* f, GPOptimizorInfo* pInfo);

/*For the convenience of Python/Go API*/
GPStream** GP_Streams_Malloc(int n);
void GP_Streams_Free(GPStream** streams);
GPStream* GP_Streams_Get(GPStream** streams, int n);
void GP_Streams_Set(GPStream** streams,GPStream* contents, int n);


/*For Print*/
/*AGPStrings come from function must be free by GP_Strings_Free*/
typedef struct AGPStrings AGPStrings;
int GP_Strings_Number(AGPStrings* strings);
const char* GP_Strings_Get(AGPStrings* strings, int n);
void GP_Strings_Free(AGPStrings* strings);

/*Return the formula string of ADF with the name of adfName, if adfName == NULL, return the whole function name. The size of string is 1
 *Example:
 * IGPAutoDefFunction* adffunction = GP_Function_Create_ByFormula(p, "f(x0, ADF(filter, x1))", "Matrix Matrix", NULL);
 * AGPStrings* formula = GP_Function_GetFormula(adffunction, NULL);
 * printf("The whole function is: %s\n", GP_Strings_Get(formula, 0));
 * GP_Strings_Free(formula);
 * formula = GP_Function_GetFormula(adffunction, "filter");
 * printf("The filter function is: %s\n", GP_Strings_Get(formula, 0));
 * GP_Strings_Free(formula);
 */
AGPStrings* GP_Function_GetFormula(IGPAutoDefFunction* f, const char* adfName);
/*Get Parameters like this: "0.1 0.5 0.3"*/
AGPStrings* GP_Function_GetParameters(IGPAutoDefFunction* f);

/*Map f by parameters, the parameters come from GP_Function_GetParameters or outsize file
 *Example:
 * const char* p = "0.5 0.3 0.77";
 * GP_Function_MapParameters(f, p);
 */
void GP_Function_MapParameters(IGPAutoDefFunction* f, const char* parameters);

/*Return All functions as a list
 *Example:
 * AGPStrings* functions = GP_Producer_ListFunctions(producer);
 * int n = GP_Strings_Number(functions);
 * for (int i=0; i<n; ++i)
 * {
 *     printf("%s\n", GP_Strings_Get(functions, i));
 * }
 * GP_Strings_Free(functions);
 */
AGPStrings* GP_Producer_ListFunctions(AGPProducer* producer);

/*Return All Types name as a list*/
AGPStrings* GP_Producer_ListTypes(AGPProducer* producer);

/*Return all type name of contents*/
AGPStrings* GP_Contents_Types(GPContents* contents);

/*Print the info for contents*/
AGPStrings* GP_Contents_Dump(GPContents* contents, int n);

/*Default GPOptimizorInfo*/
enum
{
    GP_OPTIMIZOR_VALUE = 0,
    GP_OPTIMIZOR_TIME = 1
};
/*Create standard OptimizorInfo, Used by Python/Go
 *type: GP_OPTIMIZOR_VALUE/GP_OPTIMIZOR_TIME
 *depth, maxtimes: the value in GPOptimizorInfo
 *bestCache:pBestInfo in GPOptimizorInfo
 *pPostFunction: the post treat function that will act with the result of target function, can be NULL
 *pPostExtraInput: the extra input to run pPostFunction, For example, P(x0, x1, x2), extra inputs is x1, x2
 */
GPOptimizorInfo* GP_OptimzorInfo_CreateTemplate(int depth, int maxtimes, int type, GPContents* pInput, GPWStream* bestCache, IGPAutoDefFunction* pPostFunction, GPContents* pPostExtraInput);

/*The info be freed must be come from GP_OptimzorInfo_CreateTemplate and can't be modified*/
void GP_OptimzorInfo_FreeTemplate(GPOptimizorInfo* pInfo);

double GP_OptimzorInfo_TemplateGetBestValue(GPOptimizorInfo* pInfo);


/*Get a total GPPieces Function Producer
 * producer:
 * piecesLibMeta: libNumber's xml file
 * piecesLibTable: libNumber's IFunctionTable, can be NULL
 * libNumber: the number of piecesLibMeta and piecesLibTable
 * mapReduceMeta: mapReduceMetaNumber's xmlFile, which tell GP how to build Parallel Function
 * mapReduceMetaNumber: the number of mapReduceMeta
 * Example:
 -----
 GPStream* meta = GP_Stream_Create("libsqldag.xml");
 mProducer = GP_Producer_Create(&meta, &t, 1, GP_PRODUCER_STREAM);
 //mProducer = GP_Producer_Create(&meta, &t, 1, GP_PRODUCER_TREE);
 GP_Stream_Destroy(meta);
 meta = GP_Stream_Create("Map-Reduce.xml");
 GPStream* metaMachine = GP_Stream_Create("mgpfunc.xml");
 mPieceProducer = GP_PiecesProducer_Create(mProducer, &metaMachine, NULL, 1, &meta, 1);
 GP_Stream_Destroy(meta);
 GP_Stream_Destroy(metaMachine);
 -----
 */
AGPPiecesProducer* GP_PiecesProducer_Create(AGPProducer* producer, GPStream** piecesLibMeta, IFunctionTable** piecesLibTable, int libNumber, GPStream** mapReduceMeta, int mapReduceMetaNumber);

/*
 * Release the producer created by GP_PiecesProducer_Create
 * Must be called by all GPPieces and GPPiecesFunction created by this producer released
 */
void GP_PiecesProducer_Destroy(AGPPiecesProducer* producer);

/*
 * Return all kinds of AGPPiecesProducer.
 * The name of it should be input as type in GP_Pieces_Create and GP_PiecesFunction_Create
 */
AGPStrings* GP_PiecesProducer_ListType(AGPPiecesProducer* producer);

/*GPPieces API*/
/*Create GPPieces Function
 
 */
GPPiecesFunction* GP_PiecesFunction_Create(AGPPiecesProducer* producer, const char* formula, const char* inputType, const char* type);

GPPieces* GP_PiecesFunction_Run(GPPiecesFunction* piecesFunction, GPPieces** inputs, int inputNumber);

void GP_PiecesFunction_Destroy(GPPiecesFunction* pieceFunction);


enum {
    GP_PIECES_INPUT = 0,
    GP_PIECES_OUTPUT = 1,
};

/*Pieces Function*/
GPPieces* GP_Pieces_Create(AGPPiecesProducer* producer, const char* type, const char* dataType, const char* path, unsigned int* keys, int keyNum, int usage);

GPContents* GP_Pieces_Read(GPPieces* pieces, const char* keys);
void GP_Pieces_Write(GPPieces* pieces, GPContents* src, const char* keys);
void GP_Pieces_Destroy(GPPieces* pieces);

bool GP_Pieces_Copy(AGPPiecesProducer* producer, const char* type, GPPieces* readPieces, GPPieces* writePieces);

/*For GPPieces array operate*/
GPPieces** GP_Pieces_CreateArray(int n);
void GP_Pieces_Array_Free(GPPieces** array);
GPPieces* GP_Pieces_Array_Get(GPPieces** array, int n);
void GP_Pieces_Array_Set(GPPieces** array,GPPieces* contents, int n);

unsigned int* GP_Unsigned_Int_Array_Create(int n);
void GP_Unsigned_Int_Array_Free(unsigned int* array);
unsigned int GP_Unsigned_Int_Array_Get(unsigned int* array, int n);
void GP_Unsigned_Int_Array_Set(unsigned int* array, unsigned int s, int n);

