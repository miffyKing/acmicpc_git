# HTTP

[인프런 | 김영한] 모든 개발자를 위한 HTTP 웹 기본 지식 (2023.01.27. ~ 2023.02.05.)

## 인터넷 네트워크
### 인터넷 통신
**IP(인터넷 프로토콜)의 역할**
- 지정한 IP 주소(IP Address)에 데이터 전달
- 패킷(Packet)이라는 통신 단위로 데이터 전달

**TCP(전송 제어 프로토콜)의 특징**
- 연결지향 - TCP 3 way handshake(가상 연결)
- 데이터 전달 보증
- 순서 보장

**UDP(사용자 데이터그램 프로토콜) 특징**
- 하얀 도화지에 비유(기능이 거의 없음)
- 데이터 전달 및 순서가 보장되지 않지만, 단순하고 빠름
- IP와 거의 같다. +PORT +체크섬 정도만 추가
- 애플리케이션에서 추가 작업 필요

**PORT**
- 같은 IP내에서 프로세스 구분
- 0 ~ 65535 할당 가능
- 0 ~ 1023: 잘 알려진 포트, 사용하지 않는 것이 좋음
  - FTP - 20, 21
  - TELNET - 23
  - HTTP - 80
  - HTTPS - 443

**DNS**
- 도메인 네임 시스템(Domain Name System)
- 전화번호부
- 도메인 명을 IP 주소로 변환

## URI와 웹 브라우저 요청 흐름
### URI
- URI(Resource Identifier)
  - Uniform: 리소스 식별하는 통일된 방식
  - Resource: 자원, URI로 식별할 수 있는 모든 것 (제한 없음)
  - Identifier: 다른 항목과 구분하는데 필요한 정보
- URL(Resource Locator)
  - Locator: 리소스가 있는 위치를 지정
- URN(Resource Name)
  - Name: 리소스에 이름을 부여

### URL 전체 문법
- scheme://[userinfo@]host[:port][/path][?query][#fragment]
- https://www.google.com:443/search?q=hello&hl=ko
  - scheme
    - 주로 프로토콜 사용
    - 프로토콜: 어떤 방식으로 자원에 접근할 것인가 하는 약속 규칙
    - 예) http, https, ftp 등등
    - http는 80포트, https는 443포트를 주로 사용, 포트는 생략 가능
    - https는 http에 보안 추가 (HTTP Secure)
  - userinfo
    - URL에 사용자정보를 포함해서 인증
    - 거의 사용하지 않음
  - 호스트명
    - 도메인명 또는 IP 주소를 직접 사용가능
  - PORT
    - 일반적으로 생략, 생략시 http는 80, https는 443
  - path
    - 리소스 경로(path), 계층적 구조
    - 예) 
      - /home/file1.jpg
      - /members
      - /members/100, /itmes/ihone12
  - query
    - key=value 형태
    - ?로시작, &로 추가 가능 ?keyA=valueA&keyB=valueB
    - query parameter, query string 등으로 불림, 웹서버에 제공하는 파라미터, 문자 형태
  - fragment
    - html 내부 북마크 등에 사용
    - 서버에 전송하는 정보 아님
### 웹 브라우저 요청 흐름
- https://www.google.com:443/search?q=hello&hl=ko
- 예) 웹 브라우저(IP: 100.100.100.1), 구글 서버(IP: 200.200.200.2)
1. 웹 브라우저가 DNS 서버를 조회 -> IP: 200.200.200.2와 포트(443) 정보 획득
2. HTTP 요청 메시지 생성
```
GET /search?q=hello&hl=ko HTTP/1.1
HOST: www.google.com
```
3. SOCKET 라이브러리를 통해 전달
   - A: TCP/IP 연결(IP, PORT)
   - B: 데이터 전달
4. TCP/IP 패킷 생성, HTTP 메시지 포함, 서버로 전송
5. 서버에서 HTTP 응답 메시지 생성
```
HTTP/1.1 200 OK
Content-Type: text/html;charset=UTF-8
Content-Length: 3423

<html>
  <body>...</body>
</html>
```
6. 웹 브라우저 HTML 렌더링

