#pragma once

#include <frc2/command/SubsystemBase.h>

#include <photon/PhotonCamera.h>

class PhotonVision : public frc2::SubsystemBase {
 public:
  PhotonVision();


  void  SetTargetId(int id);
  int   GetTargetId(void);
  bool  IsTargetValid(void);
  bool  IsTargetValidAndInRange(void);

  float GetTargetYaw(void);
  float GetTargetDistance(void);

  void Periodic() override;

 private:

  //photon::PhotonCamera camera{"photonvision"};
  photon::PhotonCamera camera{"Shooter-cam"};

  int   m_targetId;       //Target ID we are interested in looking for.
  bool  m_targetValid;
  float m_targetYaw;
  float m_targetDistance;


};
