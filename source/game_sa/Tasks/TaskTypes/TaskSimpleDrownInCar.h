#pragma once

#include "TaskSimple.h"

class CTaskSimpleDrownInCar : public CTaskSimple {
public:
    static constexpr auto Type = TASK_SIMPLE_DROWN_IN_CAR;

    CTaskSimpleDrownInCar() = default;  // 0x62FF20
    ~CTaskSimpleDrownInCar() override = default; // 0x62FF60

    eTaskType GetTaskType() override { return Type; }; // 0x62FF40
    bool MakeAbortable(CPed* ped, eAbortPriority priority, const CEvent* event) override { return false; } // 0x62FF50
    CTask* Clone() override { return new CTaskSimpleDrownInCar(); } // 0x636010
    bool ProcessPed(CPed* ped) override;

private:
    friend void InjectHooksMain();
    static void InjectHooks();

    bool ProcessPed_Reversed(CPed* ped);
};
