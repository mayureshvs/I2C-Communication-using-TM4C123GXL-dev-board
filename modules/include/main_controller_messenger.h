#ifndef SWRAM_MODULES_MAIN_CONTROLLER_MESSENGER_H_
#define SWRAM_MODULES_MAIN_CONTROLLER_MESSENGER_H_

void initialize_main_controller_comms();

// Sends the current poses of other robots to the main controller
// pose_list [in] : Poses of other robots
// num_poses [in] : Number of poses to be send
// returns true if operation is successful, else false
bool send_poses_robots_to_main_controller(const tPoseStampedNamed pose_list[], const uint8_t num_poses);

#endif //SWRAM_MODULES_MAIN_CONTROLLER_MESSENGER_H_