## HTTP 기본
- HTTP: HyperText Transfer Protocol
- 거의 모든 형태의 데이터 전송 가능
- 서버간에 데이터를 주고 받을 때도 대부분 HTTP 사용
### HTTP 특징
#### 클라이언트 서버 구조
- Request Response 구조
- 클라이언트는 서버에 요청을 보내고, 응답을 대기
- 서버가 요청에 대한 결과를 만들어서 응답
#### 무상태 프로토콜(스테이스리스)
- 서버가 클라이언트의 상태를 보존X
- 장점: 서버 확장성 높음(스케일 아웃)
  - 갑자기 고객이 증가해도 점원을 대거 투입할 수 있다.
  - 갑자기 클라이언트 요청이 증가해도 서버를 대거 투입할 수 있다.
  - 무한한 서버 증설 가능
  - 단점: 클라이언트가 추가 데이터 전송
#### 실무 한계
- 모든 것을 무상태로 설계 할 수 있는 경우도 있고 없는 경우도 있다.
- 무상태
  - 예) 로그인이 필요 없는 단순한 서비스 소개 화면
- 상태 유지
  - 예) 로그인
- 로그인한 사용자의 경우 로그인 했다는 상태를 서버에 유지
- 일반적으로 브라우저 쿠키와 서버 세션등을 사용해서 상태 유지
- 상태 유지는 최소한만 사용
#### 비연결성
- HTTP는 기본이 연결을 유지하지 않는 모델
- 일반적으로 초 단위의 이하의 빠른 속도로 응답
- 1시간 동안 수천명이 서비스를 사용해도 실제 서버에서 동시에 처리하는 요청은 수십개 이하로 매우 작음
- 서버 자원을 매우 효율적으로 사용할 수 있음 
#### HTTP 메시지
##### 메시지 구조
```
start-line 시작 라인
header 헤더
empty line 공백 라인 (CRLF)
message body
```
1. **시작 라인**
- start-line = request-line / status-line 
  - 요청메시지
    - request-line = method SP(공백) request-target SP HTTP-version CRLF(엔터)
      - HTTP 메서드
      - 요청 대상 (/search?q=hello&hl=ko)
      - HTTP version
  - 응답메시지
    - status-line = HTTP-version SP status-code SP reason-phrase CRLF
      - HTTP 버전
      - HTTP 상태코드: 요청 성공, 실패를 나타냄
        - 200: 성공
        - 400: 클라이언트 요청 오류
        - 500: 서버 내부 오류
      - 이유 문구: 사람이 이해할 수 있는 짧은 상태 코드 설명 글

2. **헤더**
- HTTP 전송에 필요한 모든 부가정보
  - 예) 메시지 바디의 내용, 메시지 바디의 크기, 압축, 인증, 요청 클라이언트(브라우저) 정보, 서버 애플리케이션 정보, 캐시 관리 정보
- 표준 헤더가 너무 많음
- 필요시 임의의 헤더 추가 가능

3. **메시지 바디**
- 실제 전송할 데이터
- HTML 문서, 이미지, 영상, JSON 등등 byte로 표현할 수 있는 모든 데이터 전송 가능

## HTTP 메서드
URI 설계에서 가장 중요한 것은 **리소스 식별**이다.
### 리소스의 의미
- 회원을 등록하고 수정하고 조회하는게 리소스가 아니다.
- 예) 미네랄을 캐라 -> 미네랄이 리소스
- 회원이라는 개념 자체가 리소스이다.
- 회원을 등록하고 수정하고 조회하는 것을 모두 배제
- 회원이라는 리소스만 식별하면 된다 -> 회원 리소스를 URI에 매핑

### API URI 설계
- 리소스와 행위를 분리해야한다.
  - 리소스: 회원
  - 행위: 조회, 등록, 삭제, 변경
- 리소스는 명사, 행위는 동사

