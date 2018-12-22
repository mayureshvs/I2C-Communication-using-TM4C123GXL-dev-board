#ifndef SWRAM_MODULES_UTILS_H_
#define SWRAM_MODULES_UTILS_H_

typedef struct{
	int x;
	int y;
	int z;
	int roll;
	int pitch;
	int yaw;
}tPose;

typedef struct{
	uint32_t timestamp;  //TODO: Find out the correct representation
	tPose pose;
}tPoseStamped;

typedef struct{
	uint8_t id;
	tPoseStamped pose_stamped;
}tPoseStampedNamed;

void initialize_microcontroller();
void initialize_encoders();

// Reads the current pose of this robot
// current_pose [out] : Current pose of the robot
// returns true if operation is successful, else false
bool get_current_pose_of_this_robot(tPoseStamped* current_pose);

#endif // SWRAM_MODULES_UTILS_H_ 
