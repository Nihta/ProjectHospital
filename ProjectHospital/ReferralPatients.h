﻿#pragma once
#include "Patients.h"

// Class bệnh nhân chuyển viện
class ReferralPatients :
    public Patients
{
private:
    // Ngày chuyển
    Date tranferDate;
    // Nơi chuyển
    string transferPlace;
public:
    ReferralPatients();
    ReferralPatients(string id, string n, string dB, bool gen, string dia, string tD, string tP);
    void display();
    ~ReferralPatients();
};
