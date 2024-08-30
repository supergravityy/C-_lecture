#include <stdio.h>

typedef struct USER
{
	int id;
	char name[32];
	void (*tempMethod) (struct USER* user);
}USER;

void printData(USER* user)
{
	printf("%d, %s", user->id, user->name);
}

// 제작자

/*---------------------------------------------------------*/
// C++에선 작성자의 입장과 사용자의 입장이 명확히 나뉘어야 한다.
// 이러한 관점에서는 이러한 스타일의 C코드는 확실히 이러한 조건을 충족시킬 수 없다.
/*---------------------------------------------------------*/

// 사용자

void main()
{
	USER user = { 10, "성수", printData };
	
	user.tempMethod(&user); 
	// C에서 구조체로 클래스를 흉내내볼수 있다.
	// 그러나, 클래스의 생성자 소멸자, 접근제어자 뿐만 아닌 핵심적인 부분에서 C++과의 차이가 존재한다.

	// C++에선 멤버함수 -> 메서드안에 this 포인터를 작성함으로써 &user와 같은 파라미터를 안써도 된다.
	// 만약 제작자측의 코드를 라이브러리로 작성하면, 사용자는 사용하기가 매우 불편하다 => 그래서 this 포인터가 나왔다.


	return 0;
}