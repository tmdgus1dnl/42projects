# CPP Modules

> 42Seoul | C++98 | 점수: 각 모듈 100/100 | 모듈: CPP00 ~ CPP09

C++98 표준 기반의 OOP(객체지향 프로그래밍) 학습 프로젝트입니다.  
기초 클래스 설계부터 상속, 다형성, 예외 처리, 템플릿, STL까지 10개 모듈에 걸쳐 단계적으로 구현했습니다.

---

## 목차

- [모듈 개요](#모듈-개요)
- [CPP00 — C++ 기초](#cpp00--c-기초)
- [CPP01 — 메모리와 참조자](#cpp01--메모리와-참조자)
- [CPP02 — 연산자 오버로딩](#cpp02--연산자-오버로딩)
- [CPP03 — 상속](#cpp03--상속)
- [CPP04 — 다형성](#cpp04--다형성)
- [CPP05 — 예외 처리](#cpp05--예외-처리)
- [CPP06 — 타입 캐스팅](#cpp06--타입-캐스팅)
- [CPP07 — 템플릿](#cpp07--템플릿)
- [CPP08 — STL 컨테이너](#cpp08--stl-컨테이너)
- [CPP09 — STL 심화](#cpp09--stl-심화)
- [공통 규칙](#공통-규칙)
- [깨달은 점](#깨달은-점)

---

## 모듈 개요

| 모듈 | 주제 | 핵심 개념 |
|---|---|---|
| CPP00 | C++ 기초 | 클래스, 멤버 함수, 입출력 스트림 |
| CPP01 | 메모리와 참조자 | new/delete, 참조자, 파일 스트림 |
| CPP02 | 연산자 오버로딩 | 고정소수점 클래스, Orthodox Canonical Form |
| CPP03 | 상속 | 기반/파생 클래스, 생성자/소멸자 체이닝 |
| CPP04 | 다형성 | 가상 함수, 순수 추상 클래스, 인터페이스 |
| CPP05 | 예외 처리 | exception 클래스, try/catch |
| CPP06 | 타입 캐스팅 | static_cast, dynamic_cast, reinterpret_cast |
| CPP07 | 템플릿 | 함수/클래스 템플릿 |
| CPP08 | STL 컨테이너 | 이터레이터, STL 알고리즘 |
| CPP09 | STL 심화 | BitcoinExchange, RPN, Ford-Johnson 정렬 |

---

## CPP00 — C++ 기초

C의 절차적 프로그래밍과 C++의 객체지향 프로그래밍의 차이를 이해하는 첫 모듈입니다.

**주요 구현**
- 전화번호부 프로그램 — `PhoneBook` 클래스와 `Contact` 클래스로 연락처 관리
- 클래스 내 멤버 변수는 `private`, 접근은 `getter/setter`로만 허용
- `std::cin` / `std::cout` 으로 입출력 처리
- C의 `printf` 대신 `std::cout` 사용 (C++ 스타일 강제)

**C와의 차이**  
C에서는 구조체에 함수를 넣을 수 없지만 C++에서는 클래스에 데이터와 함수를 함께 묶습니다.  
`private` 접근 제한으로 외부에서 직접 데이터를 수정할 수 없게 캡슐화합니다.

---

## CPP01 — 메모리와 참조자

힙 메모리 관리와 포인터/참조자의 차이를 다룹니다.

**주요 구현**
- `new` / `delete` — 힙 메모리 동적 할당 및 해제
- 포인터 vs 참조자 — 같은 동작을 포인터와 참조자 두 가지 방식으로 구현하고 차이 비교
- 파일 스트림 — `std::ifstream`으로 파일을 열고 문자열 치환 후 저장

**포인터 vs 참조자**

| | 포인터 | 참조자 |
|---|---|---|
| NULL 가능 여부 | 가능 | 불가 (항상 유효한 객체 참조) |
| 재할당 | 가능 | 불가 (선언 시 한 번만 바인딩) |
| 역참조 | `*ptr` | 변수명 그대로 사용 |

---

## CPP02 — 연산자 오버로딩

고정소수점(Fixed Point) 수 클래스를 구현하며 연산자 오버로딩과 Orthodox Canonical Form을 학습합니다.

**Orthodox Canonical Form**  
C++ 클래스가 갖춰야 할 4가지 기본 형태입니다.

```cpp
class Fixed {
public:
    Fixed();                            // 기본 생성자
    Fixed(const Fixed &other);          // 복사 생성자
    Fixed &operator=(const Fixed &rhs); // 복사 대입 연산자
    ~Fixed();                           // 소멸자
};
```

**연산자 오버로딩**
- 비교 연산자: `>`, `<`, `>=`, `<=`, `==`, `!=`
- 산술 연산자: `+`, `-`, `*`, `/`
- 증감 연산자: `++`, `--` (전위/후위 구분)
- 스트림 연산자: `<<` (출력용)

**고정소수점 표현**  
정수 비트와 소수 비트로 나눠 실수를 정수로 표현합니다.  
`int _rawBits`에 값을 저장하고 8비트를 소수부로 사용합니다.

---

## CPP03 — 상속

클래스 계층 구조와 생성자/소멸자 체이닝을 학습합니다.

**주요 구현**  
`ClapTrap` → `ScavTrap` → `FragTrap` 상속 계층 구현  
`DiamondTrap`이 `ScavTrap`과 `FragTrap`을 동시에 상속하는 **다중 상속** 및 **다이아몬드 문제** 처리

**다이아몬드 문제**  
`D`가 `B`, `C`를 상속하고 `B`, `C` 둘 다 `A`를 상속할 때,  
`D`가 `A`의 멤버를 두 벌 가지는 문제가 발생합니다.  
`virtual` 상속으로 기반 클래스를 한 벌만 공유하도록 해결합니다.

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

**생성자/소멸자 체이닝**  
파생 클래스 생성 시 기반 클래스 생성자가 먼저 호출되고,  
소멸 시에는 반대 순서로 소멸자가 호출됩니다.

---

## CPP04 — 다형성

가상 함수와 순수 추상 클래스를 통한 런타임 다형성을 구현합니다.

**가상 함수**  
기반 클래스 포인터로 파생 클래스 객체를 가리킬 때, 어떤 함수를 호출할지 **런타임에 결정**합니다.

```cpp
Animal *a = new Dog();
a->makeSound(); // Dog의 makeSound()가 호출됨 (가상 함수)
```

**가상 소멸자**  
기반 클래스 포인터로 파생 클래스 객체를 삭제할 때, 소멸자를 `virtual`로 선언하지 않으면 파생 클래스 소멸자가 호출되지 않아 메모리 누수가 발생합니다.

**순수 가상 함수 / 추상 클래스**  
`virtual void func() = 0;`으로 선언하면 인스턴스화할 수 없는 추상 클래스가 됩니다.  
파생 클래스에서 반드시 구현해야 하는 인터페이스를 강제할 때 사용합니다.

**딥 카피**  
포인터 멤버 변수를 가진 클래스에서 복사 생성자와 대입 연산자가 포인터 자체가 아닌 **가리키는 데이터를 복사**하도록 구현합니다.

---

## CPP05 — 예외 처리

예외 안전한(exception-safe) 클래스 설계를 학습합니다.

**주요 구현**  
관료제 시스템 — `Bureaucrat`과 `Form` 클래스 계층으로 예외 처리 시나리오 구현

**예외 클래스 설계**

```cpp
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
        const char *what() const throw() {
            return "Grade is too high";
        }
    };
    class GradeTooLowException : public std::exception { ... };
};
```

- `std::exception`을 상속해 커스텀 예외 클래스 작성
- `what()` 메서드로 오류 메시지 반환
- `throw()` 명세로 예외 던지지 않음을 보장

**try / catch**

```cpp
try {
    Bureaucrat b("Bob", 0);  // 유효 범위 초과 → 예외 발생
} catch (std::exception &e) {
    std::cout << e.what() << std::endl;
}
```

---

## CPP06 — 타입 캐스팅

C++의 4가지 캐스트 연산자를 학습합니다.

| 캐스트 | 용도 |
|---|---|
| `static_cast` | 컴파일 타임 타입 변환. 관련 있는 타입 간 변환 (`int` → `float`, 기반/파생 클래스 등) |
| `dynamic_cast` | 런타임 타입 변환. 상속 계층에서 안전한 다운캐스팅. 실패 시 `nullptr` 반환 |
| `reinterpret_cast` | 비트 패턴을 다른 타입으로 재해석. 포인터 ↔ 정수 등 위험한 변환 |
| `const_cast` | `const` 속성 추가/제거 |

**Scalar 변환기**  
문자열 리터럴을 `char`, `int`, `float`, `double`로 변환해 출력하는 프로그램 구현.  
각 타입으로의 변환 가능 여부와 오버플로우, 출력 불가 문자 등 예외 케이스를 처리합니다.

---

## CPP07 — 템플릿

타입에 의존하지 않는 범용 코드를 작성합니다.

**함수 템플릿**

```cpp
template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
```

어떤 타입이든 같은 로직을 적용할 수 있습니다. 컴파일 시점에 타입이 결정되어 코드가 생성됩니다.

**클래스 템플릿**  
범용 배열 컨테이너 `Array<T>` 구현.  
- 크기 지정 생성, 범위 초과 접근 시 예외 발생
- `operator[]` 오버로딩으로 배열처럼 접근
- 복사 생성자/대입 연산자에서 딥 카피

---

## CPP08 — STL 컨테이너

STL(Standard Template Library) 컨테이너, 이터레이터, 알고리즘을 실제로 활용합니다.

**easyfind**  
`std::find`를 래핑한 함수 템플릿. 컨테이너에서 값을 찾지 못하면 예외 발생.

**Span**  
정수를 저장하는 컨테이너 클래스. `shortestSpan()`과 `longestSpan()`으로 최소/최대 간격 계산.  
`std::vector`로 내부 저장, `std::sort` + `std::adjacent_difference`로 간격 계산.

**MutantStack**  
`std::stack`을 상속해 이터레이터를 지원하도록 확장.  
`std::stack`은 이터레이터가 없어 범위 기반 순회가 불가능한데, 내부 컨테이너(`std::deque`)의 이터레이터를 노출시켜 해결합니다.

---

## CPP09 — STL 심화

STL 컨테이너의 특성 차이를 이해하고 알고리즘에 맞는 컨테이너를 선택합니다.

**BitcoinExchange**  
CSV 파일에서 날짜별 비트코인 환율을 읽어 `std::map`에 저장.  
입력 파일의 날짜와 금액을 파싱해 가장 가까운 날짜의 환율로 계산.  
`std::map::lower_bound()`로 날짜 탐색 구현.

**RPN (역폴란드 표기법)**  
`std::stack`으로 후위 표기식을 계산.  
피연산자는 push, 연산자가 나오면 두 개를 pop해 계산 후 push.

**Ford-Johnson 병합 삽입 정렬**  
`std::vector`와 `std::list` 두 가지 컨테이너로 각각 구현.  
비교 횟수를 이론적 최소로 줄이는 정렬 알고리즘.

| 컨테이너 | 임의 접근 | 삽입/삭제 | 메모리 |
|---|---|---|---|
| `std::vector` | O(1) | O(n) | 연속 |
| `std::list` | O(n) | O(1) | 비연속 |
| `std::map` | O(log n) | O(log n) | 트리 |
| `std::stack` | 불가 | O(1) | `deque` 기반 |

---

## 공통 규칙

모든 모듈에 공통으로 적용되는 C++98 제약 사항입니다.

- `using namespace std` 금지 — 네임스페이스를 명시적으로 사용 (`std::cout` 등)
- C++ 헤더만 사용 (`<string>`, `<iostream>` 등, `<string.h>` 금지)
- 메모리 누수 없어야 함 — `new`로 할당한 메모리는 반드시 `delete`
- Orthodox Canonical Form 준수 — 클래스마다 4가지 기본 멤버 함수 구현
- `friend` 키워드 사용 금지 (일부 예외 허용)
- STL 사용 제한 — CPP08 이전에는 STL 컨테이너/알고리즘 사용 불가

---

## 깨달은 점

**캡슐화는 코드를 안전하게 만든다**  
`private` 멤버와 `getter/setter`로 데이터 접근을 제한하면, 외부에서 잘못된 방식으로 데이터를 건드리는 실수를 컴파일 타임에 잡을 수 있습니다.

**가상 소멸자를 항상 신경 써야 한다**  
기반 클래스 포인터로 파생 클래스를 다룰 때, 소멸자가 `virtual`이 아니면 메모리 누수가 발생합니다. 상속 계층이 있는 클래스는 소멸자를 반드시 `virtual`로 선언해야 합니다.

**템플릿은 타입을 추상화한다**  
같은 알고리즘을 여러 타입에 적용할 때 코드를 중복 작성하지 않아도 됩니다. 컴파일 시점에 타입이 결정되므로 런타임 오버헤드도 없습니다.

**컨테이너마다 성능 특성이 다르다**  
`vector`는 임의 접근이 빠르고, `list`는 삽입/삭제가 빠릅니다. 알고리즘이 어떤 연산을 많이 하느냐에 따라 컨테이너 선택이 성능에 직접 영향을 줍니다.

**C++98은 현대 C++과 많이 다르다**  
범위 기반 for문, `auto`, `nullptr`, `std::to_string` 등 현대 C++에서 당연히 쓰는 기능들이 C++98에서는 없습니다. 제약 안에서 문제를 해결하다 보니 오히려 언어의 기반 동작 원리를 더 깊이 이해하게 됐습니다.

---

## 사용 기술

`C++98` `OOP` `상속` `다형성` `가상 함수` `연산자 오버로딩` `템플릿` `STL` `예외 처리` `Orthodox Canonical Form`
