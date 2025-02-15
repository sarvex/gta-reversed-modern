#pragma once

#include "TaskComplexPartner.h"

class CTaskComplexPartnerChat : public CTaskComplexPartner {
public:
    int32 field_70;
    bool m_conversationEnabled;
    char field_75;
    bool m_pedConversationLoaded;

public:
    static constexpr auto Type = TASK_COMPLEX_PARTNER_CHAT;

    CTaskComplexPartnerChat(const char* commandName, CPed* partner, bool leadSpeaker, float distanceMultiplier, int8 updateDirectionCount, bool conversationEnabled, bool a8, CVector point);
    ~CTaskComplexPartnerChat() override;

    eTaskType GetTaskType() override { return Type; }
    CTask* Clone() override { return new CTaskComplexPartnerChat(m_commandName, m_partner, m_leadSpeaker,  m_distanceMultiplier, m_updateDirectionCount, m_conversationEnabled, field_75, m_point); }
    bool MakeAbortable(CPed* ped, eAbortPriority priority, const CEvent* event) override;
    virtual CTaskComplexSequence* GetPartnerSequence();

    static void InjectHooks();
    CTaskComplexPartnerChat* Constructor(const char* commandName, CPed* partner, bool leadSpeaker, float distanceMultiplier, int8 updateDirectionCount, bool conversationEnabled, bool a8, CVector point);
};
VALIDATE_SIZE(CTaskComplexPartnerChat, 0x78);
