#pragma once

#include "CHOP_CPlusPlusBase.h"
#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>
#include <vector>

class MyOpenXRCHOP : public CHOP_CPlusPlusBase
{
public:
    MyOpenXRCHOP(const OP_NodeInfo* info);
    virtual ~MyOpenXRCHOP();

    virtual void getGeneralInfo(CHOP_GeneralInfo* ginfo, const OP_Inputs* inputs, void* reserved) override;
    virtual bool getOutputInfo(CHOP_OutputInfo* outInfo, const OP_Inputs* inputs, void* reserved) override;
    virtual void execute(CHOP_Output* output, const OP_Inputs* inputs, void* reserved) override;
    virtual int getNumInfoCHOPChans() override;
    virtual void getInfoCHOPChan(int index, OP_InfoCHOPChan* chan) override;
    virtual bool getInfoDATSize(OP_InfoDATSize* infoSize) override;
    virtual void getInfoDATEntries(int index, int nEntries, OP_InfoDATEntries* entries) override;
    virtual void setupParameters(OP_ParameterManager* manager, void* reserved) override;
    virtual void pulsePressed(const char* name, void* reserved) override;

private:
    std::vector<float> viewProjMatrix;  // 64 floats: 4 matrices (L/R View/Proj)
    bool initializeOpenXR();
    void updateMatrices();
    bool isInitialized;
    // OpenXR session objects would be declared here
};
