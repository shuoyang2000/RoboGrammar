#pragma once

#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <robot_design/types.h>
#include <vector>

namespace robot_design {

enum class JointType : Index { FREE, HINGE, FIXED };

struct Link {
  Link(Index parent, JointType joint_type, Scalar joint_pos, Scalar joint_yaw,
       Scalar joint_pitch, const Vector3 &joint_axis, Scalar length)
      : parent_(parent), joint_type_(joint_type), joint_pos_(joint_pos),
        joint_yaw_(joint_yaw), joint_pitch_(joint_pitch),
        joint_axis_(joint_axis), length_(length) {}

  // Parent link index (-1 for base link)
  Index parent_;
  // Joint type
  JointType joint_type_;
  // Joint position on parent link (0 = beginning, 1 = end)
  Scalar joint_pos_;
  // Joint yaw relative to parent link
  Scalar joint_yaw_;
  // Joint pitch relative to parent link
  Scalar joint_pitch_;
  // Joint axis relative to the joint frame (defined by previous 3 parameters)
  Vector3 joint_axis_;
  // Link length
  Scalar length_;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

struct Robot {
  std::vector<Link, Eigen::aligned_allocator<Link>> links_;
};

}  // namespace drbs
