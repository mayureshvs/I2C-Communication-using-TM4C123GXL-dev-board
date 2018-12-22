#ifndef SWRAM_MODULES_SWRAM_MESSENGER_H_
#define SWRAM_MODULES_SWRAM_MESSENGER_H_

#include "utils.h"

void initialize_interrobot_comms();

// Sends the current pose of this robot to other robots
// current_pose [in] : Current pose of the robot
// returns true if operation is successful, else false
bool send_current_pose_of_this_robot_to_other_robots(const tPoseStampedNamed current_pose);

// Receives the poses of the other robots
// pose_list [out] : Poses of other robots
// num_poses [out] : Number of poses recieved
// returns true if operation is successful, else false
bool recieve_current_poses_of_other_robots(tPoseStampedNamed pose_list[], uint8_t* num_poses);

#endif //SWRAM_MODULES_SWRAM_MESSENGER_H_
