#include "MyOpenXRCHOP.h"
#include <cstring>

MyOpenXRCHOP::MyOpenXRCHOP(const OP_NodeInfo* info)
    : isInitialized(false)
{
    viewProjMatrix.resize(64, 0.0f);
    isInitialized = initializeOpenXR();
}

MyOpenXRCHOP::~MyOpenXRCHOP() {}

void MyOpenXRCHOP::getGeneralInfo(CHOP_GeneralInfo* ginfo, const OP_Inputs*, void*)
{
    ginfo->cookEveryFrame = true;
    ginfo->inputMatchIndex = 0;
}

bool MyOpenXRCHOP::getOutputInfo(CHOP_OutputInfo* outInfo, const OP_Inputs*, void*)
{
    outInfo->numChannels = 64;
    outInfo->sampleRate = 60;
    outInfo->numSamples = 1;
    return true;
}

void MyOpenXRCHOP::execute(CHOP_Output* output, const OP_Inputs*, void*)
{
    if (isInitialized)
        updateMatrices();

    for (int i = 0; i < 64; ++i)
    {
        float* chan = output->channels[i];
        chan[0] = viewProjMatrix[i];
    }
}

int MyOpenXRCHOP::getNumInfoCHOPChans() { return 0; }
void MyOpenXRCHOP::getInfoCHOPChan(int, OP_InfoCHOPChan*) {}
bool MyOpenXRCHOP::getInfoDATSize(OP_InfoDATSize* infoSize)
{
    infoSize->rows = 0;
    infoSize->cols = 0;
    return false;
}
void MyOpenXRCHOP::getInfoDATEntries(int, int, OP_InfoDATEntries*) {}

void MyOpenXRCHOP::setupParameters(OP_ParameterManager*, void*) {}
void MyOpenXRCHOP::pulsePressed(const char*, void*) {}

bool MyOpenXRCHOP::initializeOpenXR()
{
    // 初期化処理（実際のOpenXRランタイムで実装）
    return true;
}

void MyOpenXRCHOP::updateMatrices()
{
    for (int i = 0; i < 64; ++i)
        viewProjMatrix[i] = static_cast<float>(i); // 仮データ（実際はHMDから取得）
}
