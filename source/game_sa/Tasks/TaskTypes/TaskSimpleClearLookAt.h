#pragma once

#include "TaskSimple.h"

class CPed;
class CEvent;
class CTaskSimpleClearLookAt;

class NOTSA_EXPORT_VTABLE CTaskSimpleClearLookAt : public CTaskSimple {
public:
    static void InjectHooks();

    constexpr static auto Type = eTaskType::TASK_SIMPLE_CLEAR_LOOK_AT;

    CTaskSimpleClearLookAt() = default;
    ~CTaskSimpleClearLookAt() = default;

    CTask*    Clone() override { return new CTaskSimpleClearLookAt(*this); }
    eTaskType GetTaskType() override { return Type; }
    bool      MakeAbortable(CPed* ped, eAbortPriority priority, CEvent const* event) override { return true; }
    bool      ProcessPed(CPed* ped) override;

private: // Wrappers for hooks
    // 0x634670
    CTaskSimpleClearLookAt* Constructor() {
        this->CTaskSimpleClearLookAt::CTaskSimpleClearLookAt();
        return this;
    }
    // 0x6346A0
    CTaskSimpleClearLookAt* Destructor() {
        this->CTaskSimpleClearLookAt::~CTaskSimpleClearLookAt();
        return this;
    }
};
