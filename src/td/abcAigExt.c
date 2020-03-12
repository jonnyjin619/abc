/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil  -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab: */

/***********************************************************************
 * Copyright (c) 2012 - 2020 Anlogic Inc.
 * This file is strictly confidential. All rights reserved.
***********************************************************************/

/***********************************************************************
Filename:    abcAigExt.c
Description: export functions
Log:         initial version, June 2017
***********************************************************************/



#include "base/abc/abc.h"
#include "base/main/main.h"
#include "base/main/mainInt.h"
#include "bool/kit/kit.h"
#include "aig/miniaig/miniaig.h"
#include "aig/miniaig/minilut.h"

ABC_NAMESPACE_IMPL_START

void * Mini_AigStartExt() {
    return Mini_AigStart();
}
void Mini_AigStopExt(Mini_Aig_t * p) {
    Mini_AigStop(p);
}
int Mini_AigCreatePiExt(Mini_Aig_t * p) {
    return Mini_AigCreatePi(p);
}
int Mini_AigCreatePoExt(Mini_Aig_t * p, int Lit0) {
    return Mini_AigCreatePo(p, Lit0);
}
int Mini_AigLitConst0Ext() {
	return Mini_AigLitConst0();
}
int Mini_AigLitConst1Ext() {
	return Mini_AigLitConst1();
}
int Mini_AigLitNotExt(int Lit){
	return Mini_AigLitNot(Lit);
}
int Mini_AigAndExt(Mini_Aig_t * p, int Lit0,  int Lit1){
	return Mini_AigAnd(p, Lit0, Lit1);
}
int Mini_AigOrExt(Mini_Aig_t * p, int Lit0,  int Lit1){
	return Mini_AigOr(p, Lit0, Lit1);
}
int Mini_AigMuxExt(Mini_Aig_t * p, int LitC, int Lit1, int Lit0){
	return Mini_AigMux(p, LitC, Lit1, Lit0);
}
int Mini_AigXorExt(Mini_Aig_t * p, int Lit0,  int Lit1){
	return Mini_AigXor(p, Lit0, Lit1);
}

Mini_Aig_t * Mini_AigLoadExt( char * pFileName ) {
	return Mini_AigLoad(pFileName);
}

void Mini_AigSetRegNumExt(Mini_Aig_t * p, int n) {
    Mini_AigSetRegNum(p, n);
}

int Mini_AigNodeNumExt( Mini_Aig_t * p ) {
    return Mini_AigNodeNum(p);
}

void Mini_AigDumpExt(void * p, char * pFileName ) {
    Mini_AigDump(p, pFileName);
}

void Mini_AigDumpVerilogExt( char * pFileName, char * pModuleName, void * p ) {
    Mini_AigDumpVerilog(pFileName, pModuleName, p);
}

// miniLut
void * Mini_LutStartExt(int lutSize) {
    return Mini_LutStart(lutSize);
}
void Mini_LutStopExt(Mini_Lut_t * pMiniLut) {
    Mini_LutStop(pMiniLut);
}
void  Mini_LutCheckExt(Mini_Lut_t * pMiniLut){
    Mini_LutCheck(pMiniLut);
}

int Mini_LutCreatePiExt(Mini_Lut_t * pMiniLut) {
    return Mini_LutCreatePi(pMiniLut);
}
int Mini_LutCreatePoExt(Mini_Lut_t * pMiniLut, int Var0) {
    return Mini_LutCreatePo(pMiniLut, Var0);
}
int Mini_LutCreateNodeExt(Mini_Lut_t * pMiniLut, int nVars, int * pVars, unsigned * pTruth) {
    return Mini_LutCreateNode(pMiniLut, nVars, pVars, pTruth);
}

int Mini_LutWordNumExt(Mini_Lut_t * p){
    return Mini_LutWordNum(p->LutSize);
}
void Mini_LutSetRegNumExt( Mini_Lut_t * p, int n ) {
    Mini_LutSetRegNum(p, n);
}

void Mini_LutPrintStatsExt(Mini_Lut_t * p){
	Mini_LutPrintStats(p);
}
void Mini_LutDumpExt(Mini_Lut_t * p, char * pFileName){
	Mini_LutDump(p, pFileName);
}
extern int Mini_LutNodeNumExt(Mini_Lut_t * p){
	return Mini_LutNodeNum(p);
}
extern int Mini_LutNodeIsConstExt(Mini_Lut_t * p, int id){
	return Mini_LutNodeIsConst(p, id);
}
extern int Mini_LutNodeIsPiExt(Mini_Lut_t * p, int id){
	return Mini_LutNodeIsPi(p, id);
}
extern int Mini_LutNodeIsPoExt(Mini_Lut_t * p, int id){
	return Mini_LutNodeIsPo(p, id);
}
extern int Mini_LutNodeIsNodeExt(Mini_Lut_t * p, int id){
	return Mini_LutNodeIsNode(p, id);
}
extern int Mini_LutNodeFaninExt(Mini_Lut_t * p, int id, int k){
	return Mini_LutNodeFanin(p, id, k);
}

