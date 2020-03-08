import rospy
from auv.msg import bar30, ninedof, surface_command

distance = 0
des_depth = 0 
cur_depth = 0
acc = [0,0] # [old,new], acceleration
val = [0,0] # [course, fine], Thruster move value
vel = [0,0] # [old,new], velocity 
toggle = bool


pub = rospy.Publisher('Depth_Lock',ninedof, queue_size = 3)

def check_toggle(data):
    data = data()
    toggle = data.button_state.depth_lock

def get_des_depth(data)
    data = data()
    des_depth = data.depth

def get_vel(data):
    data = data()
    acc[1] = data.translation.z
    if acc[0] != 0:
        vel[1] = vel[0]  +  acc[0]  +  ((acc[1]  -  acc[0])>>1)  
    acc[0] = acc[1]
    vel[0] = vel[1]

def get_bar30(data):
    data = data()
    cur_depth = data.depth
    dist = (des_depth - cur_depth)
    abs_dist = abs(dist)
    
def listener():
    nd = ninedof()
    rospy.Subscriber('bar30',bar30,get_bar30)

    if abs_dist >= .1 || abs_dist <= -.1: # course thruster adjustment when we are outside our range
        val[0] = abs_dist / 2 # scales our thruster val over 3m so we ease into our fine adjustments
        direction = dist/abs_dist # gets +1 or -1 to determine direction
        if val[0]  > .8 || val < -.8: # if our distance is greater than 2m lock our thruster at a set max so they dont break
            val[0] = .8
        val[0] = val[0] * direction 
        nd.translation.z = val[0]
        pub.publish(nd)

    if abs_dist < .1 : # checks if we are within range for fine adjustments 
        rospy.Subscriber('ninedof',ninedof,get_vel) # get our velocity
        if vel[1] > .1 || vel[1] < -.1 : # fine thruster adjustment when we are inside our range
            if vel[1] > 0:
                val[1] += .01
                if val[1] < .8: # makes sure our thrusters dont break
                    val[1] = .8
            if vel[1] < 0:
                val[1] -= .01
                if val[1] < -.8 # makes sure our thrusters dont break
                    val[1] = -.8
            nd.translation.z = val[1]
            pub.publish(nd)

if __name__ == '__main__':
    rospy.Subscriber('surface_command',surface_command,check_toggle)
    if toggle = True:
        rospy.Subscriber('bar30',bar30,get_des_depth)
        while toggle = True:
            listener()
            rospy.Subscriber('surface_command',surface_command,check_toggle)
    rospy.spin()

