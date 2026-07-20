# sum-nbo

네트워크 바이트 순서로 저장된 32비트 정수 파일들을 읽어 합을 출력하는 프로그램입니다.

## Build

```bash
make
```

## Example

```bash
echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
echo -n -e \\x00\\x00\\x00\\xc8 > two-hundred.bin
./sum-nbo thousand.bin five-hundred.bin two-hundred.bin
```

Expected output:

```text
1000(0x000003e8) + 500(0x000001f4) + 200(0x000000c8) = 1700(0x000006a4)
```
