## 실행 방법

### 주문 화면
~~~bash
ros2 run b4_serv_robot order
~~~

### 주방 모니터
~~~bash
ros2 run b4_serv_robot monitor
~~~

### 로봇 상태 화면
~~~bash
ros2 run b4_serv_robot robot
~~~

### DB 저장 노드 실행
~~~bash
ros2 run b4_serv_robot database
~~~

### Turtlebot3 gazebo 실행
~~~bash
export TURTLEBOT3_MODEL=burger
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
~~~

### Turtlebot3 nav2 실행
~~~bash
export TURTLEBOT3_MODEL=burger
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=$HOME/map.yaml
~~~
