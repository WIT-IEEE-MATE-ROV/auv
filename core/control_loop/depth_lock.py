import rospy
from auv.msg import bar30, ninedof, thrustermove

distance = 0
des_depth = 0 
cur_depth = 0
acc = [0,0] # [old,new], acceleration
val = [.5,.5] # [course, fine], Thruster move value
vel = [0,0] # [old,new], velocity

pub = rospy.Publisher('Depth_Lock',thrustermove, queue_size = 3)

def get_vel(data):
    data = data()
    acc[1] = data.translation.z
    if acc[0] != 0:
        vel[1] = vel[0]  +  acc[0]  +  ((acc[1]  -  acc[0])>>1)  
    acc[0] = acc[1]
    vel[0] = vel[1]
    return vel

def get_bar30(data):
    data = data()
    des_depth = #todo
    cur_depth = data.depth
    dist = (des_depth - cur_depth)
    abs_dist = abs(dist)
    
def listener():
    tm = thrustermove()
    rospy.Subscriber('bar30',bar30,get_bar30)
    if abs_dist < .5 : # checks if we are within range for fine adjustments 
        vel = rospy.Subscriber('ninedof',ninedof,get_vel) # get our velocity
        if vel > .1 && vel < -.1 : # fine thruster adjustment when we are inside our range
            if vel[1] > 0:
                if val >= .5 && val <= .8: # makes sure our thrusters dont break
                    val[1] += .01
            if vel[1] < 0:
                if val <= .5 && val >= 0: # makes sure our thrusters dont break
                    val[1] -= .01
            tm.top_front = val[1]
            tm.top_back = val[1]
            pub.publish(tm)

    if abs_dist > 1 || abs_dist < -1: # course thruster adjustment when we are outside our range
        val[0] = abs_dist / 3 # scales our thruster val over 3m so we ease into our fine adjustments
        direction = dist/abs_dist # gets +1 or -1 to determine direction
            if val[0]  > .8 || val < -.8:
                val[0] = .8  * direction
        tm.top_front = val[0]
        tm.top_back = val[0]
        pub.publish(tm)

    rospy.spin()

if __name__ == '__main__':
    listener()

