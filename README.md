# ft_irc

## 앞으로 해야할 것
1. Channel 생성 
- kick
    - Channel 클래스에 있는 사람 내보내기
-  invite
    - Channel 클래스에 nickname을 통해 사람 초대하기
-  topic
    - Channel 방주제 설정(std::string topicTitle;)
-  mode - 가장 할 것 많음
    - i: 초대 전용 채널 설정/제거
    - t: 채널 운영자에 대한 TOPIC 명령 제한 설정/제거
    - k : 채널키(비밀번호) 설정/제거
    - o : 채널 운영자 권한 부여/받기
    - l: 채널에 대한 사용자 제한을 설정/해제

- *Server에서 해야할 거*
    - join 명령어 사용 시 없는 채널이면 자동 생성되고 만든 사람이 방장임. 
    - Join 후 반장은 한 명이며, 반장이 반장 권한을 줄 수 있음. -> op명령어도 만들자는 얘긴가요 ?? 안해도 될 것 같은데 !-> 확인 중~~ 
    -> 근데 operators라고 쓰여있어서 필요할지도..?

PART 명령어 : 채널 떠나는 역할인데 server에서 하실지 channel에서 하실지 ?

채널에서 하면 될듯?
---

2. Reply
    -  PASS, NICK, USER 후에 001 welcome.. 뭐시기 보내줘야함
    -  PASS ERROR 등등 노션에 정리해두심
    -  닉네임 중복일 때 보내는 에러

3. Client별 buffer 처리
    - 데이터가 한 번에 안들어 오고 조금씩 들어올 때 CR-LF ("\r\n") 이 들어오기 전까지는 처리하지말고 들고 있어야함.

4. 데이터 주고 받을 시
    -  send도 바로 보내지말고 kqueue릍 통해서 보내야함
    -  write 할 수 있을 때

## 해야되나...?

1. ping-pong 명령어 -> 일단 이거 했습니다. 적용을 해야할지,,?

2. 파일 전송

3. 파란 앵무새 봇

