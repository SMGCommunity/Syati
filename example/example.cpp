#include "syati.h"

// ********** RSM Functions ********** //
namespace RSM {
    /// @brief Called after all dependencies are loaded, all patching is complete and all static initializers are called.
    void onLoad() {

    }

    /// @brief Called before all dependencies are unloaded and all patching is reversed.
    void onUnload() {

    }
}

// ********** Hooking ********** //
// ----- Example usage of rsmCall/rsmBranch ----- //
    // Example Functions
    void sampleCallFunction(LiveActor *pActor) {
        MR::onCalcGravity(pActor); // restore original call
        OSReport("address hit\n");
    }

    void sampleBranchFunction() {
        OSReport("address hit\n");
    }

    // Using address-based hooks
    rsmCall(0x801B8ABC, sampleCallFunction);
    rsmBranch(0x801B8BE8, sampleBranchFunction);

    // Using symbol-based hooks
    extern rsmSymbol init__6KuriboFRC12JMapInfoIter;
    rsmSymCall(init__6KuriboFRC12JMapInfoIter, 0x7C, sampleCallFunction);
    rsmSymBranch(init__6KuriboFRC12JMapInfoIter, 0x1A8, sampleBranchFunction);

// ----- Example usage of rsmWrite ----- //
    // Using address-based hooks
    rsmWrite16(0x804C878E, 1);
    rsmWrite16(0x804C87EE, 1);

    // Using symbol-based hooks
    extern rsmSymbol isPermitToPlusPause__24PauseButtonCheckerInGameCFv;
    extern rsmSymbol isPermitToMinusPause__24PauseButtonCheckerInGameCFv;
    rsmSymWrite16(isPermitToPlusPause__24PauseButtonCheckerInGameCFv, 0x2E, 1);
    rsmSymWrite16(isPermitToPlusPause__24PauseButtonCheckerInGameCFv, 0x2E, 1);