### HTTP 메서드 종류
#### 주요 메서드
- GET: 리소스 조회
  - 서버에 전달하고 싶은 데이터는 query(쿼리 파라미터, 쿼리 스트링)를 통해서 전달
  - 메시지 바디를 사용해서 데이터를 전달 할 수 있지만, 지원하지 않는 곳이 많아서 권장하지 않음
- POST: 요청 데이터 처리, 주로 등록에 사용
  - 메시지 바디를 통해 서버로 요청 데이터 전달
  - 서버는 요청 데이터를 처리
    - 메시지 바디를 통해 들어온 데이터를 처리하는 모든 기능을 수행한다.
  - 주로 전달된 데이터로 신규 리소스 등록, 프로세스 처리에 사용
- PUT:  리소스를 대체, 해당 리소스가 없으면 생성
  - 클라이언트가 리소스 위치를 알고 URI 지정
- PATCH: 리소스 부분 변경
- DELETE: 리소스 삭제
#### 기타 메서드
- HEAD: GET과 동일하지만, 메시지 부분을 제외하고, 상태 줄과 헤더만 반환
- OPTIONS: 대상 리소스에 대한 통신 가능 옵션(메서드)을 설명(주로 CORS에서 사용)
- CONNECT: 대상 자원을 식별되는 서버에 대한 터널을 설정
- TRACE: 대상 리소스에 대한 경로를 따라 메시지 루프백 테스트를 수행

#### 참고하면 좋은 URI 설계 개념
- 문서(document)
  - 단일 개념(파일 하나, 객체 인스턴스, 데이터베이스 row)
  - 예) /members/100, /files/star.jpg
- 컬렉션(collection)
  - 서버가 관리하는 리소스 디렉터리
  - 서버가 리소스의 URI를 생성하고 관리
  - 예) /members
- 스토어(store)
  - 클라이언트가 관리하는 자원 저장소
  - 클라이언트가 리소스의 URI를 알고 관리
- 컨트롤러(controller), 컨트롤 URI
  - 문서, 컬렉션, 스토어로 해결하기 어려운 추가 프로세스 실행
  - 동사를 직접 사용
  - 예) /members/{id}/delete

### HTTP 상태코드
#### 2xx (Successful): 요청 정상 처리
  - 200 OK
  - 201 Created
  - 202 Accepted
  - 204 No Content 
#### 3xx (Redirection): 요청을 완료하려면 추가 행동이 필요 
  - 리다이렉트: 웹 브라우저는 3xx 응답의 결과에 Location 헤더가 있으면, Location 위치로 자동 이동
    - 영구 리다이렉션 - 특정 리소스의 URI가 영구적으로 이동
      - 원래의 URL를 사용X, 검색 엔진 등에서도 변경 인지
      - 301 Moved Permanently
        - 리다이렉트시 요청 메서드가 GET으로 변하고, 본문이 제거될 수 있음(MAY)
      - 308 Permanent Redirect
        - 301과 기능은 같음
        - 리다이렉트시 요청 메서드와 본문 유지(처음 POST를 보내면 리다이렉트도인지)
    - 일시 리다이렉션 - 일시적인 변경
      - 리소스의 URI가 일시적으로 변경
      - 302 Found
        - 리다이렉트시 요청 메서드가 GET으로 변하고, 본문이 제거될 수 있음(MAY)
      - 307 Temporary Redirect
        - 302와 기능은 같음
        - 리다이렉트시 요청 메서드와 본문 유지(요청 메서드를 변경하면 안된다. MUST NOT)
      - 303 See Other
        - 302와 기능은 같음
        - 리다이렉트시 요청 메서드가 GET으로 변경
      -PRG: Post/Redirect/Get
        - 예시) POST로 주문후에 새로 고침으로 인한 중복 주문방지
        - POST로 주문후에 주문 결화 화면을 GET 메서드로 리다이렉트
        - 새로고침해도 결과 화면을 GET으로 조회
        - 중복 주문 대신에 결과 화면만 GET으로 다시 요청
    - 특수 리다이렉션
      - 300 Multiple Choices : 안쓴다
      - 304 Not Modified
        - 캐시를 목적으로 사용
        - 클라이언트에게 리소스가 수정되지 않았음을 알려준다.
        - 따라서 클라이언트는 로컬 PC에 저장된 캐시를 재사용한다.(캐시로 리다이렉트 한다.)
