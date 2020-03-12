/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil  -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab: */

/***********************************************************************
 * Copyright (c) 2012 - 2020 Anlogic Inc.
 * This file is strictly confidential. All rights reserved.
***********************************************************************/

/***********************************************************************
Filename:    abcTDapis.cpp
Description: export functions
Log:         initial version, June 2017
***********************************************************************/


#ifndef _ABC_TD_APIS_H_
#define _ABC_TD_APIS_H_

extern "C" {

// procedures to start and stop the ABC framework
extern void   Abc_Start();
extern void   Abc_Stop();
extern void * Abc_FrameGetGlobalFrame();

// procedures to input/output 'mini AIG'
// extern void   Abc_NtkInputMiniAig(void * pAbc, void * pMiniAig);
extern void * Abc_FrameGiaOutputMiniLut(void * pAbc);
extern void   Abc_FrameGiaInputMiniLut (void * pAbc, void * pMiniLut);
extern char * Abc_FrameGiaOutputMiniLutAttr(void * pAbc, void * pMiniLut );
extern void   Abc_FrameGiaInputMiniAig (void * pAbc, void * pMiniAig);
extern void * Abc_FrameGiaOutputMiniAig(void * pAbc);

// procedures to load netlists
extern void * Mini_AigStartExt();
extern void   Mini_AigStopExt(void * pMiniAig);
extern void * Mini_AigLoadExt          (char * pFileName);

extern int    Mini_AigLitConst0Ext();
extern int    Mini_AigLitConst1Ext();

extern int    Mini_AigCreatePiExt(void * pMiniAig);
extern int    Mini_AigCreatePoExt(void * pMiniAig, int Lit0);

extern int    Mini_AigLitNotExt(int Lit);
extern int    Mini_AigAndExt(void * pMiniAig, int Lit0,  int Lit1);
extern int    Mini_AigOrExt(void * pMiniAig, int Lit0,  int Lit1);
extern int    Mini_AigMuxExt(void * pMiniAig, int LitC, int Lit1, int Lit0);
extern int    Mini_AigXorExt(void * pMiniAig, int Lit0,  int Lit1);

// working with sequential AIGs
extern void   Mini_AigSetRegNumExt(void * p, int n);
extern int    Mini_AigNodeNumExt(void * p);
extern int *  Abc_FrameReadMiniAigEquivClasses(void * pAbc );
extern void   Mini_AigDumpExt(void * p, char * pFileName );
extern void   Mini_AigDumpVerilogExt( char * pFileName, char * pModuleName, void * p );

// miniLut related
extern void * Mini_LutStartExt(int lutSize);
extern void   Mini_LutStopExt(void * pMiniLut);
extern void   Mini_LutCheckExt(void * pMiniLut);

extern int    Mini_LutCreatePiExt(void * pMiniLut);
extern int    Mini_LutCreatePoExt(void * pMiniLut, int Var0);
extern int    Mini_LutCreateNodeExt(void * pMiniLut, int nVars, int * pVars, unsigned * pTruth);

extern void   Mini_LutPrintStatsExt(void *p);
extern void   Mini_LutDumpExt(void *p, char * pFileName);
extern int    Mini_LutNodeNumExt(void *p);
extern int    Mini_LutNodeIsConstExt(void *p, int id);
extern int    Mini_LutNodeIsPiExt(void *p, int id);
extern int    Mini_LutNodeIsPoExt(void *p, int id);
extern int    Mini_LutNodeIsNodeExt(void *p, int id);
extern int    Mini_LutNodeFaninExt(void *p, int id, int k);
extern void   Mini_LutNodeTruthExt(void *p, int id, char *pTruth, char *pEqn);
extern int    Mini_LutSizeExt(void *p);
extern int    Mini_LutGetPoDriverExt(void *p, int id);
extern void   Mini_LutSetRegNumExt(void * p, int n);
extern int    Mini_LutWordNumExt(void * pMiniLut);

// procedure to return name mapping
extern int  * Abc_FrameReadMiniLutNameMapping(void * pAbc);

// procedures to set CI/CO arrival/required times
extern void   Abc_FrameMiniAigSetCiArrivals (void * pAbc, int * pArrivals);
extern void   Abc_FrameMiniAigSetCoRequireds(void * pAbc, int * pRequireds);

// procedures to get CO arrival times after mapping
extern int  * Abc_FrameMiniAigReadCoArrivals(void * pAbc);

// procedure to set AND-gate delay to tech-independent synthesis and mapping
extern void   Abc_FrameMiniAigSetAndGateDelay(void * pAbc, int Delay);

// procedure to install a new LUT library
extern int    Abc_FrameSetLutLibrary(void * pAbc, char * pLutLibString);

// procedures to execute abc commands
extern int    Cmd_CommandExecute(void * pAbc, char * sCommand);

// for printings
void Gia_ManGetMappingStatsExt(void* pAbc,
		int* nLutSize,
		int* nLuts,
		int* nFanins,
		int* LevelMax,
		float* Ave);

// misc functions
extern void   Abc_FrameSetFlag(char * pFlag, char * pValue);
extern int    Abc_FrameReadProbStatus(void * pAbc);
extern int    Abc_Lit2VarExt(int Lit);
extern int    Abc_Var2LitExt(int Var, int fCompl);
extern int    Abc_LitIsComplExt( int Lit );
extern void * Abc_FrameReadNtkExt( void * pFrame );
extern int    Abc_NtkGetFaninMaxExt( void * pNtk );
extern int    Abc_NtkNodeNumExt( void * pNtk );

extern void   Mini_LutTruthToEqnExt(unsigned * pDecimalTruth, int nVars, /*input*/
        char *pTruth, char *pEqn  /*output*/);

}

#endif
