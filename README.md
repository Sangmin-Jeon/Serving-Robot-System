# 음식점 서빙 로봇 시스템

<div style="display: flex; justify-content: space-between; align-items: center;">
  <img src="https://github.com/user-attachments/assets/e4f74c46-50d9-42e8-afc9-5f215d77e34a" alt="Image 2" width="50%" />
  <img src="https://github.com/user-attachments/assets/856dae45-87f8-419a-83f2-03113d89ef44" alt="Image 1" width="46%" />
</div>

## Overview
- **프로젝트 설명**: 음식점에서 로봇을 이용해서 주문이 들어오면 주문한 테이블로 음식을 서빙하는 로봇 자율 서빙 시스템입니다.
- **프로젝트 기간**: 2024.11.26 ~ 2024.12.2
- **팀 구성**: 3명

## 구현 내용 
| 기능    | 설명 |
|----------|---------------|
| 주문 테이블 오더 시스템 | 테이블에서 주문 정보를 주방에 전송 |, 
| 주방 모니터 | 테이블에서 주문 정보가 들어오면 확인 및 로봇 제어 |
| 로봇 모니터 | 로봇의 상태를 실시간으로 확인 | 
| DB 저장 및 통계 시스템 | 주문 정보를 DB에 저장하고 통계자료 생성 |

## 시스템 구성도
<img src="https://github.com/user-attachments/assets/e85c9882-98a7-44c6-bbc4-4d22aac16006" alt="Image 1" width="65%" />

## Tech / Skill
-	Ros2 humble  
-	Python  
-	Git     
-	OpenCV  
-	PyQt  
-	Turtlebot3 bugger


## Quick Start

### Order Display
~~~bash
ros2 run b4_serv_robot order
~~~

### Kitchen Monitor
~~~bash
ros2 run b4_serv_robot monitor
~~~

### Robot Display
~~~bash
ros2 run b4_serv_robot robot
~~~

### DB Node
~~~bash
ros2 run b4_serv_robot database
~~~

### Turtlebot3 Gazebo Execution
~~~bash
export TURTLEBOT3_MODEL=burger
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
~~~

### Turtlebot3 Navigation2 Execution
~~~bash
export TURTLEBOT3_MODEL=burger
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=$HOME/map.yaml
~~~