extern void Mini_LutNodeTruthExt(Mini_Lut_t * p, int id, char *pTruth, char *pEqn){
	//const char* name[6] = {"a", "b", "c", "d", "e", "f"};
	char hex[64];
	int nVars = 0;
	int k = 0;
	int fan = 0;

	unsigned * pDecimalTruth = Mini_LutNodeTruth(p , id);

	Mini_LutForEachFanin(p, id, fan, k)
	    nVars++;

	// get equations
	Kit_DsdWriteFromTruth(pEqn, pDecimalTruth, nVars);
	Extra_PrintHexadecimalString(hex, pDecimalTruth, nVars);
	sprintf(pTruth, "%d'h%s", (1<<nVars), hex);
}

extern void Mini_LutTruthToEqnExt(
        unsigned * pDecimalTruth,
        int nVars, /*input*/
        char *pTruth,
        char *pEqn  /*output*/){

    // get equations
    char hex[64];
    Kit_DsdWriteFromTruth(pEqn, pDecimalTruth, nVars);
    Extra_PrintHexadecimalString(hex, pDecimalTruth, nVars);
    sprintf(pTruth, "%d'h%s", (1<<nVars), hex);
}

extern int Mini_LutSizeExt(Mini_Lut_t * p){
	return p->LutSize;
}

extern int Mini_LutGetPoDriverExt(Mini_Lut_t *p, int id){
	//assert(Mini_LutNodeIsPo(p, id));

	int numDriver = 0;
	int driverID = -1;
	int k;
    for (k = 0; k < p->LutSize; k++ ) {
    	int iFaninVar = Mini_LutNodeFanin( p, id, k );
        if (iFaninVar == MINI_LUT_NULL || iFaninVar == MINI_LUT_NULL2)
            continue;

        numDriver++;
        driverID = iFaninVar;
    }
    assert(numDriver == 1);
    return driverID;
}

int  Abc_Lit2VarExt(int Lit) {
	//assert(Lit >= 0);
	//return Lit >> 1;
	return Abc_Lit2Var(Lit);
}

int Abc_Var2LitExt(int Var, int fCompl) {
  return Abc_Var2Lit(Var, fCompl);
}

int  Abc_LitIsComplExt( int Lit ){
	//assert(Lit >= 0);
	//return Lit & 1;
	return Abc_LitIsCompl(Lit);
}

Abc_Ntk_t * Abc_FrameReadNtkExt( Abc_Frame_t * p ) {
    return p->pNtkCur;
}

int Abc_NtkGetFaninMaxExt( Abc_Ntk_t * pNtk )
{
    Abc_Obj_t * pNode;
    int i, nFaninsMax = 0;
    Abc_NtkForEachNode( pNtk, pNode, i )
    {
        if ( nFaninsMax < Abc_ObjFaninNum(pNode) )
            nFaninsMax = Abc_ObjFaninNum(pNode);
    }
    return nFaninsMax;
}

int Abc_NtkNodeNumExt( void * pNtk ) {
  return Abc_NtkNodeNum((Abc_Ntk_t*) pNtk);
}

// to print_netlist status
void Gia_ManGetMappingStatsExt(Abc_Frame_t* pAbc,
		int* nLutSize,
		int* nLuts,
		int* nFanins,
		int* LevelMax,
		float* average)  {

	Gia_Man_t * p = pAbc->pGia;

    Gia_Obj_t * pObj;
    int * pLevels;
    int i, k, iFan, Ave = 0;
    if ( !Gia_ManHasMapping(p) )
        return;
    pLevels = ABC_CALLOC( int, Gia_ManObjNum(p) );
    Gia_ManForEachLut( p, i )
    {
        if ( Gia_ObjLutIsMux(p, i) )
        {
            int pFanins[3];
            if ( Gia_ObjLutSize(p, i) == 3 )
            {
                Gia_ManPrintGetMuxFanins( p, Gia_ManObj(p, i), pFanins );
                pLevels[i] = Abc_MaxInt( pLevels[i], pLevels[pFanins[0]]+1 );
                pLevels[i] = Abc_MaxInt( pLevels[i], pLevels[pFanins[1]] );
                pLevels[i] = Abc_MaxInt( pLevels[i], pLevels[pFanins[2]] );
            }
            else if ( Gia_ObjLutSize(p, i) == 2 )
            {
                pObj = Gia_ManObj( p, i );
                pLevels[i] = Abc_MaxInt( pLevels[i], pLevels[Gia_ObjFaninId0(pObj, i)] );
                pLevels[i] = Abc_MaxInt( pLevels[i], pLevels[Gia_ObjFaninId1(pObj, i)] );
            }
            (*LevelMax) = Abc_MaxInt( (*LevelMax), pLevels[i] );
            (*nFanins)++;
            continue;
        }
        (*nLuts)++;
        *nFanins += Gia_ObjLutSize(p, i);
        (*nLutSize) = Abc_MaxInt( (*nLutSize), Gia_ObjLutSize(p, i) );
        Gia_LutForEachFanin( p, i, iFan, k )
            pLevels[i] = Abc_MaxInt( pLevels[i], pLevels[iFan] );
        pLevels[i]++;
        (*LevelMax) = Abc_MaxInt( (*LevelMax), pLevels[i] );
    }
    Gia_ManForEachCo( p, pObj, i )
        Ave += pLevels[Gia_ObjFaninId0p(p, pObj)];

    (*average) = (float)Ave / Gia_ManCoNum(p);

    ABC_FREE( pLevels );
}


ABC_NAMESPACE_IMPL_END

////////////////////////////////////////////////////////////////////////
///                       END OF FILE                                ///
////////////////////////////////////////////////////////////////////////