#### 4xx (Client Error): 클라이언트 오류, 잘못된 문법등으로 서버가 요청을 수행할 수 없음
  - 오류의 원인이 클라이언트에 있음
  - 클라이언트가 이미 잘못된 요청, 데이터를 보내고 있기 때문에, 똑같은 재시도가 실패함
  - 400 Bad Request
    - 요청 구문, 메시지 등등 오류
    - 클라이언트가 잘못된 요청을 해서 서버가 요청을 처리할 수 없음
    - 예) 요청 파라미터가 잘못되거나, API 스펙이 맞지 않을 때
  - 401 Unauthorized
    - 클라이언트가 해당 리소스에 대한 인증이 필요함
  - 403 Forbidden
    - 서버가 요청을 이해했지만 승인을 거부함
    - 주로 인증 자격 증명은 있지만, 접근 권한이 불충분한 경우
  - 404 Not Found
    - 요청 리소스가 서버에 없음
#### 5xx (Server Error): 서버 오류, 서버가 정상 요청을 처리하지 못함
  - 500 Internal Server Error
    - 서버 문제로 오류 발생, 애매하면 500 오류
  - 503 Service Unavailable
    - 서비스 이용 불가
    - 서버가 일시적인 과부하 또는 예정된 작업으로 잠시 요청을 처리할 수 없음

## HTTP 헤더

### 용도
HTTP 전송에 필요한 모든 부가정보
### 표현
- Content-Type: 표현 데이터의 형식
  - 미디어 타입, 문자 인코딩
  - 예) 
    - text/html; charset=utf-8
    - application/json
    - image/png
- Content-Encoding: 표현 데이터의 압축 방식
  - 표현 데이터를 압축하기 위해 사용
  - 데이터를 전달하는 곳에서 압축 후 인코딩 헤더 추가
  - 데이터를 읽는 쪽에서 인코딩 헤더의 정보로 압축 해제
  - 예)
    - gzip
    - deflate
    - identity
- Content-Language: 표현 데이터의 자연 언어
  - 표현 데이터의 자연 언어를 표현
  - 예) 
    - ko
    - en
    - en-US
- Content-Length: 표현 데이터의 길이
  - 바이트 단위
  - Transfer-Encoding(전송 코딩)을 사용하면 Content-Length를 사용하면 안됨
### 협상
클라이언트가 선호하는 표현 요청
- Accept: 클라이언트가 선호하는 미디어 타입 전달
- Accept-Charset: 클라이언트가 선호하는 압축 인코딩
- Accept-Encoding: 클라이언트가 선호하는 압축 인코딩
- Accept-Language: 클라이언트가 선호하는 자연 언어

### 전송 방식
- 단순 전송
- 압축 전송
- 분할 전송
- 범위 전송

### 일반 정보
#### From
유저 에이전트의 이메일 정보
- 검색 엔진 같은 곳에서 주로 사용
#### Referer
이전 웹 페이지 주소
- 현재 요청된 페이지의 이전 퓁 페이지 주소
- A->B로 이동하는 경우 B를 요철할 때 Referer: A를 포함해서 요청
- Referer를 사용해서 유입 경로 분석 가능
- 요청에서 사용
#### User-Agent
유저 에이전트 애플리케이션 정보
- 클라이언트의 애플리케이션 정보(웹 브라우저 정보)
- 통계 정보
- 어떤 종류의 브라우저에서 장애가 발생하는지 파악 가능
- 요청에서 사용
#### Server
요청을 처리하는 ORIGIN 서버의 소프트웨어 정보
- Server: Apache/2.2.22(Debian)
- server:nginx
- 응답에서 사용
#### Date
메시기가 발생한 날짜와 시간
- 응답에서 사용

