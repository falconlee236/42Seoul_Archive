# 42Seoul_Archive
M1이상 맥에서는 gcc와 함께 -arch x86_64 로 아키텍쳐를 전환하여 컴파일하도록 한다.

# pipex
왜 자식 프로세스에서는 free를 안해줘도 괜찮은가?

free를 해줘야하는 이유가 다른 프로세스가 접근 못하는 경우를 막기 위해서인데
자식 프로세스에는 exit를 하면서 모든 메모리를 다 회수해 나가기 때문에
다른 프로세스가 접근 가능하다.