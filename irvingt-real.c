#include <stdio.h>
#include <stdlib.h>

#ifndef IRVINGT_HAVE_ALONG
void DumpMem_Real(void* addr, unsigned int count, unsigned int size) {
	int* data_dword = addr;
	short* data_word = addr;
	char* data_byte = addr;
	unsigned int i;

	puts("");
	printf("Dump of offset %.8X\n", (int) addr);
	puts("-------------------------------");
	switch(size) {
	case 4:
		for(i = 0; i < count; i++) {
			printf("%.8X  ", data_dword[i]);
		}
		break;
	case 2:
		for(i = 0; i < count; i++) {
			printf("%.4X ", data_word[i]);
		}
		break;
	case 1:
		/* Bytes are the default */
	default:
		for(i = 0; i < count; i++) {
			printf("%.2X ", data_byte[i]);
			if((i + 1) % 16 == 0) {
				puts("");
			}
		}
	}
	puts("");
}
#endif

#ifndef IRVINGT_HAVE_ALONG
void DumpRegs_Real(int eip, int efl, int edi, int esi, int ebp, int esp, int ebx, int edx, int ecx, int eax) {
	int cf, sf, zf, of, af, pf;

	/* Extract flags */
	cf = !!(efl & (1 << 0));
	sf = !!(efl & (1 << 7));
	zf = !!(efl & (1 << 6));
	of = !!(efl & (1 << 11));
	af = !!(efl & (1 << 4));
	pf = !!(efl & (1 << 2));

	/* Print */
	puts("");
	printf("  EAX=%.8X  EBX=%.8X  ECX=%.8X  EDX=%.8X\n", eax, ebx, ecx, edx);
	printf("  ESI=%.8X  EDI=%.8X  EBP=%.8X  ESP=%.8X\n", esi, edi, ebp, esp);
	printf(
		"  EIP=%.8X  EFL=%.8X  CF=%d  SF=%d  ZF=%d  OF=%d  AF=%d  PF=%d\n",
		eip, efl, cf, sf, zf, of, af, pf
	);
	puts("");
}
#endif

void ExitProcess(int status) {
	puts("Exit");
	exit(status);
}

void WaitMsg_Real(void) {
	puts("Press Enter to continue...");
	getchar();
}

#ifndef IRVINGT_HAVE_ALONG
void WriteDec_Real(int x) {
	printf("%d", x);
	fflush(stdout);
}
#endif

#ifndef IRVINGT_HAVE_ALONG
void WriteString_Real(const char* str) {
	printf("%s", str);
	fflush(stdout);
}
#endif