### 특별한 정보
#### Host 
요청한 호스트 정보(도메인)
- 요청에서 사용
- 필수
- 하나의 서버가 여러 도메인을 처리해야 할 때
#### Location
페이지 리다이렉션
- 웹 브라우저는 3xx 응답의 결과에 Location 헤더가 있으면, Location 위치로 자동이동(리다이렉트)
- 응답코드 3xx에서 설명
- 201 (Created): Location 값은 요청에 의해 생성된 리소스 URI
- 3xx (Redirection): Location 값은 요청을 자동으로 리디렉션 하기 위한 대상 리소스를 가리킴.
#### Allow
허용 가능한 HTTP 메서드
- 405 (Method Not Allowed) 에서 응답에 포함해야함
- Allow: GET, HEAD, PUT
#### Retry-After
유저 에이전트가 다음 요청을 하기까지 기다려야 하는 시간
- 503 (Service Unavailable): 서비스가 언제까지 불능인지 알려줄 수 있음
- Retry-After: Fri, 31 Dex 1999 23:59:59 GMT (날짜 표기)
- Retry_After: 120 (초단위 표기)

### 인증
- Authorization: 클라이언트 인증 정보를 서버에 전달
  - Authorization: Basic xxxxxxxxxxxxxxx
- WWW-Authenticate: 리소스 접근시 필요한 인증 방법 정의
  - 401 Unauthorized 응답과 함께 사용

### 쿠키
- Set-Cookie: 서버에서 클라이언트로 쿠키 전달(응답)
- Cookie: 클라이언트가 서버에서 받은 쿠키를 저장하고, HTTP 요청시 서버로 전달
- 사용처
  - 사용자 로그인 세션 관리
  - 광고 정보 트래킹
- 쿠키 정보는 항상 서버에 전송됨
  - 네트워크 트래픽 추가 유발
  - 최소한의 정보만 사용(세션 id, 인증 토큰)
  - 서버에 전송하지 않고, 웹 브라우저 내부에 데이터를 저장하고 싶으면 웹 스토리지 참고
- 주의!
  - 보안에 민감한 데이터는 저장하면 안됨(주민번호, 신용카드 번호 등등)
- 쿠키 생명주기
  - 세션 쿠키: 만료 날짜를 생략하면 브라우저 종료시 까지만 유지
  - 영속 쿠키: 만료 날짜를 입력하면 해당 날짜까지 유지
- 쿠키 보안
  - Secure
    - 쿠키는 http, https를 구분하지 않고 전송
    - Secure를 적용하면 https 인경우에만 전송
  - HttpOnly
    - XSS 공격 방지
    - 자바스크립트에서 접근 불가(document.cookie)
    - HTTP 전송에만 사용
  - SameSite
    - XSRF 공격 방지
    - 요청 도메인과 쿠키에 설정된 도메인이 같은 경우에만 쿠키 전송

## HTTP 캐시
### 캐시가 없을 때
- 데이터가 변경되지 않아도 계속 네트워크를 통해서 데이터를 다운로드 받아야 한다.
- 인터넷 네트워크는 매우 느리고 비싸다.
- 브라우저 로딩 속도가 느리다.
- 느린 사용자 경험
### 캐시 적용
- 캐시 덕분에 캐시 가능 시간동안 네트워크를 사용하지 않아도 된다.
- 비싼 네트워크 사용량을 줄일 수 있다.
- 브라우저 로딩 속도가 매우 빠르다.
- 빠른 사용자 경험
### 캐시 시간 초과
- 캐시 유효 시간이 초과해도, 서버의 데이터가 갱신되지 않으면
- 304 Not Modified + 헤더 메타 정보만 응답(바디X)
- 클라이언트는 서버가 보낸 응답 헤더 정보로 캐시의 메터 정보를 갱신
- 클라이언트는 캐시에 저장되어 있는 데이터 재활용
- 결과적으로 네트워크 다운로드가 발생하지만 용량이 적은 헤더 정보만 다운로드
- 매우 실용적인 해결책